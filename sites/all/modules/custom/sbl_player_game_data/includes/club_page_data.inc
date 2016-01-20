<?php

function club_page_set_matchday($view) {
  $matchday_arg = arg(3);
  if(isset($matchday_arg)) {
    $matchday = $matchday_arg;
  } else {
    $matchday = get_current_matchday();
  }
  return $matchday;

}