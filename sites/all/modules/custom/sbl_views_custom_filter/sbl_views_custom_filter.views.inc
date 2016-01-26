<?php

/**
 * Implements hook_views_data_alter().
 */
function sbl_views_custom_filter_views_data_alter(&$data) {
  $data['field_collection_item']['filter_player_opponent']['title'] = 'Filter player and opponent';
  $data['field_collection_item']['filter_player_opponent']['help'] = 'Find the items in which the player is player 1 or player 2.';
  $data['field_collection_item']['filter_player_opponent']['filter']['handler'] = 'sbl_views_custom_filter_handler_filter_player_opponent';
}

/**
 * Custom Filter Class
 *
 * @ingroup views_filter_handlers
 */
class sbl_views_custom_filter_handler_filter_player_opponent extends views_handler_filter {
  function query() {
    $this->ensure_my_table();
    dpm($this);
    $field = "$this->table_alias.$this->real_field";

    $player_id = arg(1);


    $table = $this->table;
    $left_table = 'field_data_field_mt_player_1';
    $field = 'item_id';
    $left_field = 'entity_id';// or wathever column you want to join with
    $type = 'LEFT';// if you want another join type play with this value
    $join = new views_join();
    $join->construct($table, $left_table, $left_field, $field, array(), $type);

    $this->query->add_where(
        $this->options['group'],
        db_or()
          ->condition('field_mt_player_1_target_id', $player_id, '=')
        );

    dpm($this->query);
    dpm($join);
  }

}