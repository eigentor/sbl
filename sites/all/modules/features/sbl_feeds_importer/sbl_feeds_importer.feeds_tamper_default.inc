<?php
/**
 * @file
 * sbl_feeds_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function sbl_feeds_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-baden_kuerzel';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'BAD',
    'replace' => 'OSG Baden-Baden',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^BAD$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'OSG Baden-Baden Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-baden_kuerzel'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-bayern';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'BAY',
    'replace' => 'FC Bayern München',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^BAY$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'FC Bayern München Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-bayern'] = $feeds_tamper;

  return $export;
}
