<?php
/**
 * @file
 * sbl_ligaverwaltung.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sbl_ligaverwaltung_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sbl_ligaverwaltung_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sbl_ligaverwaltung_node_info() {
  $items = array(
    'mannschaft' => array(
      'name' => t('Mannschaft'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'spieler' => array(
      'name' => t('Spieler'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'team_match' => array(
      'name' => t('Mannschaftsmatch'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
