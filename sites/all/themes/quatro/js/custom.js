jQuery(document).ready(function(){
  jQuery("#schalter_fb").click(function(){
	  jQuery("#schalter_fb").css("background-color","#f18000");
jQuery("#schalter_tw").css("background-color","black");
     jQuery("#container_twitter").hide();
jQuery("#container_facebook").show();

    return false;
  })
});
jQuery(document).ready(function(){
  jQuery("#schalter_tw").click(function(){
	  jQuery("#schalter_fb").css("background-color","black");
jQuery("#schalter_tw").css("background-color","#f18000");
    jQuery("#container_facebook").hide();
jQuery("#container_twitter").show();
    return false;
  })
});

(function($) {
  /**
   * @todo
   */
  Drupal.behaviors.symphonyThemeColors = {
    attach: function (context) {
      $('body', context).once('block-theme-colors-showhide', function () {													   
        jQuery('.block-theme-colors .close').click(function(e){
		  e.preventDefault();
		  jQuery('.block-theme-colors .block-theme-color-content ').hide();
		  jQuery(this).hide();
		  jQuery('.block-theme-colors .open').show();
		});
		jQuery('.block-theme-colors .open').click(function(e){
          e.preventDefault();
		  jQuery('.block-theme-colors .block-theme-color-content ').show();
		  jQuery(this).hide();
		  jQuery('.block-theme-colors .close').show();
		});  
      });
    }
  };

  Drupal.behaviors.quatroAccordion = {
    attach: function () {
	   $('.block-accordion').accordion({
          heightStyle: 'content',
		  autoHeight: false
       });
    }
  };
  
  Drupal.behaviors.quatroTabs = {
    attach: function () {
	   $('.block-tabs').tabs();
    }
  };
  
  Drupal.behaviors.quatroToggle = {
    attach: function () {
        $('div.toggle_area').find('div.toggle_content').hide().end();
	  
	    $('div.toggle_label').click(function() {
          $(this).next().slideToggle();
	  	  if($(this).hasClass('active')) {
	        $(this).removeClass('active');
		  } else {
	        $(this).addClass('active');
		  }
        });
    }
  };
  Drupal.behaviors.hide_empty_table_rows = {
    attach: function () {
      $('.page-verein .view-id-players table').each(function(a, tbl) {
        var currentTableRows = $(tbl).find('tbody tr').length;
        $(tbl).find('th').each(function(i) {
            var remove = 0;
            var currentTable = $(this).parents('table');

            var tds = currentTable.find('tr td:nth-child(' + (i + 1) + ')');
            tds.each(function(j) { if ($(this).text().trim() === '') remove++; });

            if (remove == currentTableRows) {
                $(this).hide();
                tds.hide();
            }
        });
    });
    }
  };
})(jQuery);

jQuery(document).ready(function() {
jQuery('.tooltip').tooltipster();
});
