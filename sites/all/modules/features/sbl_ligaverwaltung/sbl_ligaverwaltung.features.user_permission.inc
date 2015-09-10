<?php
/**
 * @file
 * sbl_ligaverwaltung.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sbl_ligaverwaltung_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer rh_node'.
  $permissions['administer rh_node'] = array(
    'name' => 'administer rh_node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rabbit_hole',
  );

  // Exported permission: 'bypass rh_node'.
  $permissions['bypass rh_node'] = array(
    'name' => 'bypass rh_node',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'rabbit_hole',
  );

  // Exported permission: 'php redirect rh_node'.
  $permissions['php redirect rh_node'] = array(
    'name' => 'php redirect rh_node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rabbit_hole',
  );

  return $permissions;
}
