<?php
/**
 * @file
 * sbl_standings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sbl_standings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-navigation_statistics'] = array(
    'cache' => -1,
    'css_class' => 'navigation-statistics',
    'custom' => 0,
    'machine_name' => 'navigation_statistics',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'quatro' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'quatro',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
