(function ($) {
  // Scripte als Drupal Behaviors hinzufuegen statt als document.ready.
  // Funktioniert dann auch bei Ajax Reloads.
  Drupal.behaviors.sbl_helper_stupidtable = {
    attach: function (context, settings) {

      $('th.views-field-field-pl-elo')
        .add('th.views-field-php')
        .add('th.views-field-php-1')
        .add('th.views-field-php-2')
        .add('th.views-field-php-3')
        .attr('data-sort', 'int');

       $(".view-players-leaderboard table").stupidtable()

    } // end of attach function
  };
})(jQuery);