<?php
/**
 * @file
 * sbl_standings.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function sbl_standings_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Navigation Statistikbereich';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'navigation_statistics';
  $fe_block_boxes->body = '<?php
print statistics_create_navigation();

// Only print the season selection, if we are not on a verein or spieler page
if(in_array(statistics_check_type_of_page(), array(\'panel_ergebnisse\', \'view_spielplan\', \'view_teams_leaderbord\', \'view_rangliste_teams_crosstable\'))) {
  $set_season = drupal_get_form(\'select_season_form\');
  print drupal_render($set_season);
}

?>';

  $export['navigation_statistics'] = $fe_block_boxes;

  return $export;
}
