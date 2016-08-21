<?php
// Link the title to the season that we get from the tid in the first argument
// in the url and the nid which is the Verein Node ID
$season = arg(1);
$path = 'verein/' . $row->nid . '/' . $season;
//dpm($row);
$output = l($row->node_title, $path) . ' ' . $row->field_field_ligastatus[0]['rendered']['#markup'];
?>

<?php print $output; ?>