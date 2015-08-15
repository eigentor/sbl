<?php
/**
 * @file
 * sbl_displays.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function sbl_displays_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'eingebettete_videos';
  $ds_view_mode->label = 'Eingebettete Videos';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['eingebettete_videos'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'fotostrecken';
  $ds_view_mode->label = 'Fotostrecken';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['fotostrecken'] = $ds_view_mode;

  return $export;
}
