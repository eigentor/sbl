<?php
/**
 * @file
 * sbl_kontext.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sbl_kontext_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
