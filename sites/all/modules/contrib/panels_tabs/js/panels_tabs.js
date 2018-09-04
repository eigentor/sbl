(function ($) {

/**
 * JS related to the tabs in the Panels tabs.
 */
Drupal.behaviors.panelsTabs = {
  attach: function (context) {
    var tabsID = Drupal.settings.panelsTabs.tabsID;

     var options = {};
     try {
         // If local storage is available, use it to remember the last selected tab.
        var test = 'test';
        localStorage.setItem(test, test);
        localStorage.getItem(test);
        options = {
           active: localStorage.getItem("panelsTabsCurrent"),
            activate: function (event, ui) {
              localStorage.setItem("panelsTabsCurrent", $(this).tabs('option', 'active'));
            }
        };
      } catch(e) {
        // Let options remain empty.
      }


    for (var key in Drupal.settings.panelsTabs.tabsID) {
      $('#' + tabsID[key] +':not(.tabs-processed)', context)
        .addClass('tabs-processed')
        .tabs(options);
    }
  }
};

})(jQuery);
