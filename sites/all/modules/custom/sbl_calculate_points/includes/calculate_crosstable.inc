<?php

/**
 * Functions for calculating the Crosstable
 */

/**
 * Calculate the team points for a team and season
 */

function crosstable_calculate_team_points($nid) {
  $season = arg(1);

  $team_points = '';

  // Get a list of the teams and their points from the table sbl_team_points
  $teams = db_query('SELECT
        team_points FROM {sbl_team_points} WHERE node_id = :nid AND season = :season', array(':nid' => $nid,
    ':season' => $season
  ));
  if($teams->rowCount() > 0) {
    foreach ($teams as $team) {
      $team_points = $team->team_points;
    }
  }

  return $team_points;
}

/**
 * Calculate the board points for a team and season
 */

function crosstable_calculate_board_points($nid) {

  $season = arg(1);

  $board_points = '';

  // Get a list of the teams and their points from the table sbl_team_points
  $teams = db_query('SELECT
        board_points FROM {sbl_team_points} WHERE node_id = :nid AND season = :season', array(':nid' => $nid,
    ':season' => $season
  ));

  if($teams->rowCount() > 0) {
    foreach ($teams as $team) {
      $board_points = $team->board_points;
    }
  }

  return $board_points;
}

/**
 * Get all team_match nids for a team and season
 */
function get_all_team_matches_team($nid, $season) {
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

  // Join all home and away match nids into one array
  $team_all_matches_nids = array();
  if(isset($team_home_match['node'])) {
    $team_home_match_nids = array_keys($team_home_match['node']);
    foreach($team_home_match_nids as $key => $home_match) {
      $team_all_matches_nids[] = $home_match;
    }
  }
  if(isset($team_away_match['node'])) {
    $team_away_match_nids = array_keys($team_away_match['node']);
    foreach($team_away_match_nids as $key => $away_match) {
      $team_all_matches_nids[] = $away_match;
    }
  }
  return $team_all_matches_nids;

}

/**
 * Get the opponent for each opponent column
 */

function crosstable_opponent($nid, $team_rank) {
  $season = arg(1);
$league=arg(2);
  $opponent_nid = '';
  $selected_match_nid = '';
  $team_points = '';
  $home=0;
  $away=0;

  // Get a list of the teams and their points from the table sbl_team_points
  $season_teams = db_query('SELECT
        node_id,
        name,
        team_points,
        board_points
        FROM {sbl_team_points} WHERE season = :season AND league=:league', array(
    ':season' => $season,':league'=>$league
  ));

  // Create an array with all the needed data for the team:
  // NID, name, and team and board points
  $list_team_points = array();
  $array_key = 0;

  if($season_teams->rowCount() > 0) {
    $team_home_board_points = '';
    $team_away_board_points = '';

    foreach ($season_teams as $team) {
      $array_key++;
      $list_team_points[$array_key]['team_nid'] = $team->node_id;
      $list_team_points[$array_key]['team_name'] = $team->name;
      $list_team_points[$array_key]['team_points'] = $team->team_points;;
      $list_team_points[$array_key]['board_points'] = $team->board_points;
    }

    // Create arrays to be able to sort the array
    // We extract team points, board points and name into single arrays
    // and use those for the PHP function array_multisort
    $team_points_sort = array();
    $board_points_sort = array();
    $name_sort = array();
    foreach ($list_team_points as $team_item) {
      $team_points_sort[] = $team_item['team_points'];
      $board_points_sort[] = $team_item['board_points'];
      $name_sort[] = $team_item['team_name'];
    }
    // Sort by multiple values: First the team points, then the board points,
    // and finally alphabetically by team name
    array_multisort($team_points_sort, SORT_DESC, SORT_NUMERIC,
      $board_points_sort, SORT_DESC, SORT_NUMERIC,
      $name_sort, SORT_ASC,
      $list_team_points);

    // The array starts with zero, but we start the positionint with 1,
    // so we need so subtract 1 from the number given
    $team_rank_calculate = $team_rank - 1;

    if(!empty($list_team_points[$team_rank_calculate]['team_nid'])) {
      $opponent_nid = $list_team_points[$team_rank_calculate]['team_nid'];

      // Get all matches for the team whose row is the views row
      $team_matches = get_all_team_matches_team($nid, $season);

      // get all matches for the opponent which column is displayed
      $opponent_matches = get_all_team_matches_team($opponent_nid, $season);

      // the intersection between both arrays of node ids is the match both teams played against each other
      $displayed_match = array_intersect($team_matches, $opponent_matches);
      foreach ($displayed_match as $match) {
        $selected_match_nid = $match;
      }
    }




    if (!empty($selected_match_nid)) {
      // Create an entity metadata wrapper from the match node that was found.
      $selected_match_wrapper = entity_metadata_wrapper('node', $selected_match_nid);


      // Check if the team was home team or away team and select the board points
      // from the correct field
      $team_home_value = $selected_match_wrapper->field_tm_team_1->value();
      if (!empty($team_home_value)) {
        $team_home_nid = $selected_match_wrapper->field_tm_team_1->nid->value();
      }
      $team_away_value = $selected_match_wrapper->field_tm_team_2->value();
      if (!empty($team_away_value)) {
        $team_away_nid = $selected_match_wrapper->field_tm_team_2->nid->value();
      }
      // If the team was the home team, select the home team's board points
      $team_home_board_points = $selected_match_wrapper->field_tm_board_points_team_1->label();
      if ($nid == $team_home_nid) {
        $team_points = $team_home_board_points;
		$home=1;
		$away=0;
      }
      // If the team was the away team, select the home away's board points
      $team_away_board_points = $selected_match_wrapper->field_tm_board_points_team_2->label();
      if ($nid == $team_away_nid) {
        $team_points = $team_away_board_points;
		$home=0;
		$away=1;
      }
    }
  }
  
   // Get round of match played and link it to round
	$sql = "SELECT * FROM {field_revision_field_tm_spieltag_1} WHERE entity_id=".intval($selected_match_nid);
	$result = db_query($sql);
	$round = $result->fetchField(7);

	// Get concrete match with home and away team for tooltip
	$sql = "SELECT field_tm_team_1_target_id FROM {field_revision_field_tm_team_1} WHERE entity_id=".intval($selected_match_nid);
	$result = db_query($sql);
	$team1 = $result->fetchField();
	$sql = "SELECT name FROM {sbl_team_points} WHERE node_id=".intval($team1);
	$result = db_query($sql);
	$team1_name = $result->fetchField();
	
	$sql = "SELECT field_tm_team_2_target_id FROM {field_revision_field_tm_team_2} WHERE entity_id=".intval($selected_match_nid);
	$result = db_query($sql);
	$team2 = $result->fetchField();
	$sql = "SELECT name FROM {sbl_team_points} WHERE node_id=".intval($team2);
	$result = db_query($sql);
	$team2_name = $result->fetchField();
	
	$final_result=$home==1?$team_points.":".(8-$team_points):(8-$team_points).":".$team_points;
	

  if($nid != $opponent_nid) {
	if(strlen($team_points) > 0) return "<a href='/ergebnisse/".$season."/".$league."/".$round."' class='tooltip' title='".$round.". Spieltag: ".$team1_name." - ".$team2_name." ".$final_result."'>".number_format($team_points, 1, '.', '')."</a>";
	else return "";
  } else {
    return 999;
  }


}
