<?php

/**
 * Implements hook_views_data_alter().
 */
function sbl_views_custom_filter_views_data_alter(&$data) {
  $data['field_collection_item']['filter_player_opponent']['title'] = 'Filter player and opponent';
  $data['field_collection_item']['filter_player_opponent']['help'] = 'Find the items in which the player is player 1 or player 2.';
  $data['field_collection_item']['filter_player_opponent']['filter']['handler'] = 'sbl_views_custom_filter_handler_filterp_player_opponent';
}

/**
 * Custom Filter Class
 *
 * @ingroup views_filter_handlers
 */
class sbl_views_custom_filter_handler_filterp_player_opponent extends views_handler_filter {

}