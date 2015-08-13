<?php
/**
 * @file
 * sbl_feeds_importer.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function sbl_feeds_importer_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Spieler Fide-ID';
  $rule->name = 'player_fide_id';
  $rule->field_name = 'field_fide_id';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'spieler';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'A Player with this Fide-ID already exists';
  $export['player_fide_id'] = $rule;

  return $export;
}
