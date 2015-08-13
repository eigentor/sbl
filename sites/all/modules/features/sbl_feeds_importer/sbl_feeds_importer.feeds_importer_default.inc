<?php
/**
 * @file
 * sbl_feeds_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function sbl_feeds_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_players';
  $feeds_importer->config = array(
    'name' => 'Spieler importieren',
    'description' => 'Spielerdaten mit zugeordnetem Verein pro Saison importieren',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '46',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Kombinierter Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Akad. Titel',
            'target' => 'field_pl_acad_title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Nachname',
            'target' => 'field_pl_last_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Vorname',
            'target' => 'field_pl_first_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'ID_NUMBER',
            'target' => 'field_fide_id',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'spieler',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_players'] = $feeds_importer;

  return $export;
}
