<?php
/**
 * @file
 * sbl_ligaverwaltung.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function sbl_ligaverwaltung_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_tm_game|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_tm_game';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_single_match_result',
      ),
      'left' => array(
        1 => 'field_mt_player_1',
        2 => 'field_mt_color_player_1',
        3 => 'field_mt_points_player_1',
      ),
      'right' => array(
        4 => 'field_mt_player_2',
        5 => 'field_mt_color_player_2',
        6 => 'field_mt_points_player_2',
      ),
      'hidden' => array(
        7 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_single_match_result' => 'header',
      'field_mt_player_1' => 'left',
      'field_mt_color_player_1' => 'left',
      'field_mt_points_player_1' => 'left',
      'field_mt_player_2' => 'right',
      'field_mt_color_player_2' => 'right',
      'field_mt_points_player_2' => 'right',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['field_collection_item|field_tm_game|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|team_match|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'team_match';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'body',
      ),
      'left' => array(
        2 => 'group_team_home',
        3 => 'field_tm_team_1',
        4 => 'field_tm_team_points_tm_1',
        5 => 'field_tm_board_points_team_1',
      ),
      'right' => array(
        6 => 'group_team_away',
        7 => 'field_tm_team_2',
        8 => 'field_tm_team_points_tm_2',
        9 => 'field_tm_board_points_team_2',
      ),
      'footer' => array(
        10 => 'field_tm_game',
        11 => 'path',
        12 => 'metatags',
      ),
      'hidden' => array(
        13 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'body' => 'header',
      'group_team_home' => 'left',
      'field_tm_team_1' => 'left',
      'field_tm_team_points_tm_1' => 'left',
      'field_tm_board_points_team_1' => 'left',
      'group_team_away' => 'right',
      'field_tm_team_2' => 'right',
      'field_tm_team_points_tm_2' => 'right',
      'field_tm_board_points_team_2' => 'right',
      'field_tm_game' => 'footer',
      'path' => 'footer',
      'metatags' => 'footer',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|team_match|form'] = $ds_layout;

  return $export;
}
