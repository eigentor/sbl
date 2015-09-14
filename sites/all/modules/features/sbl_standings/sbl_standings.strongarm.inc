<?php
/**
 * @file
 * sbl_standings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sbl_standings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_sehr_kurz_mit_uhrzeit_und_trennstrich';
  $strongarm->value = 'd.m.y | H:i';
  $export['date_format_sehr_kurz_mit_uhrzeit_und_trennstrich'] = $strongarm;

  return $export;
}
