<?php

function player_single_result_matchday($row, $matchday) {
  $player = $row->nid;
  $season = $row->field_saison;
  $team = arg(1);
  $points_home_player = '';
  $points_away_player = '';
  $points_player = '';
  dpm($row);

  // Get all matches for the players team for the current season
  $player_season_home_matches_query = new EntityFieldQuery();

  $player_season_home_matches_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_tm_team_1', 'target_id', $team)
    ->fieldCondition('field_tm_spieltag_1', 'value', $matchday)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_season_home_matches = $player_season_home_matches_query->execute();

  if(isset($player_season_home_matches['node'])) {
    foreach($player_season_home_matches['node'] as $season_home_match) {
      $season_home_match_wrapper = entity_metadata_wrapper('node', $season_home_match->nid);
      dpm($season_home_match_wrapper->value());
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

  if(isset($player_season_home_games['field_collection_item'])) {
    foreach($player_season_home_games['field_collection_item'] as $player_home_game) {
      $player_home_game_wrapper = entity_metadata_wrapper('field_collection_item', $player_home_game->item_id);
      $points_home_player = $player_home_game_wrapper->field_mt_points_player_1->label();
    }
  }
  return($points_home_player);
}