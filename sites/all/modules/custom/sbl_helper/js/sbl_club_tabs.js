(function ($) {
  // Scripte als Drupal Behaviors hinzufuegen statt als document.ready.
  // Funktioniert dann auch bei Ajax Reloads.
  Drupal.behaviors.sbl_helper_form_submit = {
    attach: function (context, settings) {
      $('#teamseite #tabs-0-bottom li.first a').text('Kader');
      // Set the board number for the results of each team

      $('.view-match-results.view-display-id-block_1 table tr').each(function() {
        count = $(this).index() + 1;
       $(this).find('td.views-field-counter').text(count);
      });
    } // end of attach function
  };
})(jQuery);