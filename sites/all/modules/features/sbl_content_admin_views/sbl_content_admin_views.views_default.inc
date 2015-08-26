<?php
/**
 * @file
 * sbl_content_admin_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sbl_content_admin_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'players_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Übersicht Spieler';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Spieler pro Mannschaft und Saison';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'field_pl_board_nr' => 'field_pl_board_nr',
    'title' => 'title',
    'field_fc_verein' => 'field_fc_verein',
    'field_saison' => 'field_saison',
    'field_year_id' => 'field_year_id',
    'field_pl_country' => 'field_pl_country',
    'field_pl_elo' => 'field_pl_elo',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
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
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fc_verein' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_saison' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_year_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pl_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pl_elo' => array(
      'sortable' => 1,
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
  $handler->display->display_options['arguments']['field_saison_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_saison_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field collection item: Verein (field_fc_verein) */
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['id'] = 'field_fc_verein_target_id';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['field'] = 'field_fc_verein_target_id';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_fc_verein_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'spieler' => 'spieler',
  );

  /* Display: Page (with Page Title) */
  $handler = $view->new_display('page_with_page_title', 'Page (with Page Title)', 'page_with_page_title_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Anzahl der Ergebnisse';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
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
  /* Field: Field collection item: Verein */
  $handler->display->display_options['fields']['field_fc_verein']['id'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Saison */
  $handler->display->display_options['fields']['field_saison']['id'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Jahres-ID */
  $handler->display->display_options['fields']['field_year_id']['id'] = 'field_year_id';
  $handler->display->display_options['fields']['field_year_id']['table'] = 'field_data_field_year_id';
  $handler->display->display_options['fields']['field_year_id']['field'] = 'field_year_id';
  /* Field: Field collection item: Nation */
  $handler->display->display_options['fields']['field_pl_country']['id'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['table'] = 'field_data_field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['field'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['type'] = 'country_official';
  /* Field: Field collection item: ELO */
  $handler->display->display_options['fields']['field_pl_elo']['id'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['table'] = 'field_data_field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['field'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'spieler' => 'spieler',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Field collection item: Verein (field_fc_verein) */
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['id'] = 'field_fc_verein_target_id_1';
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['field'] = 'field_fc_verein_target_id';
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['group'] = 1;
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['expose']['operator_id'] = 'field_fc_verein_target_id_1_op';
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['expose']['label'] = 'Verein';
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['expose']['operator'] = 'field_fc_verein_target_id_1_op';
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['expose']['identifier'] = 'field_fc_verein_target_id_1';
  $handler->display->display_options['filters']['field_fc_verein_target_id_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Field collection item: Saison (field_saison) */
  $handler->display->display_options['filters']['field_saison_tid']['id'] = 'field_saison_tid';
  $handler->display->display_options['filters']['field_saison_tid']['table'] = 'field_data_field_saison';
  $handler->display->display_options['filters']['field_saison_tid']['field'] = 'field_saison_tid';
  $handler->display->display_options['filters']['field_saison_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_saison_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_saison_tid']['expose']['operator_id'] = 'field_saison_tid_op';
  $handler->display->display_options['filters']['field_saison_tid']['expose']['label'] = 'Saison';
  $handler->display->display_options['filters']['field_saison_tid']['expose']['operator'] = 'field_saison_tid_op';
  $handler->display->display_options['filters']['field_saison_tid']['expose']['identifier'] = 'field_saison_tid';
  $handler->display->display_options['filters']['field_saison_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_saison_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_saison_tid']['vocabulary'] = 'saison';
  /* Filter criterion: Field collection item: Nation (field_pl_country) */
  $handler->display->display_options['filters']['field_pl_country_iso2']['id'] = 'field_pl_country_iso2';
  $handler->display->display_options['filters']['field_pl_country_iso2']['table'] = 'field_data_field_pl_country';
  $handler->display->display_options['filters']['field_pl_country_iso2']['field'] = 'field_pl_country_iso2';
  $handler->display->display_options['filters']['field_pl_country_iso2']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_pl_country_iso2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pl_country_iso2']['expose']['operator_id'] = 'field_pl_country_iso2_op';
  $handler->display->display_options['filters']['field_pl_country_iso2']['expose']['label'] = 'Nation';
  $handler->display->display_options['filters']['field_pl_country_iso2']['expose']['operator'] = 'field_pl_country_iso2_op';
  $handler->display->display_options['filters']['field_pl_country_iso2']['expose']['identifier'] = 'field_pl_country_iso2';
  $handler->display->display_options['filters']['field_pl_country_iso2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['path'] = 'admin/players';
  $translatables['players_overview'] = array(
    t('Master'),
    t('Spieler pro Mannschaft und Saison'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Node, der Field Collection field_sp_verein enthält'),
    t('Brett'),
    t('Name'),
    t('Alle'),
    t('Page (with Page Title)'),
    t('Anzahl der Ergebnisse'),
    t('Verein'),
    t('Saison'),
    t('Jahres-ID'),
    t('Nation'),
    t('ELO'),
  );
  $export['players_overview'] = $view;

  return $export;
}
