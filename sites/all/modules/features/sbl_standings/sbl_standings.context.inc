<?php
/**
 * @file
 * sbl_standings.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sbl_standings_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'statistics_area';
  $context->description = 'Blöcke für den Statistikbereich';
  $context->tag = 'Liga-Management';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'spieler/*' => 'spieler/*',
        'ergebnisse/*' => 'ergebnisse/*',
        'spielplan/*' => 'spielplan/*',
        'tabelle/*' => 'tabelle/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-21' => array(
          'module' => 'block',
          'delta' => '21',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-20' => array(
          'module' => 'block',
          'delta' => '20',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-naechste_spiele-block_1' => array(
          'module' => 'views',
          'delta' => 'naechste_spiele-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blöcke für den Statistikbereich');
  t('Liga-Management');
  $export['statistics_area'] = $context;

  return $export;
}
