<?php

/**
 * Argument Code.
 * Set the matchday argument for the view match_results / block_1
 * "Ergebnisse pro Mannschaft" that is displayed in the tab
 * "Ergebnisse" at the bottom of the team page
 */
function club_page_set_matchday($view) {
  //if the argument for the matchday is present in the URL, use it
  $matchday_arg = arg(3);
  if(isset($matchday_arg)) {
    $matchday = $matchday_arg;
  } else {
    // if the argument is not in the url, use the current matchday
    $matchday = get_current_matchday();
  }
  return $matchday;

}

/**
 * Filter the view match_results / block_1
 * "Ergebnisse pro Mannschaft" by the team on whose page
 * it is displayed.
 */
function results_filter_for_team($row) {
//  dpm($row);
  $current_team = arg(1);
  $team_1 = $row->field_tm_team_1_1;
  $team_2 = $row->field_tm_team_2_1;
  if($current_team == $team_1 || $current_team == $team_2) {
    return FALSE;
  } else {
    return TRUE;
  }
}


