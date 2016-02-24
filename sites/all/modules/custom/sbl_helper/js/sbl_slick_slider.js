(function ($) {

  // Scripte als Drupal Behaviors hinzufuegen statt als document.ready.
  // Funktioniert dann auch bei Ajax Reloads.
  Drupal.behaviors.sbl_helper = {
    attach: function (context, settings) {

//Die Header Slideshow auf der Startseite
$('.front .view-article-slider-large.view-display-id-block .view-content').slick({
    dots: true,
    arrows: false,
    infinite: true,
    autoplay: true,
    autoplaySpeed: 4000,
    fade: true,
    speed: 700,
    slidesToShow: 1,
    slidesToScroll: 1,
    slide: 'div.views-row',
    asNavFor: '.front .view-article-slider-large.view-display-id-block_1 .view-content'
});

$('.front .view-article-slider-large.view-display-id-block_1 .view-content').slick({
    dots: false,
    arrows: false,
    infinite: false,
    autoplay: false,
    slidesToShow: 4,
    slidesToScroll: 4,
    //rows: 4,
    //SlidesPerRow: 4,
    vertical: true,
    slide: 'div.views-row',
    asNavFor: '.front .view-article-slider-large.view-display-id-block .view-content',
    focusOnSelect: true
});

// Set an active class for the active thumbnail
// Get the initial active slide on page load
var active_slide = $('.front .view-article-slider-large.view-display-id-block .views-row.slick-active').index();
var number_thumb = $('.front .view-article-slider-large.view-display-id-block_1 .views-row').get(active_slide);
$(number_thumb).addClass('active-thumb');
$(number_thumb).siblings().removeClass('active-thumb');
$(number_thumb).prepend('<span class="active-arrow"></span>');
$(number_thumb).siblings().find('span.active-arrow').remove();



// We need to call it as Slick event
// On before slide change
$('.front .view-article-slider-large.view-display-id-block .view-content').on('beforeChange', function(event, slick, currentSlide, nextSlide) {
    active_slide = $('.front .view-article-slider-large.view-display-id-block .views-row.slick-active').index();
    if(active_slide == 3) {
        active_slide = 0;
    } else {
        active_slide = active_slide + 1;
    }

    var number_thumb = $('.front .view-article-slider-large.view-display-id-block_1 .views-row').get(active_slide);
    $(number_thumb).addClass('active-thumb');
    $(number_thumb).siblings().removeClass('active-thumb');
    $(number_thumb).prepend('<span class="active-arrow"></span>');
    $(number_thumb).siblings().find('span.active-arrow').remove();

});

// Position the slick slider dots for smartphone

var window_width = $(document).width();

if(window_width < 600) {
    var image_height = $('.front #block-views-article-slider-large-block .views-row .views-field-field-image img').height();
    var dots_position = image_height -45;
    $('.front #block-views-article-slider-large-block .slick-dots').css({'bottom' : 'auto', 'top' : dots_position});
}
 $(window).resize(function() {
     var window_width = $(document).width();
     if(window_width < 600) {
         image_height = $('.front #block-views-article-slider-large-block .views-row .views-field-field-image img').height();
         dots_position = image_height - 45;
         $('.front #block-views-article-slider-large-block .slick-dots').css({'bottom': 'auto', 'top': dots_position});
     } else {
         $('.front #block-views-article-slider-large-block .slick-dots').css({'bottom': '', 'top': ''});
     }
});






//$('.front #block-views-article-slider-large-block .slick-dots').css({'bottom' : title_height});

// Set the position of the slick navigation dots again after a slide change
//$('.front .view-article-slider-large.view-display-id-block .view-content').on('afterChange', function(event, slick, currentSlide, nextSlide) {
//    // Position the Slick navigation dots for the slideshow on the front page
//    var title_height = $('.front #block-views-article-slider-large-block .views-row.slick-current .views-field-title').outerHeight(true);
//    console.log(title_height);
//    $('.front #block-views-article-slider-large-block .slick-dots').css({'bottom' : title_height});
//});

$('.front .view-article-slider-large.view-display-id-block_1 .views-row').click(function(){
    $(this).addClass('active-thumb');
    $(this).siblings().removeClass('active-thumb');
    $(this).prepend('<span class="active-arrow"></span>');
    $(this).siblings().find('span.active-arrow').remove();
});

//Die Live-Leiste
$('.front .view-live-bar .view-content').slick({
    dots: false,
    arrows: true,
    fade: true,
    speed: 700,
    slidesToShow: 1,
    slidesToScroll: 1,
    slide: 'div.row-wrapper',
});








    } // end of attach function
  };
})(jq111); // This makes sure everything above uses Jquery 1.11
