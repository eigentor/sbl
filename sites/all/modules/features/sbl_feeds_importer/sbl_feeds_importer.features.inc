<?php
/**
 * @file
 * sbl_feeds_importer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sbl_feeds_importer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
}
