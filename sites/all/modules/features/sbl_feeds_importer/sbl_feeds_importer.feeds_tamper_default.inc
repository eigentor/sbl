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
  $feeds_tamper->description = 'Deutschland Länderkürzel ersetzen';
  $export['player_team_mapping-country-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-country-ned_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'NED',
    'replace' => 'NLD',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^NED$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Niederlande Länderkürzel ersetzen';
  $export['player_team_mapping-country-ned_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-country-replace_bulgaria';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'BUL',
    'replace' => 'BLG',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^BUL$/ui',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Bulgarien Länderkürzel ersetzen';
  $export['player_team_mapping-country-replace_bulgaria'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-country-replace_croatia';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'CRO',
    'replace' => 'HRV',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^CRO$/ui',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Kroatien Länderkürzel ersetzen';
  $export['player_team_mapping-country-replace_croatia'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-country-replace_denmark';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'DEN',
    'replace' => 'DNK',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^DEN$/ui',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Dänemark Länderkürzel ersetzen';
  $export['player_team_mapping-country-replace_denmark'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-country-replace_lettland';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'LAT',
    'replace' => 'LVA',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^LAT$/ui',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Lettland Länderkürzel ersetzen';
  $export['player_team_mapping-country-replace_lettland'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-country-replace_switzerland';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SUI',
    'replace' => 'CHE',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SUI$/ui',
  );
  $feeds_tamper->weight = 6;
  $feeds_tamper->description = 'Schweiz Länderkürzel ersetzen';
  $export['player_team_mapping-country-replace_switzerland'] = $feeds_tamper;

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
  $feeds_tamper->id = 'player_team_mapping-ver-find_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'TEG',
    'replace' => 'SK König Tegel',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^TEG$/ui',
  );
  $feeds_tamper->weight = 21;
  $feeds_tamper->description = 'SK König Tegel Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-gri_replace';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'GRI',
    'replace' => 'SV Griesheim 1976',
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
  $feeds_tamper->id = 'player_team_mapping-ver-replace_aachener_sv';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ASV',
    'replace' => 'Aachener SV 1856',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ASV$/ui',
  );
  $feeds_tamper->weight = 39;
  $feeds_tamper->description = 'Aachender SV Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_aachener_sv'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_aufwaerts_aachen';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'AAC',
    'replace' => 'DJK Aufwärts Aachen',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^AAC$/ui',
  );
  $feeds_tamper->weight = 36;
  $feeds_tamper->description = 'Aufwärts Aachen Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_aufwaerts_aachen'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_berlin_2';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SF2',
    'replace' => 'SF Berlin 1903 II',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SF2$/ui',
  );
  $feeds_tamper->weight = 59;
  $feeds_tamper->description = 'SF Berlin 2 VK ersetzen';
  $export['player_team_mapping-ver-replace_berlin_2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_bremer_sg';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'BSG',
    'replace' => 'Bremer SG',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^BSG$/ui',
  );
  $feeds_tamper->weight = 74;
  $feeds_tamper->description = 'Bremer SG VK ersetzen';
  $export['player_team_mapping-ver-replace_bremer_sg'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_caissa_schwarzenbach';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'CAI',
    'replace' => 'SC Caissa Schwarzenbach',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^CAI$/ui',
  );
  $feeds_tamper->weight = 42;
  $feeds_tamper->description = 'Caissa Schwarzenbach Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_caissa_schwarzenbach'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_delmenhorster_sk';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'DEL',
    'replace' => 'Delmenhorster SK',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^DEL$/ui',
  );
  $feeds_tamper->weight = 25;
  $feeds_tamper->description = 'Delmenhorster SK Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_delmenhorster_sk'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_duesseldorfer_sk';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'DUE',
    'replace' => 'Düsseldorfer SK 1914/1925',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^DUE$/ui',
  );
  $feeds_tamper->weight = 44;
  $feeds_tamper->description = 'Düsseldorfer SK Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_duesseldorfer_sk'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_emmendingen';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'EMM',
    'replace' => 'SC Emmendingen',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^EMM$/ui',
  );
  $feeds_tamper->weight = 45;
  $feeds_tamper->description = 'SC Emmendingen Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_emmendingen'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_erlangen';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ERL',
    'replace' => 'SC Erlangen',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ERL$/ui',
  );
  $feeds_tamper->weight = 46;
  $feeds_tamper->description = 'SC Erlangen Vereinskürzel';
  $export['player_team_mapping-ver-replace_erlangen'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_garching';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'GAR',
    'replace' => 'SC Garching 1980',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^GAR$/ui',
  );
  $feeds_tamper->weight = 47;
  $feeds_tamper->description = 'SC Garching Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_garching'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_godesberger_sk';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'GOD',
    'replace' => 'Godesberger SK',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^GOD$/ui',
  );
  $feeds_tamper->weight = 66;
  $feeds_tamper->description = 'Godesberg VK ersetzen';
  $export['player_team_mapping-ver-replace_godesberger_sk'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_goeggingen';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'GOG',
    'replace' => 'SK 1908 Göggingen',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^GOG$/ui',
  );
  $feeds_tamper->weight = 48;
  $feeds_tamper->description = 'Göggingen VK ersetzen';
  $export['player_team_mapping-ver-replace_goeggingen'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_heusenstamm';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'HEU',
    'replace' => 'SC Heusenstamm',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^HEU$/ui',
  );
  $feeds_tamper->weight = 49;
  $feeds_tamper->description = 'Heusenstamm VK ersetzen';
  $export['player_team_mapping-ver-replace_heusenstamm'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_hofheim';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'HOH',
    'replace' => 'SV 1920 Hofheim',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^HOH$/ui',
  );
  $feeds_tamper->weight = 50;
  $feeds_tamper->description = 'Hofheim VK ersetzen';
  $export['player_team_mapping-ver-replace_hofheim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_hsk_2';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'HS2',
    'replace' => 'Hamburger SK II',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^HS2$/ui',
  );
  $feeds_tamper->weight = 31;
  $feeds_tamper->description = 'HSK 2 Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_hsk_2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_ingbert';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ING',
    'replace' => 'SC Anderssen St. Ingbert',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ING$/ui',
  );
  $feeds_tamper->weight = 73;
  $feeds_tamper->description = 'Ingbert VK ersetzen';
  $export['player_team_mapping-ver-replace_ingbert'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_lister_turm';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'LIS',
    'replace' => 'HSK Lister Turm Hannover',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^LIS$/ui',
  );
  $feeds_tamper->weight = 52;
  $feeds_tamper->description = 'Lister Turm VK ersetzen';
  $export['player_team_mapping-ver-replace_lister_turm'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_luebecker_sv';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'LSV',
    'replace' => 'Lübecker SV 1873',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^LSV$/ui',
  );
  $feeds_tamper->weight = 72;
  $feeds_tamper->description = 'Lübecker SV VK ersetzen';
  $export['player_team_mapping-ver-replace_luebecker_sv'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_mergentheim';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'MER',
    'replace' => 'SF Anderssen Bad Mergentheim',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^MER$/ui',
  );
  $feeds_tamper->weight = 53;
  $feeds_tamper->description = 'Bad Mergentheim VK ersetzen';
  $export['player_team_mapping-ver-replace_mergentheim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_muelheim_2';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'MU2',
    'replace' => 'SV Mülheim Nord II',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^MU2$/ui',
  );
  $feeds_tamper->weight = 54;
  $feeds_tamper->description = 'Mülheim 2 VK ersetzen';
  $export['player_team_mapping-ver-replace_muelheim_2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_neukoelln';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'NEU',
    'replace' => 'SF Neukölln 1903',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^NEU$/ui',
  );
  $feeds_tamper->weight = 71;
  $feeds_tamper->description = 'Neukölln VK ersetzen';
  $export['player_team_mapping-ver-replace_neukoelln'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_nickelhuette_aue';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'AUE',
    'replace' => 'ESV Nickelhütte Aue',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^AUE$/ui',
  );
  $feeds_tamper->weight = 26;
  $feeds_tamper->description = 'Nickelhütte Aue Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_nickelhuette_aue'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_passau';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'PAS',
    'replace' => 'SK Passau 1869',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^PAS$/ui',
  );
  $feeds_tamper->weight = 55;
  $feeds_tamper->description = 'SK Passau VK ersetzen';
  $export['player_team_mapping-ver-replace_passau'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_plauen';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'PLA',
    'replace' => 'SK König Plauen',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^PLA$/ui',
  );
  $feeds_tamper->weight = 56;
  $feeds_tamper->description = 'SK Plauen VK ersetzen';
  $export['player_team_mapping-ver-replace_plauen'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_porz';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'POR',
    'replace' => 'Schachgemeinschaft Porz',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^POR$/ui',
  );
  $feeds_tamper->weight = 57;
  $feeds_tamper->description = 'SG Porz VK ersetzen';
  $export['player_team_mapping-ver-replace_porz'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_preetzer_tsv';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'PRE',
    'replace' => 'Preetzer TSV',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^PRE$/ui',
  );
  $feeds_tamper->weight = 30;
  $feeds_tamper->description = 'Preetzer TSV Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_preetzer_tsv'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_rotation_pankow';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ROT',
    'replace' => 'Rotation Pankow',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ROT$/ui',
  );
  $feeds_tamper->weight = 29;
  $feeds_tamper->description = 'Rotation Pankow Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_rotation_pankow'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sc_bann';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'BAN',
    'replace' => 'SC Bann',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^BAN$/ui',
  );
  $feeds_tamper->weight = 67;
  $feeds_tamper->description = 'SC Bann VK ersetzen';
  $export['player_team_mapping-ver-replace_sc_bann'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sc_forchheim';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'FOR',
    'replace' => 'SC Forchheim',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^FOR$/ui',
  );
  $feeds_tamper->weight = 23;
  $feeds_tamper->description = 'SC Forchheim Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sc_forchheim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sc_kreuzberg';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'KRZ',
    'replace' => 'SC Kreuzberg',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^KRZ$/ui',
  );
  $feeds_tamper->weight = 28;
  $feeds_tamper->description = 'SC Kreuzberg Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sc_kreuzberg'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sc_leipzig';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'GOL',
    'replace' => 'SC Leipzig-Gohlis ',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^GOL$/ui',
  );
  $feeds_tamper->weight = 69;
  $feeds_tamper->description = 'Leipzig-Gohlis VK ersetzen';
  $export['player_team_mapping-ver-replace_sc_leipzig'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sc_remagen';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'REM',
    'replace' => 'SC 1950 Remagen',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^REM$/ui',
  );
  $feeds_tamper->weight = 24;
  $feeds_tamper->description = 'SC Remagen Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sc_remagen'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sc_viernheim';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'VIE',
    'replace' => 'SC Viernheim',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^VIE$/ui',
  );
  $feeds_tamper->weight = 20;
  $feeds_tamper->description = 'SC Viernheim Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sc_viernheim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_schoenaich';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SAI',
    'replace' => 'TSV Schönaich',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SAI$/ui',
  );
  $feeds_tamper->weight = 58;
  $feeds_tamper->description = 'Schönaich VK ersetzen';
  $export['player_team_mapping-ver-replace_schoenaich'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_schoeneck';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SFS',
    'replace' => 'Schachfreunde Schöneck',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SFS$/ui',
  );
  $feeds_tamper->weight = 62;
  $feeds_tamper->description = 'Schöneck VK ersetzen';
  $export['player_team_mapping-ver-replace_schoeneck'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_schott_mainz';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SMA',
    'replace' => 'TSV Schott Mainz',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SMA$/ui',
  );
  $feeds_tamper->weight = 60;
  $feeds_tamper->description = 'Schott Mainz VK ersetzen';
  $export['player_team_mapping-ver-replace_schott_mainz'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_schwegenheim';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SCH',
    'replace' => 'SG Speyer-Schwegenheim',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SCH$/ui',
  );
  $feeds_tamper->weight = 38;
  $feeds_tamper->description = 'Schwegenheim Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_schwegenheim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sf_deizisau';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'DEI',
    'replace' => 'Schachfreunde Deizisau',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^DEI$/ui',
  );
  $feeds_tamper->weight = 43;
  $feeds_tamper->description = 'Schachfreunde Deizisau Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sf_deizisau'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sf_schwerin';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SSW',
    'replace' => 'SF Schwerin',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SSW$/ui',
  );
  $feeds_tamper->weight = 32;
  $feeds_tamper->description = 'SF Schwerin Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sf_schwerin'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sg_bochum';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'BOC',
    'replace' => 'SG Bochum 31',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^BOC$/ui',
  );
  $feeds_tamper->weight = 41;
  $feeds_tamper->description = 'SG Bochum Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sg_bochum'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sg_kirchheim';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'KIR',
    'replace' => 'SG Heidelberg-Kirchheim',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^KIR$/ui',
  );
  $feeds_tamper->weight = 68;
  $feeds_tamper->description = 'SG Kirchheim VK ersetzen';
  $export['player_team_mapping-ver-replace_sg_kirchheim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sk_heidelberg';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'HDS',
    'replace' => 'SK Heidelberg Handschuhsheim',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^HDS$/ui',
  );
  $feeds_tamper->weight = 27;
  $feeds_tamper->description = 'SK Heidelberg Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sk_heidelberg'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sk_zehlendorf';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ZEH',
    'replace' => 'SK Zehlendorf',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ZEH$/ui',
  );
  $feeds_tamper->weight = 34;
  $feeds_tamper->description = 'SK Zehlendorf Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sk_zehlendorf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_solingen_2';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'SO2',
    'replace' => 'SG Solingen II',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^SO2$/ui',
  );
  $feeds_tamper->weight = 61;
  $feeds_tamper->description = 'Solingen 2 VK ersetzen';
  $export['player_team_mapping-ver-replace_solingen_2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_ssf';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'STU',
    'replace' => 'Stuttgarter SF 1879',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^STU$/ui',
  );
  $feeds_tamper->weight = 70;
  $feeds_tamper->description = 'SSF VK ersetzen';
  $export['player_team_mapping-ver-replace_ssf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sv_ruedersdorf';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'RUE',
    'replace' => 'SV Glück auf Rüdersdorf',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^RUE$/ui',
  );
  $feeds_tamper->weight = 33;
  $feeds_tamper->description = 'SV Rüdersdorf Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_sv_ruedersdorf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sv_wattenscheid';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'WAT',
    'replace' => 'SV Wattenscheid 1930',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^WAT$/ui',
  );
  $feeds_tamper->weight = 19;
  $feeds_tamper->description = 'SV Wattenscheid Vereinkürzel ersetzen';
  $export['player_team_mapping-ver-replace_sv_wattenscheid'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_sv_werder_2';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'WB2',
    'replace' => 'SV Werder Bremen II',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^WB2$/ui',
  );
  $feeds_tamper->weight = 35;
  $feeds_tamper->description = 'SV Werder Bremen 2 Vereinkürzel ersetzen';
  $export['player_team_mapping-ver-replace_sv_werder_2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_tegernsee';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'TGS',
    'replace' => 'TV Tegernsee',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^TGS$/ui',
  );
  $feeds_tamper->weight = 65;
  $feeds_tamper->description = 'Tegernsee VK ersetzen';
  $export['player_team_mapping-ver-replace_tegernsee'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_tsv_bindlach';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'BIN',
    'replace' => 'TSV Bindlach-Aktionär',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^BIN$/ui',
  );
  $feeds_tamper->weight = 40;
  $feeds_tamper->description = 'TSV Blindlach Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_tsv_bindlach'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_turm_kiel';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'KIE',
    'replace' => 'SG Turm Kiel',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^KIE$/ui',
  );
  $feeds_tamper->weight = 51;
  $feeds_tamper->description = 'Turm Kiel VK ersetzen';
  $export['player_team_mapping-ver-replace_turm_kiel'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_untergrombach';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'UGR',
    'replace' => 'SC Untergrombach 1946',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^UGR$/ui',
  );
  $feeds_tamper->weight = 63;
  $feeds_tamper->description = 'Untergrombach VK ersetzen';
  $export['player_team_mapping-ver-replace_untergrombach'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_wiesbadener_sv';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'WIE',
    'replace' => 'Wiesbadener SV',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^WIE$/ui',
  );
  $feeds_tamper->weight = 22;
  $feeds_tamper->description = 'Wiesbadener SV Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_wiesbadener_sv'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_wuerselen';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'WUE',
    'replace' => 'SV Würselen 1926',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^WUE$/ui',
  );
  $feeds_tamper->weight = 64;
  $feeds_tamper->description = 'Würselen VK ersetzen';
  $export['player_team_mapping-ver-replace_wuerselen'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'player_team_mapping-ver-replace_zugwang_muenchen';
  $feeds_tamper->importer = 'player_team_mapping';
  $feeds_tamper->source = 'VER';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'ZUG',
    'replace' => 'MSA Zugzwang 82',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^ZUG$/ui',
  );
  $feeds_tamper->weight = 37;
  $feeds_tamper->description = 'Zugwang München Vereinskürzel ersetzen';
  $export['player_team_mapping-ver-replace_zugwang_muenchen'] = $feeds_tamper;

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
    'replace' => 'SV Werder Bremen',
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
