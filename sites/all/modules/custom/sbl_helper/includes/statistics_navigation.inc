<?php

/**
 * Functions for the statistics navigation block
 */

function statistics_check_type_of_page() {
  // Find out on which page of our statistics area we are.
  // There are some panels pages
  $page_type = '';
  if (panels_get_current_page_display()) {
    $page_type = 'panel_';
    switch(arg(0)) {
      case 'verein':
        $page_type .= 'verein';
        break;
      case 'spieler':
        $page_type .= 'spieler';
        break;
      case 'ergebnisse':
        $page_type .= 'ergebnisse';
        break;
    }
  }
  // and some views
  $views_page = views_get_page_view(); // Does this need a check in order not to throw an error?
  if (is_object($views_page)) {
    $page_type = 'view_' . $views_page->name;
  }
  // return as a variable where we are.
  return $page_type;
}

function statistics_create_navigation() {
  // Create a navigation block to get to the statistics area we want

  // Set default values for season and matchday
  $season = get_current_season();
  $matchday = get_current_matchday();

  //Get the season from the url arguments
  switch(statistics_check_type_of_page()) {
    case ('panel_verein'):
    case ('panel_spieler'):
      $season = arg(2);
      break;
    case 'panel_ergebnisse':
    case 'view_spielplan':
    case 'view_teams_leaderbord':
    case 'view_rangliste_teams_crosstable':
    case 'view_players_leaderboard':
      $season = arg(1);
      break;
  }


  // Set the necessary variables for our theme_list() function
  $title = 'Tabellen';
  $type = 'ul';
  $attributes = array('class' => array('tabelle', 'spielplan', 'ergebnisse'));
  $list_items = array();
  $list_items[] = l('Tabelle', 'tabelle/' . $season);
  $list_items[] = l('Kreuztabelle', 'kreuztabelle/' . $season);
  $list_items[] = l('Spielplan', 'spielplan/' . $season);
  $list_items[] = l('Ergebnisse', 'ergebnisse/' . $season . '/' . $matchday);
  $list_items[] = l('Rangliste Spieler', 'spieler-rangliste/' . $season);

  // Create an unordered List with the navigation items
  $output = theme_item_list(array('items' => $list_items, 'title' => $title, 'type' => $type, 'attributes' => $attributes));
  return $output;
}

/**
 * Create a form that sets the season by changing the URL
 */
function select_season_form($form, &$form_state) {
  // Get the default value for our Season select
  $default_season = '';
  switch(statistics_check_type_of_page()) {
    case 'panel_ergebnisse':
    case 'view_spielplan':
    case 'view_teams_leaderbord':
    case 'view_rangliste_teams_crosstable':
    case 'view_players_leaderboard':
      $default_season = arg(1);
      break;
      break;
  }


  $form['set_season'] = array(
    '#type' => 'select',
    '#title' => 'Saison',
    '#options' => array(
	141 => '2012/13',
	 142 => '2013/14',
      143 => '2014/15',
      144 => '2015/16',
    ),
    '#default_value' => $default_season,
    '#description' => 'Wählen Sie die Saison',
    //'#default_value' => variable_get('current_matchday', ''),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  // Attach a Javascript file to make the form auto-submit when we change the value of the select element
  $form['#attached']['js'][] = drupal_get_path('module', 'sbl_helper') . '/js/sbl_helper_form_submit.js';

  return $form;
}
function select_season_form_validate($form, &$form_state) {
  // Set where to redirect, when we select the season

  // Get the season from our dropdown
  $season = $form_state['values']['set_season'];
  $url = '';
  //dpm(statistics_check_type_of_page());
  // Set the url to go to for each page
  switch(statistics_check_type_of_page()) {
    case 'panel_ergebnisse':
      $url = '/' . arg(0);
      $url .= '/' . $season;
      $url .= '/' . arg(2);
      break;
    case 'view_spielplan':
    case 'view_teams_leaderbord':
    case 'view_rangliste_teams_crosstable':
    case 'view_players_leaderboard':
      $url = '/' . arg(0);
      $url .= '/' . $season;
      break;
  }
  // Set the form redirect to the above url
  $form_state['redirect'] = $url;
}
