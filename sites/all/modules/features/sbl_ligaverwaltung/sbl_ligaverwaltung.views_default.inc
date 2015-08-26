<?php
/**
 * @file
 * sbl_ligaverwaltung.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sbl_ligaverwaltung_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mannchaftsmatches';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mannchaftsmatches';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mannchaftsmatches Übersicht für Admin';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = 'Heimmannschaft';
  $handler->display->display_options['fields']['field_tm_team_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_2']['id'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['field'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['label'] = 'Gastmannschaft';
  $handler->display->display_options['fields']['field_tm_team_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_2']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Mannschaftspunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['id'] = 'field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['table'] = 'field_data_field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['field'] = 'field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['label'] = 'Mannschaftspunkte Heimmannschaft';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['element_label_colon'] = FALSE;
  /* Field: Content: Mannschaftspunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['id'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['table'] = 'field_data_field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['field'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['label'] = 'Mannschaftspunkte Gastmannschaft';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_tm_points_team_1']['id'] = 'field_tm_points_team_1';
  $handler->display->display_options['fields']['field_tm_points_team_1']['table'] = 'field_data_field_tm_points_team_1';
  $handler->display->display_options['fields']['field_tm_points_team_1']['field'] = 'field_tm_points_team_1';
  $handler->display->display_options['fields']['field_tm_points_team_1']['label'] = 'Brettpunkte Heimmannschaft';
  $handler->display->display_options['fields']['field_tm_points_team_1']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_tm_points_team_2']['id'] = 'field_tm_points_team_2';
  $handler->display->display_options['fields']['field_tm_points_team_2']['table'] = 'field_data_field_tm_points_team_2';
  $handler->display->display_options['fields']['field_tm_points_team_2']['field'] = 'field_tm_points_team_2';
  $handler->display->display_options['fields']['field_tm_points_team_2']['label'] = 'Brettpunkte Gastmannschaft';
  $handler->display->display_options['fields']['field_tm_points_team_2']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team_match' => 'team_match',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/mannschafts-matches';
  $translatables['mannchaftsmatches'] = array(
    t('Master'),
    t('Mannchaftsmatches Übersicht für Admin'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('Heimmannschaft'),
    t('Gastmannschaft'),
    t('Mannschaftspunkte Heimmannschaft'),
    t('Mannschaftspunkte Gastmannschaft'),
    t('Brettpunkte Heimmannschaft'),
    t('Brettpunkte Gastmannschaft'),
    t('Page'),
  );
  $export['mannchaftsmatches'] = $view;

  $view = new view();
  $view->name = 'players';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Spieler';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Kader';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_pl_board_nr' => 'field_pl_board_nr',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pl_board_nr' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Field collection item: Entity with the Saisondaten Spieler (field_sp_verein) */
  $handler->display->display_options['relationships']['field_sp_verein_node']['id'] = 'field_sp_verein_node';
  $handler->display->display_options['relationships']['field_sp_verein_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_sp_verein_node']['field'] = 'field_sp_verein_node';
  $handler->display->display_options['relationships']['field_sp_verein_node']['label'] = 'Node, der Field Collection field_sp_verein enthält';
  /* Field: Field collection item: Brett-Nr. */
  $handler->display->display_options['fields']['field_pl_board_nr']['id'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['table'] = 'field_data_field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['field'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['label'] = 'Brett';
  $handler->display->display_options['fields']['field_pl_board_nr']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Field collection item: Brett-Nr. (field_pl_board_nr) */
  $handler->display->display_options['sorts']['field_pl_board_nr_value']['id'] = 'field_pl_board_nr_value';
  $handler->display->display_options['sorts']['field_pl_board_nr_value']['table'] = 'field_data_field_pl_board_nr';
  $handler->display->display_options['sorts']['field_pl_board_nr_value']['field'] = 'field_pl_board_nr_value';
  /* Contextual filter: Field collection item: Saison (field_saison) */
  $handler->display->display_options['arguments']['field_saison_tid']['id'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['table'] = 'field_data_field_saison';
  $handler->display->display_options['arguments']['field_saison_tid']['field'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_options']['argument'] = '144';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_saison_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field collection item: Verein (field_fc_verein) */
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['id'] = 'field_fc_verein_target_id';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['field'] = 'field_fc_verein_target_id';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Block Spieler pro Mannschaft und Saison */
  $handler = $view->new_display('block', 'Block Spieler pro Mannschaft und Saison', 'block');

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_saison_tid' => array(
      'type' => 'none',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Field collection item: Saison (field_saison)',
    ),
    'field_fc_verein_target_id' => array(
      'type' => 'none',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Field collection item: Verein (field_fc_verein)',
    ),
  );
  $translatables['players'] = array(
    t('Master'),
    t('Kader'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Node, der Field Collection field_sp_verein enthält'),
    t('Brett'),
    t('Name'),
    t('Alle'),
    t('Block Spieler pro Mannschaft und Saison'),
    t('Content pane'),
    t('View panes'),
  );
  $export['players'] = $view;

  $view = new view();
  $view->name = 'teams_leaderbord';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Rangliste Mannschaften';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Rangliste Mannschaften';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'php' => 'php',
    'php_1' => 'php_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Mannschaftspunkte';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Brettpunkte';
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Sortieren nach Mannschaftspunkten';
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['php_1']['id'] = 'php_1';
  $handler->display->display_options['sorts']['php_1']['table'] = 'views';
  $handler->display->display_options['sorts']['php_1']['field'] = 'php';
  $handler->display->display_options['sorts']['php_1']['ui_name'] = 'Sortieren nach Brettpunkten';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mannschaft' => 'mannschaft',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tabelle';
  $translatables['teams_leaderbord'] = array(
    t('Master'),
    t('Rangliste Mannschaften'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('Mannschaftspunkte'),
    t('Brettpunkte'),
    t('Page'),
  );
  $export['teams_leaderbord'] = $view;

  return $export;
}
