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
  $view->name = 'filter_player_by_team';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Filter Spieler nach Mannschaft';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Saisondaten Spieler (field_sp_verein) */
  $handler->display->display_options['relationships']['field_sp_verein_value']['id'] = 'field_sp_verein_value';
  $handler->display->display_options['relationships']['field_sp_verein_value']['table'] = 'field_data_field_sp_verein';
  $handler->display->display_options['relationships']['field_sp_verein_value']['field'] = 'field_sp_verein_value';
  $handler->display->display_options['relationships']['field_sp_verein_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Field collection item: ELO (field_pl_elo) */
  $handler->display->display_options['sorts']['field_pl_elo_value']['id'] = 'field_pl_elo_value';
  $handler->display->display_options['sorts']['field_pl_elo_value']['table'] = 'field_data_field_pl_elo';
  $handler->display->display_options['sorts']['field_pl_elo_value']['field'] = 'field_pl_elo_value';
  $handler->display->display_options['sorts']['field_pl_elo_value']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['sorts']['field_pl_elo_value']['order'] = 'DESC';
  /* Contextual filter: Field collection item: Saison (field_saison) */
  $handler->display->display_options['arguments']['field_saison_tid']['id'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['table'] = 'field_data_field_saison';
  $handler->display->display_options['arguments']['field_saison_tid']['field'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['arguments']['field_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_saison_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field collection item: Verein (field_fc_verein) */
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['id'] = 'field_fc_verein_target_id';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['field'] = 'field_fc_verein_target_id';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary_options']['items_per_page'] = '25';
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
    'spieler' => 'spieler',
  );

  /* Display: Filter Spieler 1 */
  $handler = $view->new_display('entityreference', 'Filter Spieler 1', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'nid' => 'nid',
    'title' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Filter Spieler 2 */
  $handler = $view->new_display('entityreference', 'Filter Spieler 2', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'nid' => 'nid',
    'title' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['filter_player_by_team'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('field collection item from field_sp_verein'),
    t('Alle'),
    t('Filter Spieler 1'),
    t('Filter Spieler 2'),
  );
  $export['filter_player_by_team'] = $view;

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
