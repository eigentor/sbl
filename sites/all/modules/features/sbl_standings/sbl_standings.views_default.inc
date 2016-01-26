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
  /* Field: Content: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
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
  /* Field: Jetzt live */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Jetzt live';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'jetzt live!';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'liveportal';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Livevideo */
  $handler->display->display_options['fields']['field_livevideo']['id'] = 'field_livevideo';
  $handler->display->display_options['fields']['field_livevideo']['table'] = 'field_data_field_livevideo';
  $handler->display->display_options['fields']['field_livevideo']['field'] = 'field_livevideo';
  $handler->display->display_options['fields']['field_livevideo']['label'] = '';
  $handler->display->display_options['fields']['field_livevideo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_livevideo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_livevideo']['alter']['path'] = '/liveportal?livevideo=[field_livevideo]';
  $handler->display->display_options['fields']['field_livevideo']['alter']['alt'] = 'Live-Video';
  $handler->display->display_options['fields']['field_livevideo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_livevideo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_livevideo']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_livevideo']['type'] = 'link_plain';
  /* Field: Content: Video Zusammenfassung */
  $handler->display->display_options['fields']['field_video_zusammenfas']['id'] = 'field_video_zusammenfas';
  $handler->display->display_options['fields']['field_video_zusammenfas']['table'] = 'field_data_field_video_zusammenfas';
  $handler->display->display_options['fields']['field_video_zusammenfas']['field'] = 'field_video_zusammenfas';
  $handler->display->display_options['fields']['field_video_zusammenfas']['label'] = '';
  $handler->display->display_options['fields']['field_video_zusammenfas']['alter']['link_class'] = 'fa fa-video-camera';
  $handler->display->display_options['fields']['field_video_zusammenfas']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_zusammenfas']['empty'] = '[field_livevideo]';
  $handler->display->display_options['fields']['field_video_zusammenfas']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Spielbericht */
  $handler->display->display_options['fields']['field_match_report']['id'] = 'field_match_report';
  $handler->display->display_options['fields']['field_match_report']['table'] = 'field_data_field_match_report';
  $handler->display->display_options['fields']['field_match_report']['field'] = 'field_match_report';
  $handler->display->display_options['fields']['field_match_report']['label'] = '';
  $handler->display->display_options['fields']['field_match_report']['alter']['link_class'] = 'fa fa-file-text';
  $handler->display->display_options['fields']['field_match_report']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_report']['settings'] = array(
    'link' => 1,
  );
  /* Field: Link zu Spielergebnisse */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Link zu Spielergebnisse';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
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
  $handler->display->display_options['fields']['field_vereinskuerzel']['alter']['alt'] = '[field_tm_team_1]';
  $handler->display->display_options['fields']['field_vereinskuerzel']['alter']['link_class'] = 'tooltip';
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
  /* Field: Jetzt live */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Jetzt live';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'jetzt live!';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'liveportal';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Livevideo */
  $handler->display->display_options['fields']['field_livevideo']['id'] = 'field_livevideo';
  $handler->display->display_options['fields']['field_livevideo']['table'] = 'field_data_field_livevideo';
  $handler->display->display_options['fields']['field_livevideo']['field'] = 'field_livevideo';
  $handler->display->display_options['fields']['field_livevideo']['label'] = '';
  $handler->display->display_options['fields']['field_livevideo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_livevideo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_livevideo']['alter']['path'] = '/liveportal?livevideo=[field_livevideo]';
  $handler->display->display_options['fields']['field_livevideo']['alter']['alt'] = 'Live-Video';
  $handler->display->display_options['fields']['field_livevideo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_livevideo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_livevideo']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_livevideo']['type'] = 'link_plain';
  /* Field: Content: Video Zusammenfassung */
  $handler->display->display_options['fields']['field_video_zusammenfas']['id'] = 'field_video_zusammenfas';
  $handler->display->display_options['fields']['field_video_zusammenfas']['table'] = 'field_data_field_video_zusammenfas';
  $handler->display->display_options['fields']['field_video_zusammenfas']['field'] = 'field_video_zusammenfas';
  $handler->display->display_options['fields']['field_video_zusammenfas']['label'] = '';
  $handler->display->display_options['fields']['field_video_zusammenfas']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_video_zusammenfas']['alter']['alt'] = 'Video';
  $handler->display->display_options['fields']['field_video_zusammenfas']['alter']['link_class'] = 'fa fa-video-camera tooltip';
  $handler->display->display_options['fields']['field_video_zusammenfas']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_zusammenfas']['empty'] = '[field_livevideo]';
  $handler->display->display_options['fields']['field_video_zusammenfas']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Spielbericht */
  $handler->display->display_options['fields']['field_match_report']['id'] = 'field_match_report';
  $handler->display->display_options['fields']['field_match_report']['table'] = 'field_data_field_match_report';
  $handler->display->display_options['fields']['field_match_report']['field'] = 'field_match_report';
  $handler->display->display_options['fields']['field_match_report']['label'] = '';
  $handler->display->display_options['fields']['field_match_report']['alter']['link_class'] = 'fa fa-file-text';
  $handler->display->display_options['fields']['field_match_report']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_report']['settings'] = array(
    'link' => 1,
  );
  /* Field: Link zu Spielergebnisse */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Link zu Spielergebnisse';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
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
    t('jetzt live!'),
    t('Live-Video'),
    t('[field_livevideo]'),
    t('Block'),
    t('[field_tm_team_1]'),
    t('Video'),
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
  $handler->display->display_options['pager']['type'] = 'none';
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
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2><a href="/verein/[field_tm_team_1_1]/!1" alt="[field_tm_team_1]">[field_tm_team_1]</a> : 
<a href="/verein/[field_tm_team_2_1]/!1" alt="[field_tm_team_2]">[field_tm_team_2]</a></h2>
<div class="result">[field_tm_board_points_team_1] : [field_tm_board_points_team_2]</div>
<div class="datum">[field_datum]</div>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<?php print results_only_pairings($view); ?>';
  /* Relationship: Field collection item: Entity with the Einzelspiel (field_tm_game) */
  $handler->display->display_options['relationships']['field_tm_game_node']['id'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_tm_game_node']['field'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['label'] = 'Mannschaftsmatch with the field collection field_tm_game';
  /* Field: Content: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Field: Mannschaft 1 als NID */
  $handler->display->display_options['fields']['field_tm_team_1_1']['id'] = 'field_tm_team_1_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_1_1']['ui_name'] = 'Mannschaft 1 als NID';
  $handler->display->display_options['fields']['field_tm_team_1_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_1_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['alter']['text'] = '[field_tm_team_1_1-target_id]';
  $handler->display->display_options['fields']['field_tm_team_1_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Mannschaft 2 als NID */
  $handler->display->display_options['fields']['field_tm_team_2_1']['id'] = 'field_tm_team_2_1';
  $handler->display->display_options['fields']['field_tm_team_2_1']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2_1']['field'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_2_1']['ui_name'] = 'Mannschaft 2 als NID';
  $handler->display->display_options['fields']['field_tm_team_2_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_2_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2_1']['alter']['text'] = '[field_tm_team_2_1-target_id]';
  $handler->display->display_options['fields']['field_tm_team_2_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_2_1']['settings'] = array(
    'link' => 0,
  );
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
  $handler->display->display_options['fields']['field_mt_player_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_1']['alter']['path'] = 'spieler/[field_mt_player_1-target_id]/!1';
  $handler->display->display_options['fields']['field_mt_player_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mt_player_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Spieler 2 */
  $handler->display->display_options['fields']['field_mt_player_2']['id'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['field'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['label'] = '';
  $handler->display->display_options['fields']['field_mt_player_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_2']['alter']['path'] = 'spieler/[field_mt_player_2-target_id]/!1';
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
  /* Filter criterion: Field collection item: Ergebnis (field_single_match_result) */
  $handler->display->display_options['filters']['field_single_match_result_value']['id'] = 'field_single_match_result_value';
  $handler->display->display_options['filters']['field_single_match_result_value']['table'] = 'field_data_field_single_match_result';
  $handler->display->display_options['filters']['field_single_match_result_value']['field'] = 'field_single_match_result_value';
  $handler->display->display_options['filters']['field_single_match_result_value']['operator'] = 'not empty';
  /* Filter criterion: Content: Spiel in Ergebnissen anzeigen (field_game_has_result) */
  $handler->display->display_options['filters']['field_game_has_result_value']['id'] = 'field_game_has_result_value';
  $handler->display->display_options['filters']['field_game_has_result_value']['table'] = 'field_data_field_game_has_result';
  $handler->display->display_options['filters']['field_game_has_result_value']['field'] = 'field_game_has_result_value';
  $handler->display->display_options['filters']['field_game_has_result_value']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['filters']['field_game_has_result_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Block Ergebnisse pro Mannschaft 2 */
  $handler = $view->new_display('block', 'Block Ergebnisse pro Mannschaft 2', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>[field_tm_spieltag_1]. Spieltag [field_tm_saison]</h3>
<h2><a href="/verein/[field_tm_team_1_1]/!1" alt="[field_tm_team_1]">[field_tm_team_1]</a> : 
<a href="/verein/[field_tm_team_2_1]/!1" alt="[field_tm_team_2]">[field_tm_team_2]</a></h2>
<div class="result">[field_tm_board_points_team_1] : [field_tm_board_points_team_2]</div>
<div class="datum">[field_datum]</div>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Field: Mannschaft 1 als NID */
  $handler->display->display_options['fields']['field_tm_team_1_1']['id'] = 'field_tm_team_1_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_1_1']['ui_name'] = 'Mannschaft 1 als NID';
  $handler->display->display_options['fields']['field_tm_team_1_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_1_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['alter']['text'] = '[field_tm_team_1_1-target_id]';
  $handler->display->display_options['fields']['field_tm_team_1_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Mannschaft 2 als NID */
  $handler->display->display_options['fields']['field_tm_team_2_1']['id'] = 'field_tm_team_2_1';
  $handler->display->display_options['fields']['field_tm_team_2_1']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2_1']['field'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_2_1']['ui_name'] = 'Mannschaft 2 als NID';
  $handler->display->display_options['fields']['field_tm_team_2_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_2_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2_1']['alter']['text'] = '[field_tm_team_2_1-target_id]';
  $handler->display->display_options['fields']['field_tm_team_2_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_2_1']['settings'] = array(
    'link' => 0,
  );
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
  $handler->display->display_options['fields']['field_mt_player_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_1']['alter']['path'] = 'spieler/[field_mt_player_1-target_id]/!1';
  $handler->display->display_options['fields']['field_mt_player_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mt_player_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Spieler 2 */
  $handler->display->display_options['fields']['field_mt_player_2']['id'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['field'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['label'] = '';
  $handler->display->display_options['fields']['field_mt_player_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mt_player_2']['alter']['path'] = 'spieler/[field_mt_player_2-target_id]/!1';
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
  $translatables['match_results'] = array(
    t('Master'),
    t('Ergebnisse'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h2><a href="/verein/[field_tm_team_1_1]/!1" alt="[field_tm_team_1]">[field_tm_team_1]</a> : 
<a href="/verein/[field_tm_team_2_1]/!1" alt="[field_tm_team_2]">[field_tm_team_2]</a></h2>
<div class="result">[field_tm_board_points_team_1] : [field_tm_board_points_team_2]</div>
<div class="datum">[field_datum]</div>'),
    t('Mannschaftsmatch with the field collection field_tm_game'),
    t('[field_tm_team_1_1-target_id]'),
    t('[field_tm_team_2_1-target_id]'),
    t('B'),
    t('Ergebnis'),
    t('[field_mt_points_player_1] : [field_mt_points_player_2] '),
    t('Alle'),
    t('Block'),
    t('Block Ergebnisse pro Mannschaft 2'),
    t('<h3>[field_tm_spieltag_1]. Spieltag [field_tm_saison]</h3>
<h2><a href="/verein/[field_tm_team_1_1]/!1" alt="[field_tm_team_1]">[field_tm_team_1]</a> : 
<a href="/verein/[field_tm_team_2_1]/!1" alt="[field_tm_team_2]">[field_tm_team_2]</a></h2>
<div class="result">[field_tm_board_points_team_1] : [field_tm_board_points_team_2]</div>
<div class="datum">[field_datum]</div>'),
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
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_tm_spieltag_1' => 'field_tm_spieltag_1',
    'field_datum' => 'field_datum',
    'field_ausrichter' => 'field_ausrichter',
    'field_tm_team_1' => 'field_tm_team_1',
    'nothing' => 'nothing',
    'field_tm_team_2' => 'field_tm_team_2',
    'field_tm_board_points_team_1' => 'field_tm_board_points_team_1',
    'field_tm_board_points_team_2' => 'field_tm_board_points_team_2',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_tm_spieltag_1' => array(
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
    'field_ausrichter' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tm_team_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
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
    'field_tm_board_points_team_1' => array(
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
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'field_tm_spieltag_1',
    'icon' => '',
    'icon_size' => '',
    'hide' => array(
      'field_tm_spieltag_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_datum' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_ausrichter' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_tm_team_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'nothing' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_tm_team_2' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_tm_board_points_team_1' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_tm_board_points_team_2' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'nothing_1' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
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
  /* Field: Content: Ausrichter */
  $handler->display->display_options['fields']['field_ausrichter']['id'] = 'field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['field'] = 'field_ausrichter';
  /* Field: Content: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = 'Verein';
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['path'] = 'verein/[field_tm_team_1-target_id]/!1';
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
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['path'] = 'verein/[field_tm_team_2-target_id]/!1';
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
  /* Sort criterion: Content: Ausrichter (field_ausrichter) */
  $handler->display->display_options['sorts']['field_ausrichter_value']['id'] = 'field_ausrichter_value';
  $handler->display->display_options['sorts']['field_ausrichter_value']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['sorts']['field_ausrichter_value']['field'] = 'field_ausrichter_value';
  /* Contextual filter: Content: Saison (field_tm_saison) */
  $handler->display->display_options['arguments']['field_tm_saison_tid']['id'] = 'field_tm_saison_tid';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['field'] = 'field_tm_saison_tid';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_tm_saison_tid']['default_argument_options']['index'] = '2';
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

  /* Display: Block Spielplan pro Mannschaft */
  $handler = $view->new_display('block', 'Block Spielplan pro Mannschaft', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'team_match' => 'team_match',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Mannschaft 2 (field_tm_team_2) */
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['id'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['field'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['value'] = array(
    229 => '229',
  );
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['group'] = 2;
  /* Filter criterion: Content: Mannschaft 1 (field_tm_team_1) */
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['id'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['field'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['value'] = array(
    229 => '229',
  );
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['group'] = 2;
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
    t('Ausrichter'),
    t('Verein'),
    t('vs'),
    t(':'),
    t('[field_tm_board_points_team_1] :'),
    t('Ergebnis'),
    t('[field_tm_board_points_team_1] [field_tm_board_points_team_2] '),
    t('Alle'),
    t('Page'),
    t('Block Spielplan pro Mannschaft'),
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
  /* Field: Anzahl gespielte Spiele */
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
  /* Field: Siege */
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
  /* Field: Unentschieden */
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
  /* Field: Niederlagen */
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
  /* Field: Mannschaftspunkte PHP */
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
  /* Field: Brettpunkte PHP */
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
  /* Sort criterion: Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert';
  $handler->display->display_options['sorts']['php']['expose']['label'] = 'PHP';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return team_list_sort_by_team_and_board_points($row1->php, $row2->php, $row1->php_1, $row2->php_1);';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tabelle';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'counter' => 'counter',
    'title' => 'title',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'php_4' => 'php_4',
    'php_5' => 'php_5',
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
    'expand' => 'title',
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
      'title' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_2' => array(
        'phone' => 0,
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
  $handler->display->display_options['fields']['title']['element_class'] = 'text-left';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Anzahl gespielte Spiele */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Anzahl gespielte Spiele';
  $handler->display->display_options['fields']['php_2']['label'] = 'SP';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return team_list_calculate_played_games($row->nid);';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Siege */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Siege';
  $handler->display->display_options['fields']['php_3']['label'] = 'G';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = 'return team_list_calculate_won_games($row->nid)';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print $value ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Unentschieden */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Unentschieden';
  $handler->display->display_options['fields']['php_4']['label'] = 'U';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return team_list_calculate_drawn_games($row->nid)';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Niederlagen */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'Niederlagen';
  $handler->display->display_options['fields']['php_5']['label'] = 'V';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return team_list_calculate_lost_games($row->nid);';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Mannschaftspunkte PHP */
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
  /* Field: Brettpunkte PHP */
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
  $handler->display->display_options['path'] = 'tabelle';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tabelle';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['php_output'] = '<div class="link_zur_aktuellen_tabelle"><a href="tabelle/<?php echo get_current_season(); ?>"><i class="fa fa-arrow-circle-o-right"></i>
Zur ausführlichen Tabelle</a></div>
';
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
  $handler->display->display_options['fields']['title']['element_class'] = 'text-left';
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
    t('Spiele'),
    t('+'),
    t('='),
    t('-'),
    t('MP'),
    t('BP'),
    t('PHP'),
    t('Alle'),
    t('Page'),
    t('Tabelle'),
    t('more'),
    t('SP'),
    t('G'),
    t('U'),
    t('V'),
    t('Block'),
    t('Pl.'),
    t('Verein'),
    t('Block Tabelle'),
  );
  $export['teams_leaderbord'] = $view;

  return $export;
}
