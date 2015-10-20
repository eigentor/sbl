<?php

/**
 * Implementation of hook_views_plugins().
 */
function sbl_views_custom_filter_views_plugins() {
  $plugin = array();
  $plugin['query']['filter_player_opponent'] = array(
    'title' => t('Find Player and Opponent'),
    'help' => t('Filters by a player in a single game, he may be player 1 or player 2'),
    'handler' => 'filter_player_opponent_query',
  );
  return $plugin;
}