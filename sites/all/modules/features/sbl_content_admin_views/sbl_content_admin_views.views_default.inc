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
  $view->name = 'content_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Übersicht Inhalte';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Übersicht Inhalte';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'type' => 'type',
    'created' => 'created',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
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
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Anzahl der Ergebnisse';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Typ';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Node ID';
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
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
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Inhaltstyp';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/all-content';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Alle Inhalte Übersicht';
  $handler->display->display_options['menu']['weight'] = '8';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['content_overview'] = array(
    t('Master'),
    t('Übersicht Inhalte'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Anzahl der Ergebnisse'),
    t('Title'),
    t('Typ'),
    t('Post date'),
    t('Node ID'),
    t('Inhaltstyp'),
    t('Page'),
  );
  $export['content_overview'] = $view;

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
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_tm_spieltag_1' => 'field_tm_spieltag_1',
    'title' => 'title',
    'field_datum' => 'field_datum',
    'field_tm_team_1' => 'field_tm_team_1',
    'field_tm_team_2' => 'field_tm_team_2',
    'field_tm_team_points_tm_1' => 'field_tm_team_points_tm_1',
    'field_tm_board_points_team_1' => 'field_tm_board_points_team_1',
    'field_tm_team_points_tm_2' => 'field_tm_team_points_tm_2',
    'field_tm_board_points_team_2' => 'field_tm_board_points_team_2',
    'field_ausrichter' => 'field_ausrichter',
    'field_spiel_laeuft' => 'field_spiel_laeuft',
    'field_game_has_result' => 'field_game_has_result',
    'edit_node' => 'edit_node',
    'counter' => 'counter',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_tm_spieltag_1' => array(
      'sortable' => 1,
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
    'field_datum' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tm_team_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tm_team_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tm_team_points_tm_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tm_board_points_team_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tm_team_points_tm_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tm_board_points_team_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ausrichter' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_spiel_laeuft' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_game_has_result' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
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
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['element_label_colon'] = FALSE;
  /* Field: Content: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = 'Brettpunkte Heimmannschaft';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  /* Field: Content: Mannschaftspunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['id'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['table'] = 'field_data_field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['field'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['label'] = 'Mannschaftspunkte Gastmannschaft';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['exclude'] = TRUE;
  /* Field: Content: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = 'Endergebnis';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['alter']['text'] = '[field_tm_board_points_team_1] : [field_tm_board_points_team_2]';
  /* Field: Content: Ausrichter */
  $handler->display->display_options['fields']['field_ausrichter']['id'] = 'field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['field'] = 'field_ausrichter';
  /* Sort criterion: Content: Spieltag (field_tm_spieltag_1) */
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['id'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['field'] = 'field_tm_spieltag_1_value';
  /* Sort criterion: Content: Ausrichter (field_ausrichter) */
  $handler->display->display_options['sorts']['field_ausrichter_value']['id'] = 'field_ausrichter_value';
  $handler->display->display_options['sorts']['field_ausrichter_value']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['sorts']['field_ausrichter_value']['field'] = 'field_ausrichter_value';
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Saison (field_tm_saison) */
  $handler->display->display_options['filters']['field_tm_saison_tid']['id'] = 'field_tm_saison_tid';
  $handler->display->display_options['filters']['field_tm_saison_tid']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['filters']['field_tm_saison_tid']['field'] = 'field_tm_saison_tid';
  $handler->display->display_options['filters']['field_tm_saison_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tm_saison_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tm_saison_tid']['expose']['operator_id'] = 'field_tm_saison_tid_op';
  $handler->display->display_options['filters']['field_tm_saison_tid']['expose']['label'] = 'Saison';
  $handler->display->display_options['filters']['field_tm_saison_tid']['expose']['operator'] = 'field_tm_saison_tid_op';
  $handler->display->display_options['filters']['field_tm_saison_tid']['expose']['identifier'] = 'field_tm_saison_tid';
  $handler->display->display_options['filters']['field_tm_saison_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_tm_saison_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tm_saison_tid']['vocabulary'] = 'saison';
  /* Filter criterion: Content: Spieltag (field_tm_spieltag_1) */
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['id'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['field'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['group'] = 1;
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['expose']['operator_id'] = 'field_tm_spieltag_1_value_op';
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['expose']['label'] = 'Spieltag';
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['expose']['operator'] = 'field_tm_spieltag_1_value_op';
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['expose']['identifier'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['filters']['field_tm_spieltag_1_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Mannschaft 1 (field_tm_team_1) */
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['id'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['field'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['expose']['operator_id'] = 'field_tm_team_1_target_id_op';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['expose']['label'] = 'Heimmannschaft';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['expose']['operator'] = 'field_tm_team_1_target_id_op';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['expose']['identifier'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Mannschaft 2 (field_tm_team_2) */
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['id'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['field'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['expose']['operator_id'] = 'field_tm_team_2_target_id_op';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['expose']['label'] = 'Auswärtsmannschaft';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['expose']['operator'] = 'field_tm_team_2_target_id_op';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['expose']['identifier'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Datum */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
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
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['element_label_colon'] = FALSE;
  /* Field: Content: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = 'Brettpunkte Heimmannschaft';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  /* Field: Content: Mannschaftspunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['id'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['table'] = 'field_data_field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['field'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['label'] = 'Mannschaftspunkte Gastmannschaft';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['exclude'] = TRUE;
  /* Field: Content: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = 'Endergebnis';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['alter']['text'] = '[field_tm_board_points_team_1] : [field_tm_board_points_team_2]';
  /* Field: Content: Ausrichter */
  $handler->display->display_options['fields']['field_ausrichter']['id'] = 'field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['field'] = 'field_ausrichter';
  /* Field: Content: Spiel läuft */
  $handler->display->display_options['fields']['field_spiel_laeuft']['id'] = 'field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['table'] = 'field_data_field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['field'] = 'field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['label'] = 'Sp. läuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['type'] = 'list_key';
  /* Field: Content: Spiel in Ergebnissen anzeigen */
  $handler->display->display_options['fields']['field_game_has_result']['id'] = 'field_game_has_result';
  $handler->display->display_options['fields']['field_game_has_result']['table'] = 'field_data_field_game_has_result';
  $handler->display->display_options['fields']['field_game_has_result']['field'] = 'field_game_has_result';
  $handler->display->display_options['fields']['field_game_has_result']['label'] = 'in Erg. anz.';
  $handler->display->display_options['fields']['field_game_has_result']['type'] = 'list_key';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'admin/mannschafts-matches';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Mannschaftsmatches Übersicht';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['mannchaftsmatches'] = array(
    t('Master'),
    t('Mannchaftsmatches Übersicht für Admin'),
    t('more'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Spieltag'),
    t('Title'),
    t('Heimmannschaft'),
    t('Gastmannschaft'),
    t('Mannschaftspunkte Heimmannschaft'),
    t('Brettpunkte Heimmannschaft'),
    t('Mannschaftspunkte Gastmannschaft'),
    t('Endergebnis'),
    t('[field_tm_board_points_team_1] : [field_tm_board_points_team_2]'),
    t('Ausrichter'),
    t('Saison'),
    t('Auswärtsmannschaft'),
    t('Page'),
    t('Datum'),
    t('Sp. läuft'),
    t('in Erg. anz.'),
  );
  $export['mannchaftsmatches'] = $view;

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
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_sp_verein_node';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_sp_verein_node';
  $handler->display->display_options['fields']['nid']['label'] = 'Node ID';
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
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Spieler Übersicht';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
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
    t('Page (with Page Title)'),
    t('Anzahl der Ergebnisse'),
    t('Verein'),
    t('Saison'),
    t('Jahres-ID'),
    t('Nation'),
    t('ELO'),
    t('Node ID'),
  );
  $export['players_overview'] = $view;

  return $export;
}
