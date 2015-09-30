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
  $view->name = 'player_data_static';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Spielerdaten statisch';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Bild */
  $handler->display->display_options['fields']['field_pl_image']['id'] = 'field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['table'] = 'field_data_field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['field'] = 'field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['label'] = '';
  $handler->display->display_options['fields']['field_pl_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pl_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pl_image']['settings'] = array(
    'image_style' => 'spielerbild',
    'image_link' => '',
  );
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
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
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
    'spieler' => 'spieler',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
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
  $translatables['player_data_static'] = array(
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
    t('Alle'),
    t('Content pane'),
    t('View panes'),
  );
  $export['player_data_static'] = $view;

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
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
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
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
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
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_options']['code'] = 'return get_current_season();';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_saison_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_sp_verein' => 'field_sp_verein',
  );

  /* Display: Content pane Kader pro Verein */
  $handler = $view->new_display('panel_pane', 'Content pane Kader pro Verein', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2 class="view-title">Kader [field_saison_1]</h2>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Saison Term-ID */
  $handler->display->display_options['fields']['field_saison']['id'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['ui_name'] = 'Saison Term-ID';
  $handler->display->display_options['fields']['field_saison']['label'] = '';
  $handler->display->display_options['fields']['field_saison']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_saison']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_saison']['alter']['text'] = '[field_saison-tid]';
  $handler->display->display_options['fields']['field_saison']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_saison']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Saison Jahreszahl (Term-Name) */
  $handler->display->display_options['fields']['field_saison_1']['id'] = 'field_saison_1';
  $handler->display->display_options['fields']['field_saison_1']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison_1']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison_1']['ui_name'] = 'Saison Jahreszahl (Term-Name)';
  $handler->display->display_options['fields']['field_saison_1']['label'] = '';
  $handler->display->display_options['fields']['field_saison_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_saison_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_saison_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Brett-Nr. */
  $handler->display->display_options['fields']['field_pl_board_nr']['id'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['table'] = 'field_data_field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['field'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['label'] = 'Brett';
  $handler->display->display_options['fields']['field_pl_board_nr']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Bild */
  $handler->display->display_options['fields']['field_pl_image']['id'] = 'field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['table'] = 'field_data_field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['field'] = 'field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['field_pl_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_pl_image']['alter']['path'] = 'spieler/[nid]/[field_saison]';
  $handler->display->display_options['fields']['field_pl_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pl_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pl_image']['settings'] = array(
    'image_style' => 'spielerbild_klein',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'spieler/[nid]/[field_saison]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field collection item: Nation */
  $handler->display->display_options['fields']['field_pl_country']['id'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['table'] = 'field_data_field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['field'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['label'] = 'Nat.';
  $handler->display->display_options['fields']['field_pl_country']['type'] = 'country_icon';
  $handler->display->display_options['fields']['field_pl_country']['settings'] = array(
    'countryiconset' => 'icon_shiny',
    'property' => '',
  );
  /* Field: Field collection item: ELO */
  $handler->display->display_options['fields']['field_pl_elo']['id'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['table'] = 'field_data_field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['field'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Meistertitel */
  $handler->display->display_options['fields']['field_pl_master_title']['id'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['table'] = 'field_data_field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['field'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['label'] = 'Titel';
  $handler->display->display_options['fields']['field_pl_master_title']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_pl_master_title' => 'field_pl_master_title',
    'field_pl_elo' => 'field_pl_elo',
    'field_pl_country' => 'field_pl_country',
    'field_saison' => 'field_saison',
    'field_webseite' => 'field_webseite',
  );
  $handler->display->display_options['row_options']['separator'] = '&nbsp;&nbsp;';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'margin10';
  /* Field: Field collection item: Meistertitel */
  $handler->display->display_options['fields']['field_pl_master_title']['id'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['table'] = 'field_data_field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['field'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['label'] = 'Titel';
  $handler->display->display_options['fields']['field_pl_master_title']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pl_master_title']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_pl_master_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pl_master_title']['element_wrapper_class'] = 'margin5';
  $handler->display->display_options['fields']['field_pl_master_title']['hide_empty'] = TRUE;
  /* Field: Field collection item: ELO */
  $handler->display->display_options['fields']['field_pl_elo']['id'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['table'] = 'field_data_field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['field'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pl_elo']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_pl_elo']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pl_elo']['element_wrapper_class'] = 'margin5';
  $handler->display->display_options['fields']['field_pl_elo']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Nation */
  $handler->display->display_options['fields']['field_pl_country']['id'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['table'] = 'field_data_field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['field'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['label'] = 'Föderation';
  $handler->display->display_options['fields']['field_pl_country']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pl_country']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_pl_country']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pl_country']['element_wrapper_class'] = 'margin5';
  $handler->display->display_options['fields']['field_pl_country']['type'] = 'country_icon';
  $handler->display->display_options['fields']['field_pl_country']['settings'] = array(
    'countryiconset' => 'icon_shiny',
    'property' => 'name',
  );
  /* Field: Field collection item: Saison */
  $handler->display->display_options['fields']['field_saison']['id'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_saison']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_saison']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_saison']['element_wrapper_class'] = 'margin5';
  $handler->display->display_options['fields']['field_saison']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Webseite */
  $handler->display->display_options['fields']['field_webseite']['id'] = 'field_webseite';
  $handler->display->display_options['fields']['field_webseite']['table'] = 'field_data_field_webseite';
  $handler->display->display_options['fields']['field_webseite']['field'] = 'field_webseite';
  $handler->display->display_options['fields']['field_webseite']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['field_webseite']['label'] = 'Im Web';
  $handler->display->display_options['fields']['field_webseite']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_webseite']['alter']['text'] = '<a href="[field_webseite-url]" class="tooltip blue" title="Webseite" rel="nofollow"><i class="fa fa-globe fa-2x"></i></a>';
  $handler->display->display_options['fields']['field_webseite']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_webseite']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_webseite']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_webseite']['element_wrapper_class'] = 'margin5';
  $handler->display->display_options['fields']['field_webseite']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_webseite']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_webseite']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_webseite']['click_sort_column'] = 'url';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field collection item: Saison (field_saison) */
  $handler->display->display_options['arguments']['field_saison_tid']['id'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['table'] = 'field_data_field_saison';
  $handler->display->display_options['arguments']['field_saison_tid']['field'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_saison_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Inhalt: Beitrags-ID',
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

  /* Display: Content pane Spieler Saisonergebnisse Durchschnitt */
  $handler = $view->new_display('panel_pane', 'Content pane Spieler Saisonergebnisse Durchschnitt', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Saison als TID */
  $handler->display->display_options['fields']['field_saison']['id'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['ui_name'] = 'Saison als TID';
  $handler->display->display_options['fields']['field_saison']['label'] = '';
  $handler->display->display_options['fields']['field_saison']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_saison']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_saison']['alter']['text'] = '[field_saison-tid]';
  $handler->display->display_options['fields']['field_saison']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Verein */
  $handler->display->display_options['fields']['field_fc_verein']['id'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_fc_verein']['alter']['path'] = 'verein/[field_fc_verein-target_id]/[field_saison]';
  $handler->display->display_options['fields']['field_fc_verein']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field collection item: Saison (field_saison) */
  $handler->display->display_options['arguments']['field_saison_tid']['id'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['table'] = 'field_data_field_saison';
  $handler->display->display_options['arguments']['field_saison_tid']['field'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_saison_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Inhalt: Beitrags-ID',
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
    t('Content pane Kader pro Verein'),
    t('<h2 class="view-title">Kader [field_saison_1]</h2>'),
    t('[field_saison-tid]'),
    t('Brett'),
    t('Bild'),
    t('Nat.'),
    t('ELO'),
    t('Titel'),
    t('View panes'),
    t('Content pane Spielerkarte Daten 1'),
    t('Föderation'),
    t('Saison'),
    t('Im Web'),
    t('<a href="[field_webseite-url]" class="tooltip blue" title="Webseite" rel="nofollow"><i class="fa fa-globe fa-2x"></i></a>'),
    t('Content pane Spieler Saisonergebnisse Durchschnitt'),
    t('Verein'),
  );
  $export['players'] = $view;

  $view = new view();
  $view->name = 'single_games_player';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Einzelspiele pro Spieler';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Auswärtsspiele';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_mt_player_1' => 'field_mt_player_1',
    'field_mt_player_2' => 'field_mt_player_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_mt_player_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mt_player_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2 class="view-title">Ergebnisse und Gegner [field_tm_saison]</h2>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Relationship: Field collection item: Entity with the Einzelspiel (field_tm_game) */
  $handler->display->display_options['relationships']['field_tm_game_node']['id'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_tm_game_node']['field'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['label'] = 'Node that contains the field collection field_tm_game';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_mt_player_1_target_id']['id'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['relationships']['field_mt_player_1_target_id']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['relationships']['field_mt_player_1_target_id']['field'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['relationships']['field_mt_player_1_target_id']['label'] = 'Spieler 1 referenziert in field_mt_player_1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_mt_player_2_target_id']['id'] = 'field_mt_player_2_target_id';
  $handler->display->display_options['relationships']['field_mt_player_2_target_id']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['relationships']['field_mt_player_2_target_id']['field'] = 'field_mt_player_2_target_id';
  $handler->display->display_options['relationships']['field_mt_player_2_target_id']['label'] = 'Spieler 2 referenziert in field_mt_player_2';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_tm_spieltag']['id'] = 'field_tm_spieltag';
  $handler->display->display_options['fields']['field_tm_spieltag']['table'] = 'field_data_field_tm_spieltag';
  $handler->display->display_options['fields']['field_tm_spieltag']['field'] = 'field_tm_spieltag';
  $handler->display->display_options['fields']['field_tm_spieltag']['relationship'] = 'field_tm_game_node';
  /* Field: Content: Datum */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'short_no_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field collection item: Spieler 2 */
  $handler->display->display_options['fields']['field_mt_player_2']['id'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['field'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['label'] = 'Gegner: Name';
  $handler->display->display_options['fields']['field_mt_player_2']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Content: Spieltag (field_tm_spieltag_1) */
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['id'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['field'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['relationship'] = 'field_tm_game_node';
  /* Contextual filter: Content: Saison (field_tm_saison) */
  $handler->display->display_options['arguments']['field_tm_saison_tid']['id'] = 'field_tm_saison_tid';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['field'] = 'field_tm_saison_tid';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field collection item: Spieler 1 (field_mt_player_1) */
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['id'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['field'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_mt_player_1_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_tm_game' => 'field_tm_game',
  );

  /* Display: Content pane Einzelspiele Heim */
  $handler = $view->new_display('panel_pane', 'Content pane Einzelspiele Heim', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2 class="view-title">Ergebnisse und Gegner</h2>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field Collection Item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['ui_name'] = 'Field Collection Item ID';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Saison als TID */
  $handler->display->display_options['fields']['field_tm_saison_1']['id'] = 'field_tm_saison_1';
  $handler->display->display_options['fields']['field_tm_saison_1']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison_1']['field'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_saison_1']['ui_name'] = 'Saison als TID';
  $handler->display->display_options['fields']['field_tm_saison_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_saison_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison_1']['alter']['text'] = '[field_tm_saison_1-tid]';
  $handler->display->display_options['fields']['field_tm_saison_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_saison_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Spieler 1 als NID */
  $handler->display->display_options['fields']['field_mt_player_1_1']['id'] = 'field_mt_player_1_1';
  $handler->display->display_options['fields']['field_mt_player_1_1']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1_1']['field'] = 'field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1_1']['ui_name'] = 'Spieler 1 als NID';
  $handler->display->display_options['fields']['field_mt_player_1_1']['label'] = '';
  $handler->display->display_options['fields']['field_mt_player_1_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_1_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mt_player_1_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mt_player_1_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Spieler 2 als NID */
  $handler->display->display_options['fields']['field_mt_player_2_1']['id'] = 'field_mt_player_2_1';
  $handler->display->display_options['fields']['field_mt_player_2_1']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2_1']['field'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2_1']['ui_name'] = 'Spieler 2 als NID';
  $handler->display->display_options['fields']['field_mt_player_2_1']['label'] = '';
  $handler->display->display_options['fields']['field_mt_player_2_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_2_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mt_player_2_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mt_player_2_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Saison */
  $handler->display->display_options['fields']['field_tm_saison']['id'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['field'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_saison']['label'] = '';
  $handler->display->display_options['fields']['field_tm_saison']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_saison']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['relationship'] = 'field_tm_game_node';
  /* Field: Content: Datum */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'short_no_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Field collection item: Spieler 1 */
  $handler->display->display_options['fields']['field_mt_player_1']['id'] = 'field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['field'] = 'field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['label'] = '';
  $handler->display->display_options['fields']['field_mt_player_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mt_player_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Spieler 2 */
  $handler->display->display_options['fields']['field_mt_player_2']['id'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['field'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['label'] = 'Gegner';
  $handler->display->display_options['fields']['field_mt_player_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_2']['alter']['path'] = 'spieler/[field_mt_player_2_1]/[field_tm_saison_1]';
  $handler->display->display_options['fields']['field_mt_player_2']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Punkte Spieler 1 */
  $handler->display->display_options['fields']['field_mt_points_player_1']['id'] = 'field_mt_points_player_1';
  $handler->display->display_options['fields']['field_mt_points_player_1']['table'] = 'field_data_field_mt_points_player_1';
  $handler->display->display_options['fields']['field_mt_points_player_1']['field'] = 'field_mt_points_player_1';
  $handler->display->display_options['fields']['field_mt_points_player_1']['label'] = '';
  $handler->display->display_options['fields']['field_mt_points_player_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mt_points_player_1']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Punkte Spieler 2 */
  $handler->display->display_options['fields']['field_mt_points_player_2']['id'] = 'field_mt_points_player_2';
  $handler->display->display_options['fields']['field_mt_points_player_2']['table'] = 'field_data_field_mt_points_player_2';
  $handler->display->display_options['fields']['field_mt_points_player_2']['field'] = 'field_mt_points_player_2';
  $handler->display->display_options['fields']['field_mt_points_player_2']['label'] = '';
  $handler->display->display_options['fields']['field_mt_points_player_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mt_points_player_2']['element_label_colon'] = FALSE;
  /* Field: Ergebnis aus Spielerpunkten zusammengesetzt */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Ergebnis aus Spielerpunkten zusammengesetzt';
  $handler->display->display_options['fields']['nothing']['label'] = 'Ergebnis';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_tm_game' => 'field_tm_game',
  );
  /* Filter criterion: Arguments nach Spieler und Saison als Filter */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['ui_name'] = 'Arguments nach Spieler und Saison als Filter';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'return filter_single_games_player($row);';
  $handler->display->display_options['argument_input'] = array(
    'field_mt_player_1_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Field collection item: Spieler 1 (field_mt_player_1)',
    ),
    'field_tm_saison_tid' => array(
      'type' => 'panel',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '2',
      'fixed' => '',
      'label' => 'Inhalt: Saison (field_tm_saison)',
    ),
  );
  $translatables['single_games_player'] = array(
    t('Master'),
    t('Auswärtsspiele'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h2 class="view-title">Ergebnisse und Gegner [field_tm_saison]</h2>'),
    t('Node that contains the field collection field_tm_game'),
    t('Spieler 1 referenziert in field_mt_player_1'),
    t('Spieler 2 referenziert in field_mt_player_2'),
    t('Broken handler field_data_field_tm_spieltag.field_tm_spieltag'),
    t('Datum'),
    t('Gegner: Name'),
    t('Alle'),
    t('Content pane Einzelspiele Heim'),
    t('<h2 class="view-title">Ergebnisse und Gegner</h2>'),
    t('.'),
    t('[field_tm_saison_1-tid]'),
    t('Spieltag'),
    t('Gegner'),
    t('Ergebnis'),
    t('View panes'),
  );
  $export['single_games_player'] = $view;

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
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_facebook' => 'field_facebook',
    'field_twitter_club' => 'field_twitter_club',
    'field_website_club' => 'field_website_club',
    'field_der_bundesliga_seit' => 'field_der_bundesliga_seit',
  );
  $handler->display->display_options['row_options']['separator'] = '&nbsp;&nbsp;';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Logo Club */
  $handler->display->display_options['fields']['field_logo_team']['id'] = 'field_logo_team';
  $handler->display->display_options['fields']['field_logo_team']['table'] = 'field_data_field_logo_team';
  $handler->display->display_options['fields']['field_logo_team']['field'] = 'field_logo_team';
  $handler->display->display_options['fields']['field_logo_team']['label'] = '';
  $handler->display->display_options['fields']['field_logo_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_team']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_team']['settings'] = array(
    'image_style' => 'vereinslogo',
    'image_link' => '',
  );
  /* Field: Content: Facebook */
  $handler->display->display_options['fields']['field_facebook']['id'] = 'field_facebook';
  $handler->display->display_options['fields']['field_facebook']['table'] = 'field_data_field_facebook';
  $handler->display->display_options['fields']['field_facebook']['field'] = 'field_facebook';
  $handler->display->display_options['fields']['field_facebook']['label'] = '';
  $handler->display->display_options['fields']['field_facebook']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_facebook']['alter']['text'] = '<a href="[field_facebook-url]" class="tooltip blue" title="Facebook" rel="nofollow"><i class="fa fa-facebook-square fa-2x"></i></a>';
  $handler->display->display_options['fields']['field_facebook']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_facebook']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_facebook']['element_wrapper_class'] = 'one-fifth';
  $handler->display->display_options['fields']['field_facebook']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_facebook']['click_sort_column'] = 'url';
  /* Field: Content: Twitter */
  $handler->display->display_options['fields']['field_twitter_club']['id'] = 'field_twitter_club';
  $handler->display->display_options['fields']['field_twitter_club']['table'] = 'field_data_field_twitter_club';
  $handler->display->display_options['fields']['field_twitter_club']['field'] = 'field_twitter_club';
  $handler->display->display_options['fields']['field_twitter_club']['label'] = '';
  $handler->display->display_options['fields']['field_twitter_club']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_club']['alter']['text'] = '<a href="[field_twitter_club-url]" class="tooltip blue" title="Twitter" rel="nofollow"><i class="fa fa-twitter-square fa-2x"></i></a>';
  $handler->display->display_options['fields']['field_twitter_club']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_club']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_twitter_club']['element_wrapper_class'] = 'one-fifth';
  $handler->display->display_options['fields']['field_twitter_club']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_club']['click_sort_column'] = 'url';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website_club']['id'] = 'field_website_club';
  $handler->display->display_options['fields']['field_website_club']['table'] = 'field_data_field_website_club';
  $handler->display->display_options['fields']['field_website_club']['field'] = 'field_website_club';
  $handler->display->display_options['fields']['field_website_club']['label'] = '';
  $handler->display->display_options['fields']['field_website_club']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website_club']['alter']['text'] = '<a href="[field_website_club-url]" class="tooltip blue" title="Website" rel="nofollow"><i class="fa fa-globe fa-2x"></i></a>';
  $handler->display->display_options['fields']['field_website_club']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_club']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_website_club']['element_wrapper_class'] = 'one-fifth last';
  $handler->display->display_options['fields']['field_website_club']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_website_club']['click_sort_column'] = 'url';
  /* Field: Content: In der Liga seit */
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['id'] = 'field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['table'] = 'field_data_field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['field'] = 'field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['element_wrapper_class'] = 'margin10';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['hide_empty'] = TRUE;
  /* Field: Content: Größte Erfolge */
  $handler->display->display_options['fields']['field_groesste_erfolge']['id'] = 'field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['table'] = 'field_data_field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['field'] = 'field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_groesste_erfolge']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_groesste_erfolge']['hide_empty'] = TRUE;
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Spielort */
  $handler->display->display_options['fields']['field_venue_club']['id'] = 'field_venue_club';
  $handler->display->display_options['fields']['field_venue_club']['table'] = 'field_data_field_venue_club';
  $handler->display->display_options['fields']['field_venue_club']['field'] = 'field_venue_club';
  $handler->display->display_options['fields']['field_venue_club']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_venue_club']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_venue_club']['element_wrapper_class'] = 'one-third';
  $handler->display->display_options['fields']['field_venue_club']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_venue_club']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_venue_club']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Heimspiele */
  $handler->display->display_options['fields']['field_heimspiele']['id'] = 'field_heimspiele';
  $handler->display->display_options['fields']['field_heimspiele']['table'] = 'field_data_field_heimspiele';
  $handler->display->display_options['fields']['field_heimspiele']['field'] = 'field_heimspiele';
  $handler->display->display_options['fields']['field_heimspiele']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_heimspiele']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_heimspiele']['element_wrapper_class'] = 'two-third last';
  $handler->display->display_options['fields']['field_heimspiele']['hide_empty'] = TRUE;
  /* Field: Content: Vorsitzender */
  $handler->display->display_options['fields']['field_chairman_club']['id'] = 'field_chairman_club';
  $handler->display->display_options['fields']['field_chairman_club']['table'] = 'field_data_field_chairman_club';
  $handler->display->display_options['fields']['field_chairman_club']['field'] = 'field_chairman_club';
  $handler->display->display_options['fields']['field_chairman_club']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_chairman_club']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_chairman_club']['element_wrapper_class'] = 'one-third';
  $handler->display->display_options['fields']['field_chairman_club']['hide_empty'] = TRUE;
  /* Field: Content: Mannschaftsführer */
  $handler->display->display_options['fields']['field_captain_team']['id'] = 'field_captain_team';
  $handler->display->display_options['fields']['field_captain_team']['table'] = 'field_data_field_captain_team';
  $handler->display->display_options['fields']['field_captain_team']['field'] = 'field_captain_team';
  $handler->display->display_options['fields']['field_captain_team']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_captain_team']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_captain_team']['element_wrapper_class'] = 'one-third';
  $handler->display->display_options['fields']['field_captain_team']['hide_empty'] = TRUE;
  /* Field: Content: Internet-Verantwortlicher */
  $handler->display->display_options['fields']['field_web_admin_club']['id'] = 'field_web_admin_club';
  $handler->display->display_options['fields']['field_web_admin_club']['table'] = 'field_data_field_web_admin_club';
  $handler->display->display_options['fields']['field_web_admin_club']['field'] = 'field_web_admin_club';
  $handler->display->display_options['fields']['field_web_admin_club']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_web_admin_club']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_web_admin_club']['element_wrapper_class'] = 'one-third last';
  $handler->display->display_options['fields']['field_web_admin_club']['hide_empty'] = TRUE;
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

  /* Display: Block Vereinslogos klein */
  $handler = $view->new_display('block', 'Block Vereinslogos klein', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Logo Icon */
  $handler->display->display_options['fields']['field_logo_icon']['id'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['table'] = 'field_data_field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['field'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['label'] = '';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_logo_icon']['alter']['path'] = 'verein/[nid]/144';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['link_class'] = 'tooltip';
  $handler->display->display_options['fields']['field_logo_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_icon']['settings'] = array(
    'image_style' => 'vereinslogo_klein',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Saison (field_t_saison) */
  $handler->display->display_options['filters']['field_t_saison_tid']['id'] = 'field_t_saison_tid';
  $handler->display->display_options['filters']['field_t_saison_tid']['table'] = 'field_data_field_t_saison';
  $handler->display->display_options['filters']['field_t_saison_tid']['field'] = 'field_t_saison_tid';
  $handler->display->display_options['filters']['field_t_saison_tid']['value'] = array(
    144 => '144',
  );
  $handler->display->display_options['filters']['field_t_saison_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_t_saison_tid']['vocabulary'] = 'saison';
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
    t('<a href="[field_facebook-url]" class="tooltip blue" title="Facebook" rel="nofollow"><i class="fa fa-facebook-square fa-2x"></i></a>'),
    t('<a href="[field_twitter_club-url]" class="tooltip blue" title="Twitter" rel="nofollow"><i class="fa fa-twitter-square fa-2x"></i></a>'),
    t('<a href="[field_website_club-url]" class="tooltip blue" title="Website" rel="nofollow"><i class="fa fa-globe fa-2x"></i></a>'),
    t('View panes'),
    t('Content pane Verein Basisdaten 2'),
    t('Spielort'),
    t('Heimspiele'),
    t('Vorsitzender'),
    t('Mannschaftsführer'),
    t('Internet-Verantwortlicher'),
    t('Block Vereinslogos klein'),
    t('[title]'),
  );
  $export['team_info'] = $view;

  return $export;
}
