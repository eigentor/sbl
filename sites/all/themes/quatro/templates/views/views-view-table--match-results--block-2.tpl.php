<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */


// Get the team names for the team_match that is displayed
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
?>

<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
  <?php if (!empty($title) || !empty($caption)) : ?>
    <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        <?php ?>
        <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
          <?php
          // if the fields / columns are the players, print the name of the club of each player as
          // the table label.
          if($field == 'field_mt_player_1') {
            $label = $team_1_name;
          } elseif ($field == 'field_mt_player_2') {
            $label = $team_2_name;
          }
          print $label; ?>
        </th>
      <?php endforeach; ?>
    </tr>
    </thead>
  <?php endif; ?>
  <tbody>
  <?php foreach ($rows as $row_count => $row): ?>
    <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
      <?php foreach ($row as $field => $content): ?>
        <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
          <?php print $content; ?>
        </td>
      <?php endforeach; ?>
    </tr>
  <?php endforeach; ?>
  </tbody>
</table>