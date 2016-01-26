<?php

/**
 * Implements hook_views_data()
 */
function sbl_views_custom_fields_views_data() {
  $data = array();
  $data['views']['team_points'] = array(
    'title' => t('Team points'),
    'help' => t('Calculate and display the team points for the current season.'),
    'field' => array(
      'handler' => 'sbl_views_custom_fields_team_points_handler',
    ),
    'sort' => array(
      'handler' => 'sbl_views_custom_fields_team_points_sort',
    ),
  );
  $data['views']['board_points'] = array(
    'title' => t('Board points'),
    'help' => t('Calculate and display the board points for the current season.'),
    'field' => array(
      'handler' => 'sbl_views_custom_fields_board_points_handler',
    ),
  );
  return $data;
}

/**
 * A handler to provide a field that is completely custom by the administrator.
 *
 * @ingroup views_field_handlers
 */
class sbl_views_custom_fields_team_points_handler extends views_handler_field {

  function query() {
    // do nothing -- to override the parent query.
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function render($values) {
    //dpm($values);

    $season = arg(1);
    $nid = $values->nid;

    // Get all Team Matches the team has been involved in
    // The season that is viewed
    // Query for Home matches
    $team_home_match_query = new EntityFieldQuery();

    $team_home_match_query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'team_match')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('field_tm_team_1', 'target_id', $nid)
      ->fieldCondition('field_tm_saison', 'tid', $season)
      ->fieldCondition('field_game_has_result', 'value', 1)
      // Bypass node access
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

    $team_home_match = $team_home_match_query->execute();

    // Query for away matches
    $team_away_match_query = new EntityFieldQuery();

    $team_away_match_query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'team_match')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('field_tm_team_2', 'target_id', $nid)
      ->fieldCondition('field_tm_saison', 'tid', $season)
      ->fieldCondition('field_game_has_result', 'value', 1)
      // Bypass node access
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

    $team_away_match = $team_away_match_query->execute();

    // Set the variable for the home team points
    $team_home_team_points = 0;
    $team_away_team_points = 0;


    // Get the nids for the home matches, extract the home team points
    if(isset($team_home_match['node'])) {
      $team_home_match_nids = array_keys($team_home_match['node']);
      foreach($team_home_match_nids as $key => $home_match) {
        $team_home_match_wrapper = entity_metadata_wrapper('node', $home_match);
        if(!is_null($team_home_match_wrapper->field_tm_team_points_tm_1->label())) {
          $team_home_team_points += $team_home_match_wrapper->field_tm_team_points_tm_1->label();

        }
      }
    }

    // Get the nids for the away matches, extract the away team points
    if(isset($team_away_match['node'])) {
      $team_away_match_nids = array_keys($team_away_match['node']);
      foreach($team_away_match_nids as $key => $away_match) {
        $team_away_match_wrapper = entity_metadata_wrapper('node', $away_match);
        if(!is_null($team_away_match_wrapper->field_tm_team_points_tm_2->label())) {
          $team_away_team_points += $team_away_match_wrapper->field_tm_team_points_tm_2->label();
        }
      }
    }
    $team_sum_team_points = 0;
    $team_sum_team_points = floatval($team_home_team_points + $team_away_team_points);

    return $team_sum_team_points;
  }
}

/**
 * Add a sort handler for the team points field
 *
 * @ingroup views_sort_handlers
 */
class sbl_views_custom_fields_team_points_sort extends views_handler_sort {
  function query() {
    // do nothing -- to override the parent query.
    //dpm($this);
    //$this->ensure_my_table();
    // Add the field.
    $this->ensure_my_table();
    // Add the field.
    //$this->query->add_orderby($this->table_alias, $this->real_field, $this->options['order']);
    //dpm($this->query);
  }
}

/**
 * A handler to provide a field that is completely custom by the administrator.
 *
 * @ingroup views_field_handlers
 */
class sbl_views_custom_fields_board_points_handler extends views_handler_field {
  function query() {
    // do nothing -- to override the parent query.
  }

  function render($values) {
    //dpm($values);

    $season = arg(1);
    $nid = $values->nid;

    //Get all Team Matches the team has been involved in
    // Query for Home matches
    $team_home_match_query = new EntityFieldQuery();

    $team_home_match_query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'team_match')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('field_tm_team_1', 'target_id', $nid)
      ->fieldCondition('field_tm_saison', 'tid', $season)
      ->fieldCondition('field_game_has_result', 'value', 1)
      // Bypass node access
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

    $team_home_match = $team_home_match_query->execute();

    // Query for away matches
    $team_away_match_query = new EntityFieldQuery();

    $team_away_match_query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'team_match')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('field_tm_team_2', 'target_id', $nid)
      ->fieldCondition('field_tm_saison', 'tid', $season)
      ->fieldCondition('field_game_has_result', 'value', 1)
      // Bypass node access
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

    $team_away_match = $team_away_match_query->execute();

    // Set the variable for the home team points
    $team_home_board_points = 0;
    $team_away_board_points = 0;

    // the actual value from the database
    // is the option field key for the board points.
    // So we need to match it to the real points
    $match_board_points = array(
      1 => 0,
      2 => 0.5,
      3 => 1,
      4 => 1.5,
      5 => 2,
      6 => 2.5,
      7 => 3,
      8 => 3.5,
      9 => 4,
      10 => 4.5,
      11 => 5,
      12 => 5.5,
      13 => 6,
      14 => 6.5,
      15 => 7,
      16 => 7.5,
      17 => 8,
    );

    // Get the nids for the home matches, extract the home team points
    if(isset($team_home_match['node'])) {
      $team_home_match_nids = array_keys($team_home_match['node']);
      foreach($team_home_match_nids as $key => $home_match) {
        //dpm($home_match);
        // Get the points for the team with db_query
        $results = db_query("select field_tm_board_points_team_1_value from {field_data_field_tm_board_points_team_1} where entity_id = :home_match", array(':home_match' => $home_match));
        foreach($results as $result) {
          $real_points = $match_board_points[$result->field_tm_board_points_team_1_value];
          $team_home_board_points += $real_points;
        }
//        $team_home_match_wrapper = entity_metadata_wrapper('node', $home_match);
//        if(!is_null($team_home_match_wrapper->field_tm_board_points_team_1->label())) {
//          $team_home_board_points += $team_home_match_wrapper->field_tm_board_points_team_1->label();
//        }

      }
      //dpm($team_home_board_points);
    }

    // Get the nids for the away matches, extract the away team points
    if(isset($team_away_match['node'])) {
      $team_away_match_nids = array_keys($team_away_match['node']);
      foreach($team_away_match_nids as $key => $away_match) {
        $results = db_query("select field_tm_board_points_team_2_value from {field_data_field_tm_board_points_team_2} where entity_id = :away_match", array(':away_match' => $away_match));
        foreach($results as $result) {
          $real_points = $match_board_points[$result->field_tm_board_points_team_2_value];
          $team_away_board_points += $real_points;
        }

//        $team_away_match_wrapper = entity_metadata_wrapper('node', $away_match);
//        if(!is_null($team_away_match_wrapper->field_tm_board_points_team_2->label())) {
//          $team_away_board_points += $team_away_match_wrapper->field_tm_board_points_team_2->label();
//        }
      }
    }
    $team_sum_board_points = 0;
    $team_sum_board_points = floatval($team_home_board_points + $team_away_board_points);


    return $team_sum_board_points;
  }
}

