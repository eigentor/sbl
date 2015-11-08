<?php

function player_single_result_matchday($row, $matchday) {
  $player = $row->nid;
  $season = $row->field_saison;
  $team = arg(1);
  $points_home_player = '';
  $points_away_player = '';
  $points_player = '';

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

  $single_games_matchday = array();
  // Get the single games from the match. The result is always just one match, because it is
  // selected by matchday per column
  if(!empty($season_matches_combined)) {
    foreach($season_matches_combined as $season_match) {
      $season_matches_combined_wrapper = entity_metadata_wrapper('node', $season_match->nid);
      $single_games = $season_matches_combined_wrapper->field_tm_game->value();
      foreach($single_games as $game) {
        // Write the field collection item IDs into the array
        $single_games_matchday[] = $game->item_id;
      }
    }
  }

  // Get the home games for the player
  $player_season_home_games_query = new EntityFieldQuery();

  $player_season_home_games_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_tm_game')
    ->fieldCondition('field_mt_player_1', 'target_id', $player)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_season_home_games = $player_season_home_games_query->execute();

  // Get the home games for the player
  $player_season_away_games_query = new EntityFieldQuery();

  $player_season_away_games_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_tm_game')
    ->fieldCondition('field_mt_player_2', 'target_id', $player)
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

  // Make sure the variable player_points always exists
  $player_points = '';
  foreach($player_games_combined as $player_game) {
    // Check, if the player played in the game that is in the array of the games
    // his team played on the matchday
    if(in_array($player_game->item_id, $single_games_matchday)) {
      $player_game_wrapper = entity_metadata_wrapper('field_collection_item', $player_game->item_id);
      if($player_game_wrapper->field_mt_player_1->nid->value() == $player) {
        $player_points = $player_game_wrapper->field_mt_points_player_1->label();
      } else {
        $player_points = $player_game_wrapper->field_mt_points_player_2->label();
      }
    }
  }

  return($player_points);
}