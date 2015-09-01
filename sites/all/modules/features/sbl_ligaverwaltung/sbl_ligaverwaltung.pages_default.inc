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
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
    ),
    'panels_page_title_state' => 1,
    'panels_page_title' => 'Joha',
  );
  $display = new panels_display();
  $display->layout = 'omega_12_twocol_6_6_bricks';
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
    ),
  );
  $display->cache = array();
  $display->title = ' ';
  $display->uuid = '23a9552e-1d74-4eb8-8776-9a668a586cd0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5e9c497f-53fc-4219-a37b-ac42cd4e6ac8';
    $pane->panel = 'left_above';
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
    $display->panels['left_above'][0] = 'new-5e9c497f-53fc-4219-a37b-ac42cd4e6ac8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-5e9c497f-53fc-4219-a37b-ac42cd4e6ac8';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['team_page'] = $page;

  return $pages;

}
