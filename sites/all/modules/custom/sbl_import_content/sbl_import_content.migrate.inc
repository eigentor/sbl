<?php

/**
 * @file
 * Declares our migrations.
 */


/**
 * Implements hook_migrate_api().
 */
function sbl_import_content_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'league_management' => array(
        'title' => t('Liga-Verwaltung Migrations'),
        'default_format' => 'plain_text',
      ),
    ),
    'migrations' => array(
      'import_players' => array(
        'class_name' => 'ImportPlayerMigration',
        'group_name' => 'league_management',
      ),
    ),
  );
  return $api;
}