<?php
/**
 * @file
 * sbl_panels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function sbl_panels_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'neueste_beitraege';
  $page->task = 'page';
  $page->admin_title = 'Neueste Beitraege';
  $page->admin_description = '';
  $page->path = 'aktuell';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Aktuelles',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_neueste_beitraege__panel_context_875053a7-1be7-408d-8cc2-254e2b327c23';
  $handler->task = 'page';
  $handler->subtask = 'neueste_beitraege';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Neueste Beiträge',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Neueste Beiträge';
  $display->uuid = '58466759-6295-41e5-ae57-0a064d5f77f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1251dbf0-0362-47dc-873f-617edbc369dc';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'news_blog';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 1,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'abstand-unten',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1251dbf0-0362-47dc-873f-617edbc369dc';
    $display->content['new-1251dbf0-0362-47dc-873f-617edbc369dc'] = $pane;
    $display->panels['middle'][0] = 'new-1251dbf0-0362-47dc-873f-617edbc369dc';
    $pane = new stdClass();
    $pane->pid = 'new-be9f9817-4f41-4dc9-9dc1-be0083268b09';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'aktuell_spielberichte';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 1,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'block-spielberichte one-half',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'be9f9817-4f41-4dc9-9dc1-be0083268b09';
    $display->content['new-be9f9817-4f41-4dc9-9dc1-be0083268b09'] = $pane;
    $display->panels['middle'][1] = 'new-be9f9817-4f41-4dc9-9dc1-be0083268b09';
    $pane = new stdClass();
    $pane->pid = 'new-ea1d9c46-e2f8-4dfa-9c2c-7eb8823632b5';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'aktuell_bundesliga';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'block-bundesliga one-half last',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ea1d9c46-e2f8-4dfa-9c2c-7eb8823632b5';
    $display->content['new-ea1d9c46-e2f8-4dfa-9c2c-7eb8823632b5'] = $pane;
    $display->panels['middle'][2] = 'new-ea1d9c46-e2f8-4dfa-9c2c-7eb8823632b5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['neueste_beitraege'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'test_panel';
  $page->task = 'page';
  $page->admin_title = 'Panel Kolumnen';
  $page->admin_description = '';
  $page->path = 'aktuell/kolumnen';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Kolumnen',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_test_panel__panel_context_310c1b92-7dff-4085-ba61-65eb61e4cd47';
  $handler->task = 'page';
  $handler->subtask = 'test_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel Kolumnen',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Beitrag',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '244',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Kolumnen';
  $display->uuid = 'f08a9077-9dbb-4bf3-b10a-d0f4d799ec81';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-67e9168c-23ae-4d7a-912b-4620e561919e';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'context_entity:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '67e9168c-23ae-4d7a-912b-4620e561919e';
    $display->content['new-67e9168c-23ae-4d7a-912b-4620e561919e'] = $pane;
    $display->panels['middle'][0] = 'new-67e9168c-23ae-4d7a-912b-4620e561919e';
    $pane = new stdClass();
    $pane->pid = 'new-6d8e3f26-1f93-4053-aabe-9a9512d4f29d';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'weisheiten_im_endspiel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 1,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'block-kolumnen one-half',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6d8e3f26-1f93-4053-aabe-9a9512d4f29d';
    $display->content['new-6d8e3f26-1f93-4053-aabe-9a9512d4f29d'] = $pane;
    $display->panels['middle'][1] = 'new-6d8e3f26-1f93-4053-aabe-9a9512d4f29d';
    $pane = new stdClass();
    $pane->pid = 'new-24e649cb-abfe-4328-8965-a3eafe338bb3';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'der_leser_ist_am_zug';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'block-kolumnen one-half last',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '24e649cb-abfe-4328-8965-a3eafe338bb3';
    $display->content['new-24e649cb-abfe-4328-8965-a3eafe338bb3'] = $pane;
    $display->panels['middle'][2] = 'new-24e649cb-abfe-4328-8965-a3eafe338bb3';
    $pane = new stdClass();
    $pane->pid = 'new-4d66d186-924c-4f8e-b879-e2585aacc9a9';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'clone_of_aktuell_ulis_kommentar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4d66d186-924c-4f8e-b879-e2585aacc9a9';
    $display->content['new-4d66d186-924c-4f8e-b879-e2585aacc9a9'] = $pane;
    $display->panels['middle'][3] = 'new-4d66d186-924c-4f8e-b879-e2585aacc9a9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['test_panel'] = $page;

  return $pages;

}
