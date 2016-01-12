(function ($) {
  // Scripte als Drupal Behaviors hinzufuegen statt als document.ready.
  // Funktioniert dann auch bei Ajax Reloads.
  Drupal.behaviors.sbl_helper_form_submit = {
    attach: function (context, settings) {
      $('#teamseite #tabs-0-bottom li.first a').text('Kader');
    } // end of attach function
  };
})(jQuery);