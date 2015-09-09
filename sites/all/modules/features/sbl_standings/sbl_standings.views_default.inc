<?php
/**
 * @file
 * sbl_standings.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sbl_standings_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'match_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Ergebnisse';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ergebnisse';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_tm_team_1' => 'field_tm_team_1',
    'field_tm_team_2' => 'field_tm_team_2',
    'field_tm_team_points_tm_1' => 'field_tm_team_points_tm_1',
    'field_tm_team_points_tm_2' => 'field_tm_team_points_tm_2',
    'field_datum' => 'field_datum',
    'field_mt_player_1' => 'field_mt_player_1',
    'field_mt_player_2' => 'field_mt_player_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_tm_team_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tm_team_2' => array(
      'sortable' => 0,
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
    'field_tm_team_points_tm_2' => array(
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
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2>[field_tm_team_1] : [field_tm_team_2]</h2>
<div class="result">[field_tm_board_points_team_1] : [field_tm_board_points_team_2]</div>
<div class="datum">[field_datum]</div>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Relationship: Field collection item: Entity with the Einzelspiel (field_tm_game) */
  $handler->display->display_options['relationships']['field_tm_game_node']['id'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_tm_game_node']['field'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['label'] = 'Mannschaftsmatch with the field collection field_tm_game';
  /* Field: Content: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_2']['id'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['field'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_2']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  /* Field: Content: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  /* Field: Content: Mannschaftspunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['id'] = 'field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['table'] = 'field_data_field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['field'] = 'field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['element_label_colon'] = FALSE;
  /* Field: Content: Mannschaftspunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['id'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['table'] = 'field_data_field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['field'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['element_label_colon'] = FALSE;
  /* Field: Content: Datum */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_datum']['label'] = '';
  $handler->display->display_options['fields']['field_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'B';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Field collection item: Spieler 1 */
  $handler->display->display_options['fields']['field_mt_player_1']['id'] = 'field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['field'] = 'field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['label'] = '';
  $handler->display->display_options['fields']['field_mt_player_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mt_player_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Spieler 2 */
  $handler->display->display_options['fields']['field_mt_player_2']['id'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['field'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['label'] = '';
  $handler->display->display_options['fields']['field_mt_player_2']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_mt_points_player_1] : [field_mt_points_player_2] ';
  /* Contextual filter: Content: Saison (field_tm_saison) */
  $handler->display->display_options['arguments']['field_tm_saison_tid']['id'] = 'field_tm_saison_tid';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['field'] = 'field_tm_saison_tid';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_argument_options']['argument'] = '143';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Spieltag (field_tm_spieltag_1) */
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['id'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['field'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['default_argument_options']['argument'] = '15';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tm_spieltag_1_value']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['argument'] = '778';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_tm_game' => 'field_tm_game',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['match_results'] = array(
    t('Master'),
    t('Ergebnisse'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h2>[field_tm_team_1] : [field_tm_team_2]</h2>
<div class="result">[field_tm_board_points_team_1] : [field_tm_board_points_team_2]</div>
<div class="datum">[field_datum]</div>'),
    t('Mannschaftsmatch with the field collection field_tm_game'),
    t('B'),
    t('Ergebnis'),
    t('[field_mt_points_player_1] : [field_mt_points_player_2] '),
    t('Alle'),
    t('Block'),
  );
  $export['match_results'] = $view;

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
  $handler->display->display_options['title'] = 'Aktuelle Tabelle';
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
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
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
  $handler->display->display_options['fields']['title']['label'] = 'Titel';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Mannschaftspunkte';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return team_list_calculate_team_points($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Brettpunkte';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return team_list_calculate_board_points($row->nid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Sort criterion: Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert';
  $handler->display->display_options['sorts']['php']['expose']['label'] = 'PHP';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return team_list_sort_by_team_and_board_points($row1->php, $row2->php, $row1->php_1, $row2->php_1);';
  /* Contextual filter: Content: Saison (field_t_saison) */
  $handler->display->display_options['arguments']['field_t_saison_tid']['id'] = 'field_t_saison_tid';
  $handler->display->display_options['arguments']['field_t_saison_tid']['table'] = 'field_data_field_t_saison';
  $handler->display->display_options['arguments']['field_t_saison_tid']['field'] = 'field_t_saison_tid';
  $handler->display->display_options['arguments']['field_t_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_t_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_t_saison_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_t_saison_tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_t_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_t_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_t_saison_tid']['summary_options']['items_per_page'] = '25';
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
    t('Aktuelle Tabelle'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Titel'),
    t('Mannschaftspunkte'),
    t('Brettpunkte'),
    t('PHP'),
    t('Alle'),
    t('Page'),
  );
  $export['teams_leaderbord'] = $view;

  return $export;
}
