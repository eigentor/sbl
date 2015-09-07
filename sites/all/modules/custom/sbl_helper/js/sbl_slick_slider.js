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




    } // end of attach function
  };
})(jq111); // This makes sure everything above uses Jquery 1.11
