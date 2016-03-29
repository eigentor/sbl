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
        .add('th.views-field-php-4')
		.add('th.views-field-php-5')
        .attr('data-sort', 'int').attr('data-sort-default', 'desc');

      $('th.views-field-title')
        .attr('data-sort', 'string');
      $(".view-players-leaderboard table td.views-field-nothing").each(function(index) {
        $(this).html(index + 1);
      });

       $(".view-players-leaderboard table").stupidtable();

      $('.view-players-leaderboard table th').click(function(){
        setTimeout(function(){
          $('.view-players-leaderboard table td.views-field-nothing').each(function(index) {
            $(this).html(index + 1);
          });
        }, 300);
      });





    } // end of attach function
  };
})(jQuery);