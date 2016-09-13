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
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_tm_team_1_target_id']['id'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['relationships']['field_tm_team_1_target_id']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['relationships']['field_tm_team_1_target_id']['field'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['relationships']['field_tm_team_1_target_id']['label'] = 'Heimmannschaft referenziert von field_tm_team_1';
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_tm_team_2_target_id']['id'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['relationships']['field_tm_team_2_target_id']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['relationships']['field_tm_team_2_target_id']['field'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['relationships']['field_tm_team_2_target_id']['label'] = 'Auswärtsmannschaft referenziert von field_tm_team_2';
  /* Feld: Inhalt: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Inhalt: Saison */
  $handler->display->display_options['fields']['field_tm_saison']['id'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['field'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['label'] = '';
  $handler->display->display_options['fields']['field_tm_saison']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison']['alter']['text'] = '[field_tm_saison-tid]';
  $handler->display->display_options['fields']['field_tm_saison']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['alter']['text'] = '[field_tm_spieltag_1-value]';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Feld: Datum für Berechnung */
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
  /* Feld: Inhalt: Spiel läuft */
  $handler->display->display_options['fields']['field_spiel_laeuft']['id'] = 'field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['table'] = 'field_data_field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['field'] = 'field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['label'] = '';
  $handler->display->display_options['fields']['field_spiel_laeuft']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spiel_laeuft']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spiel_laeuft']['type'] = 'list_key';
  /* Feld: Datum für Anzeige */
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
  /* Feld: Logo Heimmannschaft */
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
  /* Feld: Vereinskürzel Heimmannschaft */
  $handler->display->display_options['fields']['field_vereinskuerzel']['id'] = 'field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel']['table'] = 'field_data_field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel']['field'] = 'field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel']['relationship'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['fields']['field_vereinskuerzel']['ui_name'] = 'Vereinskürzel Heimmannschaft';
  $handler->display->display_options['fields']['field_vereinskuerzel']['label'] = '';
  $handler->display->display_options['fields']['field_vereinskuerzel']['element_label_colon'] = FALSE;
  /* Feld: Brettpunkte Heimmannschaft */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['ui_name'] = 'Brettpunkte Heimmannschaft';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['empty'] = '0';
  /* Feld: Logo Auswärtsmannschaft */
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
  /* Feld: Vereinskürzel Auswärtsmannschaft */
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['id'] = 'field_vereinskuerzel_1';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['table'] = 'field_data_field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['field'] = 'field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['relationship'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['ui_name'] = 'Vereinskürzel Auswärtsmannschaft';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['label'] = '';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['element_label_colon'] = FALSE;
  /* Feld: Brettpunkte Auswärtsmannschaft */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['ui_name'] = 'Brettpunkte Auswärtsmannschaft';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['empty'] = '0';
  /* Feld: Jetzt live */
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
  /* Feld: Inhalt: Livevideo */
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
  /* Feld: Inhalt: Video Zusammenfassung */
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
  /* Feld: Inhalt: Spielbericht */
  $handler->display->display_options['fields']['field_match_report']['id'] = 'field_match_report';
  $handler->display->display_options['fields']['field_match_report']['table'] = 'field_data_field_match_report';
  $handler->display->display_options['fields']['field_match_report']['field'] = 'field_match_report';
  $handler->display->display_options['fields']['field_match_report']['label'] = '';
  $handler->display->display_options['fields']['field_match_report']['alter']['link_class'] = 'fa fa-file-text';
  $handler->display->display_options['fields']['field_match_report']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_report']['settings'] = array(
    'link' => 1,
  );
  /* Feld: Link zu Spielergebnisse */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Link zu Spielergebnisse';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Sortierkriterien: Inhalt: Beitragsdatum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'team_match' => 'team_match',
  );
  /* Filterkriterium: Inhalt: Saison (field_tm_saison) */
  $handler->display->display_options['filters']['field_tm_saison_tid']['id'] = 'field_tm_saison_tid';
  $handler->display->display_options['filters']['field_tm_saison_tid']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['filters']['field_tm_saison_tid']['field'] = 'field_tm_saison_tid';
  $handler->display->display_options['filters']['field_tm_saison_tid']['value'] = array(
    522 => '522',
  );
  $handler->display->display_options['filters']['field_tm_saison_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tm_saison_tid']['vocabulary'] = 'saison';
  /* Filterkriterium: Inhalt: Liga (field_liga) */
  $handler->display->display_options['filters']['field_liga_tid']['id'] = 'field_liga_tid';
  $handler->display->display_options['filters']['field_liga_tid']['table'] = 'field_data_field_liga';
  $handler->display->display_options['filters']['field_liga_tid']['field'] = 'field_liga_tid';
  $handler->display->display_options['filters']['field_liga_tid']['value'] = array(
    517 => '517',
  );
  $handler->display->display_options['filters']['field_liga_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_liga_tid']['vocabulary'] = 'liga';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Saison als TID */
  $handler->display->display_options['fields']['field_tm_saison_1']['id'] = 'field_tm_saison_1';
  $handler->display->display_options['fields']['field_tm_saison_1']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison_1']['field'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison_1']['ui_name'] = 'Saison als TID';
  $handler->display->display_options['fields']['field_tm_saison_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_saison_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison_1']['alter']['text'] = '[field_tm_saison_1-tid]';
  $handler->display->display_options['fields']['field_tm_saison_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_saison_1']['type'] = 'taxonomy_term_reference_plain';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Feld: Node-ID Heimmannschaft */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Node-ID Heimmannschaft';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Node-ID Auswärtsmannschaft */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['fields']['nid_1']['ui_name'] = 'Node-ID Auswärtsmannschaft';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Inhalt: Saison */
  $handler->display->display_options['fields']['field_tm_saison']['id'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['table'] = 'field_data_field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['field'] = 'field_tm_saison';
  $handler->display->display_options['fields']['field_tm_saison']['label'] = '';
  $handler->display->display_options['fields']['field_tm_saison']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_saison']['alter']['text'] = '[field_tm_saison-tid]';
  $handler->display->display_options['fields']['field_tm_saison']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['alter']['text'] = '[field_tm_spieltag_1-value]';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Feld: Datum für Berechnung */
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
  /* Feld: Inhalt: Spiel läuft */
  $handler->display->display_options['fields']['field_spiel_laeuft']['id'] = 'field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['table'] = 'field_data_field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['field'] = 'field_spiel_laeuft';
  $handler->display->display_options['fields']['field_spiel_laeuft']['label'] = '';
  $handler->display->display_options['fields']['field_spiel_laeuft']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spiel_laeuft']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spiel_laeuft']['type'] = 'list_key';
  /* Feld: Datum für Anzeige */
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
  /* Feld: Logo Heimmannschaft */
  $handler->display->display_options['fields']['field_logo_icon']['id'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['table'] = 'field_data_field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['field'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon']['relationship'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['fields']['field_logo_icon']['ui_name'] = 'Logo Heimmannschaft';
  $handler->display->display_options['fields']['field_logo_icon']['label'] = '';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_logo_icon']['alter']['path'] = 'verein/[nid]/[field_tm_saison_1] ';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_logo_icon']['alter']['link_class'] = 'tooltip';
  $handler->display->display_options['fields']['field_logo_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_icon']['settings'] = array(
    'image_style' => 'vereinslogo_klein',
    'image_link' => '',
  );
  /* Feld: Vereinskürzel Heimmannschaft */
  $handler->display->display_options['fields']['field_vereinskuerzel']['id'] = 'field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel']['table'] = 'field_data_field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel']['field'] = 'field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel']['relationship'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['fields']['field_vereinskuerzel']['ui_name'] = 'Vereinskürzel Heimmannschaft';
  $handler->display->display_options['fields']['field_vereinskuerzel']['label'] = '';
  $handler->display->display_options['fields']['field_vereinskuerzel']['alter']['alt'] = '[field_tm_team_1]';
  $handler->display->display_options['fields']['field_vereinskuerzel']['alter']['link_class'] = 'tooltip';
  $handler->display->display_options['fields']['field_vereinskuerzel']['element_label_colon'] = FALSE;
  /* Feld: Brettpunkte Heimmannschaft */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['ui_name'] = 'Brettpunkte Heimmannschaft';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['empty'] = '0';
  /* Feld: Logo Auswärtsmannschaft */
  $handler->display->display_options['fields']['field_logo_icon_1']['id'] = 'field_logo_icon_1';
  $handler->display->display_options['fields']['field_logo_icon_1']['table'] = 'field_data_field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon_1']['field'] = 'field_logo_icon';
  $handler->display->display_options['fields']['field_logo_icon_1']['relationship'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['fields']['field_logo_icon_1']['ui_name'] = 'Logo Auswärtsmannschaft';
  $handler->display->display_options['fields']['field_logo_icon_1']['label'] = '';
  $handler->display->display_options['fields']['field_logo_icon_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_logo_icon_1']['alter']['path'] = 'verein/[nid]/[field_tm_saison_1]';
  $handler->display->display_options['fields']['field_logo_icon_1']['alter']['alt'] = '[title_1]';
  $handler->display->display_options['fields']['field_logo_icon_1']['alter']['link_class'] = 'tooltip';
  $handler->display->display_options['fields']['field_logo_icon_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_icon_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_icon_1']['settings'] = array(
    'image_style' => 'vereinslogo_klein',
    'image_link' => '',
  );
  /* Feld: Vereinskürzel Auswärtsmannschaft */
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['id'] = 'field_vereinskuerzel_1';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['table'] = 'field_data_field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['field'] = 'field_vereinskuerzel';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['relationship'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['ui_name'] = 'Vereinskürzel Auswärtsmannschaft';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['label'] = '';
  $handler->display->display_options['fields']['field_vereinskuerzel_1']['element_label_colon'] = FALSE;
  /* Feld: Brettpunkte Auswärtsmannschaft */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['ui_name'] = 'Brettpunkte Auswärtsmannschaft';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['empty'] = '0';
  /* Feld: Jetzt live */
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
  /* Feld: Inhalt: Livevideo */
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
  /* Feld: Inhalt: Video Zusammenfassung */
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
  /* Feld: Inhalt: Spielbericht */
  $handler->display->display_options['fields']['field_match_report']['id'] = 'field_match_report';
  $handler->display->display_options['fields']['field_match_report']['table'] = 'field_data_field_match_report';
  $handler->display->display_options['fields']['field_match_report']['field'] = 'field_match_report';
  $handler->display->display_options['fields']['field_match_report']['label'] = '';
  $handler->display->display_options['fields']['field_match_report']['alter']['link_class'] = 'fa fa-file-text';
  $handler->display->display_options['fields']['field_match_report']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_report']['settings'] = array(
    'link' => 1,
  );
  /* Feld: Link zu Spielergebnisse */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Link zu Spielergebnisse';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'match-active-[field_spiel_laeuft]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $translatables['live_bar'] = array(
    t('Master'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Heimmannschaft referenziert von field_tm_team_1'),
    t('Auswärtsmannschaft referenziert von field_tm_team_2'),
    t('[field_tm_saison-tid]'),
    t('[field_tm_spieltag_1-value]'),
    t('jetzt live!'),
    t('Live-Video'),
    t('[field_livevideo]'),
    t('Block'),
    t('[field_tm_saison_1-tid]'),
    t('Titel'),
    t('[title]'),
    t('[field_tm_team_1]'),
    t('[title_1]'),
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
  /* Kopfbereich: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2><a href="/verein/[field_tm_team_1_1]/!1" alt="[field_tm_team_1]">[field_tm_team_1]</a> : 
<a href="/verein/[field_tm_team_2_1]/!1" alt="[field_tm_team_2]">[field_tm_team_2]</a></h2>
<div class="result">[field_tm_board_points_team_1] : [field_tm_board_points_team_2]</div>
<div class="datum">[field_datum]</div>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<?php print results_only_pairings($view); ?>';
  /* Beziehung: Field collection item: Entity with the Einzelspiel (field_tm_game) */
  $handler->display->display_options['relationships']['field_tm_game_node']['id'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_tm_game_node']['field'] = 'field_tm_game_node';
  $handler->display->display_options['relationships']['field_tm_game_node']['label'] = 'Mannschaftsmatch with the field collection field_tm_game';
  /* Feld: Inhalt: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Feld: Mannschaft 1 als NID */
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
  /* Feld: Mannschaft 2 als NID */
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
  /* Feld: Inhalt: Mannschaft 1 */
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
  /* Feld: Inhalt: Mannschaft 2 */
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
  /* Feld: Inhalt: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Mannschaftspunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['id'] = 'field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['table'] = 'field_data_field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['field'] = 'field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Mannschaftspunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['id'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['table'] = 'field_data_field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['field'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Datum */
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
  /* Feld: Global: Ergebniszähler einer Ansicht */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'B';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Feld: Field collection item: Spieler 1 */
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
  /* Feld: Field collection item: Spieler 2 */
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
  /* Feld: Ergebnis aus Spielerpunkten zusammengesetzt */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Ergebnis aus Spielerpunkten zusammengesetzt';
  $handler->display->display_options['fields']['nothing']['label'] = 'Ergebnis';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_mt_points_player_1] : [field_mt_points_player_2] ';
  /* Kontextfilter: Inhalt: Saison (field_tm_saison) */
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
  /* Kontextfilter: Inhalt: Spieltag (field_tm_spieltag_1) */
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
  /* Kontextfilter: Inhalt: Beitrags-ID */
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
  /* Filterkriterium: Field collection item: Feldname */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_tm_game' => 'field_tm_game',
  );
  /* Filterkriterium: Field collection item: Ergebnis (field_single_match_result) */
  $handler->display->display_options['filters']['field_single_match_result_value']['id'] = 'field_single_match_result_value';
  $handler->display->display_options['filters']['field_single_match_result_value']['table'] = 'field_data_field_single_match_result';
  $handler->display->display_options['filters']['field_single_match_result_value']['field'] = 'field_single_match_result_value';
  $handler->display->display_options['filters']['field_single_match_result_value']['operator'] = 'not empty';
  /* Filterkriterium: Inhalt: Spiel in Ergebnissen anzeigen (field_game_has_result) */
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Field collection item: Feldname */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_tm_game' => 'field_tm_game',
  );
  $handler->display->display_options['filters']['field_name']['group'] = 1;
  /* Filterkriterium: Field collection item: Ergebnis (field_single_match_result) */
  $handler->display->display_options['filters']['field_single_match_result_value']['id'] = 'field_single_match_result_value';
  $handler->display->display_options['filters']['field_single_match_result_value']['table'] = 'field_data_field_single_match_result';
  $handler->display->display_options['filters']['field_single_match_result_value']['field'] = 'field_single_match_result_value';
  $handler->display->display_options['filters']['field_single_match_result_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_single_match_result_value']['group'] = 1;
  /* Filterkriterium: Inhalt: Spiel in Ergebnissen anzeigen (field_game_has_result) */
  $handler->display->display_options['filters']['field_game_has_result_value']['id'] = 'field_game_has_result_value';
  $handler->display->display_options['filters']['field_game_has_result_value']['table'] = 'field_data_field_game_has_result';
  $handler->display->display_options['filters']['field_game_has_result_value']['field'] = 'field_game_has_result_value';
  $handler->display->display_options['filters']['field_game_has_result_value']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['filters']['field_game_has_result_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_game_has_result_value']['group'] = 1;

  /* Display: Block Ergebnisse pro Mannschaft 2 */
  $handler = $view->new_display('block', 'Block Ergebnisse pro Mannschaft 2', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Unfiltered text */
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
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Feld: Mannschaft 1 als NID */
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
  /* Feld: Mannschaft 2 als NID */
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
  /* Feld: Inhalt: Mannschaft 1 */
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
  /* Feld: Inhalt: Mannschaft 2 */
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
  /* Feld: Inhalt: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Mannschaftspunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['id'] = 'field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['table'] = 'field_data_field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['field'] = 'field_tm_team_points_tm_1';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_points_tm_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Mannschaftspunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['id'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['table'] = 'field_data_field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['field'] = 'field_tm_team_points_tm_2';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['relationship'] = 'field_tm_game_node';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_points_tm_2']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Datum */
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
  /* Feld: Global: Ergebniszähler einer Ansicht */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'B';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Feld: Field collection item: Spieler 1 */
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
  /* Feld: Field collection item: Spieler 2 */
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
  /* Feld: Ergebnis aus Spielerpunkten zusammengesetzt */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Ergebnis aus Spielerpunkten zusammengesetzt';
  $handler->display->display_options['fields']['nothing']['label'] = 'Ergebnis';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_mt_points_player_1] : [field_mt_points_player_2] ';
  $translatables['match_results'] = array(
    t('Master'),
    t('Ergebnisse'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
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
  $view->name = 'players_leaderboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Rangliste Spieler';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Topscorer der Saison';
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
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_fc_verein_1' => 'field_fc_verein_1',
    'nid' => 'nid',
    'nothing' => 'nothing',
    'title' => 'title',
    'field_pl_country' => 'field_pl_country',
    'field_fc_verein' => 'field_fc_verein',
    'field_pl_elo' => 'field_pl_elo',
    'php_1' => 'php_1',
    'php' => 'php',
    'php_2' => 'php_2',
    'php_4' => 'php_4',
    'php_3' => 'php_3',
    'php_5' => 'php_5',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_fc_verein_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
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
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
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
    'field_fc_verein' => array(
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
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_5' => array(
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
      'field_fc_verein_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'nid' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'nothing' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_pl_country' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_fc_verein' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_pl_elo' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_1' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'php_2' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_4' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_3' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_5' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
    ),
  );
  /* Kopfbereich: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Erklärungstext';
  $handler->display->display_options['header']['area_text_custom']['content'] = 'Spieler mit weniger als drei gewerteten Partien sind ausgeblendet, um eine repräsentative Rangfolge erstellen zu können.
Die anderen Spieler sind nach der ELO-Performance sortiert.<br />Die ELO-Gewinne und -Verluste sind gerundete Näherungswerte.<br />
Klicken Sie auf die jeweilgen Spaltenüberschriften, um danach auf- oder absteigend zu sortieren.<br /><br />';
  /* Beziehung: Inhalt: Saisondaten Spieler (field_sp_verein) */
  $handler->display->display_options['relationships']['field_sp_verein_value']['id'] = 'field_sp_verein_value';
  $handler->display->display_options['relationships']['field_sp_verein_value']['table'] = 'field_data_field_sp_verein';
  $handler->display->display_options['relationships']['field_sp_verein_value']['field'] = 'field_sp_verein_value';
  $handler->display->display_options['relationships']['field_sp_verein_value']['delta'] = '-1';
  /* Feld: Verein des Spielers: Node ID */
  $handler->display->display_options['fields']['field_fc_verein_1']['id'] = 'field_fc_verein_1';
  $handler->display->display_options['fields']['field_fc_verein_1']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein_1']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein_1']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['fields']['field_fc_verein_1']['ui_name'] = 'Verein des Spielers: Node ID';
  $handler->display->display_options['fields']['field_fc_verein_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fc_verein_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_fc_verein_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Node-ID des Spielers */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Node-ID des Spielers';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'RNG';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Spieler';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'spieler/[nid]/!1';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'text-left';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Field collection item: Nation */
  $handler->display->display_options['fields']['field_pl_country']['id'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['table'] = 'field_data_field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['field'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['fields']['field_pl_country']['label'] = 'Nat.';
  $handler->display->display_options['fields']['field_pl_country']['type'] = 'country_icon';
  $handler->display->display_options['fields']['field_pl_country']['settings'] = array(
    'countryiconset' => 'icon_shiny',
    'property' => '',
  );
  /* Feld: Field collection item: Verein */
  $handler->display->display_options['fields']['field_fc_verein']['id'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['fields']['field_fc_verein']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_fc_verein']['alter']['path'] = 'verein/[field_fc_verein-target_id]/!1';
  $handler->display->display_options['fields']['field_fc_verein']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Field collection item: ELO */
  $handler->display->display_options['fields']['field_pl_elo']['id'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['table'] = 'field_data_field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['field'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['fields']['field_pl_elo']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Feld: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Punkte';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return player_calculate_won_points($row->nid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
  print $value;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Anzahl gespielte Spiele */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Anzahl gespielte Spiele';
  $handler->display->display_options['fields']['php']['label'] = 'SP';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return player_calculate_played_games($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Prozentzahl erreichter Punkte pro Spiel */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Prozentzahl erreichter Punkte pro Spiel';
  $handler->display->display_options['fields']['php_2']['label'] = '%';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return player_percentage($row->nid);';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Elo-Schnitt */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Elo-Schnitt';
  $handler->display->display_options['fields']['php_4']['label'] = 'Elo-Ø';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return player_elo_average($row->nid);';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: Elo-Performance */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Elo-Performance';
  $handler->display->display_options['fields']['php_3']['label'] = 'Elo-Perf.';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = 'return player_elo_performance($row->nid);';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: ELO Veränderung */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'ELO Veränderung';
  $handler->display->display_options['fields']['php_5']['label'] = 'ELO +/-';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return calculate_elo_change($row->nid)';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Sortierkriterien: Sort by ELO Performance */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Sort by ELO Performance';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return players_sort_leaderboard($row1->php_3, $row2->php_3);';
  /* Sortierkriterien: Inhalt: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Kontextfilter: Field collection item: Saison (field_saison) */
  $handler->display->display_options['arguments']['field_saison_tid']['id'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['table'] = 'field_data_field_saison';
  $handler->display->display_options['arguments']['field_saison_tid']['field'] = 'field_saison_tid';
  $handler->display->display_options['arguments']['field_saison_tid']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['arguments']['field_saison_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_saison_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_saison_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_saison_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_saison_tid']['summary_options']['items_per_page'] = '25';
  /* Kontextfilter: Field collection item: Liga (field_pl_league) */
  $handler->display->display_options['arguments']['field_pl_league_tid']['id'] = 'field_pl_league_tid';
  $handler->display->display_options['arguments']['field_pl_league_tid']['table'] = 'field_data_field_pl_league';
  $handler->display->display_options['arguments']['field_pl_league_tid']['field'] = 'field_pl_league_tid';
  $handler->display->display_options['arguments']['field_pl_league_tid']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['arguments']['field_pl_league_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_pl_league_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_pl_league_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_pl_league_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_pl_league_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_pl_league_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_pl_league_tid']['summary_options']['items_per_page'] = '25';
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
  /* Filterkriterium: Hide the players with less than x played games */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['ui_name'] = 'Hide the players with less than x played games';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'return filter_players_leaderboard($row->php);';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Verein des Spielers: Node ID */
  $handler->display->display_options['fields']['field_fc_verein_1']['id'] = 'field_fc_verein_1';
  $handler->display->display_options['fields']['field_fc_verein_1']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein_1']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein_1']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['fields']['field_fc_verein_1']['ui_name'] = 'Verein des Spielers: Node ID';
  $handler->display->display_options['fields']['field_fc_verein_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fc_verein_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_fc_verein_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Node-ID des Spielers */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Node-ID des Spielers';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'RNG';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Spieler';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'spieler/[nid]/!1';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'text-left';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Field collection item: Nation */
  $handler->display->display_options['fields']['field_pl_country']['id'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['table'] = 'field_data_field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['field'] = 'field_pl_country';
  $handler->display->display_options['fields']['field_pl_country']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['fields']['field_pl_country']['label'] = 'Nat.';
  $handler->display->display_options['fields']['field_pl_country']['type'] = 'country_icon';
  $handler->display->display_options['fields']['field_pl_country']['settings'] = array(
    'countryiconset' => 'icon_shiny',
    'property' => '',
  );
  /* Feld: Field collection item: Verein */
  $handler->display->display_options['fields']['field_fc_verein']['id'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['table'] = 'field_data_field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['field'] = 'field_fc_verein';
  $handler->display->display_options['fields']['field_fc_verein']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['fields']['field_fc_verein']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_fc_verein']['alter']['path'] = 'verein/[field_fc_verein-target_id]/!1';
  $handler->display->display_options['fields']['field_fc_verein']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Field collection item: ELO */
  $handler->display->display_options['fields']['field_pl_elo']['id'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['table'] = 'field_data_field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['field'] = 'field_pl_elo';
  $handler->display->display_options['fields']['field_pl_elo']['relationship'] = 'field_sp_verein_value';
  $handler->display->display_options['fields']['field_pl_elo']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Feld: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Punkte';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return player_calculate_won_points($row->nid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
  print number_format(floatval($value),1,\'.\',\'\');
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Anzahl gespielte Spiele */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Anzahl gespielte Spiele';
  $handler->display->display_options['fields']['php']['label'] = 'SP';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return player_calculate_played_games($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Prozentzahl erreichter Punkte pro Spiel */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Prozentzahl erreichter Punkte pro Spiel';
  $handler->display->display_options['fields']['php_2']['label'] = '%';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return player_percentage($row->nid);';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Elo-Schnitt */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Elo-Schnitt';
  $handler->display->display_options['fields']['php_4']['label'] = 'Elo-Ø';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return player_elo_average($row->nid);';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: Elo-Performance */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Elo-Performance';
  $handler->display->display_options['fields']['php_3']['label'] = 'Elo-Perf.';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = 'return player_elo_performance($row->nid);';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: ELO Veränderung */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'ELO Veränderung';
  $handler->display->display_options['fields']['php_5']['label'] = 'ELO +/-';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return calculate_elo_change($row->nid)';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  $handler->display->display_options['path'] = 'spieler-rangliste';
  $translatables['players_leaderboard'] = array(
    t('Master'),
    t('Topscorer der Saison'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Erklärungstext'),
    t('Spieler mit weniger als drei gewerteten Partien sind ausgeblendet, um eine repräsentative Rangfolge erstellen zu können.
Die anderen Spieler sind nach der ELO-Performance sortiert.<br />Die ELO-Gewinne und -Verluste sind gerundete Näherungswerte.<br />
Klicken Sie auf die jeweilgen Spaltenüberschriften, um danach auf- oder absteigend zu sortieren.<br /><br />'),
    t('field collection item from field_sp_verein'),
    t('Verein'),
    t('Beitrags-ID'),
    t('RNG'),
    t('Spieler'),
    t('Nat.'),
    t('ELO'),
    t('Punkte'),
    t('SP'),
    t('%'),
    t('Elo-Ø'),
    t('Elo-Perf.'),
    t('ELO +/-'),
    t('Alle'),
    t('Page'),
  );
  $export['players_leaderboard'] = $view;

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
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_tm_spieltag_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
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
  /* Feld: Inhalt: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = 'R';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Datum */
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
  /* Feld: Inhalt: Ausrichter */
  $handler->display->display_options['fields']['field_ausrichter']['id'] = 'field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['field'] = 'field_ausrichter';
  /* Feld: Inhalt: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = 'Verein';
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['path'] = 'verein/[field_tm_team_1-target_id]/!1';
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'vs';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = ':';
  /* Feld: Inhalt: Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_2']['id'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['field'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['label'] = 'Verein';
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['path'] = 'verein/[field_tm_team_2-target_id]/!1';
  $handler->display->display_options['fields']['field_tm_team_2']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Inhalt: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['text'] = '[field_tm_board_points_team_1] :';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  /* Feld: Ergebnis zusammengesetzt aus Brettpunkten */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Ergebnis zusammengesetzt aus Brettpunkten';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Ergebnis';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_tm_board_points_team_1] [field_tm_board_points_team_2] ';
  /* Sortierkriterien: Inhalt: Spieltag (field_tm_spieltag_1) */
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['id'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['field'] = 'field_tm_spieltag_1_value';
  /* Sortierkriterien: Inhalt: Ausrichter (field_ausrichter) */
  $handler->display->display_options['sorts']['field_ausrichter_value']['id'] = 'field_ausrichter_value';
  $handler->display->display_options['sorts']['field_ausrichter_value']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['sorts']['field_ausrichter_value']['field'] = 'field_ausrichter_value';
  /* Kontextfilter: Inhalt: Saison (field_tm_saison) */
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
    'team_match' => 'team_match',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = 'R';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Datum */
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
  /* Feld: Inhalt: Ausrichter */
  $handler->display->display_options['fields']['field_ausrichter']['id'] = 'field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['field'] = 'field_ausrichter';
  /* Feld: Inhalt: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = 'Heim';
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['path'] = 'verein/[field_tm_team_1-target_id]/!1';
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = ':';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_2']['id'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['field'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['label'] = 'Gast';
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['path'] = 'verein/[field_tm_team_2-target_id]/!1';
  $handler->display->display_options['fields']['field_tm_team_2']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Inhalt: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['text'] = '[field_tm_board_points_team_1] :';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  /* Feld: Ergebnis zusammengesetzt aus Brettpunkten */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Ergebnis zusammengesetzt aus Brettpunkten';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Ergebnis';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_tm_board_points_team_1] [field_tm_board_points_team_2] ';
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
    'team_match' => 'team_match',
  );
  /* Filterkriterium: Inhalt: Liga (field_liga) */
  $handler->display->display_options['filters']['field_liga_tid']['id'] = 'field_liga_tid';
  $handler->display->display_options['filters']['field_liga_tid']['table'] = 'field_data_field_liga';
  $handler->display->display_options['filters']['field_liga_tid']['field'] = 'field_liga_tid';
  $handler->display->display_options['filters']['field_liga_tid']['value'] = array(
    517 => '517',
  );
  $handler->display->display_options['filters']['field_liga_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_liga_tid']['vocabulary'] = 'liga';
  $handler->display->display_options['path'] = 'spielplan';

  /* Display: Block Spielplan pro Mannschaft */
  $handler = $view->new_display('block', 'Block Spielplan pro Mannschaft', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = 'R';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Datum */
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
  /* Feld: Inhalt: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1_1']['id'] = 'field_tm_team_1_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_1_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Inhalt: Ausrichter */
  $handler->display->display_options['fields']['field_ausrichter']['id'] = 'field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['field'] = 'field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['empty'] = '[field_tm_team_1_1]';
  $handler->display->display_options['fields']['field_ausrichter']['hide_alter_empty'] = FALSE;
  /* Feld: Inhalt: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = 'Verein';
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['path'] = 'verein/[field_tm_team_1-target_id]/!1';
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = ':';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_2']['id'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['field'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['label'] = 'Verein';
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['path'] = 'verein/[field_tm_team_2-target_id]/!1';
  $handler->display->display_options['fields']['field_tm_team_2']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Inhalt: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['text'] = '[field_tm_board_points_team_1] :';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  /* Feld: Ergebnis zusammengesetzt aus Brettpunkten */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Ergebnis zusammengesetzt aus Brettpunkten';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Ergebnis';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_tm_board_points_team_1] [field_tm_board_points_team_2] ';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'team_match' => 'team_match',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Inhalt: Mannschaft 2 (field_tm_team_2) */
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['id'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['field'] = 'field_tm_team_2_target_id';
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['value'] = array(
    229 => '229',
  );
  $handler->display->display_options['filters']['field_tm_team_2_target_id']['group'] = 2;
  /* Filterkriterium: Inhalt: Mannschaft 1 (field_tm_team_1) */
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['id'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['field'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['value'] = array(
    229 => '229',
  );
  $handler->display->display_options['filters']['field_tm_team_1_target_id']['group'] = 2;

  /* Display: Page 2. Liga */
  $handler = $view->new_display('page', 'Page 2. Liga', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Spieltag */
  $handler->display->display_options['fields']['field_tm_spieltag_1']['id'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['field'] = 'field_tm_spieltag_1';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['label'] = 'R';
  $handler->display->display_options['fields']['field_tm_spieltag_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Datum */
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
  /* Feld: Inhalt: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1_1']['id'] = 'field_tm_team_1_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_team_1_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tm_team_1_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Inhalt: Ausrichter */
  $handler->display->display_options['fields']['field_ausrichter']['id'] = 'field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['field'] = 'field_ausrichter';
  $handler->display->display_options['fields']['field_ausrichter']['empty'] = '[field_tm_team_1_1]';
  $handler->display->display_options['fields']['field_ausrichter']['hide_alter_empty'] = FALSE;
  /* Feld: Inhalt: Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_team_1']['id'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['field'] = 'field_tm_team_1';
  $handler->display->display_options['fields']['field_tm_team_1']['label'] = 'Heim';
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_1']['alter']['path'] = 'verein/[field_tm_team_1-target_id]/!1';
  $handler->display->display_options['fields']['field_tm_team_1']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = ':';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_team_2']['id'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['table'] = 'field_data_field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['field'] = 'field_tm_team_2';
  $handler->display->display_options['fields']['field_tm_team_2']['label'] = 'Gast';
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_tm_team_2']['alter']['path'] = 'verein/[field_tm_team_2-target_id]/!1';
  $handler->display->display_options['fields']['field_tm_team_2']['settings'] = array(
    'link' => 0,
  );
  /* Feld: Inhalt: Brettpunkte Mannschaft 1 */
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['id'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['table'] = 'field_data_field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['field'] = 'field_tm_board_points_team_1';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['alter']['text'] = '[field_tm_board_points_team_1] :';
  $handler->display->display_options['fields']['field_tm_board_points_team_1']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Brettpunkte Mannschaft 2 */
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['id'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['table'] = 'field_data_field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['field'] = 'field_tm_board_points_team_2';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['label'] = '';
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tm_board_points_team_2']['element_label_colon'] = FALSE;
  /* Feld: Ergebnis zusammengesetzt aus Brettpunkten */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Ergebnis zusammengesetzt aus Brettpunkten';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Ergebnis';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_tm_board_points_team_1] [field_tm_board_points_team_2] ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Inhalt: Spieltag (field_tm_spieltag_1) */
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['id'] = 'field_tm_spieltag_1_value';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['table'] = 'field_data_field_tm_spieltag_1';
  $handler->display->display_options['sorts']['field_tm_spieltag_1_value']['field'] = 'field_tm_spieltag_1_value';
  /* Sortierkriterien: Inhalt: Ausrichter (field_ausrichter) */
  $handler->display->display_options['sorts']['field_ausrichter_value']['id'] = 'field_ausrichter_value';
  $handler->display->display_options['sorts']['field_ausrichter_value']['table'] = 'field_data_field_ausrichter';
  $handler->display->display_options['sorts']['field_ausrichter_value']['field'] = 'field_ausrichter_value';
  /* Sortierkriterien: Inhalt: Mannschaft 1 (field_tm_team_1) */
  $handler->display->display_options['sorts']['field_tm_team_1_target_id']['id'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['sorts']['field_tm_team_1_target_id']['table'] = 'field_data_field_tm_team_1';
  $handler->display->display_options['sorts']['field_tm_team_1_target_id']['field'] = 'field_tm_team_1_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Saison (field_tm_saison) */
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
  /* Kontextfilter: Inhalt: Liga (field_liga) */
  $handler->display->display_options['arguments']['field_liga_tid']['id'] = 'field_liga_tid';
  $handler->display->display_options['arguments']['field_liga_tid']['table'] = 'field_data_field_liga';
  $handler->display->display_options['arguments']['field_liga_tid']['field'] = 'field_liga_tid';
  $handler->display->display_options['arguments']['field_liga_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_liga_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_liga_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_liga_tid']['title'] = '%2';
  $handler->display->display_options['arguments']['field_liga_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_liga_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_liga_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_liga_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_liga_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_liga_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_liga_tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_liga_tid']['validate_options']['code'] = 'if($argument=="519") {
$handler->validated_title="Spielplan 2. Bundesliga West";
return true;
}
elseif($argument=="518") {
$handler->validated_title="Spielplan 2. Bundesliga Nord";
return true;
}
elseif($argument=="520") {
$handler->validated_title="Spielplan 2. Bundesliga Ost";
return true;
}
elseif($argument=="521") {
$handler->validated_title="Spielplan 2. Bundesliga Süd";
return true;
}
return false;';
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
    'team_match' => 'team_match',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'spielplan-liga-2';
  $translatables['spielplan'] = array(
    t('Master'),
    t('Spielplan'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
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
    t('Heim'),
    t('Gast'),
    t('Block Spielplan pro Mannschaft'),
    t('[field_tm_team_1_1]'),
    t('Page 2. Liga'),
    t('%2'),
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
  $handler->display->display_options['sorts']['php']['expose']['label'] = 'PHP';
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
  $handler->display->display_options['title'] = 'Tabelle';
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
      'field_logo_icon' => array(
        'phone' => 'phone',
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
  $handler->display->display_options['fields']['field_ligastatus']['exclude'] = TRUE;
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
  /* Feld: Anzahl gespielte Spiele */
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
  /* Feld: Siege */
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
  /* Feld: Unentschieden */
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
  /* Feld: Niederlagen */
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert';
  $handler->display->display_options['sorts']['php']['expose']['label'] = 'PHP';
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
  $handler->display->display_options['path'] = 'tabelle_gesamt';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tabelle';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Fußbereich: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['php_output'] = '<div class="link_zur_aktuellen_tabelle"><a href="/tabelle/<?php echo get_current_season(); ?>"><i class="fa fa-arrow-circle-o-right"></i>
Zur ausführlichen Tabelle</a></div>
';
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
  $handler->display->display_options['fields']['counter']['label'] = 'Pl.';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '[counter].';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Verein';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'text-left';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Vereinsname kurz */
  $handler->display->display_options['fields']['field_vereinsname_kurz']['id'] = 'field_vereinsname_kurz';
  $handler->display->display_options['fields']['field_vereinsname_kurz']['table'] = 'field_data_field_vereinsname_kurz';
  $handler->display->display_options['fields']['field_vereinsname_kurz']['field'] = 'field_vereinsname_kurz';
  $handler->display->display_options['fields']['field_vereinsname_kurz']['label'] = 'Verein';
  $handler->display->display_options['fields']['field_vereinsname_kurz']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_vereinsname_kurz']['alter']['text'] = '<a href="/verein/[nid]/!1">[field_vereinsname_kurz]</a>';
  $handler->display->display_options['fields']['field_vereinsname_kurz']['element_class'] = 'text-left';
  $handler->display->display_options['fields']['field_vereinsname_kurz']['element_label_colon'] = FALSE;
  /* Feld: Global: PHP */
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
  /* Feld: Global: PHP */
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
  /* Kontextfilter: Inhalt: Saison (field_t_saison) */
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

  /* Display: Newsfeed */
  $handler = $view->new_display('feed', 'Newsfeed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'counter',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'node_rss';
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
  /* Feld: Inhalt: Vereinsname kurz */
  $handler->display->display_options['fields']['field_vereinsname_kurz']['id'] = 'field_vereinsname_kurz';
  $handler->display->display_options['fields']['field_vereinsname_kurz']['table'] = 'field_data_field_vereinsname_kurz';
  $handler->display->display_options['fields']['field_vereinsname_kurz']['field'] = 'field_vereinsname_kurz';
  $handler->display->display_options['fields']['field_vereinsname_kurz']['label'] = 'Vereinsname';
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Saison (field_t_saison) */
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
  $handler->display->display_options['path'] = 'tabelle.xml';

  /* Display: Brett 1-4 */
  $handler = $view->new_display('page', 'Brett 1-4', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tabelle Brett 1-4';
  $handler->display->display_options['display_description'] = 'Ansicht für Brett 1-4';
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
      'field_logo_icon' => array(
        'phone' => 'phone',
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = 'Diese Tabelle zeigt die Rangliste der Mannschaften, wenn man nur die <strong>Bretter 1-4</strong> wertet.<br /><br />
<span class="meister"> </span> Meister<br />
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
  $handler->display->display_options['fields']['field_ligastatus']['exclude'] = TRUE;
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
  /* Feld: Anzahl gespielte Spiele */
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
  /* Feld: Siege */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Siege';
  $handler->display->display_options['fields']['php_3']['label'] = 'G';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'top\',\'wins\')';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print $value ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Unentschieden */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Unentschieden';
  $handler->display->display_options['fields']['php_4']['label'] = 'U';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'top\',\'draws\')';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: Niederlagen */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'Niederlagen';
  $handler->display->display_options['fields']['php_5']['label'] = 'V';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'top\',\'losses\')';
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
  $handler->display->display_options['fields']['php']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'top\',\'mp\')';
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
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'top\');';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
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
  $handler->display->display_options['path'] = 'tabelle-brett-1-4';

  /* Display: Brett 5-8 */
  $handler = $view->new_display('page', 'Brett 5-8', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tabelle Brett 5-8';
  $handler->display->display_options['display_description'] = 'Ansicht für Brett 5-8';
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
      'field_logo_icon' => array(
        'phone' => 'phone',
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = 'Diese Tabelle zeigt die Rangliste der Mannschaften, wenn man nur die <strong>Bretter 5-8</strong> wertet.<br /><br />
<span class="meister"> </span> Meister<br />
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
  $handler->display->display_options['fields']['field_ligastatus']['exclude'] = TRUE;
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
  /* Feld: Anzahl gespielte Spiele */
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
  /* Feld: Siege */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Siege';
  $handler->display->display_options['fields']['php_3']['label'] = 'G';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'low\',\'wins\')';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print $value ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Unentschieden */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Unentschieden';
  $handler->display->display_options['fields']['php_4']['label'] = 'U';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'low\',\'draws\')';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: Niederlagen */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'Niederlagen';
  $handler->display->display_options['fields']['php_5']['label'] = 'V';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'low\',\'losses\')';
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
  $handler->display->display_options['fields']['php']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'low\',\'mp\')';
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
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return team_list_calculate_board_points_half($row->nid,\'low\');';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
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
  $handler->display->display_options['path'] = 'tabelle-brett-5-8';

  /* Display: Setzliste */
  $handler = $view->new_display('page', 'Setzliste', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Teamstatistik';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'counter' => 'counter',
    'field_logo_icon' => 'field_logo_icon',
    'title' => 'title',
    'php_1' => 'php_1',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'php_4' => 'php_4',
    'php_5' => 'php_5',
    'php' => 'php',
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
    'php' => array(
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
      'field_logo_icon' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'title' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_2' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'php_3' => array(
        'phone' => 0,
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
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>Die Mannschaften in der Reihenfolge der Setzliste, d.h. sortiert nach dem ELO-Schnitt der gemeldeten Spieler.<br />In den weiteren Spalten ist der ELO Gewinn/Verlust der gesamten Mannschaft, der ELO-Schnitt der ersten 8 Bretter sowie die Anzahl der aufgestellten Großmeister (GM), Internationaler Meister (IM) und FIDE-Meister zu sehen.</p>';
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
  /* Feld: ELO +/- */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'ELO +/-';
  $handler->display->display_options['fields']['php_1']['label'] = 'ELO +/-';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return get_team_elo_win_total($row->nid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php echo $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Siege */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['ui_name'] = 'Siege';
  $handler->display->display_options['fields']['php_3']['label'] = 'ELO-Ø (1-8)';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = 'return get_elo_average_per_team_first_eight($row->nid)';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php print number_format($value, 0, \',\', \'.\'); ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: ELO-Durchschnitt */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'ELO-Durchschnitt';
  $handler->display->display_options['fields']['php_2']['label'] = 'ELO-Ø (alle)';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return get_elo_average_per_team($row->nid);';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print number_format($value, 0, \',\', \'.\'); ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Anzahl GMs */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['ui_name'] = 'Anzahl GMs';
  $handler->display->display_options['fields']['php_4']['label'] = 'GM';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return get_titles_per_team($row->nid,\'GM\')';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Feld: Anzahl IMs */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['ui_name'] = 'Anzahl IMs';
  $handler->display->display_options['fields']['php_5']['label'] = 'IM';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return get_titles_per_team($row->nid,\'IM\')';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Feld: Anzahl FMs */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Anzahl FMs';
  $handler->display->display_options['fields']['php']['label'] = 'FM';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return get_titles_per_team($row->nid,\'FM\')';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['ui_name'] = 'Sortieren nach Mannschaftspunkten und Brettpunkten kombiniert';
  $handler->display->display_options['sorts']['php']['expose']['label'] = 'PHP';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return team_list_sort_by_elo($row1->php_3,$row2->php_3);';
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
  $handler->display->display_options['path'] = 'setzliste';
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
    t('<span class="meister"> </span> Meister<br />
<span class="absteiger"> </span> Absteiger'),
    t('(M) = Amtierender Meister, (N) = Neuling'),
    t('field collection item from field_ligenzuordnung'),
    t('Ligastatus'),
    t('SP'),
    t('G'),
    t('U'),
    t('V'),
    t('Block'),
    t('Pl.'),
    t('Verein'),
    t('<a href="/verein/[nid]/!1">[field_vereinsname_kurz]</a>'),
    t('Block Tabelle'),
    t('Newsfeed'),
    t('Vereinsname'),
    t('Brett 1-4'),
    t('Tabelle Brett 1-4'),
    t('Ansicht für Brett 1-4'),
    t('Diese Tabelle zeigt die Rangliste der Mannschaften, wenn man nur die <strong>Bretter 1-4</strong> wertet.<br /><br />
<span class="meister"> </span> Meister<br />
<span class="absteiger"> </span> Absteiger'),
    t('Brett 5-8'),
    t('Tabelle Brett 5-8'),
    t('Ansicht für Brett 5-8'),
    t('Diese Tabelle zeigt die Rangliste der Mannschaften, wenn man nur die <strong>Bretter 5-8</strong> wertet.<br /><br />
<span class="meister"> </span> Meister<br />
<span class="absteiger"> </span> Absteiger'),
    t('Setzliste'),
    t('Teamstatistik'),
    t('<p>Die Mannschaften in der Reihenfolge der Setzliste, d.h. sortiert nach dem ELO-Schnitt der gemeldeten Spieler.<br />In den weiteren Spalten ist der ELO Gewinn/Verlust der gesamten Mannschaft, der ELO-Schnitt der ersten 8 Bretter sowie die Anzahl der aufgestellten Großmeister (GM), Internationaler Meister (IM) und FIDE-Meister zu sehen.</p>'),
    t('ELO +/-'),
    t('ELO-Ø (1-8)'),
    t('ELO-Ø (alle)'),
    t('GM'),
    t('IM'),
    t('FM'),
  );
  $export['teams_leaderbord'] = $view;

  return $export;
}
