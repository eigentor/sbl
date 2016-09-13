<?php
/**
 * @file
 * sbl_crosstable.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sbl_crosstable_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rangliste_teams_crosstable';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Kreuztabelle';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aktuelle Tabelle';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
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
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Global: Ergebniszähler einer Ansicht */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'RNG';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '[counter].';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Anzahl gespielte Spiele */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Anzahl gespielte Spiele';
  $handler->display->display_options['fields']['php_2']['label'] = 'Spiele';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return team_list_calculate_played_games($row->nid);';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Siege */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Siege';
  $handler->display->display_options['fields']['php_3']['label'] = '+';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = 'return team_list_calculate_won_games($row->nid)';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print $value ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Unentschieden */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Unentschieden';
  $handler->display->display_options['fields']['php_4']['label'] = '=';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return team_list_calculate_drawn_games($row->nid)';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: Niederlagen */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'Niederlagen';
  $handler->display->display_options['fields']['php_5']['label'] = '-';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return team_list_calculate_lost_games($row->nid);';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Feld: Mannschaftspunkte PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Mannschaftspunkte PHP';
  $handler->display->display_options['fields']['php']['label'] = 'MP';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return team_list_calculate_team_points($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Brettpunkte PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Brettpunkte PHP';
  $handler->display->display_options['fields']['php_1']['label'] = 'BP';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return team_list_calculate_board_points($row->nid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Sortierkriterien: Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return team_list_sort_by_team_and_board_points($row1->php, $row2->php, $row1->php_1, $row2->php_1);';
  /* Sortierkriterien: Inhalt: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Kontextfilter: Inhalt: Saison (field_t_saison) */
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Kreuztabelle';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['row_class'] = 'table-[counter]';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'counter' => 'counter',
    'field_logo_icon' => 'field_logo_icon',
    'title' => 'title',
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
    'php_16' => 'php_16',
    'php_18' => 'php_18',
    'php_17' => 'php_17',
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
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_logo_icon' => array(
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
      'empty_column' => 0,
    ),
    'php_16' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_18' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_17' => array(
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
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'nid',
    'icon' => '',
    'icon_size' => '',
    'hide' => array(
      'nid' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'counter' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_logo_icon' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'title' => array(
        'phone' => 0,
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
      'php_16' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_18' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_17' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_1' => array(
        'phone' => 0,
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
  $handler->display->display_options['header']['area_text_custom']['content'] = '<span class="meister"> </span> Meister<br />
<span class="absteiger"> </span> Absteiger';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Fußbereich: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '(M) = Amtierender Meister, (N) = Neuling';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Beziehung: Inhalt: Ligenzuordnung (field_ligenzuordnung) */
  $handler->display->display_options['relationships']['field_ligenzuordnung_value']['id'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['relationships']['field_ligenzuordnung_value']['table'] = 'field_data_field_ligenzuordnung';
  $handler->display->display_options['relationships']['field_ligenzuordnung_value']['field'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['relationships']['field_ligenzuordnung_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Global: Ergebniszähler einer Ansicht */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '[counter].';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Feld: Inhalt: Logo Icon */
  $handler->display->display_options['fields']['field_logo_icon']['id'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['table'] = 'field_data_field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['field'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['label'] = '';
  $handler->display->display_options['fields']['field_logo_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_icon']['settings'] = array(
    'image_style' => 'vereinslogo_klein',
    'image_link' => 'content',
  );
  /* Feld: Field collection item: Ligastatus */
  $handler->display->display_options['fields']['field_ligastatus']['id'] = 'field_ligastatus';
  $handler->display->display_options['fields']['field_ligastatus']['table'] = 'field_data_field_ligastatus';
  $handler->display->display_options['fields']['field_ligastatus']['field'] = 'field_ligastatus';
  $handler->display->display_options['fields']['field_ligastatus']['relationship'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['fields']['field_ligastatus']['label'] = '';
  $handler->display->display_options['fields']['field_ligastatus']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ligastatus']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'text-left';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Punkte gegen 1, der Tabelle */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Punkte gegen 1, der Tabelle';
  $handler->display->display_options['fields']['php_2']['label'] = '1';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return crosstable_opponent($row->nid, 1);';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 2. der Tabelle */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Punkte gegen 2. der Tabelle';
  $handler->display->display_options['fields']['php_3']['label'] = '2';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = 'return crosstable_opponent($row->nid, 2);';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 3. der Tabelle */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Punkte gegen 3. der Tabelle';
  $handler->display->display_options['fields']['php_4']['label'] = '3';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return crosstable_opponent($row->nid, 3);';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 4. der Tabelle */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'Punkte gegen 4. der Tabelle';
  $handler->display->display_options['fields']['php_5']['label'] = '4';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return crosstable_opponent($row->nid, 4);';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 5. der Tabelle */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['ui_name'] = 'Punkte gegen 5. der Tabelle';
  $handler->display->display_options['fields']['php_6']['label'] = '5';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_value'] = 'return crosstable_opponent($row->nid, 5);';
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 6. der Tabelle */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['ui_name'] = 'Punkte gegen 6. der Tabelle';
  $handler->display->display_options['fields']['php_7']['label'] = '6';
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_value'] = 'return crosstable_opponent($row->nid, 6);';
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 7. der Tabelle */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['ui_name'] = 'Punkte gegen den 7. der Tabelle';
  $handler->display->display_options['fields']['php_8']['label'] = '7';
  $handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_8']['php_value'] = 'return crosstable_opponent($row->nid, 7);';
  $handler->display->display_options['fields']['php_8']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 8. der Tabelle */
  $handler->display->display_options['fields']['php_9']['id'] = 'php_9';
  $handler->display->display_options['fields']['php_9']['table'] = 'views';
  $handler->display->display_options['fields']['php_9']['field'] = 'php';
  $handler->display->display_options['fields']['php_9']['ui_name'] = 'Punkte gegen den 8. der Tabelle';
  $handler->display->display_options['fields']['php_9']['label'] = '8';
  $handler->display->display_options['fields']['php_9']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_9']['php_value'] = 'return crosstable_opponent($row->nid, 8);';
  $handler->display->display_options['fields']['php_9']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_9']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_9']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 9. der Tabelle */
  $handler->display->display_options['fields']['php_10']['id'] = 'php_10';
  $handler->display->display_options['fields']['php_10']['table'] = 'views';
  $handler->display->display_options['fields']['php_10']['field'] = 'php';
  $handler->display->display_options['fields']['php_10']['ui_name'] = 'Punkte gegen den 9. der Tabelle';
  $handler->display->display_options['fields']['php_10']['label'] = '9';
  $handler->display->display_options['fields']['php_10']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_10']['php_value'] = 'return crosstable_opponent($row->nid, 9);';
  $handler->display->display_options['fields']['php_10']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_10']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_10']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 10. der Tabelle */
  $handler->display->display_options['fields']['php_11']['id'] = 'php_11';
  $handler->display->display_options['fields']['php_11']['table'] = 'views';
  $handler->display->display_options['fields']['php_11']['field'] = 'php';
  $handler->display->display_options['fields']['php_11']['ui_name'] = 'Punkte gegen den 10. der Tabelle';
  $handler->display->display_options['fields']['php_11']['label'] = '10';
  $handler->display->display_options['fields']['php_11']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_11']['php_value'] = 'return crosstable_opponent($row->nid, 10);';
  $handler->display->display_options['fields']['php_11']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_11']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_11']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 11. der Tabelle */
  $handler->display->display_options['fields']['php_12']['id'] = 'php_12';
  $handler->display->display_options['fields']['php_12']['table'] = 'views';
  $handler->display->display_options['fields']['php_12']['field'] = 'php';
  $handler->display->display_options['fields']['php_12']['ui_name'] = 'Punkte gegen den 11. der Tabelle';
  $handler->display->display_options['fields']['php_12']['label'] = '11';
  $handler->display->display_options['fields']['php_12']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_12']['php_value'] = 'return crosstable_opponent($row->nid, 11);';
  $handler->display->display_options['fields']['php_12']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_12']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_12']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 12. der Tabelle */
  $handler->display->display_options['fields']['php_13']['id'] = 'php_13';
  $handler->display->display_options['fields']['php_13']['table'] = 'views';
  $handler->display->display_options['fields']['php_13']['field'] = 'php';
  $handler->display->display_options['fields']['php_13']['ui_name'] = 'Punkte gegen den 12. der Tabelle';
  $handler->display->display_options['fields']['php_13']['label'] = '12';
  $handler->display->display_options['fields']['php_13']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_13']['php_value'] = 'return crosstable_opponent($row->nid, 12);';
  $handler->display->display_options['fields']['php_13']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_13']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_13']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 13. der Tabelle */
  $handler->display->display_options['fields']['php_14']['id'] = 'php_14';
  $handler->display->display_options['fields']['php_14']['table'] = 'views';
  $handler->display->display_options['fields']['php_14']['field'] = 'php';
  $handler->display->display_options['fields']['php_14']['ui_name'] = 'Punkte gegen den 13. der Tabelle';
  $handler->display->display_options['fields']['php_14']['label'] = '13';
  $handler->display->display_options['fields']['php_14']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_14']['php_value'] = 'return crosstable_opponent($row->nid, 13);';
  $handler->display->display_options['fields']['php_14']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_14']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_14']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 14. der Tabelle */
  $handler->display->display_options['fields']['php_15']['id'] = 'php_15';
  $handler->display->display_options['fields']['php_15']['table'] = 'views';
  $handler->display->display_options['fields']['php_15']['field'] = 'php';
  $handler->display->display_options['fields']['php_15']['ui_name'] = 'Punkte gegen den 14. der Tabelle';
  $handler->display->display_options['fields']['php_15']['label'] = '14';
  $handler->display->display_options['fields']['php_15']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_15']['php_value'] = 'return crosstable_opponent($row->nid, 14);';
  $handler->display->display_options['fields']['php_15']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_15']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_15']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 15. der Tabelle */
  $handler->display->display_options['fields']['php_16']['id'] = 'php_16';
  $handler->display->display_options['fields']['php_16']['table'] = 'views';
  $handler->display->display_options['fields']['php_16']['field'] = 'php';
  $handler->display->display_options['fields']['php_16']['ui_name'] = 'Punkte gegen den 15. der Tabelle';
  $handler->display->display_options['fields']['php_16']['label'] = '15';
  $handler->display->display_options['fields']['php_16']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_16']['php_value'] = 'return crosstable_opponent($row->nid, 15);';
  $handler->display->display_options['fields']['php_16']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_16']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_16']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 16. der Tabelle */
  $handler->display->display_options['fields']['php_18']['id'] = 'php_18';
  $handler->display->display_options['fields']['php_18']['table'] = 'views';
  $handler->display->display_options['fields']['php_18']['field'] = 'php';
  $handler->display->display_options['fields']['php_18']['ui_name'] = 'Punkte gegen den 16. der Tabelle';
  $handler->display->display_options['fields']['php_18']['label'] = '16';
  $handler->display->display_options['fields']['php_18']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_18']['php_value'] = 'return crosstable_opponent($row->nid, 16);';
  $handler->display->display_options['fields']['php_18']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_18']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_18']['php_click_sortable'] = '';
  /* Feld: Anzahl der absolvierten Spiele */
  $handler->display->display_options['fields']['php_17']['id'] = 'php_17';
  $handler->display->display_options['fields']['php_17']['table'] = 'views';
  $handler->display->display_options['fields']['php_17']['field'] = 'php';
  $handler->display->display_options['fields']['php_17']['ui_name'] = 'Anzahl der absolvierten Spiele';
  $handler->display->display_options['fields']['php_17']['label'] = 'SP';
  $handler->display->display_options['fields']['php_17']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_17']['php_value'] = 'return team_list_calculate_played_games($row->nid);';
  $handler->display->display_options['fields']['php_17']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_17']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_17']['php_click_sortable'] = '';
  /* Feld: Mannschaftspunkte PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Mannschaftspunkte PHP';
  $handler->display->display_options['fields']['php']['label'] = 'MP';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return crosstable_calculate_team_points($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Brettpunkte PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Brettpunkte PHP';
  $handler->display->display_options['fields']['php_1']['label'] = 'BP';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return crosstable_calculate_board_points($row->nid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return team_list_sort_by_team_and_board_points($row1->php, $row2->php, $row1->php_1, $row2->php_1);';
  /* Sortierkriterien: Inhalt: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Field collection item: Saison (field_liga_saison) */
  $handler->display->display_options['arguments']['field_liga_saison_tid']['id'] = 'field_liga_saison_tid';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['table'] = 'field_data_field_liga_saison';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['field'] = 'field_liga_saison_tid';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['relationship'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['summary_options']['items_per_page'] = '25';
  /* Kontextfilter: Field collection item: Liga (field_liga_verein) */
  $handler->display->display_options['arguments']['field_liga_verein_tid']['id'] = 'field_liga_verein_tid';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['table'] = 'field_data_field_liga_verein';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['field'] = 'field_liga_verein_tid';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['relationship'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'kreuztabelle';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Kreuztabelle';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['row_class'] = 'table-2bl-[counter]';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'counter' => 'counter',
    'field_logo_icon' => 'field_logo_icon',
    'title' => 'title',
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
    'php_17' => 'php_17',
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
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_logo_icon' => array(
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
    'php_17' => array(
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
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'nid',
    'icon' => '',
    'icon_size' => '',
    'hide' => array(
      'nid' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'counter' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_logo_icon' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'title' => array(
        'phone' => 0,
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
      'php_17' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_1' => array(
        'phone' => 0,
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
  $handler->display->display_options['header']['area_text_custom']['content'] = '<span class="meister"> </span> Meister<br />
<span class="absteiger"> </span> Absteiger';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Fußbereich: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '(M) = Amtierender Meister, (N) = Neuling, (A) = Absteiger aus der Bundesliga ';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Beziehung: Inhalt: Ligenzuordnung (field_ligenzuordnung) */
  $handler->display->display_options['relationships']['field_ligenzuordnung_value']['id'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['relationships']['field_ligenzuordnung_value']['table'] = 'field_data_field_ligenzuordnung';
  $handler->display->display_options['relationships']['field_ligenzuordnung_value']['field'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['relationships']['field_ligenzuordnung_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Global: Ergebniszähler einer Ansicht */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '[counter].';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Feld: Inhalt: Logo Icon */
  $handler->display->display_options['fields']['field_logo_icon']['id'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['table'] = 'field_data_field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['field'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['label'] = '';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_logo_icon']['alter']['text'] = '<a href="/verein/[nid]/%1">[field_logo_icon]</a>';
  $handler->display->display_options['fields']['field_logo_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_icon']['settings'] = array(
    'image_style' => 'vereinslogo_klein',
    'image_link' => '',
  );
  /* Feld: Field collection item: Ligastatus */
  $handler->display->display_options['fields']['field_ligastatus']['id'] = 'field_ligastatus';
  $handler->display->display_options['fields']['field_ligastatus']['table'] = 'field_data_field_ligastatus';
  $handler->display->display_options['fields']['field_ligastatus']['field'] = 'field_ligastatus';
  $handler->display->display_options['fields']['field_ligastatus']['relationship'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['fields']['field_ligastatus']['label'] = '';
  $handler->display->display_options['fields']['field_ligastatus']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ligastatus']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/verein/[nid]/%1">[title]</a> [field_ligastatus]';
  $handler->display->display_options['fields']['title']['alter']['path'] = '/verein/[nid]/%1';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'text-left';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Punkte gegen 1, der Tabelle */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Punkte gegen 1, der Tabelle';
  $handler->display->display_options['fields']['php_2']['label'] = '1';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return crosstable_opponent($row->nid, 1);';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 2. der Tabelle */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Punkte gegen 2. der Tabelle';
  $handler->display->display_options['fields']['php_3']['label'] = '2';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = 'return crosstable_opponent($row->nid, 2);';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 3. der Tabelle */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Punkte gegen 3. der Tabelle';
  $handler->display->display_options['fields']['php_4']['label'] = '3';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return crosstable_opponent($row->nid, 3);';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 4. der Tabelle */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'Punkte gegen 4. der Tabelle';
  $handler->display->display_options['fields']['php_5']['label'] = '4';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return crosstable_opponent($row->nid, 4);';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 5. der Tabelle */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['ui_name'] = 'Punkte gegen 5. der Tabelle';
  $handler->display->display_options['fields']['php_6']['label'] = '5';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_value'] = 'return crosstable_opponent($row->nid, 5);';
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Feld: Punkte gegen 6. der Tabelle */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['ui_name'] = 'Punkte gegen 6. der Tabelle';
  $handler->display->display_options['fields']['php_7']['label'] = '6';
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_value'] = 'return crosstable_opponent($row->nid, 6);';
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 7. der Tabelle */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['ui_name'] = 'Punkte gegen den 7. der Tabelle';
  $handler->display->display_options['fields']['php_8']['label'] = '7';
  $handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_8']['php_value'] = 'return crosstable_opponent($row->nid, 7);';
  $handler->display->display_options['fields']['php_8']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 8. der Tabelle */
  $handler->display->display_options['fields']['php_9']['id'] = 'php_9';
  $handler->display->display_options['fields']['php_9']['table'] = 'views';
  $handler->display->display_options['fields']['php_9']['field'] = 'php';
  $handler->display->display_options['fields']['php_9']['ui_name'] = 'Punkte gegen den 8. der Tabelle';
  $handler->display->display_options['fields']['php_9']['label'] = '8';
  $handler->display->display_options['fields']['php_9']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_9']['php_value'] = 'return crosstable_opponent($row->nid, 8);';
  $handler->display->display_options['fields']['php_9']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_9']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_9']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 9. der Tabelle */
  $handler->display->display_options['fields']['php_10']['id'] = 'php_10';
  $handler->display->display_options['fields']['php_10']['table'] = 'views';
  $handler->display->display_options['fields']['php_10']['field'] = 'php';
  $handler->display->display_options['fields']['php_10']['ui_name'] = 'Punkte gegen den 9. der Tabelle';
  $handler->display->display_options['fields']['php_10']['label'] = '9';
  $handler->display->display_options['fields']['php_10']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_10']['php_value'] = 'return crosstable_opponent($row->nid, 9);';
  $handler->display->display_options['fields']['php_10']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_10']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_10']['php_click_sortable'] = '';
  /* Feld: Punkte gegen den 10. der Tabelle */
  $handler->display->display_options['fields']['php_11']['id'] = 'php_11';
  $handler->display->display_options['fields']['php_11']['table'] = 'views';
  $handler->display->display_options['fields']['php_11']['field'] = 'php';
  $handler->display->display_options['fields']['php_11']['ui_name'] = 'Punkte gegen den 10. der Tabelle';
  $handler->display->display_options['fields']['php_11']['label'] = '10';
  $handler->display->display_options['fields']['php_11']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_11']['php_value'] = 'return crosstable_opponent($row->nid, 10);';
  $handler->display->display_options['fields']['php_11']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_11']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_11']['php_click_sortable'] = '';
  /* Feld: Anzahl der absolvierten Spiele */
  $handler->display->display_options['fields']['php_17']['id'] = 'php_17';
  $handler->display->display_options['fields']['php_17']['table'] = 'views';
  $handler->display->display_options['fields']['php_17']['field'] = 'php';
  $handler->display->display_options['fields']['php_17']['ui_name'] = 'Anzahl der absolvierten Spiele';
  $handler->display->display_options['fields']['php_17']['label'] = 'SP';
  $handler->display->display_options['fields']['php_17']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_17']['php_value'] = 'return team_list_calculate_played_games($row->nid);';
  $handler->display->display_options['fields']['php_17']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_17']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_17']['php_click_sortable'] = '';
  /* Feld: Mannschaftspunkte PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Mannschaftspunkte PHP';
  $handler->display->display_options['fields']['php']['label'] = 'MP';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return crosstable_calculate_team_points($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Brettpunkte PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Brettpunkte PHP';
  $handler->display->display_options['fields']['php_1']['label'] = 'BP';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return crosstable_calculate_board_points($row->nid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return team_list_sort_by_team_and_board_points($row1->php, $row2->php, $row1->php_1, $row2->php_1);';
  /* Sortierkriterien: Inhalt: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Field collection item: Saison (field_liga_saison) */
  $handler->display->display_options['arguments']['field_liga_saison_tid']['id'] = 'field_liga_saison_tid';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['table'] = 'field_data_field_liga_saison';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['field'] = 'field_liga_saison_tid';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['relationship'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_liga_saison_tid']['summary_options']['items_per_page'] = '25';
  /* Kontextfilter: Field collection item: Liga (field_liga_verein) */
  $handler->display->display_options['arguments']['field_liga_verein_tid']['id'] = 'field_liga_verein_tid';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['table'] = 'field_data_field_liga_verein';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['field'] = 'field_liga_verein_tid';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['relationship'] = 'field_ligenzuordnung_value';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_liga_verein_tid']['title'] = '%2';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_liga_verein_tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_liga_verein_tid']['validate_options']['code'] = 'if($argument=="519") {
$handler->validated_title="Kreuztabelle 2. Bundesliga West";
return true;
}
elseif($argument=="518") {
$handler->validated_title="Kreuztabelle 2. Bundesliga Nord";
return true;
}
elseif($argument=="520") {
$handler->validated_title="Kreuztabelle 2. Bundesliga Ost";
return true;
}
elseif($argument=="521") {
$handler->validated_title="Kreuztabelle 2. Bundesliga Süd";
return true;
}
return false;';
  $handler->display->display_options['path'] = 'kreuztabelle-liga-2';
  $translatables['rangliste_teams_crosstable'] = array(
    t('Master'),
    t('Aktuelle Tabelle'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('RNG'),
    t('[counter].'),
    t('Team'),
    t('Spiele'),
    t('+'),
    t('='),
    t('-'),
    t('MP'),
    t('BP'),
    t('Alle'),
    t('Page'),
    t('Kreuztabelle'),
    t('<span class="meister"> </span> Meister<br />
<span class="absteiger"> </span> Absteiger'),
    t('(M) = Amtierender Meister, (N) = Neuling'),
    t('field collection item from field_ligenzuordnung'),
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
    t('16'),
    t('SP'),
    t('(M) = Amtierender Meister, (N) = Neuling, (A) = Absteiger aus der Bundesliga '),
    t('<a href="/verein/[nid]/%1">[field_logo_icon]</a>'),
    t('<a href="/verein/[nid]/%1">[title]</a> [field_ligastatus]'),
    t('%2'),
  );
  $export['rangliste_teams_crosstable'] = $view;

  return $export;
}
