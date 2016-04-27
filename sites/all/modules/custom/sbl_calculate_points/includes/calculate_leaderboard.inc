<?php


/**
 * Calculate total ELO win/loss for a team
 */
 
function get_team_elo_win_total($nid) {

$season=arg(1);
if(empty($season)) $season=get_current_season();

$elo_gain_total = db_query("SELECT SUM(elo_change) as 'summe' FROM sbl_elo_gain_per_team WHERE season=".$season." AND team=".$nid." LIMIT 1")->fetchField();
if(empty($elo_gain_total)) $elo_gain_total=0;

return $elo_gain_total > 0?"<span style='color:green'>+".$elo_gain_total."</span>":"<span style='color:red'>".$elo_gain_total."</span>";
}

/**
 * Calculation functions for the main leaderboard (View leaderbord)
 */
 
function get_players_per_club($nid) {
// Get Player IDs per Team
$season=arg(1);
if(empty($season)) $season=get_current_season();

$team_players_query = new EntityFieldQuery();
$team_players_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_sp_verein')
    ->fieldCondition('field_fc_verein', 'target_id', $nid)
	->fieldCondition('field_saison', 'tid', $season)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

$team_players = $team_players_query->execute();

$player_ids=array();

 if (isset($team_players['field_collection_item'])) {
    foreach ($team_players['field_collection_item'] as $players) {
      // Write the home games for the player into the array $player_games_combined
      $player_ids[] = $players->item_id;
    }
  }
return $player_ids;
}

function get_titles_per_team($nid,$players_title='GM') {
$title_player=array();
$player_ids=get_players_per_club($nid);
for($i=0;$i<count($player_ids);$i++) {
$title_player[$i] = @db_query("SELECT field_pl_master_title_value FROM field_data_field_pl_master_title WHERE entity_id='".$player_ids[$i]."' LIMIT 1")->fetchField();
if(empty($title_player[$i])) $title_player[$i]="_none";	
}
$titles=array_count_values($title_player);
if(empty($titles[$players_title])) $anzahl_titeltraeger=0;
else $anzahl_titeltraeger=$titles[$players_title];
return $anzahl_titeltraeger;
}

function get_elo_average_per_team($nid) {
$elo_player=array();
$count_rated_players=0;
$elo_gesamt=0;
$player_ids=get_players_per_club($nid);
//dpm($player_ids);
for($i=0;$i<count($player_ids);$i++) {
$elo_player[$i] = db_query("SELECT field_pl_elo_value FROM field_data_field_pl_elo WHERE entity_id='".$player_ids[$i]."' LIMIT 1")->fetchField();
if(empty($elo_player[$i])) $elo_player[$i]="0";
else $count_rated_players++;
$elo_gesamt+=intval($elo_player[$i]);
}
$elo_average=round($elo_gesamt/$count_rated_players,1);
return $elo_average;
}

function get_elo_average_per_team_first_eight($nid) {
$elo_player=array();
$count_rated_players=0;
$elo_gesamt=0;
$player_ids=get_players_per_club($nid);
for($i=0;$i<8;$i++) {
$elo_player[$i] = db_query("SELECT field_pl_elo_value FROM field_data_field_pl_elo WHERE entity_id='".$player_ids[$i]."' LIMIT 1")->fetchField();
if(empty($elo_player[$i])) $elo_player[$i]="0";
else $count_rated_players++;
$elo_gesamt+=intval($elo_player[$i]);
}
$elo_average=round($elo_gesamt/$count_rated_players,1);
return $elo_average;
}


function team_list_calculate_team_points($nid) {
  // Check if we are viewing the page view for the table, and if not, set the season not from the
  // argument but from the function get_current_season(). This is needed for the block
  // view of the leaderbord. */
 
  if(arg(0)=="tabelle") $season=arg(1);
	else $season=get_current_season();
 

  // Get all Team Matches the team has been involved in
  // The season that is viewed
  // Query for Home matches
  $team_home_match_query = new EntityFieldQuery();

  $team_home_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_1', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_home_match = $team_home_match_query->execute();

  // Query for away matches
  $team_away_match_query = new EntityFieldQuery();

  $team_away_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_2', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_away_match = $team_away_match_query->execute();

  // Set the variable for the home team points
  $team_home_team_points = 0;
  $team_away_team_points = 0;


  // Get the nids for the home matches, extract the home team points
  if(isset($team_home_match['node'])) {
    $team_home_match_nids = array_keys($team_home_match['node']);
    foreach($team_home_match_nids as $key => $home_match) {
      $team_home_match_wrapper = entity_metadata_wrapper('node', $home_match);
      if(!is_null($team_home_match_wrapper->field_tm_team_points_tm_1->label())) {
        $team_home_team_points += $team_home_match_wrapper->field_tm_team_points_tm_1->label();

      }
    }
  }

  // Get the nids for the away matches, extract the away team points
  if(isset($team_away_match['node'])) {
    $team_away_match_nids = array_keys($team_away_match['node']);
    foreach($team_away_match_nids as $key => $away_match) {
      $team_away_match_wrapper = entity_metadata_wrapper('node', $away_match);
      if(!is_null($team_away_match_wrapper->field_tm_team_points_tm_2->label())) {
        $team_away_team_points += $team_away_match_wrapper->field_tm_team_points_tm_2->label();
      }
    }
  }
  $team_sum_team_points = 0;
  $team_sum_team_points = floatval($team_home_team_points + $team_away_team_points);

  return $team_sum_team_points;
}

function team_list_calculate_board_points($nid) {

  // Check if we are viewing the page view for the table, and if not, set the season not from the
  // argument but from the function get_current_season(). This is needed for the block
  // view of the leaderbord. */
 if(arg(0)=="tabelle") $season=arg(1);
 else $season=get_current_season();
 

  //Get all Team Matches the team has been involved in
  // Query for Home matches
  $team_home_match_query = new EntityFieldQuery();

  $team_home_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_1', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_home_match = $team_home_match_query->execute();

  // Query for away matches
  $team_away_match_query = new EntityFieldQuery();

  $team_away_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_2', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_away_match = $team_away_match_query->execute();

  // Set the variable for the home team points
  $team_home_board_points = 0;
  $team_away_board_points = 0;

  // Get the nids for the home matches, extract the home team points
  if(isset($team_home_match['node'])) {
    $team_home_match_nids = array_keys($team_home_match['node']);
    foreach($team_home_match_nids as $key => $home_match) {
      $team_home_match_wrapper = entity_metadata_wrapper('node', $home_match);
      if(!is_null($team_home_match_wrapper->field_tm_board_points_team_1->label())) {
        $team_home_board_points += $team_home_match_wrapper->field_tm_board_points_team_1->label();
      }

    }
  }

  // Get the nids for the away matches, extract the away team points
  if(isset($team_away_match['node'])) {
    $team_away_match_nids = array_keys($team_away_match['node']);
    foreach($team_away_match_nids as $key => $away_match) {
      $team_away_match_wrapper = entity_metadata_wrapper('node', $away_match);
      if(!is_null($team_away_match_wrapper->field_tm_board_points_team_2->label())) {
        $team_away_board_points += $team_away_match_wrapper->field_tm_board_points_team_2->label();
      }
    }
  }
  $team_sum_board_points = 0;
  $team_sum_board_points = floatval($team_home_board_points + $team_away_board_points);


  return $team_sum_board_points;
}

/**
 * Count how many games a team has played.
 */
function team_list_calculate_played_games($nid) {

  $season = arg(1);

  //Get all Team Matches the team has been involved in
  // Query for Home matches
  $team_home_match_query = new EntityFieldQuery();

  $team_home_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_1', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_home_match = $team_home_match_query->execute();

  // Query for away matches
  $team_away_match_query = new EntityFieldQuery();

  $team_away_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_2', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_away_match = $team_away_match_query->execute();

  // Count the home matches
  $home_match_number = '';
  if(isset($team_home_match['node'])) {
    $home_match_number = count($team_home_match['node']);
  }
  // count the away matches
  $away_match_number = '';
  if(isset($team_away_match['node'])) {
    $away_match_number = count($team_away_match['node']);
  }
  $total_games_number = $home_match_number + $away_match_number;

  return $total_games_number;
}

/**
 * Count how many games a team has won.
 */
function team_list_calculate_won_games($nid) {

  $season = arg(1);

  //Get all Team Matches the team has been involved in
  // Query for Home matches
  $team_home_match_query = new EntityFieldQuery();

  $team_home_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_1', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    ->fieldCondition('field_tm_team_points_tm_1', 'value', 2)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_home_match = $team_home_match_query->execute();

  // Query for away matches
  $team_away_match_query = new EntityFieldQuery();

  $team_away_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_2', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    ->fieldCondition('field_tm_team_points_tm_2', 'value', 2)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_away_match = $team_away_match_query->execute();

  // Count the home matches
  $won_home_match_number = '';
  if(isset($team_home_match['node'])) {
    $won_home_match_number = count($team_home_match['node']);
    //dpm($team_home_match['node']);
  }
  // count the away matches
  $won_away_match_number = '';
  if(isset($team_away_match['node'])) {
    $won_away_match_number = count($team_away_match['node']);
    //dpm($team_away_match['node']);
  }
  $total_won_games_number = $won_home_match_number + $won_away_match_number;

  //$node_wrapper = entity_metadata_wrapper('node', 590);
  //dpm($node_wrapper->value());

  return $total_won_games_number;
}

/**
 * Count how many games a team has drawn.
 */
function team_list_calculate_drawn_games($nid) {

  $season = arg(1);

  //Get all Team Matches the team has been involved in
  // Query for Home matches
  $team_home_match_query = new EntityFieldQuery();

  $team_home_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_1', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    ->fieldCondition('field_tm_team_points_tm_1', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_home_match = $team_home_match_query->execute();

  // Query for away matches
  $team_away_match_query = new EntityFieldQuery();

  $team_away_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_2', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    ->fieldCondition('field_tm_team_points_tm_2', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_away_match = $team_away_match_query->execute();

  // Count the home matches
  $drawn_home_match_number = '';
  if(isset($team_home_match['node'])) {
    $drawn_home_match_number = count($team_home_match['node']);
    //dpm($team_home_match['node']);
  }
  // count the away matches
  $drawn_away_match_number = '';
  if(isset($team_away_match['node'])) {
    $drawn_away_match_number = count($team_away_match['node']);
    //dpm($team_away_match['node']);
  }
  $total_drawn_games_number = $drawn_home_match_number + $drawn_away_match_number;

  //$node_wrapper = entity_metadata_wrapper('node', 590);
  //dpm($node_wrapper->value());

  return $total_drawn_games_number;
}

/**
 * Count how many games a team has drawn.
 */
function team_list_calculate_lost_games($nid) {

  $season = arg(1);

  //Get all Team Matches the team has been involved in
  // Query for Home matches
  $team_home_match_query = new EntityFieldQuery();

  $team_home_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_1', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    ->fieldCondition('field_tm_team_points_tm_1', 'value', 0)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_home_match = $team_home_match_query->execute();

  // Query for away matches
  $team_away_match_query = new EntityFieldQuery();

  $team_away_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_2', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    ->fieldCondition('field_tm_team_points_tm_2', 'value', 0)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_away_match = $team_away_match_query->execute();

  // Count the home matches
  $lost_home_match_number = '';
  if(isset($team_home_match['node'])) {
    $lost_home_match_number = count($team_home_match['node']);
    //dpm($team_home_match['node']);
  }
  // count the away matches
  $lost_away_match_number = '';
  if(isset($team_away_match['node'])) {
    $lost_away_match_number = count($team_away_match['node']);
    //dpm($team_away_match['node']);
  }
  $total_lost_games_number = $lost_home_match_number + $lost_away_match_number;

  //$node_wrapper = entity_metadata_wrapper('node', 590);
  //dpm($node_wrapper->value());

  return $total_lost_games_number;
}

function team_list_calculate_board_points_half($nid,$kategorie,$result='') {

  // Check if we are viewing the page view for the table, and if not, set the season not from the
  // argument but from the function get_current_season(). This is needed for the block
  // view of the leaderbord. */
  /*
  $view = views_get_page_view();
  if(isset($view) && $view->name == 'teams_leaderbord') {
    $season = arg(1);
  } else {
    $season = get_current_season();
  } */
  
  $season=arg(1);
  

  //Get all Team Matches the team has been involved in
  // Query for Home matches
  $team_home_match_query = new EntityFieldQuery();

  $team_home_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_1', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_home_match = $team_home_match_query->execute();

  // Query for away matches
  $team_away_match_query = new EntityFieldQuery();

  $team_away_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_2', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_game_has_result', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_away_match = $team_away_match_query->execute();

  // Set the variable for the home team points
  $team_home_board_points = 0;
  $team_away_board_points = 0;
  
  $team_home_board_points_old=0;
  $team_away_board_points_old = 0;
  $team_home_wins = 0;
  $team_away_wins = 0;
  $team_home_draws = 0;
  $team_away_draws = 0;
  $team_home_losses = 0;
  $team_away_losses = 0;

  // Get the nids for the home matches, extract the home team points
  if(isset($team_home_match['node'])) {
    $team_home_match_nids = array_keys($team_home_match['node']);
    foreach($team_home_match_nids as $key => $home_match) {
      $team_home_match_wrapper = entity_metadata_wrapper('node', $home_match);
	  if($kategorie=="top") {
      if(!is_null($team_home_match_wrapper->field_tm_board_points_team_1_top->label())) {
        $team_home_board_points += $team_home_match_wrapper->field_tm_board_points_team_1_top->label();
      }
	  }
	  else {
	  if(!is_null($team_home_match_wrapper->field_tm_board_points_team_1_low->label())) {
        $team_home_board_points += $team_home_match_wrapper->field_tm_board_points_team_1_low->label();
      }
	  }
	$team_home_wins+=($team_home_board_points-$team_home_board_points_old) > 2?1:0;
	$team_home_draws+=($team_home_board_points-$team_home_board_points_old) == 2?1:0;
	$team_home_losses+=($team_home_board_points-$team_home_board_points_old) < 2?1:0;
	$team_home_board_points_old=$team_home_board_points;
    }
  }

  // Get the nids for the away matches, extract the away team points
  if(isset($team_away_match['node'])) {
    $team_away_match_nids = array_keys($team_away_match['node']);
    foreach($team_away_match_nids as $key => $away_match) {
      $team_away_match_wrapper = entity_metadata_wrapper('node', $away_match);
	 if($kategorie=="top") {
      if(!is_null($team_away_match_wrapper->field_tm_board_points_team_2_top->label())) {
        $team_away_board_points += $team_away_match_wrapper->field_tm_board_points_team_2_top->label();
      }
	  }
	 else {
	 if(!is_null($team_away_match_wrapper->field_tm_board_points_team_2_low->label())) {
        $team_away_board_points += $team_away_match_wrapper->field_tm_board_points_team_2_low->label();
      }
	 }
	$team_away_wins+=($team_away_board_points-$team_away_board_points_old) > 2?1:0;
	$team_away_draws+=($team_away_board_points-$team_away_board_points_old) == 2?1:0;
	$team_away_losses+=($team_away_board_points-$team_away_board_points_old) < 2?1:0;
	$team_away_board_points_old=$team_away_board_points;
    }
  }
  $team_sum_board_points = 0;
  $team_sum_board_points = floatval($team_home_board_points + $team_away_board_points);
  
  $team_sum_wins_count = 0;
  $team_sum_wins_count = intval($team_home_wins + $team_away_wins);

  $team_sum_draws_count = 0;
  $team_sum_draws_count = intval($team_home_draws + $team_away_draws);
  
  $team_sum_losses_count = 0;
  $team_sum_losses_count = intval($team_home_losses + $team_away_losses);
 
$team_sum_mp_count=(2*$team_sum_wins_count) + $team_sum_draws_count;

	switch($result) {
	case "wins":
	return $team_sum_wins_count;
	case "draws":
	return $team_sum_draws_count;
	case "losses":
	return $team_sum_losses_count;
	case "mp":
	return $team_sum_mp_count;
	default:
	return $team_sum_board_points;
	}

}

