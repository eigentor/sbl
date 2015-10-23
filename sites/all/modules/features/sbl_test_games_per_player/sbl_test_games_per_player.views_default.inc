<?php
/**
 * @file
 * sbl_test_games_per_player.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sbl_test_games_per_player_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'test_games_per_player';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Test Einzelspiele pro Spieler';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field collection item: Spieler 1 */
  $handler->display->display_options['fields']['field_mt_player_1']['id'] = 'field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['field'] = 'field_mt_player_1';
  $handler->display->display_options['fields']['field_mt_player_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field collection item: Spieler 2 */
  $handler->display->display_options['fields']['field_mt_player_2']['id'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['table'] = 'field_data_field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['field'] = 'field_mt_player_2';
  $handler->display->display_options['fields']['field_mt_player_2']['settings'] = array(
    'link' => 0,
  );
  /* Filter criterion: Field collection item: Field name */
  $handler->display->display_options['filters']['field_name']['id'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['field_name']['field'] = 'field_name';
  $handler->display->display_options['filters']['field_name']['value'] = array(
    'field_tm_game' => 'field_tm_game',
  );
  /* Filter criterion: Field collection item: Filter player and opponent */
  $handler->display->display_options['filters']['filter_player_opponent']['id'] = 'filter_player_opponent';
  $handler->display->display_options['filters']['filter_player_opponent']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['filter_player_opponent']['field'] = 'filter_player_opponent';
  /* Filter criterion: Field collection item: Spieler 1 (field_mt_player_1) */
  $handler->display->display_options['filters']['field_mt_player_1_target_id']['id'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['filters']['field_mt_player_1_target_id']['table'] = 'field_data_field_mt_player_1';
  $handler->display->display_options['filters']['field_mt_player_1_target_id']['field'] = 'field_mt_player_1_target_id';
  $handler->display->display_options['filters']['field_mt_player_1_target_id']['value']['value'] = '316';

  /* Display: Seite */
  $handler = $view->new_display('page', 'Seite', 'page_1');
  $handler->display->display_options['path'] = 'spielertest';
  $translatables['test_games_per_player'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Spieler 1'),
    t('Spieler 2'),
    t('Seite'),
  );
  $export['test_games_per_player'] = $view;

  return $export;
}
