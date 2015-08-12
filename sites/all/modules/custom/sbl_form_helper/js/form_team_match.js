(function ($) {

  // Scripte als Drupal Behaviors hinzufuegen statt als document.ready.
  // Funktioniert dann auch bei Ajax Reloads.
  Drupal.behaviors.oebv_helper = {
    attach: function (context, settings) {
      // Set the points per player on the team match node form dependent on the other player

     //function to set player points depending on single game result

      function set_single_game_player_points(single_game_result_select, player_points_select, points_matching_array) {
        $(single_game_result_select).change(function(){
          // get the value from the result selector
          var single_match_result = $(this).val();
          // set the player points to the matching value
         for(var key in points_matching_array) {
            if(single_match_result === key) {
              //console.log(points_matching_array[key]);
              var value = points_matching_array[key];
              //console.log(value);
              $(player_points_select).val(value);
            }
          }
        });
      }

      // Create arrays to match the game results to the points for each player
      // Notice: for the val() the key for the points select is used.
      // So 1 means 1 point, 2 means 0 points, and 3 means 0.5 points.

      //create arrays for matching game result values to player points
      var match_result_player_1_points = {};
      match_result_player_1_points['_none'] = '_none';
      match_result_player_1_points['1'] = 1;
      match_result_player_1_points['2'] = 2;
      match_result_player_1_points['3'] = 3;
      match_result_player_1_points['4'] = 1;
      match_result_player_1_points['5'] = 2;
      match_result_player_1_points['6'] = 2;

      //create arrays for matching game result values to player points
      var match_result_player_2_points = {};
      match_result_player_2_points['_none'] = '_none';
      match_result_player_2_points['1'] = 2;
      match_result_player_2_points['2'] = 1;
      match_result_player_2_points['3'] = 3;
      match_result_player_2_points['4'] = 2;
      match_result_player_2_points['5'] = 1;
      match_result_player_2_points['6'] = 2;

      //console.log(match_result_player_1_points);

      // Instances of function set_single_game_player_points()

      // Set the points for player 1
      set_single_game_player_points('form#team-match-node-form .field-name-field-single-match-result select.form-select',
      'form#team-match-node-form .field-name-field-mt-points-player-1 select.form-select', match_result_player_1_points);

      // Set the points for player 2
      set_single_game_player_points('form#team-match-node-form .field-name-field-single-match-result select.form-select',
        'form#team-match-node-form .field-name-field-mt-points-player-2 select.form-select', match_result_player_2_points);

    } // end of attach function
  };
})(jQuery);
