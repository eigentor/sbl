<?php
/**
 * @file
 * sbl_inhaltsytpen.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sbl_inhaltsytpen_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function sbl_inhaltsytpen_node_info() {
  $items = array(
    'content_startseite' => array(
      'name' => t('Content Startseite'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'partiendownload' => array(
      'name' => t('Partiendownload'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'photos' => array(
      'name' => t('Fotostrecken'),
      'base' => 'node_content',
      'description' => t('Inhaltstyp, mit dem Fotostrecken in einer Slideshow angezeigt werden können.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
