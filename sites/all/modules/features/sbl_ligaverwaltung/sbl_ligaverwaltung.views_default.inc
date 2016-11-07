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
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Feld: Inhalt: Bild */
  $handler->display->display_options['fields']['field_pl_image']['id'] = 'field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['table'] = 'field_data_field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['field'] = 'field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['label'] = '';
  $handler->display->display_options['fields']['field_pl_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pl_image']['empty'] = '<img src="/sites/default/files/styles/spielerbild/public/dummy_2.jpg" />';
  $handler->display->display_options['fields']['field_pl_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pl_image']['settings'] = array(
    'image_style' => 'spielerbild',
    'image_link' => '',
  );
  /* Sortierkriterien: Inhalt: Beitragsdatum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontextfilter: Inhalt: Beitrags-ID */
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
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
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
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('<img src="/sites/default/files/styles/spielerbild/public/dummy_2.jpg" />'),
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
  $view->human_name = 'Spielerdaten Spielerseite und Vereinsseite (Kader etc.)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Kader';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_saison' => 'field_saison',
    'field_saison_1' => 'field_saison_1',
    'field_pl_board_nr' => 'field_pl_board_nr',
    'field_pl_image' => 'field_pl_image',
    'title' => 'title',
    'field_pl_country' => 'field_pl_country',
    'field_pl_elo' => 'field_pl_elo',
    'field_pl_master_title' => 'field_pl_master_title',
    'php' => 'php',
    'php_1' => 'php_1',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'php_4' => 'php_4',
    'php_5' => 'php_5',
    'php_6' => 'php_6',
    'php_7' => 'php_7',
    'php_8' => 'php_8',
    'php_9' => 'php_9',
    'php_10' => 'php_10',
    'php_11' => 'php_11',
    'php_12' => 'php_12',
    'php_13' => 'php_13',
    'php_14' => 'php_14',
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
    'field_saison' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_saison_1' => array(
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
    'field_pl_image' => array(
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
    'field_pl_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pl_elo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pl_master_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_5' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_6' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_7' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_8' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_9' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_10' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_11' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_12' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_13' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_14' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'field_pl_board_nr',
    'icon' => '',
    'icon_size' => '',
    'hide' => array(
      'nid' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_saison' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_saison_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_board_nr' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_image' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_country' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_elo' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_master_title' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_1' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_2' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_3' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_4' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_5' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_6' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_7' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_8' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_9' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_10' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_11' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_12' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_13' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_14' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
    ),
  );
  /* Kopfbereich: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Beziehung: Field collection item: Entity with the Saisondaten Spieler (field_sp_verein) */
  $handler->display->display_options['relationships']['field_sp_verein_node']['id'] = 'field_sp_verein_node';
  $handler->display->display_options['relationships']['field_sp_verein_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_sp_verein_node']['field'] = 'field_sp_verein_node';
  $handler->display->display_options['relationships']['field_sp_verein_node']['label'] = 'Node, der Field Collection field_sp_verein enthält';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sortierkriterien: Field collection item: Brett-Nr. (field_pl_board_nr) */
  $handler->display->display_options['sorts']['field_pl_board_nr_value']['id'] = 'field_pl_board_nr_value';
  $handler->display->display_options['sorts']['field_pl_board_nr_value']['table'] = 'field_data_field_pl_board_nr';
  $handler->display->display_options['sorts']['field_pl_board_nr_value']['field'] = 'field_pl_board_nr_value';
  /* Kontextfilter: Inhalt: Beitrags-ID */
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
  /* Kontextfilter: Field collection item: Saison (field_saison) */
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
  /* Filterkriterium: Field collection item: Feldname */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_sp_verein' => 'field_sp_verein',
  );

  /* Display: Content pane Kader pro Verein */
  $handler = $view->new_display('panel_pane', 'Content pane Kader pro Verein', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_saison' => 'field_saison',
    'field_saison_1' => 'field_saison_1',
    'field_pl_board_nr' => 'field_pl_board_nr',
    'field_pl_image' => 'field_pl_image',
    'title' => 'title',
    'field_pl_country' => 'field_pl_country',
    'field_pl_elo' => 'field_pl_elo',
    'field_pl_master_title' => 'field_pl_master_title',
    'php' => 'php',
    'php_1' => 'php_1',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'php_4' => 'php_4',
    'php_5' => 'php_5',
    'php_6' => 'php_6',
    'php_7' => 'php_7',
    'php_8' => 'php_8',
    'php_9' => 'php_9',
    'php_10' => 'php_10',
    'php_11' => 'php_11',
    'php_12' => 'php_12',
    'php_13' => 'php_13',
    'php_14' => 'php_14',
    'php_15' => 'php_15',
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
    'field_saison' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_saison_1' => array(
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
    'field_pl_image' => array(
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
    'field_pl_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pl_elo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pl_master_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_5' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_6' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_7' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_8' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_9' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_10' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_11' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_12' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_13' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_14' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_15' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'field_pl_board_nr',
    'icon' => '',
    'icon_size' => '',
    'hide' => array(
      'nid' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_saison' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_saison_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_board_nr' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_image' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_country' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_elo' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_master_title' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_1' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_2' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_3' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_4' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_5' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_6' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_7' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_8' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_9' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_10' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_11' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_12' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_13' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_14' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_15' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2 class="view-title">Kader [field_saison_1]</h2>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Kopfbereich: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'ELO-Durchschnitt';
  $handler->display->display_options['header']['php']['php_output'] = '<?php
$sum_elo=0;
$sum_elo_first_eight=0;
$counter_all=0;
for($i=0;$i<8;$i++) {
$sum_elo_first_eight+=intval($results[$i]->field_field_pl_elo[0][\'raw\'][\'value\']);
}
for($i=0;$i<count($results);$i++) {
$sum_elo+=intval($results[$i]->field_field_pl_elo[0][\'raw\'][\'value\']);
if(intval($results[$i]->field_field_pl_elo[0][\'raw\'][\'value\']) > 0) $counter_all++;
}
echo "<strong>ELO-Durchschnitt (Brett 1-8):</strong> ".round($sum_elo_first_eight/8,0);
echo "<br /><strong>ELO-Durchschnitt (alle Bretter):</strong> ".round($sum_elo/$counter_all,0);
?>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Saison Term-ID */
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
  /* Feld: Saison Jahreszahl (Term-Name) */
  $handler->display->display_options['fields']['field_saison_1']['id'] = 'field_saison_1';
  $handler->display->display_options['fields']['field_saison_1']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison_1']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison_1']['ui_name'] = 'Saison Jahreszahl (Term-Name)';
  $handler->display->display_options['fields']['field_saison_1']['label'] = '';
  $handler->display->display_options['fields']['field_saison_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_saison_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_saison_1']['type'] = 'taxonomy_term_reference_plain';
  /* Feld: Field collection item: Brett-Nr. */
  $handler->display->display_options['fields']['field_pl_board_nr']['id'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['table'] = 'field_data_field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['field'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['label'] = 'B';
  $handler->display->display_options['fields']['field_pl_board_nr']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Feld: Inhalt: Bild */
  $handler->display->display_options['fields']['field_pl_image']['id'] = 'field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['table'] = 'field_data_field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['field'] = 'field_pl_image';
  $handler->display->display_options['fields']['field_pl_image']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['field_pl_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_pl_image']['alter']['path'] = 'spieler/[nid]/[field_saison]';
  $handler->display->display_options['fields']['field_pl_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pl_image']['empty'] = '<img src="/sites/default/files/styles/spielerbild_klein/public/dummy_2.jpg" />';
  $handler->display->display_options['fields']['field_pl_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pl_image']['settings'] = array(
    'image_style' => 'spielerbild_klein',
    'image_link' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'spieler/[nid]/[field_saison]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Field collection item: Nation */
  $handler->display->display_options['fields']['field_pl_country']['id'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['table'] = 'field_data_field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['field'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['label'] = 'Nat.';
  $handler->display->display_options['fields']['field_pl_country']['type'] = 'country_icon';
  $handler->display->display_options['fields']['field_pl_country']['settings'] = array(
    'countryiconset' => 'icon_shiny',
    'property' => '',
  );
  /* Feld: Field collection item: ELO */
  $handler->display->display_options['fields']['field_pl_elo']['id'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['table'] = 'field_data_field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['field'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Feld: Field collection item: Meistertitel */
  $handler->display->display_options['fields']['field_pl_master_title']['id'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['table'] = 'field_data_field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['field'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['label'] = 'Titel';
  $handler->display->display_options['fields']['field_pl_master_title']['element_label_colon'] = FALSE;
  /* Feld: Punkte Spieler 1. Spieltag */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Punkte Spieler 1. Spieltag';
  $handler->display->display_options['fields']['php']['label'] = '1';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print player_single_result_matchday($row, 1);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 2. Spieltag */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Punkte Spieler 2. Spieltag';
  $handler->display->display_options['fields']['php_1']['label'] = '2';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
print player_single_result_matchday($row, 2);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 3. Spieltag */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Punkte Spieler 3. Spieltag';
  $handler->display->display_options['fields']['php_2']['label'] = '3';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php 
print player_single_result_matchday($row, 3);
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 4. Spieltag */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Punkte Spieler 4. Spieltag';
  $handler->display->display_options['fields']['php_3']['label'] = '4';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php 
print player_single_result_matchday($row, 4);
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 5. Spieltag */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Punkte Spieler 5. Spieltag';
  $handler->display->display_options['fields']['php_4']['label'] = '5';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php 
print player_single_result_matchday($row, 5);
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 6. Spieltag */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'Punkte Spieler 6. Spieltag';
  $handler->display->display_options['fields']['php_5']['label'] = '6';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php 
print player_single_result_matchday($row, 6);
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 7. Spieltag */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['ui_name'] = 'Punkte Spieler 7. Spieltag';
  $handler->display->display_options['fields']['php_6']['label'] = '7';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php 
print player_single_result_matchday($row, 7);
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 8. Spieltag */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['ui_name'] = 'Punkte Spieler 8. Spieltag';
  $handler->display->display_options['fields']['php_7']['label'] = '8';
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php 
print player_single_result_matchday($row, 8);
?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 9. Spieltag */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['ui_name'] = 'Punkte Spieler 9. Spieltag';
  $handler->display->display_options['fields']['php_8']['label'] = '9';
  $handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_8']['php_output'] = '<?php 
print player_single_result_matchday($row, 9);
?>';
  $handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 10. Spieltag */
  $handler->display->display_options['fields']['php_9']['id'] = 'php_9';
  $handler->display->display_options['fields']['php_9']['table'] = 'views';
  $handler->display->display_options['fields']['php_9']['field'] = 'php';
  $handler->display->display_options['fields']['php_9']['ui_name'] = 'Punkte Spieler 10. Spieltag';
  $handler->display->display_options['fields']['php_9']['label'] = '10';
  $handler->display->display_options['fields']['php_9']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_9']['php_output'] = '<?php 
print player_single_result_matchday($row, 10);
?>';
  $handler->display->display_options['fields']['php_9']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_9']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 11. Spieltag */
  $handler->display->display_options['fields']['php_10']['id'] = 'php_10';
  $handler->display->display_options['fields']['php_10']['table'] = 'views';
  $handler->display->display_options['fields']['php_10']['field'] = 'php';
  $handler->display->display_options['fields']['php_10']['ui_name'] = 'Punkte Spieler 11. Spieltag';
  $handler->display->display_options['fields']['php_10']['label'] = '11';
  $handler->display->display_options['fields']['php_10']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_10']['php_output'] = '<?php 
print player_single_result_matchday($row, 11);
?>';
  $handler->display->display_options['fields']['php_10']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_10']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 12. Spieltag */
  $handler->display->display_options['fields']['php_11']['id'] = 'php_11';
  $handler->display->display_options['fields']['php_11']['table'] = 'views';
  $handler->display->display_options['fields']['php_11']['field'] = 'php';
  $handler->display->display_options['fields']['php_11']['ui_name'] = 'Punkte Spieler 12. Spieltag';
  $handler->display->display_options['fields']['php_11']['label'] = '12';
  $handler->display->display_options['fields']['php_11']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_11']['php_output'] = '<?php 
print player_single_result_matchday($row, 12);
?>';
  $handler->display->display_options['fields']['php_11']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_11']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 13. Spieltag */
  $handler->display->display_options['fields']['php_12']['id'] = 'php_12';
  $handler->display->display_options['fields']['php_12']['table'] = 'views';
  $handler->display->display_options['fields']['php_12']['field'] = 'php';
  $handler->display->display_options['fields']['php_12']['ui_name'] = 'Punkte Spieler 13. Spieltag';
  $handler->display->display_options['fields']['php_12']['label'] = '13';
  $handler->display->display_options['fields']['php_12']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_12']['php_output'] = '<?php 
print player_single_result_matchday($row, 13);
?>';
  $handler->display->display_options['fields']['php_12']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_12']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 14. Spieltag */
  $handler->display->display_options['fields']['php_13']['id'] = 'php_13';
  $handler->display->display_options['fields']['php_13']['table'] = 'views';
  $handler->display->display_options['fields']['php_13']['field'] = 'php';
  $handler->display->display_options['fields']['php_13']['ui_name'] = 'Punkte Spieler 14. Spieltag';
  $handler->display->display_options['fields']['php_13']['label'] = '14';
  $handler->display->display_options['fields']['php_13']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_13']['php_output'] = '<?php 
print player_single_result_matchday($row, 14);
?>';
  $handler->display->display_options['fields']['php_13']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_13']['php_click_sortable'] = '';
  /* Feld: Punkte Spieler 15. Spieltag */
  $handler->display->display_options['fields']['php_14']['id'] = 'php_14';
  $handler->display->display_options['fields']['php_14']['table'] = 'views';
  $handler->display->display_options['fields']['php_14']['field'] = 'php';
  $handler->display->display_options['fields']['php_14']['ui_name'] = 'Punkte Spieler 15. Spieltag';
  $handler->display->display_options['fields']['php_14']['label'] = '15';
  $handler->display->display_options['fields']['php_14']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_14']['php_output'] = '<?php 
print player_single_result_matchday($row, 15);
?>';
  $handler->display->display_options['fields']['php_14']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_14']['php_click_sortable'] = '';
  /* Feld: Gesamtpunktzahl */
  $handler->display->display_options['fields']['php_15']['id'] = 'php_15';
  $handler->display->display_options['fields']['php_15']['table'] = 'views';
  $handler->display->display_options['fields']['php_15']['field'] = 'php';
  $handler->display->display_options['fields']['php_15']['ui_name'] = 'Gesamtpunktzahl';
  $handler->display->display_options['fields']['php_15']['label'] = 'Ges.';
  $handler->display->display_options['fields']['php_15']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_15']['php_value'] = 'return player_points_sum($row)';
  $handler->display->display_options['fields']['php_15']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_15']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_15']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Field collection item: Verein (field_fc_verein) */
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
  /* Kontextfilter: Field collection item: Saison (field_saison) */
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
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'field_pl_facebook' => 'field_pl_facebook',
    'field_pl_twitter' => 'field_pl_twitter',
    'field_wikipedia_eintrag' => 'field_wikipedia_eintrag',
    'field_webseite' => 'field_webseite',
  );
  $handler->display->display_options['row_options']['separator'] = '&nbsp;&nbsp;';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'margin10';
  /* Feld: Field collection item: Meistertitel */
  $handler->display->display_options['fields']['field_pl_master_title']['id'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['table'] = 'field_data_field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['field'] = 'field_pl_master_title';
  $handler->display->display_options['fields']['field_pl_master_title']['label'] = 'Titel';
  $handler->display->display_options['fields']['field_pl_master_title']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_pl_master_title']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_pl_master_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pl_master_title']['element_wrapper_class'] = 'margin5';
  $handler->display->display_options['fields']['field_pl_master_title']['hide_empty'] = TRUE;
  /* Feld: Field collection item: ELO */
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
  /* Feld: Field collection item: Nation */
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
  /* Feld: Field collection item: Saison */
  $handler->display->display_options['fields']['field_saison']['id'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_saison']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_saison']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_saison']['element_wrapper_class'] = 'margin5';
  $handler->display->display_options['fields']['field_saison']['type'] = 'taxonomy_term_reference_plain';
  /* Feld: Inhalt: Facebook */
  $handler->display->display_options['fields']['field_pl_facebook']['id'] = 'field_pl_facebook';
  $handler->display->display_options['fields']['field_pl_facebook']['table'] = 'field_data_field_pl_facebook';
  $handler->display->display_options['fields']['field_pl_facebook']['field'] = 'field_pl_facebook';
  $handler->display->display_options['fields']['field_pl_facebook']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['field_pl_facebook']['label'] = '';
  $handler->display->display_options['fields']['field_pl_facebook']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pl_facebook']['alter']['text'] = '&nbsp;&nbsp;<a href="[field_pl_facebook-url]" rel="nofollow" class="tooltip blue tooltipstered" title="Facebook"><i class="fa fa-facebook-square fa-2x"></i></a>';
  $handler->display->display_options['fields']['field_pl_facebook']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pl_facebook']['click_sort_column'] = 'url';
  /* Feld: Inhalt: Twitter */
  $handler->display->display_options['fields']['field_pl_twitter']['id'] = 'field_pl_twitter';
  $handler->display->display_options['fields']['field_pl_twitter']['table'] = 'field_data_field_pl_twitter';
  $handler->display->display_options['fields']['field_pl_twitter']['field'] = 'field_pl_twitter';
  $handler->display->display_options['fields']['field_pl_twitter']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['field_pl_twitter']['label'] = '';
  $handler->display->display_options['fields']['field_pl_twitter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pl_twitter']['alter']['text'] = '&nbsp;&nbsp;<a href="[field_pl_twitter-url]" rel="nofollow" class="tooltip blue tooltipstered" title="Twitter"><i class="fa fa-twitter-square fa-2x"></i></a>';
  $handler->display->display_options['fields']['field_pl_twitter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pl_twitter']['click_sort_column'] = 'url';
  /* Feld: Inhalt: Wikipedia Eintrag */
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['id'] = 'field_wikipedia_eintrag';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['table'] = 'field_data_field_wikipedia_eintrag';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['field'] = 'field_wikipedia_eintrag';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['label'] = '';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['alter']['text'] = '&nbsp;&nbsp;<a href="[field_wikipedia_eintrag-url]" rel="nofollow" class="tooltip blue tooltipstered" title="Wikipedia"><i class="fa fa-wikipedia-w fa-2x"></i></a>';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['element_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['element_label_class'] = 'margin5';
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wikipedia_eintrag']['click_sort_column'] = 'url';
  /* Feld: Inhalt: Webseite */
  $handler->display->display_options['fields']['field_webseite']['id'] = 'field_webseite';
  $handler->display->display_options['fields']['field_webseite']['table'] = 'field_data_field_webseite';
  $handler->display->display_options['fields']['field_webseite']['field'] = 'field_webseite';
  $handler->display->display_options['fields']['field_webseite']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['field_webseite']['label'] = '';
  $handler->display->display_options['fields']['field_webseite']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_webseite']['alter']['text'] = '&nbsp;&nbsp;<a href="[field_webseite-url]" rel="nofollow" class="tooltip blue tooltipstered" title="Webseite"><i class="fa fa-globe fa-2x"></i></a>';
  $handler->display->display_options['fields']['field_webseite']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webseite']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_webseite']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_webseite']['click_sort_column'] = 'url';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Beitrags-ID */
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
  /* Kontextfilter: Field collection item: Saison (field_saison) */
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
  /* Feld: Verein NID */
  $handler->display->display_options['fields']['field_fc_verein_1']['id'] = 'field_fc_verein_1';
  $handler->display->display_options['fields']['field_fc_verein_1']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein_1']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein_1']['ui_name'] = 'Verein NID';
  $handler->display->display_options['fields']['field_fc_verein_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fc_verein_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_fc_verein_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Saison als TID */
  $handler->display->display_options['fields']['field_saison']['id'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['ui_name'] = 'Saison als TID';
  $handler->display->display_options['fields']['field_saison']['label'] = '';
  $handler->display->display_options['fields']['field_saison']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_saison']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_saison']['alter']['text'] = '[field_saison-tid]';
  $handler->display->display_options['fields']['field_saison']['element_label_colon'] = FALSE;
  /* Feld: Liga als TID */
  $handler->display->display_options['fields']['field_pl_league_1']['id'] = 'field_pl_league_1';
  $handler->display->display_options['fields']['field_pl_league_1']['table'] = 'field_data_field_pl_league';
  $handler->display->display_options['fields']['field_pl_league_1']['field'] = 'field_pl_league';
  $handler->display->display_options['fields']['field_pl_league_1']['ui_name'] = 'Liga als TID';
  $handler->display->display_options['fields']['field_pl_league_1']['label'] = '';
  $handler->display->display_options['fields']['field_pl_league_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pl_league_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pl_league_1']['alter']['text'] = '[field_pl_league_1-tid]';
  $handler->display->display_options['fields']['field_pl_league_1']['element_label_colon'] = FALSE;
  /* Feld: Field collection item: Verein */
  $handler->display->display_options['fields']['field_fc_verein']['id'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_fc_verein']['alter']['path'] = 'verein/[field_fc_verein-target_id]/[field_saison]';
  $handler->display->display_options['fields']['field_fc_verein']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Field collection item: Liga */
  $handler->display->display_options['fields']['field_pl_league']['id'] = 'field_pl_league';
  $handler->display->display_options['fields']['field_pl_league']['table'] = 'field_data_field_pl_league';
  $handler->display->display_options['fields']['field_pl_league']['field'] = 'field_pl_league';
  $handler->display->display_options['fields']['field_pl_league']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_pl_league']['alter']['path'] = '/tabelle/[field_saison]/[field_pl_league_1]';
  $handler->display->display_options['fields']['field_pl_league']['type'] = 'taxonomy_term_reference_plain';
  /* Feld: Elo-Schnitt */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Elo-Schnitt';
  $handler->display->display_options['fields']['php_1']['label'] = 'Elo-Ø Gegner';
  $handler->display->display_options['fields']['php_1']['empty'] = '0';
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print player_elo_opponents($row->field_pl_league_1); ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Punkte */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Punkte';
  $handler->display->display_options['fields']['php_2']['label'] = 'Punkte';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print player_single_points($row->field_pl_league_1); ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Anzahl gespielte Spiele */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Anzahl gespielte Spiele';
  $handler->display->display_options['fields']['php']['label'] = 'Spiele';
  $handler->display->display_options['fields']['php']['empty'] = '0';
  $handler->display->display_options['fields']['php']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print player_number_played_games($row->field_pl_league_1); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Prozentzahl erreichter Punkte pro Spiel */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Prozentzahl erreichter Punkte pro Spiel';
  $handler->display->display_options['fields']['php_3']['label'] = '%';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print player_single_percentage($row->field_pl_league_1); ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Elo-Performance */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Elo-Performance';
  $handler->display->display_options['fields']['php_4']['label'] = 'Elo-Perf.';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print player_single_elo_performance($row->field_pl_league_1); ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: ELO Veränderung */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'ELO Veränderung';
  $handler->display->display_options['fields']['php_5']['label'] = 'ELO +/-';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
$change=player_elo_change($row->field_pl_league_1);
update_elo($row->field_fc_verein_1,$change);
print $change > 0?"<span style=\'color:green\'>+".$change."</span>":"<span style=\'color:red\'>".$change."</span>";
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Beitrags-ID */
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
  /* Kontextfilter: Field collection item: Saison (field_saison) */
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

  /* Display: Spieler alle Saisonergebnisse */
  $handler = $view->new_display('panel_pane', 'Spieler alle Saisonergebnisse', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ergebnisse vergangener Spielzeiten';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'field_saison' => 'field_saison',
    'field_fc_verein_1' => 'field_fc_verein_1',
    'field_saison_1' => 'field_saison_1',
    'field_fc_verein' => 'field_fc_verein',
    'field_pl_league' => 'field_pl_league',
    'field_pl_board_nr' => 'field_pl_board_nr',
    'field_pl_elo' => 'field_pl_elo',
    'php_1' => 'php_1',
    'php_2' => 'php_2',
    'php' => 'php',
    'php_3' => 'php_3',
    'php_4' => 'php_4',
    'php_5' => 'php_5',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
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
    'field_fc_verein_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_saison_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fc_verein' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pl_league' => array(
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
    'field_pl_elo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'php_5' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'field_saison_1',
    'icon' => '',
    'icon_size' => '',
    'hide' => array(
      'counter' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_saison' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_fc_verein_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_saison_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_fc_verein' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_league' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_board_nr' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_pl_elo' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_1' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_2' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_3' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_4' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_5' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Global: Ergebniszähler einer Ansicht */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Feld: Saison als TID */
  $handler->display->display_options['fields']['field_saison']['id'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison']['ui_name'] = 'Saison als TID';
  $handler->display->display_options['fields']['field_saison']['label'] = '';
  $handler->display->display_options['fields']['field_saison']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_saison']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_saison']['alter']['text'] = '[field_saison-tid]';
  $handler->display->display_options['fields']['field_saison']['element_label_colon'] = FALSE;
  /* Feld: Verein NID */
  $handler->display->display_options['fields']['field_fc_verein_1']['id'] = 'field_fc_verein_1';
  $handler->display->display_options['fields']['field_fc_verein_1']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein_1']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein_1']['ui_name'] = 'Verein NID';
  $handler->display->display_options['fields']['field_fc_verein_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fc_verein_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_fc_verein_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Field collection item: Saison */
  $handler->display->display_options['fields']['field_saison_1']['id'] = 'field_saison_1';
  $handler->display->display_options['fields']['field_saison_1']['table'] = 'field_data_field_saison';
  $handler->display->display_options['fields']['field_saison_1']['field'] = 'field_saison';
  $handler->display->display_options['fields']['field_saison_1']['type'] = 'taxonomy_term_reference_plain';
  /* Feld: Field collection item: Verein */
  $handler->display->display_options['fields']['field_fc_verein']['id'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_fc_verein']['alter']['path'] = 'verein/[field_fc_verein-target_id]/[field_saison]';
  $handler->display->display_options['fields']['field_fc_verein']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Field collection item: Liga */
  $handler->display->display_options['fields']['field_pl_league']['id'] = 'field_pl_league';
  $handler->display->display_options['fields']['field_pl_league']['table'] = 'field_data_field_pl_league';
  $handler->display->display_options['fields']['field_pl_league']['field'] = 'field_pl_league';
  $handler->display->display_options['fields']['field_pl_league']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_pl_league']['alter']['path'] = '/tabelle/[field_saison]/[field_pl_league-tid]';
  $handler->display->display_options['fields']['field_pl_league']['type'] = 'taxonomy_term_reference_plain';
  /* Feld: Field collection item: Brett-Nr. */
  $handler->display->display_options['fields']['field_pl_board_nr']['id'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['table'] = 'field_data_field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['field'] = 'field_pl_board_nr';
  $handler->display->display_options['fields']['field_pl_board_nr']['label'] = 'Brett';
  $handler->display->display_options['fields']['field_pl_board_nr']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Feld: Field collection item: ELO */
  $handler->display->display_options['fields']['field_pl_elo']['id'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['table'] = 'field_data_field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['field'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Feld: Elo-Schnitt */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Elo-Schnitt';
  $handler->display->display_options['fields']['php_1']['label'] = 'Gegner-Ø';
  $handler->display->display_options['fields']['php_1']['empty'] = '0';
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print player_elo_opponents_all_seasons($row->field_saison); ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Punkte */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Punkte';
  $handler->display->display_options['fields']['php_2']['label'] = 'Punkte';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print player_single_points_all_seasons($row->field_saison); ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Anzahl gespielte Spiele */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Anzahl gespielte Spiele';
  $handler->display->display_options['fields']['php']['label'] = 'Pkt.';
  $handler->display->display_options['fields']['php']['empty'] = '0';
  $handler->display->display_options['fields']['php']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $row->php_2 . "/" . player_number_played_games_per_season($row->field_saison); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Prozentzahl erreichter Punkte pro Spiel */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Prozentzahl erreichter Punkte pro Spiel';
  $handler->display->display_options['fields']['php_3']['label'] = '%';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print player_single_percentage_all_seasons($row->field_saison); ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Elo-Performance */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Elo-Performance';
  $handler->display->display_options['fields']['php_4']['label'] = 'Elo-Perf.';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print player_single_elo_performance_all_seasons($row->field_saison); ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: ELO Veränderung */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'ELO Veränderung';
  $handler->display->display_options['fields']['php_5']['label'] = 'ELO +/-';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php print player_elo_change_all_seasons($row->field_saison); ?>
<?php
$max_rows=get_view_rowcount();
if($max_rows==$row->counter) {
$gegner_durchschnitt=player_elo_opponents_all_seasons(0);
$punkte_gesamt=player_single_points_all_seasons(0);
$spiele_gesamt=player_number_played_games_per_season(0);
$prozente_gesamt=player_number_played_games_per_season(0) > 0? round((player_single_points_all_seasons(0)/player_number_played_games_per_season(0)*100),0):0;
$elo_performance_gesamt=player_single_elo_performance_all_seasons(0);
$elo_change=player_elo_change_all_seasons(0);
print \'</td></tr><tr class="odd views-row-first"><th class="views-field views-field-field-saison-1 footable-visible footable-first-column"><span class="footable-toggle"></span>Gesamt</th>\';
print \'<th class="views-field views-field-field-fc-verein footable-visible"></th><th class="views-field views-field-field-pl-board-nr expand footable-visible"></th><th class="views-field views-field-field-pl-elo footable-visible"></th>\';
print \'<th class="views-field views-field-field-pl-elo footable-visible"></th>\';
print \'<th class="views-field views-field-php-1 footable-visible">\'.$gegner_durchschnitt.\'</th>\';
print \'<th class="views-field views-field-php footable-visible">\'.$punkte_gesamt . \'/\' . $spiele_gesamt.\'</th>\';
print \'<th class="views-field views-field-php-3 footable-visible">\'.$prozente_gesamt.\'</th>\';
print \'<th class="views-field views-field-php-4 footable-visible">\'.$elo_performance_gesamt.\'</th>\';
print \'<th class="views-field views-field-php-5 footable-visible footable-last-column">\'.$elo_change.\'</th></tr>\';
}
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Field collection item: Jahres-ID (field_year_id) */
  $handler->display->display_options['sorts']['field_year_id_value']['id'] = 'field_year_id_value';
  $handler->display->display_options['sorts']['field_year_id_value']['table'] = 'field_data_field_year_id';
  $handler->display->display_options['sorts']['field_year_id_value']['field'] = 'field_year_id_value';
  $handler->display->display_options['sorts']['field_year_id_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Beitrags-ID */
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Field collection item: Feldname */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_sp_verein' => 'field_sp_verein',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filterkriterium: Field collection item: Saison (field_saison) */
  $handler->display->display_options['filters']['field_saison_tid']['id'] = 'field_saison_tid';
  $handler->display->display_options['filters']['field_saison_tid']['table'] = 'field_data_field_saison';
  $handler->display->display_options['filters']['field_saison_tid']['field'] = 'field_saison_tid';
  $handler->display->display_options['filters']['field_saison_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_saison_tid']['value'] = array(
    522 => '522',
  );
  $handler->display->display_options['filters']['field_saison_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_saison_tid']['vocabulary'] = 'saison';
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
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Node, der Field Collection field_sp_verein enthält'),
    t('Name'),
    t('Alle'),
    t('Content pane Kader pro Verein'),
    t('<h2 class="view-title">Kader [field_saison_1]</h2>'),
    t('ELO-Durchschnitt'),
    t('[field_saison-tid]'),
    t('B'),
    t('Bild'),
    t('<img src="/sites/default/files/styles/spielerbild_klein/public/dummy_2.jpg" />'),
    t('Nat.'),
    t('ELO'),
    t('Titel'),
    t('1'),
    t('2'),
    t('3'),
    t('4'),
    t('5'),
    t('6'),
    t('7'),
    t('8'),
    t('9'),
    t('10'),
    t('11'),
    t('12'),
    t('13'),
    t('14'),
    t('15'),
    t('Ges.'),
    t('View panes'),
    t('Content pane Spielerkarte Daten 1'),
    t('Föderation'),
    t('Saison'),
    t('&nbsp;&nbsp;<a href="[field_pl_facebook-url]" rel="nofollow" class="tooltip blue tooltipstered" title="Facebook"><i class="fa fa-facebook-square fa-2x"></i></a>'),
    t('&nbsp;&nbsp;<a href="[field_pl_twitter-url]" rel="nofollow" class="tooltip blue tooltipstered" title="Twitter"><i class="fa fa-twitter-square fa-2x"></i></a>'),
    t('&nbsp;&nbsp;<a href="[field_wikipedia_eintrag-url]" rel="nofollow" class="tooltip blue tooltipstered" title="Wikipedia"><i class="fa fa-wikipedia-w fa-2x"></i></a>'),
    t('&nbsp;&nbsp;<a href="[field_webseite-url]" rel="nofollow" class="tooltip blue tooltipstered" title="Webseite"><i class="fa fa-globe fa-2x"></i></a>'),
    t('Content pane Spieler Saisonergebnisse Durchschnitt'),
    t('Verein'),
    t('[field_pl_league_1-tid]'),
    t('Liga'),
    t('Elo-Ø Gegner'),
    t('Punkte'),
    t('Spiele'),
    t('%'),
    t('Elo-Perf.'),
    t('ELO +/-'),
    t('Spieler alle Saisonergebnisse'),
    t('Ergebnisse vergangener Spielzeiten'),
    t('Ergebniszähler einer Ansicht'),
    t('Brett'),
    t('Gegner-Ø'),
    t('Pkt.'),
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
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
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
  /* Kopfbereich: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2 class="view-title">Ergebnisse und Gegner [field_tm_saison]</h2>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Beziehung: Field collection item: Entity with the Einzelspiel (field_tm_game) */
  $handler->display->display_options['relationships']['field_tm_game_node']['id'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_tm_game_node']['field'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['label'] = 'Node that contains the field collection field_tm_game';
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_mt_player_1_target_id']['id'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['relationships']['field_mt_player_1_target_id']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['relationships']['field_mt_player_1_target_id']['field'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['relationships']['field_mt_player_1_target_id']['label'] = 'Spieler 1 referenziert in field_mt_player_1';
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_mt_player_2_target_id']['id'] = 'field_mt_player_2_target_id';
  $handler->display->display_options['relationships']['field_mt_player_2_target_id']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['relationships']['field_mt_player_2_target_id']['field'] = 'field_mt_player_2_target_id';
  $handler->display->display_options['relationships']['field_mt_player_2_target_id']['label'] = 'Spieler 2 referenziert in field_mt_player_2';
  /* Beziehung: Field collection item: Entity with the Saisondaten Spieler (field_sp_verein) */
  $handler->display->display_options['relationships']['field_sp_verein_node']['id'] = 'field_sp_verein_node';
  $handler->display->display_options['relationships']['field_sp_verein_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_sp_verein_node']['field'] = 'field_sp_verein_node';
  $handler->display->display_options['relationships']['field_sp_verein_node']['label'] = 'Field collection Item field_sp_verein';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['field_tm_spieltag']['id'] = 'field_tm_spieltag';
  $handler->display->display_options['fields']['field_tm_spieltag']['table'] = 'field_data_field_tm_spieltag';
  $handler->display->display_options['fields']['field_tm_spieltag']['field'] = 'field_tm_spieltag';
  $handler->display->display_options['fields']['field_tm_spieltag']['relationship'] = 'field_tm_game_node';
  /* Feld: Inhalt: Datum */
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
  /* Feld: Field collection item: Spieler 2 */
  $handler->display->display_options['fields']['field_mt_player_2']['id'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['field'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['label'] = 'Gegner: Name';
  $handler->display->display_options['fields']['field_mt_player_2']['settings'] = array(
    'link' => 0,
  );
  /* Sortierkriterien: Inhalt: Liga (field_liga) */
  $handler->display->display_options['sorts']['field_liga_tid']['id'] = 'field_liga_tid';
  $handler->display->display_options['sorts']['field_liga_tid']['table'] = 'field_data_field_liga';
  $handler->display->display_options['sorts']['field_liga_tid']['field'] = 'field_liga_tid';
  $handler->display->display_options['sorts']['field_liga_tid']['relationship'] = 'field_tm_game_node';
  /* Sortierkriterien: Inhalt: Spieltag (field_tm_spieltag_1) */
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['id'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['field'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['relationship'] = 'field_tm_game_node';
  /* Kontextfilter: Inhalt: Saison (field_tm_saison) */
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
  /* Kontextfilter: Field collection item: Spieler 1 (field_mt_player_1) */
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
  /* Filterkriterium: Field collection item: Feldname */
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
  /* Kopfbereich: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2 class="view-title">Ergebnisse und Gegner</h2>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Field Collection Item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['ui_name'] = 'Field Collection Item ID';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Feld: Saison als TID */
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
  /* Feld: Spieler 1 als NID */
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
  /* Feld: Spieler 2 als NID */
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
  /* Feld: Inhalt: Saison */
  $handler->display->display_options['fields']['field_tm_saison']['id'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['field'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_saison']['label'] = '';
  $handler->display->display_options['fields']['field_tm_saison']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_saison']['type'] = 'taxonomy_term_reference_plain';
  /* Feld: Inhalt: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['relationship'] = 'field_tm_game_node';
  /* Feld: Inhalt: Datum */
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
  /* Feld: Field collection item: Spieler 1 */
  $handler->display->display_options['fields']['field_mt_player_1']['id'] = 'field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['field'] = 'field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['label'] = '';
  $handler->display->display_options['fields']['field_mt_player_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mt_player_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Ergebnis aus Spielerpunkten zusammengesetzt */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Ergebnis aus Spielerpunkten zusammengesetzt';
  $handler->display->display_options['fields']['nothing']['label'] = 'Ergebnis';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Feld: Field collection item: Spieler 2 */
  $handler->display->display_options['fields']['field_mt_player_2']['id'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['field'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['label'] = 'Gegner';
  $handler->display->display_options['fields']['field_mt_player_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_2']['alter']['path'] = 'spieler/[field_mt_player_2_1]/[field_tm_saison_1]';
  $handler->display->display_options['fields']['field_mt_player_2']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Gegner: Nation */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Gegner: Nation';
  $handler->display->display_options['fields']['php_2']['label'] = 'Nat.';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print opponent_country($row); ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Field collection item: Punkte Spieler 1 */
  $handler->display->display_options['fields']['field_mt_points_player_1']['id'] = 'field_mt_points_player_1';
  $handler->display->display_options['fields']['field_mt_points_player_1']['table'] = 'field_data_field_mt_points_player_1';
  $handler->display->display_options['fields']['field_mt_points_player_1']['field'] = 'field_mt_points_player_1';
  $handler->display->display_options['fields']['field_mt_points_player_1']['label'] = '';
  $handler->display->display_options['fields']['field_mt_points_player_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mt_points_player_1']['element_label_colon'] = FALSE;
  /* Feld: Field collection item: Punkte Spieler 2 */
  $handler->display->display_options['fields']['field_mt_points_player_2']['id'] = 'field_mt_points_player_2';
  $handler->display->display_options['fields']['field_mt_points_player_2']['table'] = 'field_data_field_mt_points_player_2';
  $handler->display->display_options['fields']['field_mt_points_player_2']['field'] = 'field_mt_points_player_2';
  $handler->display->display_options['fields']['field_mt_points_player_2']['label'] = '';
  $handler->display->display_options['fields']['field_mt_points_player_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mt_points_player_2']['element_label_colon'] = FALSE;
  /* Feld: Gegner: Verein */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Gegner: Verein';
  $handler->display->display_options['fields']['php']['label'] = 'Verein';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print opponent_team($row); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Gegner: Meistertitel */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Gegner: Meistertitel';
  $handler->display->display_options['fields']['php_3']['label'] = 'Titel';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print opponent_master_title($row); ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Gegner: ELO */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Gegner: ELO';
  $handler->display->display_options['fields']['php_1']['label'] = 'ELO';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print opponent_elo($row); ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Leeres Argument zum Übergeben der Spieler-Node ID */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'Leeres Argument zum Übergeben der Spieler-Node ID';
  $handler->display->display_options['arguments']['null']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Kontextfilter: Leeres Argument zum Übergeben der Saison */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['ui_name'] = 'Leeres Argument zum Übergeben der Saison';
  $handler->display->display_options['arguments']['null_1']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Field collection item: Feldname */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_tm_game' => 'field_tm_game',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filterkriterium: Field collection item: Spieler 1 (field_mt_player_1) */
  $handler->display->display_options['filters']['field_mt_player_1_target_id']['id'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['filters']['field_mt_player_1_target_id']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['filters']['field_mt_player_1_target_id']['field'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['filters']['field_mt_player_1_target_id']['group'] = 2;
  /* Filterkriterium: Field collection item: Spieler 2 (field_mt_player_2) */
  $handler->display->display_options['filters']['field_mt_player_2_target_id']['id'] = 'field_mt_player_2_target_id';
  $handler->display->display_options['filters']['field_mt_player_2_target_id']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['filters']['field_mt_player_2_target_id']['field'] = 'field_mt_player_2_target_id';
  $handler->display->display_options['filters']['field_mt_player_2_target_id']['group'] = 2;
  /* Filterkriterium: Inhalt: Saison (field_tm_saison) */
  $handler->display->display_options['filters']['field_tm_saison_tid']['id'] = 'field_tm_saison_tid';
  $handler->display->display_options['filters']['field_tm_saison_tid']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['filters']['field_tm_saison_tid']['field'] = 'field_tm_saison_tid';
  $handler->display->display_options['filters']['field_tm_saison_tid']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['filters']['field_tm_saison_tid']['value'] = array(
    522 => '522',
  );
  $handler->display->display_options['filters']['field_tm_saison_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tm_saison_tid']['vocabulary'] = 'saison';
  $handler->display->display_options['argument_input'] = array(
    'null' => array(
      'type' => 'none',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Leeres Argument zum Übergeben der Spieler-Node ID',
    ),
    'null_1' => array(
      'type' => 'none',
      'context' => 'entity:node.field_addthis',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Leeres Argument zum Übergeben der Saison',
    ),
  );
  $translatables['single_games_player'] = array(
    t('Master'),
    t('Auswärtsspiele'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('<h2 class="view-title">Ergebnisse und Gegner [field_tm_saison]</h2>'),
    t('Node that contains the field collection field_tm_game'),
    t('Spieler 1 referenziert in field_mt_player_1'),
    t('Spieler 2 referenziert in field_mt_player_2'),
    t('Field collection Item field_sp_verein'),
    t('Beschädigte Behandlungsroutine field_data_field_tm_spieltag.field_tm_spieltag'),
    t('Datum'),
    t('Gegner: Name'),
    t('Alle'),
    t('Content pane Einzelspiele Heim'),
    t('<h2 class="view-title">Ergebnisse und Gegner</h2>'),
    t('.'),
    t('[field_tm_saison_1-tid]'),
    t('Spieltag'),
    t('Ergebnis'),
    t('Gegner'),
    t('Nat.'),
    t('Verein'),
    t('Titel'),
    t('ELO'),
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
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Feld: Inhalt: Logo Club */
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
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Inhalt: In der Liga seit */
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['id'] = 'field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['table'] = 'field_data_field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['field'] = 'field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['hide_empty'] = TRUE;
  /* Feld: Inhalt: Größte Erfolge */
  $handler->display->display_options['fields']['field_groesste_erfolge']['id'] = 'field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['table'] = 'field_data_field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['field'] = 'field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['hide_empty'] = TRUE;
  /* Sortierkriterien: Inhalt: Beitragsdatum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontextfilter: Inhalt: Beitrags-ID */
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
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
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
  );
  $handler->display->display_options['row_options']['separator'] = '&nbsp;&nbsp;';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Logo Club */
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
  /* Feld: Inhalt: In der Liga seit */
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['id'] = 'field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['table'] = 'field_data_field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['field'] = 'field_der_bundesliga_seit';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['element_wrapper_class'] = 'margin10';
  $handler->display->display_options['fields']['field_der_bundesliga_seit']['hide_empty'] = TRUE;
  /* Feld: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Liga';
  $handler->display->display_options['fields']['php']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['php']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['php']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['php']['element_wrapper_class'] = 'margin10';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$league=check_current_league_of_club();
$league_name=set_league_name($league);
print "<a href=\'/".set_link_to_league_table($league)."\'>".$league_name."</a>";
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Inhalt: Größte Erfolge */
  $handler->display->display_options['fields']['field_groesste_erfolge']['id'] = 'field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['table'] = 'field_data_field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['field'] = 'field_groesste_erfolge';
  $handler->display->display_options['fields']['field_groesste_erfolge']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_groesste_erfolge']['element_label_class'] = 'clearboth';
  $handler->display->display_options['fields']['field_groesste_erfolge']['hide_empty'] = TRUE;
  /* Feld: Inhalt: Website */
  $handler->display->display_options['fields']['field_website_club']['id'] = 'field_website_club';
  $handler->display->display_options['fields']['field_website_club']['table'] = 'field_data_field_website_club';
  $handler->display->display_options['fields']['field_website_club']['field'] = 'field_website_club';
  $handler->display->display_options['fields']['field_website_club']['label'] = '';
  $handler->display->display_options['fields']['field_website_club']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website_club']['alter']['text'] = '<a href="[field_website_club-url]" class="tooltip blue" title="Website" rel="nofollow"><i class="fa fa-globe fa-2x"></i> [field_website_club-url]</a>';
  $handler->display->display_options['fields']['field_website_club']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_club']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_website_club']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_website_club']['click_sort_column'] = 'url';
  /* Feld: Inhalt: Facebook */
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
  /* Feld: Inhalt: Twitter */
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
  /* Feld: Inhalt: Spielort */
  $handler->display->display_options['fields']['field_venue_club']['id'] = 'field_venue_club';
  $handler->display->display_options['fields']['field_venue_club']['table'] = 'field_data_field_venue_club';
  $handler->display->display_options['fields']['field_venue_club']['field'] = 'field_venue_club';
  $handler->display->display_options['fields']['field_venue_club']['alter']['text'] = '[field_venue_club]<br />[field_freier_text]';
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
  $handler->display->display_options['fields']['field_venue_club']['delta_limit'] = 'all';
  /* Feld: Inhalt: Heimspiele */
  $handler->display->display_options['fields']['field_heimspiele']['id'] = 'field_heimspiele';
  $handler->display->display_options['fields']['field_heimspiele']['table'] = 'field_data_field_heimspiele';
  $handler->display->display_options['fields']['field_heimspiele']['field'] = 'field_heimspiele';
  $handler->display->display_options['fields']['field_heimspiele']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_heimspiele']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_heimspiele']['element_wrapper_class'] = 'two-third last';
  $handler->display->display_options['fields']['field_heimspiele']['hide_empty'] = TRUE;
  /* Feld: Inhalt: Vorsitzender */
  $handler->display->display_options['fields']['field_chairman_club']['id'] = 'field_chairman_club';
  $handler->display->display_options['fields']['field_chairman_club']['table'] = 'field_data_field_chairman_club';
  $handler->display->display_options['fields']['field_chairman_club']['field'] = 'field_chairman_club';
  $handler->display->display_options['fields']['field_chairman_club']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_chairman_club']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_chairman_club']['element_wrapper_class'] = 'one-third';
  $handler->display->display_options['fields']['field_chairman_club']['hide_empty'] = TRUE;
  /* Feld: Inhalt: Mannschaftsführer */
  $handler->display->display_options['fields']['field_captain_team']['id'] = 'field_captain_team';
  $handler->display->display_options['fields']['field_captain_team']['table'] = 'field_data_field_captain_team';
  $handler->display->display_options['fields']['field_captain_team']['field'] = 'field_captain_team';
  $handler->display->display_options['fields']['field_captain_team']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_captain_team']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_captain_team']['element_wrapper_class'] = 'one-third';
  $handler->display->display_options['fields']['field_captain_team']['hide_empty'] = TRUE;
  /* Feld: Inhalt: Internet-Verantwortlicher */
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
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Logo Icon */
  $handler->display->display_options['fields']['field_logo_icon']['id'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['table'] = 'field_data_field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['field'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['label'] = '';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_logo_icon']['alter']['path'] = 'verein/[nid]/522';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['link_class'] = 'tooltip';
  $handler->display->display_options['fields']['field_logo_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_icon']['settings'] = array(
    'image_style' => 'vereinslogo_klein',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Inhalt: Vereinskürzel (field_vereinskuerzel) */
  $handler->display->display_options['sorts']['field_vereinskuerzel_value']['id'] = 'field_vereinskuerzel_value';
  $handler->display->display_options['sorts']['field_vereinskuerzel_value']['table'] = 'field_data_field_vereinskuerzel';
  $handler->display->display_options['sorts']['field_vereinskuerzel_value']['field'] = 'field_vereinskuerzel_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mannschaft' => 'mannschaft',
  );
  /* Filterkriterium: Inhalt: Saison (field_t_saison) */
  $handler->display->display_options['filters']['field_t_saison_tid']['id'] = 'field_t_saison_tid';
  $handler->display->display_options['filters']['field_t_saison_tid']['table'] = 'field_data_field_t_saison';
  $handler->display->display_options['filters']['field_t_saison_tid']['field'] = 'field_t_saison_tid';
  $handler->display->display_options['filters']['field_t_saison_tid']['value'] = array(
    522 => '522',
  );
  $handler->display->display_options['filters']['field_t_saison_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_t_saison_tid']['vocabulary'] = 'saison';
  $translatables['team_info'] = array(
    t('Master'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('In der Liga seit'),
    t('Größte Erfolge'),
    t('Alle'),
    t('Content pane Verein Basisdaten 1'),
    t('Liga'),
    t('<a href="[field_website_club-url]" class="tooltip blue" title="Website" rel="nofollow"><i class="fa fa-globe fa-2x"></i> [field_website_club-url]</a>'),
    t('<a href="[field_facebook-url]" class="tooltip blue" title="Facebook" rel="nofollow"><i class="fa fa-facebook-square fa-2x"></i></a>'),
    t('<a href="[field_twitter_club-url]" class="tooltip blue" title="Twitter" rel="nofollow"><i class="fa fa-twitter-square fa-2x"></i></a>'),
    t('View panes'),
    t('Content pane Verein Basisdaten 2'),
    t('Spielort'),
    t('[field_venue_club]<br />[field_freier_text]'),
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
