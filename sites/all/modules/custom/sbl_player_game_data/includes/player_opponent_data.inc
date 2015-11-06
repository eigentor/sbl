<?php

/**
 * Get the opponents team in the individual games list view
 * on the player page.
 */
function opponent_team($row) {
  $player = arg(1);
  $season = arg(2);
  $opponent = '';
  $opponent_club_name = '';

  // Get the nid of the opponent
  if(!is_null($row->field_mt_player_1_1) && !is_null($row->field_mt_player_2_1)) {
    if($row->field_mt_player_1_1 == $player) {
      $opponent = $row->field_mt_player_2_1;
    } else {
      $opponent = $row->field_mt_player_1_1;
    }
  }

  // Get the season data for all players for the current season
  $opponent_season_data_query = new EntityFieldQuery();

  $opponent_season_data_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_sp_verein')
    ->fieldCondition('field_saison', 'tid', $season)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $opponent_season_data = $opponent_season_data_query->execute();

  // Get the player node for the opponent
  $opponent_player_node_query = new EntityFieldQuery();

  $opponent_player_node_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'spieler')
    ->propertyCondition('nid', $opponent)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $opponent_player_node = $opponent_player_node_query->execute();

  if(isset($opponent_season_data['field_collection_item'])) {
    // Write all field collection item ids for the player data of the current
    // season into an array
    $opponent_season_items = array_keys($opponent_season_data['field_collection_item']);
  }

  // We have the player node of the opponent
  if(isset($opponent_player_node['node'])) {
    // We need to get the opponent with a foreach, since it comes in array, even if the array has got only one element
    foreach($opponent_player_node['node'] as $opponent_player) {
      // Create an entity metadata wrapper from the opponent node
      $opponent_player_node_wrapper = entity_metadata_wrapper('node', $opponent_player->nid);
      $player_season_data = $opponent_player_node_wrapper->field_sp_verein->value();
      foreach($player_season_data as $player_data) {
        // Cross-reference the field collection items of the type field_sp_verein against
        // the array of player season data we created earlier.
        // This way, we select the data for the current season.
        if(in_array($player_data->item_id, $opponent_season_items)) {
          // Now we have the correct season data for the opponent and can extract the name of his club
          $player_data_wrapper = entity_metadata_wrapper('field_collection_item', $player_data->item_id);
          $opponent_club_name_title = $player_data_wrapper->field_fc_verein->label();
          // Link the club name to the team page
          $opponent_club_nid = $player_data->field_fc_verein[LANGUAGE_NONE][0]['target_id'];
          $opponent_club_node_url = 'verein/' .  $opponent_club_nid . '/' . $season;
          $opponent_club_name = l($opponent_club_name_title, $opponent_club_node_url);
        }
      }
    }
  }
  print $opponent_club_name;

}

function opponent_elo($row) {
  $player = arg(1);
  $season = arg(2);
  $opponent = '';
  $opponent_elo = '';

  // Get the nid of the opponent
  if(!is_null($row->field_mt_player_1_1) && !is_null($row->field_mt_player_2_1)) {
    if($row->field_mt_player_1_1 == $player) {
      $opponent = $row->field_mt_player_2_1;
    } else {
      $opponent = $row->field_mt_player_1_1;
    }
  }

  // Get the season data for all players for the current season
  $opponent_season_data_query = new EntityFieldQuery();

  $opponent_season_data_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_sp_verein')
    ->fieldCondition('field_saison', 'tid', $season)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $opponent_season_data = $opponent_season_data_query->execute();

  // Get the player node for the opponent
  $opponent_player_node_query = new EntityFieldQuery();

  $opponent_player_node_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'spieler')
    ->propertyCondition('nid', $opponent)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $opponent_player_node = $opponent_player_node_query->execute();

  if(isset($opponent_season_data['field_collection_item'])) {
    // Write all field collection item ids for the player data of the current
    // season into an array
    $opponent_season_items = array_keys($opponent_season_data['field_collection_item']);
  }

  // We have the player node of the opponent
  if(isset($opponent_player_node['node'])) {
    // We need to get the opponent with a foreach, since it comes in array, even if the array has got only one element
    foreach($opponent_player_node['node'] as $opponent_player) {
      // Create an entity metadata wrapper from the opponent node
      $opponent_player_node_wrapper = entity_metadata_wrapper('node', $opponent_player->nid);
      $player_season_data = $opponent_player_node_wrapper->field_sp_verein->value();
      foreach($player_season_data as $player_data) {
        // Cross-reference the field collection items of the type field_sp_verein against
        // the array of player season data we created earlier.
        // This way, we select the data for the current season.
        if(in_array($player_data->item_id, $opponent_season_items)) {
          // Now we have the correct season data for the opponent and can extract the name of his club
          $player_data_wrapper = entity_metadata_wrapper('field_collection_item', $player_data->item_id);
          $opponent_elo = $player_data_wrapper->field_pl_elo->value();
        }
      }
    }
  }
  print $opponent_elo;

}