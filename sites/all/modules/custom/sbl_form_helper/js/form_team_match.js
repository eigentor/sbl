(function ($) {

  // Scripte als Drupal Behaviors hinzufuegen statt als document.ready.
  // Funktioniert dann auch bei Ajax Reloads.
  Drupal.behaviors.oebv_helper = {
    attach: function (context, settings) {
      // Set the points per player on the team match node form dependent on the other player

      $('form#team-match-node-form select#edit-field-tm-game-und-0-field-ergebnis-und').change(function(){
        var single_match_result = $('form#team-match-node-form select#edit-field-tm-game-und-0-field-ergebnis-und').val();
        $('form#team-match-node-form input#edit-field-tm-game-und-0-field-mt-points-player-1-und-0-value').val(single_match_result);
      });

    } // end of attach function
  };
})(jQuery);
