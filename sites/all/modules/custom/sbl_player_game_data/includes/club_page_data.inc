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


/**
 * Custom Funktion, um die Ergebnisse pro Spieltag für die Teamseite auszugeben
 *
 */
function print_results_matchday_club(){

  $season = '';
  $matchday = '';
  $match_node = '';
  $team = '';

// Print the results for a matchday
// We get the season and the matchday from the URL
  $team = arg(1);
  $season = arg(2);
  $matchday_arg = arg(3);
  if(isset($matchday_arg)) {
    $matchday = $matchday_arg;
  } else {
    // if the argument is not in the url, use the current matchday
    $matchday = get_current_matchday();
  }

  // Get all home matches for the players team for the current season
  $player_season_home_matches_query = new EntityFieldQuery();

  $player_season_home_matches_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_tm_team_1', 'target_id', $team)
    ->fieldCondition('field_tm_spieltag_1', 'value', $matchday)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_season_home_matches = $player_season_home_matches_query->execute();

  // Get all away matches for the players team for the current season
  $player_season_away_matches_query = new EntityFieldQuery();

  $player_season_away_matches_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_tm_team_2', 'target_id', $team)
    ->fieldCondition('field_tm_spieltag_1', 'value', $matchday)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_season_away_matches = $player_season_away_matches_query->execute();

  // Write home and away games into one array
  $season_matches_combined = array();

  // Write the home games in to the $season_games_combined array
  if(isset($player_season_home_matches['node'])) {
    foreach($player_season_home_matches['node'] as $season_home_match) {
      $season_matches_combined[] = $season_home_match;
    }
  }

  // Write the away games in to the $season_games_combined array
  if(isset($player_season_away_matches['node'])) {
    foreach($player_season_away_matches['node'] as $season_away_match) {
      $season_matches_combined[] = $season_away_match;
    }
  }
  if(!empty($season_matches_combined)) {
    foreach($season_matches_combined as $match) {
      $match_node = $match->nid;
      print views_embed_view('match_results', 'block_2', $season, $matchday, $match_node);
    }
  }

//  $season_title_raw = taxonomy_term_load($season);
//  $season_title = $season_title_raw->name;
//
//// Set the title to show the season and Spieltag
//  drupal_set_title('Ergebnisse ' . $matchday . '. Spieltag ' . $season_title);
}

