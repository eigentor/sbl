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
        'spielplan-liga-2/*' => 'spielplan-liga-2/*',
        'tabelle/*' => 'tabelle/*',
        'tabelle-liga-2/*' => 'tabelle-liga-2/*',
        'kreuztabelle/*' => 'kreuztabelle/*',
        'kreuztabelle-liga-2/*' => 'kreuztabelle-liga-2/*',
        'spieler-rangliste/*' => 'spieler-rangliste/*',
        'hall-fame' => 'hall-fame',
        'setzliste/*' => 'setzliste/*',
        'setzliste-liga-2/*' => 'setzliste-liga-2/*',
        'vereine-der-2-bundesliga-nord' => 'vereine-der-2-bundesliga-nord',
        'vereine-der-2-bundesliga-west' => 'vereine-der-2-bundesliga-west',
        'vereine-der-2-bundesliga-sued' => 'vereine-der-2-bundesliga-sued',
        'vereine-der-2-bundesliga-ost' => 'vereine-der-2-bundesliga-ost',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-26' => array(
          'module' => 'block',
          'delta' => '26',
          'region' => 'above_content',
          'weight' => '-10',
        ),
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
