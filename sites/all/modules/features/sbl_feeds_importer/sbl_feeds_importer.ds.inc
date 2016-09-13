<?php
/**
 * @file
 * sbl_feeds_importer.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function sbl_feeds_importer_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_sp_verein|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_sp_verein';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_saison',
        1 => 'field_fc_verein',
        2 => 'field_pl_board_nr',
        3 => 'field_pl_elo',
        4 => 'field_pl_master_title',
        5 => 'field_pl_country',
        6 => 'field_pl_league',
      ),
      'hidden' => array(
        7 => 'field_year_id',
        8 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_saison' => 'ds_content',
      'field_fc_verein' => 'ds_content',
      'field_pl_board_nr' => 'ds_content',
      'field_pl_elo' => 'ds_content',
      'field_pl_master_title' => 'ds_content',
      'field_pl_country' => 'ds_content',
      'field_pl_league' => 'ds_content',
      'field_year_id' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['field_collection_item|field_sp_verein|form'] = $ds_layout;

  return $export;
}
