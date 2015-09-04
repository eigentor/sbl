<?php
  // If the player, whose page is displayed, is player 2, display player 1 in the
  // Column "Gegner: Name"
  $player = arg(1);
  if($row->field_field_mt_player_2[0]['raw']['target_id'] == $player) {
    $output = $row->field_field_mt_player_1[0]['rendered']['#markup'];
  }
?>

<?php print $output; ?>

