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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field collection item: Saison (field_saison) */
  $handler->display->display_options['arguments']['field_saison_tid']['id'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['table'] = 'field_data_field_saison';
  $handler->display->display_options['arguments']['field_saison_tid']['field'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_options']['code'] = 'return set_current_season();';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_saison_tid']['summary_options']['items_per_page'] = '25';

  /* Display: Content pane Spieler Liste pro Verein */
  $handler = $view->new_display('panel_pane', 'Content pane Spieler Liste pro Verein', 'panel_pane_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Brett-Nr. */
  $handler->display->display_options['fields']['field_pl_board_nr']['id'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['table'] = 'field_data_field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['field'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Verein (field_fc_verein) */
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['id'] = 'field_fc_verein_target_id';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['field'] = 'field_fc_verein_target_id';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field collection item: Saison (field_saison) */
  $handler->display->display_options['arguments']['field_saison_tid']['id'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['table'] = 'field_data_field_saison';
  $handler->display->display_options['arguments']['field_saison_tid']['field'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_saison_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'field_fc_verein_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Field collection item: Verein (field_fc_verein)',
    ),
    'field_saison_tid' => array(
      'type' => 'panel',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Field collection item: Saison (field_saison)',
    ),
  );

  /* Display: Content pane Spielerkarte Daten 1 */
  $handler = $view->new_display('panel_pane', 'Content pane Spielerkarte Daten 1', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Meistertitel */
  $handler->display->display_options['fields']['field_pl_master_title']['id'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['table'] = 'field_data_field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['field'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['label'] = 'Titel';
  $handler->display->display_options['fields']['field_pl_master_title']['hide_empty'] = TRUE;
  /* Field: Field collection item: ELO */
  $handler->display->display_options['fields']['field_pl_elo']['id'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['table'] = 'field_data_field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['field'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Nation */
  $handler->display->display_options['fields']['field_pl_country']['id'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['table'] = 'field_data_field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['field'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['label'] = 'Föderation';
  $handler->display->display_options['fields']['field_pl_country']['type'] = 'country_icon';
  $handler->display->display_options['fields']['field_pl_country']['settings'] = array(
    'countryiconset' => 'icon_shiny',
    'property' => 'name',
  );
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
    t('Name'),
    t('Alle'),
    t('Content pane Spieler Liste pro Verein'),
    t('Brett-Nr.'),
    t('View panes'),
    t('Content pane Spielerkarte Daten 1'),
    t('Titel'),
    t('ELO'),
    t('Föderation'),
  );
  $export['players'] = $view;

  $view = new view();
  $view->name = 'team_info';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Verein Basisdaten';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Logo Club */
  $handler->display->display_options['fields']['field_logo_team']['id'] = 'field_logo_team';
  $handler->display->display_options['fields']['field_logo_team']['table'] = 'field_data_field_logo_team';
  $handler->display->display_options['fields']['field_logo_team']['field'] = 'field_logo_team';
  $handler->display->display_options['fields']['field_logo_team']['label'] = '';
  $handler->display->display_options['fields']['field_logo_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_team']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_team']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: In der Liga seit */
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['id'] = 'field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['table'] = 'field_data_field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['field'] = 'field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['hide_empty'] = TRUE;
  /* Field: Content: Größte Erfolge */
  $handler->display->display_options['fields']['field_groesste_erfolge']['id'] = 'field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['table'] = 'field_data_field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['field'] = 'field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Content pane Verein Basisdaten 1 */
  $handler = $view->new_display('panel_pane', 'Content pane Verein Basisdaten 1', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Inhalt: Beitrags-ID',
    ),
  );

  /* Display: Content pane Verein Basisdaten 2 */
  $handler = $view->new_display('panel_pane', 'Content pane Verein Basisdaten 2', 'panel_pane_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Spielort */
  $handler->display->display_options['fields']['field_venue_club']['id'] = 'field_venue_club';
  $handler->display->display_options['fields']['field_venue_club']['table'] = 'field_data_field_venue_club';
  $handler->display->display_options['fields']['field_venue_club']['field'] = 'field_venue_club';
  $handler->display->display_options['fields']['field_venue_club']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_venue_club']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_venue_club']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Reisepartner */
  $handler->display->display_options['fields']['field_travel_partner_club']['id'] = 'field_travel_partner_club';
  $handler->display->display_options['fields']['field_travel_partner_club']['table'] = 'field_data_field_travel_partner_club';
  $handler->display->display_options['fields']['field_travel_partner_club']['field'] = 'field_travel_partner_club';
  $handler->display->display_options['fields']['field_travel_partner_club']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_travel_partner_club']['click_sort_column'] = 'url';
  /* Field: Content: Heimspiele */
  $handler->display->display_options['fields']['field_heimspiele']['id'] = 'field_heimspiele';
  $handler->display->display_options['fields']['field_heimspiele']['table'] = 'field_data_field_heimspiele';
  $handler->display->display_options['fields']['field_heimspiele']['field'] = 'field_heimspiele';
  $handler->display->display_options['fields']['field_heimspiele']['hide_empty'] = TRUE;
  /* Field: Content: Vorsitzender */
  $handler->display->display_options['fields']['field_chairman_club']['id'] = 'field_chairman_club';
  $handler->display->display_options['fields']['field_chairman_club']['table'] = 'field_data_field_chairman_club';
  $handler->display->display_options['fields']['field_chairman_club']['field'] = 'field_chairman_club';
  $handler->display->display_options['fields']['field_chairman_club']['hide_empty'] = TRUE;
  /* Field: Content: Mannschaftsführer */
  $handler->display->display_options['fields']['field_captain_team']['id'] = 'field_captain_team';
  $handler->display->display_options['fields']['field_captain_team']['table'] = 'field_data_field_captain_team';
  $handler->display->display_options['fields']['field_captain_team']['field'] = 'field_captain_team';
  $handler->display->display_options['fields']['field_captain_team']['hide_empty'] = TRUE;
  /* Field: Content: Internet-Verantwortlicher */
  $handler->display->display_options['fields']['field_web_admin_club']['id'] = 'field_web_admin_club';
  $handler->display->display_options['fields']['field_web_admin_club']['table'] = 'field_data_field_web_admin_club';
  $handler->display->display_options['fields']['field_web_admin_club']['field'] = 'field_web_admin_club';
  $handler->display->display_options['fields']['field_web_admin_club']['hide_empty'] = TRUE;
  /* Field: Content: Twitter */
  $handler->display->display_options['fields']['field_twitter_club']['id'] = 'field_twitter_club';
  $handler->display->display_options['fields']['field_twitter_club']['table'] = 'field_data_field_twitter_club';
  $handler->display->display_options['fields']['field_twitter_club']['field'] = 'field_twitter_club';
  $handler->display->display_options['fields']['field_twitter_club']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_club']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_club']['click_sort_column'] = 'url';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website_club']['id'] = 'field_website_club';
  $handler->display->display_options['fields']['field_website_club']['table'] = 'field_data_field_website_club';
  $handler->display->display_options['fields']['field_website_club']['field'] = 'field_website_club';
  $handler->display->display_options['fields']['field_website_club']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_club']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_website_club']['click_sort_column'] = 'url';
  /* Field: Content: Facebook */
  $handler->display->display_options['fields']['field_facebook']['id'] = 'field_facebook';
  $handler->display->display_options['fields']['field_facebook']['table'] = 'field_data_field_facebook';
  $handler->display->display_options['fields']['field_facebook']['field'] = 'field_facebook';
  $handler->display->display_options['fields']['field_facebook']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_facebook']['click_sort_column'] = 'url';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="website">[field_website_club]</div>
<div class="facebook">[field_facebook]</div>
<div class="twitter">[field_twitter_club]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Inhalt: Beitrags-ID',
    ),
  );
  $translatables['team_info'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('In der Liga seit'),
    t('Größte Erfolge'),
    t('Alle'),
    t('Content pane Verein Basisdaten 1'),
    t('View panes'),
    t('Content pane Verein Basisdaten 2'),
    t('Spielort'),
    t('Reisepartner'),
    t('Heimspiele'),
    t('Vorsitzender'),
    t('Mannschaftsführer'),
    t('Internet-Verantwortlicher'),
    t('Twitter'),
    t('Website'),
    t('Facebook'),
    t('<div class="website">[field_website_club]</div>
<div class="facebook">[field_facebook]</div>
<div class="twitter">[field_twitter_club]</div>'),
  );
  $export['team_info'] = $view;

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
