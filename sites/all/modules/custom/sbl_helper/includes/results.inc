<?php

/**
 * Functions for the results page ergebnisse/$season/$matchday,
 * this is panel page.
 */

/**
 * Custom Funktion, um die Ergebnisse pro Spieltag auszugeben
 *
 */ 
function print_results_matchday(){

  $season = '';
  $matchday = '';
  $match_node = '';
 	
// Print the results for a matchday
// We get the season and the matchday from the URL
  $season = arg(1);
  if(strlen(arg(2)) < 3) {
  $matchday = arg(2);
  $league=517;
  }
  else {
   $league=arg(2);
   $matchday = arg(3);
  }
  
  
  switch($league) {
  case 517:
  $league_text="Bundesliga";
  break;
  case 518:
  $league_text="2. Liga Nord";
  break;
  case 519:
  $league_text="2. Liga West";
  break;
  case 520:
  $league_text="2. Liga Ost";
  break;
  case 521:
  $league_text="2. Liga Süd";
  break;
  case 560:
  $league_text="Frauen-Bundesliga";
  break;
  }
  

// Now get all Team Match nodes for that specific Match Day
  $matches_match_day = new EntityFieldQuery();

  $matches_match_day->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'team_match')
    ->fieldCondition('field_tm_saison', 'tid', $season)
    ->fieldCondition('field_tm_spieltag_1', 'value', $matchday)
	->fieldCondition('field_liga', 'tid', $league)
    // Bypass node access
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $matches_match_day_result = $matches_match_day->execute();
  if(isset($matches_match_day_result['node'])) {
    $matches = array_keys($matches_match_day_result['node']);
    foreach($matches as $match_node) {
      // print an instance of the view "Ergebnisse" for each of the team_match nodes
      print views_embed_view('match_results', 'block', $season, $matchday, $match_node);
    }
  }
  $season_title_raw = taxonomy_term_load($season);
  $season_title = $season_title_raw->name;

// Set the title to show the season and Spieltag
  drupal_set_title('Ergebnisse der ' . $league_text . ', ' . $matchday . '. Spieltag ' . $season_title);
}

/**
 *  The pager for the results page
 */

function results_pager() {
  // Do not print the pager temporarily for the season 2015/16
   // Print the pager.
   
   if(strlen(arg(2)) < 3) $league=517;
	else $league=arg(2); //Liga hinzufügen

	switch($league) {
	case 517:
	$rounds_max=15;
	break;
	case 520:
	$rounds_max=10;
	break;
	case 560:
	$rounds_max=12;
	break;
	default:
	$rounds_max=9;
	break;
	}

    print '<div class="results-pager">';
	
    $i = 0;
    while ($i < $rounds_max) {
      $i++;
      if ($i == arg(3)) {
        $active_class = 'active';
      }
      else {
        $active_class = '';
      }
      // Create links for the numbers 1-15 for each matchday.
      // We simply keep the first and the second argument and only
      // change the third.
      print l($i, '/' . arg(0) . '/' . arg(1) . '/' . $league . '/' . $i, array(
        'attributes' => array(
          'class' => array(
            'pager',
            $active_class
          )
        )
      ));
    }
    print '</div>';
}

/**
 * Print only the names of the teams and the match date, if there are
 * no results yet.
 */
function results_only_pairings($view) {
  // the second argument is the node id of the team_match we are displaying
  // Get this team match
  $nid = $view->args[2];
  $team_match_wrapper = entity_metadata_wrapper('node', $nid);

  // Extract the data we want to display from the entity_metadata_wrapper
  $team_1_name = '';
  $team_2_name = '';
  $match_date = '';

  $field_team_1 = $team_match_wrapper->field_tm_team_1->label();
  if(!is_null($field_team_1)) {
    $team_1_name = $team_match_wrapper->field_tm_team_1->label();
  }
  $field_team_2 = $team_match_wrapper->field_tm_team_2->label();
  if(!is_null($field_team_2)) {
    $team_2_name = $team_match_wrapper->field_tm_team_2->label();
  }
  $field_datum = $team_match_wrapper->field_datum->value();
  if(!is_null($field_datum)) {
    $match_date_timestamp = $team_match_wrapper->field_datum->value();
    $match_date = format_date($match_date_timestamp, 'long');
  }

  $output = '<h2>';
  $output .= $team_1_name . ' : ' . $team_2_name;
  $output .= '</h2>';
  $output .= '<div class="datum">';
  $output .= $match_date;
  $output .= '</div>';

  return $output;

}