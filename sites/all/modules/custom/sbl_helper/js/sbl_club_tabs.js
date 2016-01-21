(function ($) {
  // Scripte als Drupal Behaviors hinzufuegen statt als document.ready.
  // Funktioniert dann auch bei Ajax Reloads.
  Drupal.behaviors.sbl_helper_form_submit = {
    attach: function (context, settings) {
      $('#teamseite #tabs-0-bottom li.first a').text('Kader');
      $('#teamseite #tabs-0-bottom li.last a').text('Ergebnisse');

      // Die Scrollposition beibehalten, wenn man auf den Pager klickt
      var elementToTest = $("body.page-verein");
      if(elementToTest.length > 0) {
        $(window).scrollTop(window.name);
        window.name = 0;
      }

      $('#teamseite .results-pager a').click(function(){
        window.name = $(window).scrollTop();
      });

    } // end of attach function
  };
})(jQuery);