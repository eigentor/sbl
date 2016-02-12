<?php

function player_get_games($player_team) {

  $player_nid = arg(1);
  $season = arg(2);

  // Get all the team matches for the player's club
  // Get all home matches for the players team for the current season
  $player_season_home_matches_query = new EntityFieldQuery();

  $player_season_home_matches_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_tm_team_1', 'target_id', $player_team)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_season_home_matches = $player_season_home_matches_query->execute();

  // Get all away matches for the players team for the current season
  $player_season_away_matches_query = new EntityFieldQuery();

  $player_season_away_matches_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_tm_team_2', 'target_id', $player_team)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_season_away_matches = $player_season_away_matches_query->execute();

  // Write home and away games into one array
  $season_matches_combined = array();

  // Write the home games in to the $season_games_combined array
  if (isset($player_season_home_matches['node'])) {
    foreach ($player_season_home_matches['node'] as $season_home_match) {
      $season_matches_combined[] = $season_home_match->nid;
    }
  }

  // Write the away games in to the $season_games_combined array
  if (isset($player_season_away_matches['node'])) {
    foreach ($player_season_away_matches['node'] as $season_away_match) {
      $season_matches_combined[] = $season_away_match->nid;
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

  if (isset($player_season_home_games['field_collection_item'])) {
    foreach ($player_season_home_games['field_collection_item'] as $player_home_game) {
      // Write the home games for the player into the array $player_games_combined
      $player_games_combined[] = $player_home_game->item_id;
    }
  }

  if (isset($player_season_away_games['field_collection_item'])) {
    foreach ($player_season_away_games['field_collection_item'] as $player_away_game) {
      $player_games_combined[] = $player_away_game->item_id;
    }
  }
}

$single_games_team_season = array();

// Extract all field_tm_game entity IDs from the team match nodes.
// Thus we get a list of all the field collection item ids that were played that season
if (!empty($season_matches_combined)) {
  foreach ($season_matches_combined as $season_match) {
    $season_matches_combined_wrapper = entity_metadata_wrapper('node', $season_match);
    $single_games = $season_matches_combined_wrapper->field_tm_game->value();
    foreach ($single_games as $game) {
      // Write the field collection item IDs into the array
      $single_games_team_season[] = $game->item_id;
    }
  }
}

// Now get an intersection between the two queries: the entity_ids of the single games
// the player played - which are contained in the array $player_games_combined
// and all single games that were played by his team in the season - which are contained
// in the array $single_games_team_season. The field collection items that are in both arrays
// have been played by the player in the season

$single_games_player_season = '';
$single_games_player_season = array_intersect($player_games_combined, $single_games_team_season);

//dpm($single_games_player_season);
