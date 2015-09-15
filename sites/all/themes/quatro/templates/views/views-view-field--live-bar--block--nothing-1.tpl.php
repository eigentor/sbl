<?php

// Check if the date of the game is smaller or equal to now.
// So the game has started. We show the results link.
$date_game = new Datetime($row->field_field_datum[0]['raw']['value']);
$now = new Datetime();
$season = $row->field_field_tm_saison[0]['raw']['tid'];
$matchday = $row->field_field_tm_spieltag_1[0]['raw']['value'];
$link_to_results = l('Ergebnisse', 'ergebnisse/' . $season . '/' . $matchday, array('attributes' => array('class' => 'link-to-results')));
if ($date_game <= $now) {
  $output = $link_to_results;
} else {
  $output = '';
}
?>

<?php print $output;?>