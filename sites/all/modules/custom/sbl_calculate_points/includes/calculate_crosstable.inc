<?php

/**
 * Functions for calculating the Crosstable
 */

/**
 * Calculate the team points for a team and season
 */

function crosstable_calculate_team_points($nid) {
  $season = arg(1);

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

/**
 * Calculate the board points for a team and season
 */

function crosstable_calculate_board_points($nid) {

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
 * Get the opponent for each opponent column
 */

function crosstable_opponenent($view) {
  // Get a list of all teams in the table
  $list_teams = array();
  foreach($view->result as $result) {
    $list_teams[] = $result->nid;
  }
  $list_team_team_points = array();
  foreach($list_teams as $key => $team_nid) {
    $team_points = crosstable_calculate_team_points($team_nid);
    $board_points = crosstable_calculate_board_points($team_nid);
    $list_team_team_points[$team_nid]['team_points'] = $team_points;
    $list_team_team_points[$team_nid]['board_points'] = $board_points;
  }
  $team_points_sort = array();
  $board_points_sort = array();
  foreach($list_team_team_points as $team) {
    $team_points_sort[] = $team['team_points'];
    $board_points_sort[] = $team['board_points'];
  }
  //dpm($team_points_sort);
  array_multisort($team_points_sort, SORT_DESC, SORT_NUMERIC,
    $board_points_sort, SORT_DESC, SORT_NUMERIC,
    $list_team_team_points);

  dpm($list_team_team_points);
}