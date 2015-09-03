<?php
/**
 * @file
 * sbl_ligaverwaltung.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function sbl_ligaverwaltung_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'spielerseite';
  $page->task = 'page';
  $page->admin_title = 'Spielerseite';
  $page->admin_description = 'Zur Anzeige der Mannschaftsinfo pro Saison';
  $page->path = 'spieler/!player/!season';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'player' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
    'season' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_spielerseite__panel_context_ca5c15b1-00e0-47d5-8bb1-55a8c487d334';
  $handler->task = 'page';
  $handler->subtask = 'spielerseite';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Spieler-Seite',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
    ),
    'panels_page_title_state' => 0,
    'panels_page_title' => '',
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = ' ';
  $display->uuid = '23a9552e-1d74-4eb8-8776-9a668a586cd0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d4ec3532-5b97-4f8e-aabe-70a85ac56ade';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'players-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd4ec3532-5b97-4f8e-aabe-70a85ac56ade';
    $display->content['new-d4ec3532-5b97-4f8e-aabe-70a85ac56ade'] = $pane;
    $display->panels['bottom'][0] = 'new-d4ec3532-5b97-4f8e-aabe-70a85ac56ade';
    $pane = new stdClass();
    $pane->pid = 'new-42a8e869-d8d6-48ec-b208-dc094c0bab23';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'single_games_player-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '42a8e869-d8d6-48ec-b208-dc094c0bab23';
    $display->content['new-42a8e869-d8d6-48ec-b208-dc094c0bab23'] = $pane;
    $display->panels['bottom'][1] = 'new-42a8e869-d8d6-48ec-b208-dc094c0bab23';
    $pane = new stdClass();
    $pane->pid = 'new-39ffd5ec-18df-4705-be9a-dd4db53481d2';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'player_data_static-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '39ffd5ec-18df-4705-be9a-dd4db53481d2';
    $display->content['new-39ffd5ec-18df-4705-be9a-dd4db53481d2'] = $pane;
    $display->panels['left'][0] = 'new-39ffd5ec-18df-4705-be9a-dd4db53481d2';
    $pane = new stdClass();
    $pane->pid = 'new-e6b8d18f-962e-4917-8738-25470dd47fea';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'players-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e6b8d18f-962e-4917-8738-25470dd47fea';
    $display->content['new-e6b8d18f-962e-4917-8738-25470dd47fea'] = $pane;
    $display->panels['right'][0] = 'new-e6b8d18f-962e-4917-8738-25470dd47fea';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['spielerseite'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'team_page';
  $page->task = 'page';
  $page->admin_title = 'Mannschaftsseite';
  $page->admin_description = 'Zur Anzeige der Mannschaftsinfo pro Saison';
  $page->path = 'verein/!team/!season';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'team' => array(
      'settings' => array(),
      'identifier' => 'No context',
    ),
    'season' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_team_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'team_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Mannschafts-Seite',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'teamseite',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
    ),
    'panels_page_title_state' => 0,
    'panels_page_title' => '',
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = ' ';
  $display->uuid = '23a9552e-1d74-4eb8-8776-9a668a586cd0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7dbe7b94-2212-4f83-acd8-8f1e9ee56c76';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'players-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7dbe7b94-2212-4f83-acd8-8f1e9ee56c76';
    $display->content['new-7dbe7b94-2212-4f83-acd8-8f1e9ee56c76'] = $pane;
    $display->panels['bottom'][0] = 'new-7dbe7b94-2212-4f83-acd8-8f1e9ee56c76';
    $pane = new stdClass();
    $pane->pid = 'new-5e9c497f-53fc-4219-a37b-ac42cd4e6ac8';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'team_info-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5e9c497f-53fc-4219-a37b-ac42cd4e6ac8';
    $display->content['new-5e9c497f-53fc-4219-a37b-ac42cd4e6ac8'] = $pane;
    $display->panels['left'][0] = 'new-5e9c497f-53fc-4219-a37b-ac42cd4e6ac8';
    $pane = new stdClass();
    $pane->pid = 'new-fb140854-cd27-4853-bf25-d6ca21ff5a1f';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'team_info-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fb140854-cd27-4853-bf25-d6ca21ff5a1f';
    $display->content['new-fb140854-cd27-4853-bf25-d6ca21ff5a1f'] = $pane;
    $display->panels['right'][0] = 'new-fb140854-cd27-4853-bf25-d6ca21ff5a1f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-5e9c497f-53fc-4219-a37b-ac42cd4e6ac8';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['team_page'] = $page;

  return $pages;

}
