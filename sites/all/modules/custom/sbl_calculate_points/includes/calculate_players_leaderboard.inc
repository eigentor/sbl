<?php

function get_team_nid_from_player_nid($season, $player_nid) {
  // get the team nid from the player node and the season
  $player_node_wrapper = entity_metadata_wrapper('node', $player_nid);

  $player_season_data = array();
  if(!empty($player_node_wrapper->field_sp_verein->value())) {
    foreach($player_node_wrapper->field_sp_verein->value() as $season_data) {
      $player_season_data[] = $season_data->item_id;
    }
  }

  $season_data_item_id = '';
  foreach($player_season_data as $data) {
    $players_season_data_query = new EntityFieldQuery();

    $players_season_data_query->entityCondition('entity_type', 'field_collection_item')
      ->entityCondition('bundle', 'field_sp_verein')
      ->propertyCondition('item_id', $data)
      ->fieldCondition('field_saison', 'tid', $season)
      // Bypass node access
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

    $players_season_data = $players_season_data_query->execute();
    if(isset($players_season_data['field_collection_item'])) {
      foreach($players_season_data['field_collection_item'] as $season_data) {
        $season_data_item_id = $season_data->item_id;
      }
    }
  }

  $team_nid = '';
  if(!empty($season_data_item_id)) {
    $season_data_wrapper = entity_metadata_wrapper('field_collection_item', $season_data_item_id);
    $team_nid = $season_data_wrapper->field_fc_verein->nid->value();
  }

  return $team_nid;
}

function player_get_games_per_season($player_nid, $team_nid, $season) {

  // Get all the team matches for the player's club
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
      $season_matches_combined[] = $season_home_match->nid;
    }
  }

  // Write the away games in to the $season_games_combined array
  if(isset($player_season_away_matches['node'])) {
    foreach($player_season_away_matches['node'] as $season_away_match) {
      $season_matches_combined[] = $season_away_match->nid;
    }
  }

  // Now get the single games that were played in team matches this season.

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
      $player_games_combined[] = $player_home_game->item_id;
    }
  }

  if(isset($player_season_away_games['field_collection_item'])) {
    foreach($player_season_away_games['field_collection_item'] as $player_away_game) {
      $player_games_combined[] = $player_away_game->item_id;
    }
  }

  $single_games_team_season = array();

  // Extract all field_tm_game entity IDs from the team match nodes.
  // Thus we get a list of all the field collection item ids that were played that season
  if(!empty($season_matches_combined)) {
    foreach($season_matches_combined as $season_match) {
      $season_matches_combined_wrapper = entity_metadata_wrapper('node', $season_match);
      $single_games = $season_matches_combined_wrapper->field_tm_game->value();
      foreach($single_games as $game) {
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

  return $single_games_player_season;
}

/**
* Count how many games a player has played.
 */
function player_calculate_played_games($player_nid) {

  $season = arg(1);
  // Get the team nid from the season and player nid
  $team_nid = get_team_nid_from_player_nid($season, $player_nid);
  $games_player = '';
  // Get all the games the player has played in the season
  $games_player = player_get_games_per_season($player_nid, $team_nid, $season);

  $games_player_number = '';

  $games_player_number = count($games_player);

  return $games_player_number;
}

/**
 * Add up all the points a player has won in a season.
 */

function player_calculate_won_points($player_nid) {
  $season = arg(1);
  // Get the team nid from the season and player nid
  $team_nid = get_team_nid_from_player_nid($season, $player_nid);
  $games_player = '';
  // Get all the games the player has played in the season
  $games_player = player_get_games_per_season($player_nid, $team_nid, $season);

  $player_sum_points = '';
  foreach($games_player as $game) {
    $game_wrapper = entity_metadata_wrapper('field_collection_item', $game);
    //dpm($game_wrapper->value());
    if($game_wrapper->field_mt_player_1->nid->value() == $player_nid)  {
      $player_sum_points += $game_wrapper->field_mt_points_player_1->label();
    } elseif($game_wrapper->field_mt_player_2->nid->value() == $player_nid)  {
      $player_sum_points += $game_wrapper->field_mt_points_player_2->label();
    }
  }
  return $player_sum_points;

}

/**
 * Add up all the points a player has won in a season.
 */

function player_percentage($player_nid) {
  $season = arg(1);
  // Get the team nid from the season and player nid
  $team_nid = get_team_nid_from_player_nid($season, $player_nid);
  $games_player = '';
  // Get all the games the player has played in the season
  $games_player = player_get_games_per_season($player_nid, $team_nid, $season);

  $player_sum_points = '';
  foreach($games_player as $game) {
    $game_wrapper = entity_metadata_wrapper('field_collection_item', $game);
    //dpm($game_wrapper->value());
    if($game_wrapper->field_mt_player_1->nid->value() == $player_nid)  {
      $player_sum_points += $game_wrapper->field_mt_points_player_1->label();
    } elseif($game_wrapper->field_mt_player_2->nid->value() == $player_nid)  {
      $player_sum_points += $game_wrapper->field_mt_points_player_2->label();
    }
  }
  $number_games = '';
  $number_games = count($games_player);
  $percentage = '';
  if($number_games != '' && $player_sum_points != '') {
    $percentage = round(($player_sum_points / $number_games) * 100);
  }
  return $percentage;
}

function players_sort_leaderboard($played_games_1, $played_games_2) {
  $a = $played_games_1;
  $b = $played_games_2;
  // Sort by played games
  if($a > 3) {
    return -1;
  } elseif ($a < 3) {
    return 1;
  }
}



