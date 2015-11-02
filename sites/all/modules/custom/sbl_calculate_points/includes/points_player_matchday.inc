<?php

/**
 * Calculate the points per Player depending on the matchday and season
 */

function points_player_per_matchday($row, $matchday) {
  //dpm($row);

  $player_nid = $row->nid;
  $season = arg(2);
  $team = arg(1);

  // Get all Team Matches the team has been involved in
  // The season that is viewed
  // Query for Home matches
  $player_home_game_query = new EntityFieldQuery();

  $player_home_game_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_tm_game')
    ->fieldCondition('field_mt_player_1', 'target_id', $player_nid)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_home_game = $player_home_game_query->execute();

  // Query for away matches
  $player_away_game_query = new EntityFieldQuery();

  $player_away_game_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_tm_game')
    //->fieldCondition('field_game_has_result', 'value', 1)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $player_away_match = $player_away_game_query->execute();

  //dpm($player_home_game);



  if(isset($player_home_game['field_collection_item'])) {
    foreach($player_home_game['field_collection_item'] as $home_game) {
      $home_game_wrapper = entity_metadata_wrapper('field_collection_item', $home_game->item_id);
      //$home_games[] = $home_game->item_id;
    }
  }
  //dpm($home_games);

  // Get all team matches for the displayed team to cross-reference them with the
  // players games
  // Query for Home matches
  $team_season_home_matches_query = new EntityFieldQuery();

  $team_season_home_matches_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_tm_team_1', 'target_id', $team)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $team_season_home_matches = $team_season_home_matches_query->execute();

   // Write the home games into an array
  $home_games = array();

  if(isset($team_season_home_matches['node'])) {
    //dpm($team_season_home_matches['node']);
     foreach ($team_season_home_matches['node'] as $season_home_match) {
       //if($season_match->nid == 580) {
        $team_season_home_matches_wrapper = entity_metadata_wrapper('node', $season_home_match->nid);
        dpm($team_season_home_matches_wrapper->value());
        //$home_games[] =
      //}
    }
  }

}