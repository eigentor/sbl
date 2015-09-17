<?php

/**
 * Calculation functions for the main leaderboard (View leaderbord)
 */

function team_list_calculate_team_points($nid) {
  // Check if we are viewing the page view for the table, and if not, set the season not from the
  // argument but from the function get_current_season(). This is needed for the block
  // view of the leaderbord. */
  $view = views_get_page_view();
  if(isset($view) && $view->name == 'teams_leaderbord') {
    $season = arg(1);
  } else {
    $season = get_current_season();
  }

  // Get all Team Matches the team has been involved in
  // The season that is viewed
  // Query for Home matches
  $team_home_match_query = new EntityFieldQuery();

  $team_home_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_1', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
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
  $view = views_get_page_view();
  if(isset($view) && $view->name == 'teams_leaderbord') {
    $season = arg(1);
  } else {
    $season = get_current_season();
  }

  //Get all Team Matches the team has been involved in
  // Query for Home matches
  $team_home_match_query = new EntityFieldQuery();

  $team_home_match_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_tm_team_1', 'target_id', $nid)
    ->fieldCondition('field_tm_saison', 'tid', $season)
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