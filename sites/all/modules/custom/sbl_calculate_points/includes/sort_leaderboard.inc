<?php

/**
 * Filter functions for the main leaderboard (View leaderbord)
 */

function team_list_sort_by_team_and_board_points($team_points_1, $team_points_2 ,$board_points_1, $board_points_2) {
  $a = $team_points_1;
  $b = $team_points_2;
  $c = $board_points_1;
  $d = $board_points_2;
  // Sort by team points, if the team points are different
  if($a > $b) {
    return -1;
  } elseif ($a < $b) {
    return 1;
  }
  // If the team points are the same, additionally sort by board points
  elseif ($a == $b && $c > $d) {
    return -1;
  } elseif ($a == $b && $c < $d) {
    return 1;
  }
}

