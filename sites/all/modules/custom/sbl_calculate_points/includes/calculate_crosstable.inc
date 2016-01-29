<?php

/**
 * Functions for calculating the Crosstable
 */

/**
 * Calculate the team points for a team and season
 */

function crosstable_calculate_team_points($nid) {
  $season = arg(1);

  // Get a list of the teams and their points from the table sbl_team_points
  $teams = db_query('SELECT
        team_points FROM {sbl_team_points} WHERE node_id = :nid AND season = :season', array(':nid' => $nid,
      ':season' => $season
    ));

  foreach($teams as $team) {
    $team_points = $team->team_points;
  }

  return $team_points;
}

/**
 * Calculate the board points for a team and season
 */

function crosstable_calculate_board_points($nid) {

 $season = arg(1);

  // Get a list of the teams and their points from the table sbl_team_points
  $teams = db_query('SELECT
        board_points FROM {sbl_team_points} WHERE node_id = :nid AND season = :season', array(':nid' => $nid,
      ':season' => $season
    ));

  foreach($teams as $team) {
    $board_points = $team->board_points;
  }

  return $board_points;
}

/**
 * Get the opponent for each opponent column
 */

function crosstable_opponent($team_rank) {
  $season = arg(1);

  // Get a list of the teams and their points from the table sbl_team_points
  $season_teams = db_query('SELECT
        node_id,
        name,
        team_points,
        board_points
        FROM {sbl_team_points} WHERE season = :season', array(
      ':season' => $season
    ));

  // Create an array with all the needed data for the team:
  // NID, name, and team and board points
  $list_team_points = array();
  $array_key = 0;
  foreach($season_teams as $team) {
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
  foreach($list_team_points as $team_item) {
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
  $team_rank_calculate = $team_rank -1;

  return $list_team_points[$team_rank_calculate]['team_nid'];
}

function crosstable_opponent_2($team_rank) {

  $season = arg(1);

  // Get a list of the teams and their points from the table sbl_team_points
  $season_teams = db_query('SELECT
        node_id,
        name,
        team_points,
        board_points
        FROM {sbl_team_points} WHERE season = :season', array(
      ':season' => $season
    ));

  // Create an array with all the needed data for the team:
  // NID, name, and team and board points
  $list_team_points = array();
  $array_key = 0;
  foreach($season_teams as $team) {
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
  foreach($list_team_points as $team_item) {
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
  $team_rank_calculate = $team_rank -1;

  return $list_team_points[$team_rank_calculate]['team_nid'];

}