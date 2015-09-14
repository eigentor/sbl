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
  $view->name = 'live_bar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Live-Leiste';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_tm_team_1_target_id']['id'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['relationships']['field_tm_team_1_target_id']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['relationships']['field_tm_team_1_target_id']['field'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['relationships']['field_tm_team_1_target_id']['label'] = 'Heimmannschaft referenziert von field_tm_team_1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_tm_team_2_target_id']['id'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['relationships']['field_tm_team_2_target_id']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['relationships']['field_tm_team_2_target_id']['field'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['relationships']['field_tm_team_2_target_id']['label'] = 'Auswärtsmannschaft referenziert von field_tm_team_2';
  /* Field: Content: Saison */
  $handler->display->display_options['fields']['field_tm_saison']['id'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['field'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['label'] = '';
  $handler->display->display_options['fields']['field_tm_saison']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison']['alter']['text'] = '[field_tm_saison-tid]';
  $handler->display->display_options['fields']['field_tm_saison']['element_label_colon'] = FALSE;
  /* Field: Content: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['alter']['text'] = '[field_tm_spieltag_1-value]';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Field: Datum für Berechnung */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['ui_name'] = 'Datum für Berechnung';
  $handler->display->display_options['fields']['field_datum']['label'] = '';
  $handler->display->display_options['fields']['field_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Spiel läuft */
  $handler->display->display_options['fields']['field_spiel_laeuft']['id'] = 'field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['table'] = 'field_data_field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['field'] = 'field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['label'] = '';
  $handler->display->display_options['fields']['field_spiel_laeuft']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spiel_laeuft']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spiel_laeuft']['type'] = 'list_key';
  /* Field: Datum für Anzeige */
  $handler->display->display_options['fields']['field_datum_1']['id'] = 'field_datum_1';
  $handler->display->display_options['fields']['field_datum_1']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum_1']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum_1']['ui_name'] = 'Datum für Anzeige';
  $handler->display->display_options['fields']['field_datum_1']['label'] = '';
  $handler->display->display_options['fields']['field_datum_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum_1']['settings'] = array(
    'format_type' => 'very_short_time_separator',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Logo Heimmannschaft */
  $handler->display->display_options['fields']['field_logo_icon']['id'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['table'] = 'field_data_field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['field'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['relationship'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['fields']['field_logo_icon']['ui_name'] = 'Logo Heimmannschaft';
  $handler->display->display_options['fields']['field_logo_icon']['label'] = '';
  $handler->display->display_options['fields']['field_logo_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_icon']['settings'] = array(
    'image_style' => 'vereinslogo_klein',
    'image_link' => '',
  );
  /* Field: Vereinskürzel Heimmannschaft */
  $handler->display->display_options['fields']['field_vereinskuerzel']['id'] = 'field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel']['table'] = 'field_data_field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel']['field'] = 'field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel']['relationship'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['fields']['field_vereinskuerzel']['ui_name'] = 'Vereinskürzel Heimmannschaft';
  $handler->display->display_options['fields']['field_vereinskuerzel']['label'] = '';
  $handler->display->display_options['fields']['field_vereinskuerzel']['element_label_colon'] = FALSE;
  /* Field: Brettpunkte Heimmannschaft */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['ui_name'] = 'Brettpunkte Heimmannschaft';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['empty'] = '0';
  /* Field: Logo Auswärtsmannschaft */
  $handler->display->display_options['fields']['field_logo_team']['id'] = 'field_logo_team';
  $handler->display->display_options['fields']['field_logo_team']['table'] = 'field_data_field_logo_team';
  $handler->display->display_options['fields']['field_logo_team']['field'] = 'field_logo_team';
  $handler->display->display_options['fields']['field_logo_team']['relationship'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['fields']['field_logo_team']['ui_name'] = 'Logo Auswärtsmannschaft';
  $handler->display->display_options['fields']['field_logo_team']['label'] = '';
  $handler->display->display_options['fields']['field_logo_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_team']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_team']['settings'] = array(
    'image_style' => 'vereinslogo_klein',
    'image_link' => '',
  );
  /* Field: Vereinskürzel Auswärtsmannschaft */
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['id'] = 'field_vereinskuerzel_1';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['table'] = 'field_data_field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['field'] = 'field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['relationship'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['ui_name'] = 'Vereinskürzel Auswärtsmannschaft';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['label'] = '';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['element_label_colon'] = FALSE;
  /* Field: Brettpunkte Auswärtsmannschaft */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['ui_name'] = 'Brettpunkte Auswärtsmannschaft';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['empty'] = '0';
  /* Field: Content: Livevideo */
  $handler->display->display_options['fields']['field_livevideo']['id'] = 'field_livevideo';
  $handler->display->display_options['fields']['field_livevideo']['table'] = 'field_data_field_livevideo';
  $handler->display->display_options['fields']['field_livevideo']['field'] = 'field_livevideo';
  $handler->display->display_options['fields']['field_livevideo']['label'] = '';
  $handler->display->display_options['fields']['field_livevideo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_livevideo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_livevideo']['alter']['path'] = '/liveportal?livevideo=[field_livevideo]';
  $handler->display->display_options['fields']['field_livevideo']['alter']['alt'] = 'Link zum Live-Video';
  $handler->display->display_options['fields']['field_livevideo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_livevideo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_livevideo']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_livevideo']['type'] = 'link_plain';
  /* Field: Content: Video Zusammenfassung */
  $handler->display->display_options['fields']['field_video_zusammenfassung']['id'] = 'field_video_zusammenfassung';
  $handler->display->display_options['fields']['field_video_zusammenfassung']['table'] = 'field_data_field_video_zusammenfassung';
  $handler->display->display_options['fields']['field_video_zusammenfassung']['field'] = 'field_video_zusammenfassung';
  $handler->display->display_options['fields']['field_video_zusammenfassung']['label'] = '';
  $handler->display->display_options['fields']['field_video_zusammenfassung']['alter']['path'] = 'liveportal?[field_livevideo] ';
  $handler->display->display_options['fields']['field_video_zusammenfassung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_zusammenfassung']['empty'] = '[field_livevideo]';
  $handler->display->display_options['fields']['field_video_zusammenfassung']['click_sort_column'] = 'url';
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
  /* Filter criterion: Filter nach aktueller Saison und Datum des Spieltages */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['ui_name'] = 'Filter nach aktueller Saison und Datum des Spieltages';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'return check_current_season_date_matchday($row);';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['live_bar'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Heimmannschaft referenziert von field_tm_team_1'),
    t('Auswärtsmannschaft referenziert von field_tm_team_2'),
    t('[field_tm_saison-tid]'),
    t('[field_tm_spieltag_1-value]'),
    t('Link zum Live-Video'),
    t('[field_livevideo]'),
    t('Block'),
  );
  $export['live_bar'] = $view;

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
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['exclude'] = TRUE;
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
  $view->name = 'spielplan';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Spielplan';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Spielplan';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_tm_spieltag_1' => 'field_tm_spieltag_1',
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
    'field_tm_spieltag_1' => array(
      'sortable' => 0,
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
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = 'R';
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
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = 'Verein';
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'vs';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = ':';
  /* Field: Content: Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_2']['id'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['field'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['label'] = 'Verein';
  $handler->display->display_options['fields']['field_tm_team_2']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['text'] = '[field_tm_board_points_team_1] :';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  /* Field: Content: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  /* Field: Ergebnis zusammengesetzt aus Brettpunkten */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Ergebnis zusammengesetzt aus Brettpunkten';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Ergebnis';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_tm_board_points_team_1] [field_tm_board_points_team_2] ';
  /* Sort criterion: Content: Spieltag (field_tm_spieltag_1) */
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['id'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['field'] = 'field_tm_spieltag_1_value';
  /* Contextual filter: Content: Saison (field_tm_saison) */
  $handler->display->display_options['arguments']['field_tm_saison_tid']['id'] = 'field_tm_saison_tid';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['field'] = 'field_tm_saison_tid';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_argument_options']['code'] = 'return get_current_season();';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['path'] = 'spielplan';
  $translatables['spielplan'] = array(
    t('Master'),
    t('Spielplan'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('R'),
    t('Datum'),
    t('Verein'),
    t('vs'),
    t(':'),
    t('[field_tm_board_points_team_1] :'),
    t('Ergebnis'),
    t('[field_tm_board_points_team_1] [field_tm_board_points_team_2] '),
    t('Alle'),
    t('Page'),
  );
  $export['spielplan'] = $view;

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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'RNG';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '[counter].';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'MP';
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
  $handler->display->display_options['fields']['php_1']['label'] = 'BP';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tabelle';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Pl.';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '[counter].';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Verein';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'MP';
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
  $handler->display->display_options['fields']['php_1']['label'] = 'BP';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return team_list_calculate_board_points($row->nid);';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Saison (field_t_saison) */
  $handler->display->display_options['arguments']['field_t_saison_tid']['id'] = 'field_t_saison_tid';
  $handler->display->display_options['arguments']['field_t_saison_tid']['table'] = 'field_data_field_t_saison';
  $handler->display->display_options['arguments']['field_t_saison_tid']['field'] = 'field_t_saison_tid';
  $handler->display->display_options['arguments']['field_t_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_t_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_t_saison_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_t_saison_tid']['default_argument_options']['code'] = 'return get_current_season();';
  $handler->display->display_options['arguments']['field_t_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_t_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_t_saison_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Block Tabelle';
  $translatables['teams_leaderbord'] = array(
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
    t('MP'),
    t('BP'),
    t('PHP'),
    t('Alle'),
    t('Page'),
    t('more'),
    t('Block'),
    t('Tabelle'),
    t('Pl.'),
    t('Verein'),
    t('Block Tabelle'),
  );
  $export['teams_leaderbord'] = $view;

  return $export;
}
