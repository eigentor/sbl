(function ($) {
  // Scripte als Drupal Behaviors hinzufuegen statt als document.ready.
  // Funktioniert dann auch bei Ajax Reloads.
  Drupal.behaviors.sbl_helper_form_submit = {
    attach: function (context, settings) {
       $('.block #select-season-form select#edit-set-season').change(function(){
           $('#select-season-form').submit();
       });
     } // end of attach function
  };
})(jQuery); // This makes sure everything above uses Jquery 1.11
