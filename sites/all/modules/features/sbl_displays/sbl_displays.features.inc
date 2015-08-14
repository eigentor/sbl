<?php
/**
 * @file
 * sbl_displays.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sbl_displays_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
