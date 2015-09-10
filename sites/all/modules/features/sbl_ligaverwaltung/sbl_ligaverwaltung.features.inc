<?php
/**
 * @file
 * sbl_ligaverwaltung.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sbl_ligaverwaltung_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
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
 * Implements hook_image_default_styles().
 */
function sbl_ligaverwaltung_image_default_styles() {
  $styles = array();

  // Exported image style: spielerbild.
  $styles['spielerbild'] = array(
    'label' => 'Spielerbild',
    'effects' => array(
      36 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 175,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: vereinslogo.
  $styles['vereinslogo'] = array(
    'label' => 'Vereinslogo',
    'effects' => array(
      35 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 130,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: vereinslogo_klein.
  $styles['vereinslogo_klein'] = array(
    'label' => 'Vereinslogo klein',
    'effects' => array(
      37 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 30,
          'height' => 30,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function sbl_ligaverwaltung_node_info() {
  $items = array(
    'mannschaft' => array(
      'name' => t('Verein'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'spieler' => array(
      'name' => t('Spieler'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'team_match' => array(
      'name' => t('Mannschaftsmatch'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
