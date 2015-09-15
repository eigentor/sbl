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
        'verein/*' => 'verein/*',
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
