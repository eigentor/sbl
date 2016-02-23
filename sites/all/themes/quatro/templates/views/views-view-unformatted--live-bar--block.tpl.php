<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$current_matchday = get_current_matchday();
$spieltage = array();
$i = 1;
while($i <= 15) {
  $spieltage[] = $i;
  $i++;
}
//dpm($spieltage);

// Now sort the matchdays starting from the current one,
// and in the end append the ones before the current one.
// This way it looks correct in the slider.
$spieltage_vor = array();
$spieltage_nach = array();
foreach($spieltage as $spieltag) {
  if($spieltag < $current_matchday) {
    $spieltage_vor[] = $spieltag;
  }
}
foreach($spieltage as $spieltag) {
  if($spieltag >= $current_matchday) {
    $spieltage_nach[] = $spieltag;
  }
}
$spieltage_sorted = array_merge($spieltage_nach, $spieltage_vor);
//dpm($spieltage_sorted);

//dpm($spieltage);
$grouped_results = array();
foreach($spieltage_sorted as $spieltag) {
  foreach($view->result as $key => $result) {
    if(!empty($result->field_field_tm_spieltag_1) && $result->field_field_tm_spieltag_1[0]['raw']['value'] == $spieltag) {
      $grouped_results[$spieltag][] = $key;
    }
  }
}
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach($grouped_results as $grouped_key => $result): ?>
    <div class = "row-wrapper spieltag-<?php print $grouped_key; ?>">
      <div class="spieltag-nummer"><?php print $grouped_key; ?>. Spieltag</div>
  <?php foreach ($rows as $id => $row): ?>
    <?php if(in_array($id, $result)): ?>
      <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
        <?php print $row; ?>
      </div>
    <?php endif; ?>
  <?php endforeach; ?>
    </div>
<?php endforeach; ?>
