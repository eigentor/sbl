(function ($) {

  // Scripte als Drupal Behaviors hinzufuegen statt als document.ready.
  // Funktioniert dann auch bei Ajax Reloads.
  Drupal.behaviors.oebv_helper = {
    attach: function (context, settings) {


// Set the points per player on the team match node form dependent on the other player
// function to set player points depending on single game result

function set_single_game_player_points(single_game_result_select, player_points_select, points_matching_array) {
  $(single_game_result_select).each(function(){
    // execute the function on loading the form
    // get the value from the result select
      var single_match_result = $(this).val();
      // set the player points to the matching value
      for(var key in points_matching_array) {
        if (single_match_result === key) {
          var value = points_matching_array[key];
          $(this).parents('td').find(player_points_select).val(value);
          // display the value before the select
          var current_text_value = $(this).parents('td').find(player_points_select + ' option:selected').text();
          var formatted_text_value = '<span class="player-points">' + current_text_value + '</span>'
          $(this).parents('td').find(player_points_select).prev('span.player-points').remove();
          $(this).parents('td').find(player_points_select).before(formatted_text_value);
        }
      }
    // then, execute the function when changing the select result for single game
    $(this).change(function(){
      // get the value from the result select
      var single_match_result = $(this).val();
	  change_total_standing();
      // set the player points to the matching value
      for(var key in points_matching_array) {
        if (single_match_result === key) {
          var value = points_matching_array[key];
          $(this).parents('td').find(player_points_select).val(value);
          // display the value before the select
          var current_text_value = $(this).parents('td').find(player_points_select + ' option:selected').text();
          var formatted_text_value = '<span class="player-points">' + current_text_value + '</span>'
          $(this).parents('td').find(player_points_select).prev('span.player-points').remove();
          $(this).parents('td').find(player_points_select).before(formatted_text_value);
        }
      }
    });
  });
}

//Aktualisiert die gesamten Brett- und Mannschaftspunkte, wenn Einzelergebnisse geändert werden
function change_total_standing() {
	var bp_heim=1;
	var bp_gast=1;
	var bp_heim_top=1;
	var bp_heim_low=1;
	var bp_gast_top=1;
	var bp_gast_low=1;
	var mp_heim=0;
	var mp_gast=0;
	for(var i=0;i<=7;i++) {
		jQuery.globalEval("var punkte=jQuery(\"[id^=edit-field-tm-game-und-"+i+"-field-mt-points-player-1-und]\").val();");
		switch(punkte) {
			case "1":
			bp_heim+=2;
			if(i<=3) bp_heim_top+=2;
			else bp_heim_low+=2;
			break;
			case "2":
			bp_gast+=2;
			if(i<=3) bp_gast_top+=2;
			else bp_gast_low+=2;
			break;
			case "3":
			bp_heim+=1;
			bp_gast+=1;
			if(i<=3) {
			bp_heim_top+=1;
			bp_gast_top+=1;
			}
			else {
			bp_heim_low+=1;
			bp_gast_low+=1;
			}
			break;
			case "4":
			bp_heim+=2;
			if(i<=3) bp_heim_top+=2;
			else bp_heim_low+=2;
			break;
			case "5":
			bp_gast+=2;
			if(i<=3) bp_gast_top+=2;
			else bp_gast_low+=2;
			break;
		}
	}
	switch(true) {
		case bp_heim > 9:
		mp_heim=2;
		break;
		case bp_heim == 9:
		mp_heim=1;
		break;
		case bp_heim < 9:
		mp_heim=0;
		break;
	}
	
	switch(true) {
		case bp_gast > 9:
		mp_gast=2;
		break;
		case bp_gast == 9:
		mp_gast=1;
		break;
		case bp_gast < 9:
		mp_gast=0;
		break;
	}
	$("#edit-field-tm-team-points-tm-1-und").val(mp_heim);
	$("#edit-field-tm-team-points-tm-2-und").val(mp_gast);
	$("#edit-field-tm-board-points-team-1-und").val(bp_heim);
	$("#edit-field-tm-board-points-team-2-und").val(bp_gast);
	$("#edit-field-tm-board-points-team-1-top-und").val(bp_heim_top);
	$("#edit-field-tm-board-points-team-2-top-und").val(bp_gast_top);
	$("#edit-field-tm-board-points-team-1-low-und").val(bp_heim_low);
	$("#edit-field-tm-board-points-team-2-low-und").val(bp_gast_low);
}

//console.log($('.field-name-field-mt-points-player-1 select.form-select option:selected').text());

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
'.field-name-field-mt-points-player-1 select.form-select', match_result_player_1_points);

// Set the points for player 2
set_single_game_player_points('form#team-match-node-form .field-name-field-single-match-result select.form-select',
  '.field-name-field-mt-points-player-2 select.form-select', match_result_player_2_points);

// Hide the player point select field itself and replace it with a mere display of the value of the select
$('form#team-match-node-form .field-name-field-mt-points-player-1 select.form-select').add
('form#team-match-node-form .field-name-field-mt-points-player-2 select.form-select').hide();

// Create an array to match the opponent's board color to the own board color
var match_board_color = {}
match_board_color['_none'] = '_none';
match_board_color['black'] = 'white';
match_board_color['white'] = 'black';

// Set the board color dependent on the board color of the opponent. This way the board color needs only to be set for one of the two players.
function set_single_game_board_color(player_board_color_select, opponent_board_color_select, match_color_array) {
  $(player_board_color_select).each(function(){
      $(this).change(function(){
        // get the value from board color select
        var board_color = $(this).val();
        //console.log(board_color);
        for(var key in match_color_array) {
          if (board_color === key) {
            console.log(match_color_array[key]);
            var opponent_color = match_color_array[key];
            $(this).parents('td').find(opponent_board_color_select).val(opponent_color);
          }
        }
      });
  });
}

// Instances of function set_single_game_player_points()
set_single_game_board_color('form#team-match-node-form .field-name-field-mt-color-player-1 select.form-select',
'.field-name-field-mt-color-player-2 select.form-select', match_board_color);

set_single_game_board_color('form#team-match-node-form .field-name-field-mt-color-player-2 select.form-select',
'.field-name-field-mt-color-player-1 select.form-select', match_board_color);


// Alle Farben automatisch setzen, wenn Match aufgerufen wird.
	   var firstColor=$( "#edit-field-tm-game-und-0-field-mt-color-player-1-und" ).val();
	   if(firstColor=="_none") {
	for(var i=0;i<=7;i++) {
		if(i % 2 === 0) {
			$("#edit-field-tm-game-und-"+i+"-field-mt-color-player-1-und").val("black");
			$("#edit-field-tm-game-und-"+i+"-field-mt-color-player-2-und").val("white");
		}
		else {
			$("#edit-field-tm-game-und-"+i+"-field-mt-color-player-1-und").val("white");
			$("#edit-field-tm-game-und-"+i+"-field-mt-color-player-2-und").val("black");
		}
		}	
	   }
  


//function reload_chosen {
//
//}



    } // end of attach function
  };
})(jQuery);
