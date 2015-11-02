<?php

/**
 * Get the opponents team in the individual games list view
 * on the player page.
 */
function opponent_team($row) {
  $player = arg(1);
  $season = arg(2);
  $opponent = '';

  // Get the nid of the opponent
  if(!is_null($row->field_mt_player_1_1) && !is_null($row->field_mt_player_2_1)) {
    if($row->field_mt_player_1_1 == $player) {
    $opponent = $row->field_mt_player_2_1;
    } else {
      $opponent = $row->field_mt_player_1_1;
    }
  }

  // Get the season data for the opponent
  $opponent_season_data_query = new EntityFieldQuery();

  $opponent_season_data_query->entityCondition('entity_type', 'field_collection_item')
    ->entityCondition('bundle', 'field_sp_verein')
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $opponent_season_data = $opponent_season_data_query->execute();

  if(isset($opponent_season_data['field_collection_item'])) {
    dpm($opponent_season_data['field_collection_item']);
    foreach($opponent_season_data['field_collection_item'] as $season_data) {
      if($season_data->item_id == 7) {
        $season_data_wrapper = entity_metadata_wrapper('field_collection_item', $season_data->item_id);
        dpm($season_data_wrapper->value());
      }
    }
  }

}