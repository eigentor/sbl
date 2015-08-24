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
  $feeds_tamper->id = 'player_team_mapping-country-find_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'GER',
    'replace' => 'DEU',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^GER$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'ger_replace';
  $export['player_team_mapping-country-find_replace'] = $feeds_tamper;

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

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-dor_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'DOR',
    'replace' => 'SC Hansa Dortmund',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^DOR$/ui',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'SC Hansa Dortmund Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-dor_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-dre_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'DRE',
    'replace' => 'USV TU Dresden',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^DRE$/ui',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'USV TU Dresden Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-dre_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-ems_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'EMS',
    'replace' => 'SK Turm Emsdetten',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^EMS$/ui',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'SK Turm Emsdetten Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-ems_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-epp_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'EPP',
    'replace' => 'SC Eppingen',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^EPP$/ui',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'SC Eppingen Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-epp_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-erf_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ERF',
    'replace' => 'Erfurter SK',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ERF$/ui',
  );
  $feeds_tamper->weight = 6;
  $feeds_tamper->description = 'Erfurter SK Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-erf_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-gri_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'GRI',
    'replace' => 'SV Griesheim',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^GRI$/ui',
  );
  $feeds_tamper->weight = 7;
  $feeds_tamper->description = 'SV Griesheim Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-gri_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-hoc_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'HOC',
    'replace' => 'SV 1930 Hockenheim',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^HOC$/ui',
  );
  $feeds_tamper->weight = 8;
  $feeds_tamper->description = 'SV 1930 Hockenheim Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-hoc_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-hsk_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'HSK',
    'replace' => 'Hamburger SK',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^HSK$/ui',
  );
  $feeds_tamper->weight = 9;
  $feeds_tamper->description = 'Hamburger SK Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-hsk_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-kat_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'KAT',
    'replace' => 'SF Katernberg',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^KAT$/ui',
  );
  $feeds_tamper->weight = 10;
  $feeds_tamper->description = 'SF Katernberg Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-kat_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-mul_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'MUL',
    'replace' => 'SV Mülheim Nord',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^MUL$/ui',
  );
  $feeds_tamper->weight = 11;
  $feeds_tamper->description = 'SV Mülheim Nord Vereinkürzel ersetzen';
  $export['player_team_mapping-ver-mul_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-nor_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'NOR',
    'replace' => 'SK Norderstedt 1975',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^NOR$/ui',
  );
  $feeds_tamper->weight = 12;
  $feeds_tamper->description = 'SK Norderstedt 1975 Vereinkürzel ersetzen';
  $export['player_team_mapping-ver-nor_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-ros_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ROS',
    'replace' => 'SSC Rostock 07',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ROS$/ui',
  );
  $feeds_tamper->weight = 13;
  $feeds_tamper->description = 'SSC Rostock 07 Vereinkürzel ersetzen';
  $export['player_team_mapping-ver-ros_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-sfb_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SFB',
    'replace' => 'SF Berlin 1903',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SFB$/ui',
  );
  $feeds_tamper->weight = 14;
  $feeds_tamper->description = 'SF Berlin 1903 Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-sfb_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-sha_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SHA',
    'replace' => 'SK Schwäbisch Hall',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SHA$/ui',
  );
  $feeds_tamper->weight = 15;
  $feeds_tamper->description = 'SK Schwäbisch Hall Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-sha_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-sol_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SOL',
    'replace' => 'SG Solingen',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SOL$/ui',
  );
  $feeds_tamper->weight = 16;
  $feeds_tamper->description = 'SG Solingen Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-sol_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-tri_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'TRI',
    'replace' => 'SG Trier',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^TRI$/ui',
  );
  $feeds_tamper->weight = 17;
  $feeds_tamper->description = 'SG Trier Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-tri_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-wbr_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'WBR',
    'replace' => 'Werder Bremen',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^WBR$/ui',
  );
  $feeds_tamper->weight = 18;
  $feeds_tamper->description = 'Werder Bremen Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-wbr_replace'] = $feeds_tamper;

  return $export;
}
