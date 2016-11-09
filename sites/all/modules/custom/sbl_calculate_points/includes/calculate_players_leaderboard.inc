<?php

function get_team_nid_from_player_nid($season, $player_nid) {
  $players_season_data = drupal_static('players_data_list');

  $team_nid = '';
  if(!empty($players_season_data[$player_nid])) {
    $team_nid = $players_season_data[$player_nid]['team'];
  }

  return $team_nid;
}

function get_elo_from_player_nid($season, $player_nid) {
  $players_season_data = drupal_static('players_data_list');
  $elo_player = 0;
  if(!empty($players_season_data[$player_nid])) {
    $elo_player = $players_season_data[$player_nid]['elo'];
  }

  return $elo_player;
}

/**
* Count how many games a player has played.
 */
function player_calculate_played_games($player_nid) {

  $season = arg(1);
  // Get the team nid from the season and player nid

  $players_season_data = drupal_static('players_data_list');
  $games_player = '';
  // Get all the games the player has played in the season

  $games_player = $players_season_data[$player_nid]['games'];

  $games_player_number = '';

  $games_player_number = count($games_player);

  return $games_player_number;
}

/**
 * Add up all the points a player has won in a season.
 */

function player_calculate_won_points($player_nid) {
  $season = arg(1);
  // Get the team nid from the season and player nid

  $players_season_data = drupal_static('players_data_list');
  $games_player = '';
  // Get all the games the player has played in the season

  $games_player = $players_season_data[$player_nid]['games'];

  $player_sum_points = '';
  foreach($games_player as $game) {
    $game_wrapper = entity_metadata_wrapper('field_collection_item', $game);
    $player_game_wrapper_player_1 = $game_wrapper->field_mt_player_1->value();
    $player_game_wrapper_player_2 = $game_wrapper->field_mt_player_2->value();
    if (!empty($player_game_wrapper_player_1) && !empty($player_game_wrapper_player_2)) {
      if ($game_wrapper->field_mt_player_1->nid->value() == $player_nid) {
        $player_sum_points += $game_wrapper->field_mt_points_player_1->label();
      }
      elseif ($game_wrapper->field_mt_player_2->nid->value() == $player_nid) {
        $player_sum_points += $game_wrapper->field_mt_points_player_2->label();
      }
    }
  }
  return $player_sum_points;

}

function calculate_elo_change($player_nid) {
 $season = arg(1);
  // Get the team nid from the season and player nid
   $players_season_data = drupal_static('players_data_list');
  $elo_player = '';
  // Get all the games the player has played in the season

  $elo_player = $players_season_data[$player_nid]['elo'];
if($elo_player > 0 && !empty ($elo_player)) {
  $kfaktor=$elo_player >=2400?10:20;
  $games_played=player_calculate_played_games($player_nid);
  $eloschnitt=player_elo_average($player_nid);
  $elo_summe=$games_played * $eloschnitt;
  $points_scored=player_calculate_won_points($player_nid);
  $exponent=($eloschnitt - $elo_player) / 400;
  $we=1/(1+(pow(10,$exponent)));
 
  $summe_gewinnerwartungen=round(($we * $games_played),3);
  $elo_new=$elo_player + ($kfaktor *($points_scored-$summe_gewinnerwartungen));
  $difference=number_format(round($elo_new-$elo_player, 0), 0);
  if($difference !=0) $change=$difference > 0?"<span style='color:green'>+".$difference."</span>":"<span style='color:red'>".$difference."</span>";
	else $change=$difference;
  }
  else $change=0;
  
  return $change;
  
}

/**
 * Add up all the points a player has won in a season.
 */

function player_percentage($player_nid) {
  $season = arg(1);
  // Get the team nid from the season and player nid
   $players_season_data = drupal_static('players_data_list');
  $games_player = '';
  // Get all the games the player has played in the season
   $games_player = $players_season_data[$player_nid]['games'];

  $player_sum_points = '';
  foreach($games_player as $game) {
    $game_wrapper = entity_metadata_wrapper('field_collection_item', $game);
    $player_game_wrapper_player_1 = $game_wrapper->field_mt_player_1->value();
    $player_game_wrapper_player_2 = $game_wrapper->field_mt_player_2->value();
    if(!empty($player_game_wrapper_player_1) && !empty($player_game_wrapper_player_2)) {
      if ($game_wrapper->field_mt_player_1->nid->value() == $player_nid) {
        $player_sum_points += $game_wrapper->field_mt_points_player_1->label();
      }
      elseif ($game_wrapper->field_mt_player_2->nid->value() == $player_nid) {
        $player_sum_points += $game_wrapper->field_mt_points_player_2->label();
      }
    }
  }
  $number_games = '';
  $number_games = count($games_player);
  $percentage = '';
  if($number_games != '' && $player_sum_points != '') {
    $percentage = round(($player_sum_points / $number_games) * 100);
  }
  if($player_sum_points == 0) {
      $percentage = 0;
    }
  return $percentage;
}

/**
 * Calculate the elo performance of a player.
 */

function player_elo_performance($player_nid) {
  $season = arg(1);
  // Get the team nid from the season and player nid
   $players_season_data = drupal_static('players_data_list');
  $games_player = '';
  // Get all the games the player has played in the season

  $games_player = $players_season_data[$player_nid]['games'];

  $players_season_elo = array();

  // Get the players elo list for the current season from drupal_static.
  // We saved it into there in hook_views_pre_build in the sbl_calculate_points.module
  $players_data_list = drupal_static('players_data_list');

  $elo_performance = '';
  $elo_sum = '';

  foreach($games_player as $game) {
    $game_wrapper = entity_metadata_wrapper('field_collection_item', $game);
    $player_1 = $game_wrapper->field_mt_player_1->value();
    $player_2 = $game_wrapper->field_mt_player_2->value();
    if(!empty($player_1) && $game_wrapper->field_mt_player_1->nid->value() == $player_nid)  {
      $opponent = $game_wrapper->field_mt_player_2->value();
      if(!empty($opponent)) {
        $elo_game = $players_data_list[$game_wrapper->field_mt_player_2->nid->value()]['elo'];
        if($game_wrapper->field_mt_points_player_1->label() == 1) {
          $elo_sum += $elo_game + 400;
        } elseif($game_wrapper->field_mt_points_player_1->label() == 0) {
          $elo_sum += $elo_game - 400;
        } elseif($game_wrapper->field_mt_points_player_1->label() == 0.5) {
          $elo_sum += $elo_game;
        }
      }
    } elseif(!empty($player_2) && $game_wrapper->field_mt_player_2->nid->value() == $player_nid)  {
      $opponent = $game_wrapper->field_mt_player_1->value();
      if(!empty($opponent)) {
        $elo_game = $players_data_list[$game_wrapper->field_mt_player_1->nid->value()]['elo'];
        if($game_wrapper->field_mt_points_player_2->label() == 1) {
          $elo_sum += $elo_game + 400;
        } elseif($game_wrapper->field_mt_points_player_2->label() == 0) {
          $elo_sum += $elo_game - 400;
        } elseif($game_wrapper->field_mt_points_player_2->label() == 0.5) {
          $elo_sum += $elo_game;
        }
      }
    }
  }

  if(!empty($games_player)) {
    $count_games = count($games_player);
    $elo_performance = round($elo_sum / $count_games);
  }
  return $elo_performance;
}

/**
 * Add up all the points a player has won in a season.
 */

function player_elo_average($player_nid) {
  $season = arg(1);
  // Get the team nid from the season and player nid
  $players_season_data = drupal_static('players_data_list');
  $games_player = '';
  // Get all the games the player has played in the season

  $games_player = $players_season_data[$player_nid]['games'];

  $players_season_elo = array();

  // Get the players elo list for the current season from drupal_static.
  // We saved it into there in hook_views_pre_build in the sbl_calculate_points.module
  $players_data_list = drupal_static('players_data_list');

  $elo_performance = '';
  $elo_sum = '';

  foreach($games_player as $game) {
    $game_wrapper = entity_metadata_wrapper('field_collection_item', $game);
    $player_1 = $game_wrapper->field_mt_player_1->value();
    $player_2 = $game_wrapper->field_mt_player_2->value();
    if(!empty($player_1) && $game_wrapper->field_mt_player_1->nid->value() == $player_nid)  {
      $opponent = $game_wrapper->field_mt_player_2->value();
      if(!empty($opponent)) {
        $elo_game = $players_data_list[$game_wrapper->field_mt_player_2->nid->value()]['elo'];
        $elo_sum += $elo_game;
      }
    } elseif(!empty($player_2) && $game_wrapper->field_mt_player_2->nid->value() == $player_nid)  {
      $opponent = $game_wrapper->field_mt_player_1->value();
      if(!empty($opponent)) {
        $elo_game = $players_data_list[$game_wrapper->field_mt_player_1->nid->value()]['elo'];
        $elo_sum += $elo_game;
        }
      }
  }
  $elo_total = '';

  if(!empty($games_player)) {
    $count_games = count($games_player);
    $elo_total = round($elo_sum / $count_games);
  }
  return $elo_total;
}

/**
 * Sort function for the players leaderboard.
 * Sort by Elo Performance
 */

function players_sort_leaderboard($elo_1, $elo_2) {
  $a = $elo_1;
  $b = $elo_2;
  // Sort by played games
  if($a > $b) {
    return -1;
  } elseif ($a < $b) {
    return 1;
  }
}

/**
 * Filter function for the players leaderboard.
 * Hide players with less than 3 played games
 */
function filter_players_leaderboard($number_games) {
if(arg(2)==517 || !(arg(2))) $min=2;
else $min=1;
  if($number_games < $min) {
    return TRUE;
  } else {
    return FALSE;
  }
}



