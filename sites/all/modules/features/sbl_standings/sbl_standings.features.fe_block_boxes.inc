<?php
/**
 * @file
 * sbl_standings.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function sbl_standings_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Navigation Statistikbereich';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'navigation_statistics';
  $fe_block_boxes->body = '&nbsp;';

  $export['navigation_statistics'] = $fe_block_boxes;

  return $export;
}
