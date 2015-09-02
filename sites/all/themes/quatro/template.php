<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
 


function quatro_preprocess_html(&$vars) { 
  $file = theme_get_setting('theme_color') . '-style.css';
  drupal_add_css(path_to_theme() . '/css/'. $file, array('group' => CSS_THEME, 'weight' => 115,'browsers' => array(), 'preprocess' => FALSE));
  drupal_add_js(path_to_theme() . '/js/jquery.tooltipster.js');
  drupal_add_library('system', 'ui.accordion');
  drupal_add_library('system', 'ui.tabs');
}
 
function quatro_alpha_page_structure_alter(&$vars) {
  if (!empty($vars['#excluded']['content_bottom_first'])) {
    $vars['#excluded']['content_bottom_first']['#weight'] = 10;
    $vars['content']['content']['content']['content_bottom_first'] = $vars['#excluded']['content_bottom_first'];
  }

  if (!empty($vars['#excluded']['content_bottom_second'])) {
    $vars['#excluded']['content_bottom_second']['#weight'] = 11;
    $vars['content']['content']['content']['content_bottom_second'] = $vars['#excluded']['content_bottom_second'];
  }

}


function quatro_preprocess_page(&$vars) {

  // Set the page title for the "Verein" Panels Page
  if (arg(0) == 'verein' && is_numeric(arg(1))) {
    //dpm($vars);
    $nid = arg(1);

    // Search for the ticket matching the Rabattcode
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'mannschaft')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyCondition('nid', $nid, '=')
      // Bypass node access
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');


    $result = $query->execute();

    // If a ticket was found, set the price field to the ticket price
    if (isset($result['node'])) {
      $node_ids = array_keys($result['node']);
      $node_id = $node_ids[0];
      $node = node_load($node_id);
      drupal_set_title($node->title);
    }
  }
  // Set the page title for the "Spieler" Panels Page
  if (arg(0) == 'spieler' && is_numeric(arg(1))) {
    //dpm($vars);
    $nid = arg(1);

    // Search for the ticket matching the Rabattcode
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'spieler')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyCondition('nid', $nid, '=')
      // Bypass node access
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');


    $result = $query->execute();

    // If a ticket was found, set the price field to the ticket price
    if (isset($result['node'])) {
      $node_ids = array_keys($result['node']);
      $node_id = $node_ids[0];
      $node = node_load($node_id);
      drupal_set_title($node->title);
    }
  }
}
