<?php
/**
 * @file
 * sbl_ligaverwaltung.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sbl_ligaverwaltung_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_players|node|match|form';
  $field_group->group_name = 'group_players';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'match';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Spieler',
    'weight' => '7',
    'children' => array(
      0 => 'field_mt_spieler_1',
      1 => 'field_spieler_2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-players field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_players|node|match|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_away|node|team_match|form';
  $field_group->group_name = 'group_team_away';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team_match';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Gastmannschaft',
    'weight' => '12',
    'children' => array(
      0 => 'field_tm_board_points_team_2',
      1 => 'field_tm_team_2',
      2 => 'field_tm_team_points_tm_2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-team-away field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_team_away|node|team_match|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_home|node|team_match|form';
  $field_group->group_name = 'group_team_home';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team_match';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Heimmannschaft',
    'weight' => '11',
    'children' => array(
      0 => 'field_tm_board_points_team_1',
      1 => 'field_tm_team_1',
      2 => 'field_tm_team_points_tm_1',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-team-home field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_team_home|node|team_match|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teams|node|match|form';
  $field_group->group_name = 'group_teams';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'match';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mannschaften',
    'weight' => '2',
    'children' => array(
      0 => 'field_mt_mannschaft_1',
      1 => 'field_mt_mannschaft_2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Mannschaften',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-teams field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_teams|node|match|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gastmannschaft');
  t('Heimmannschaft');
  t('Mannschaften');
  t('Spieler');

  return $field_groups;
}
