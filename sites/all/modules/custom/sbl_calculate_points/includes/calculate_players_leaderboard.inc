<?php

/**
* Count how many games a player has played.
 */
function player_calculate_played_games($player_nid, $team_nid) {

  $season = arg(1);

  $points_home_player = '';
  $points_away_player = '';
  $points_player = '';

  // First, get all the team matches for the player's club
  // Get all home matches for the players team for the current season
  $player_season_home_matches_query = new EntityFieldQuery();

  $player_season_home_matches_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_tm_team_1', 'target_id', $team_nid)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_season_home_matches = $player_season_home_matches_query->execute();

  // Get all away matches for the players team for the current season
  $player_season_away_matches_query = new EntityFieldQuery();

  $player_season_away_matches_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_tm_team_2', 'target_id', $team_nid)
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


  // Get all the single games the player was involved in
  // Get the home games for the player
  $player_season_home_games_query = new EntityFieldQuery();

  $player_season_home_games_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_tm_game')
    ->fieldCondition('field_mt_player_1', 'target_id', $player_nid)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_season_home_games = $player_season_home_games_query->execute();

  // Get the home games for the player
  $player_season_away_games_query = new EntityFieldQuery();

  $player_season_away_games_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_tm_game')
    ->fieldCondition('field_mt_player_2', 'target_id', $player_nid)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_season_away_games = $player_season_away_games_query->execute();

  // Write home and away games into one array
  $player_games_combined = array();

  if(isset($player_season_home_games['field_collection_item'])) {
    foreach($player_season_home_games['field_collection_item'] as $player_home_game) {
      // Write the home games for the player into the array $player_games_combined
      $player_games_combined[] = $player_home_game;
      $player_home_game_wrapper = entity_metadata_wrapper('field_collection_item', $player_home_game->item_id);
      $points_home_player = $player_home_game_wrapper->field_mt_points_player_1->label();
    }
  }

  if(isset($player_season_away_games['field_collection_item'])) {
    foreach($player_season_away_games['field_collection_item'] as $player_away_game) {
      $player_games_combined[] = $player_away_game;
    }
  }

  dpm($player_games_combined);



//  // Query for away matches
//  $team_away_match_query = new EntityFieldQuery();
//
//  $team_away_match_query->entityCondition('entity_type', 'node')
//    ->entityCondition('bundle', 'team_match')
//    ->propertyCondition('status', NODE_PUBLISHED)
//    ->fieldCondition('field_tm_team_2', 'target_id', $nid)
//    ->fieldCondition('field_tm_saison', 'tid', $season)
//    ->fieldCondition('field_game_has_result', 'value', 1)
//    // Bypass node access
//    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
//
//  $team_away_match = $team_away_match_query->execute();
//
//  // Count the home matches
//  $home_match_number = '';
//  if (isset($team_home_match['node'])) {
//    $home_match_number = count($team_home_match['node']);
//  }
//  // count the away matches
//  $away_match_number = '';
//  if (isset($team_away_match['node'])) {
//    $away_match_number = count($team_away_match['node']);
//  }
//  $total_games_number = $home_match_number + $away_match_number;
}

