<?php

/**
 * Display the game result depending on if the player, which player page we view, was Player 1 or Player 2
 */

$player = arg(1);
$output = '';
// If the player we view was player 2, reverse the result, else display it in the original order
if (isset($row->field_field_mt_points_player_1[0]['raw']['value']) && isset($row->field_field_mt_points_player_2[0]['raw']['value']) && isset($row->field_field_mt_player_2[0]['raw']['target_id'])){
  if($row->field_field_mt_player_2[0]['raw']['target_id'] == $player) {
    $output = $row->field_field_mt_points_player_2[0]['rendered']['#markup'] . ' : ' . $output = $row->field_field_mt_points_player_1[0]['rendered']['#markup'];
  } else {
    $output = $row->field_field_mt_points_player_1[0]['rendered']['#markup'] . ' : ' . $output = $row->field_field_mt_points_player_2[0]['rendered']['#markup'];
  }
}

?>

<?php print $output; ?>