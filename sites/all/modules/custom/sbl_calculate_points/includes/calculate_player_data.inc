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

$single_games_player_season = array();
$single_games_player_season = array_intersect($player_games_combined, $single_games_team_season);

  $games_data = array();

foreach($single_games_player_season as $key => $game_id) {
  $game_wrapper = entity_metadata_wrapper('field_collection_item', $game_id);

  // Get the opponent's elo
  $opponent_elo = '';
  $opponent_name = '';
  $points_player = '';

  $player_1 = $game_wrapper->field_mt_player_1->value();
  $player_2 = $game_wrapper->field_mt_player_2->value();
  if(!empty($player_1) && $game_wrapper->field_mt_player_1->nid->value() == $player_nid)  {
    // The points are the points for player 1
    $points_player = $game_wrapper->field_mt_points_player_1->label();
    // The opponent is player 2
    $opponent = $game_wrapper->field_mt_player_2->value();
    if(!empty($opponent)) {
      $opponent_name = $opponent->title;
      // Now iterate through the field collections field_sp_verein of the opponent and find the one
      // for the current season
      $season_data = $game_wrapper->field_mt_player_2->field_sp_verein->value();
      if (!empty($season_data)) {
        foreach ($game_wrapper->field_mt_player_2->field_sp_verein->value() as $season_data) {
          if (!empty($season_data->field_saison) && $season_data->field_saison[LANGUAGE_NONE][0]['tid'] == $season) {
            // The opponent elo is the one inside the field collection item for the current season
            $opponent_elo = $season_data->field_pl_elo[LANGUAGE_NONE][0]['value'];
          }
        }
      }
    }
  } elseif(!empty($player_2) && $game_wrapper->field_mt_player_2->nid->value() == $player_nid)  {
    // The points are the points for player 2
    $points_player = $game_wrapper->field_mt_points_player_2->label();
    $opponent = $game_wrapper->field_mt_player_1->value();
    if(!empty($opponent)) {
      $opponent_name = $opponent->title;
      // Now iterate through the field collections field_sp_verein and find the one
      // for the current season
      $season_data = $game_wrapper->field_mt_player_1->field_sp_verein->value();
      if (!empty($season_data)) {
        foreach ($game_wrapper->field_mt_player_1->field_sp_verein->value() as $season_data) {
          //dpm($season_data);
          if (!empty($season_data->field_saison) && $season_data->field_saison[LANGUAGE_NONE][0]['tid'] == $season) {
            $opponent_elo = $season_data->field_pl_elo[LANGUAGE_NONE][0]['value'];
          }
        }
      }
    }
  }
  $games_data[$key]['game_id'] = $game_id;
  $games_data[$key]['points_player'] = $points_player;
  $games_data[$key]['opponent_name'] = $opponent_name;
  $games_data[$key]['opponent_elo'] = $opponent_elo;
}

return $games_data;

}

function player_number_played_games() {
  $number_played_games = 0;
  $player_games = drupal_static('player_games');
  if(!empty($player_games)) {
    $number_played_games = count($player_games);
  }

  return $number_played_games;

}

function player_elo_opponents() {

  $player_nid = arg(1);
  $games_player = drupal_static('player_games');

  $elo_sum = '';

  foreach($games_player as $game) {
    $elo_sum += $game['opponent_elo'];
  }
  $elo_total = '';

  if(!empty($games_player)) {
    $count_games = count($games_player);
    $elo_total = round($elo_sum / $count_games);
  }

  //dpm($elo_total);

  return $elo_total;
}