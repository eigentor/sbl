<?php
  // If the player, whose page is displayed, is player 2, display player 1 in the
  // Column "Gegner: Name". Link this displayed player 1 to his player page.
  $player = arg(1);
  if(isset($row->field_field_mt_player_2[0]['raw']['target_id']) &&
    $row->field_field_mt_player_2[0]['raw']['target_id'] == $player) {
    // get all the necessary data to link the player to his player page
    $player_name = $row->field_field_mt_player_1[0]['rendered']['#markup'];
    $player_nid = $row->field_field_mt_player_1_1[0]['raw']['target_id'];
    $season_tid = $row->field_field_tm_saison_1[0]['raw']['tid'];
    $player_link = '/spieler/' . $player_nid . '/' . $season_tid;
    $output = l($player_name, $player_link);
  }
?>

<?php print $output; ?>

