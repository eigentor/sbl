<?php

// Check if the date of the game is smaller or equal to now.
// So the game has started. We show the results link.
//dpm($view);
$date_game = '';
$season = '';
$matchday = '';
$link_to_results = '';
$date_game = new Datetime($row->field_field_datum[0]['raw']['value']);
$now = new Datetime();
if(!empty($row->field_field_tm_saison)) {
  $season = $row->field_field_tm_saison[0]['raw']['tid'];
}
if(!empty($matchday = $row->field_field_tm_spieltag_1)) {
  $matchday = $row->field_field_tm_spieltag_1[0]['raw']['value'];
}
if(!empty($season) && !empty($matchday)) {
  $link_to_results = l('Ergebnisse', 'ergebnisse/' . $season . '/' . $matchday, array('attributes' => array('class' => 'link-to-results')));
}
if ($date_game != '' && $date_game <= $now) {
  $output = $link_to_results;
} else {
  $output = '';
}
?>

<?php print $output;?>