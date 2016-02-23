<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
//dpm($view->result[1]);
$spieltage = array();
$i = 0;
while($i <= 15) {
  $spieltage[] = $i;
  $i++;
}
dpm($view->result[0]);
//dpm($spieltage);
$grouped_results = array();
foreach($spieltage as $spieltag) {
  foreach($view->result as $key => $result) {
    if(!empty($result->field_field_tm_spieltag_1) && $result->field_field_tm_spieltag_1[0]['raw']['value'] == $spieltag) {
      $grouped_results[$spieltag][] = $key;
    }
  }
}
dpm($grouped_results);
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach($grouped_results as $grouped_key => $result): ?>
    <div class = "row-wrapper spieltag-<?php print $grouped_key; ?>">
  <?php foreach ($rows as $id => $row): ?>
    <?php if(in_array($id, $result)): ?>
      <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
        <?php print $row; ?>
      </div>
    <?php endif; ?>
  <?php endforeach; ?>
    </div>
<?php endforeach; ?>
