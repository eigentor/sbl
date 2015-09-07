<?php
/**
 * @file
 * sbl_slideshow.features.inc
 */

/**
 * Implements hook_views_api().
 */
function sbl_slideshow_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sbl_slideshow_image_default_styles() {
  $styles = array();

  // Exported image style: article_slideshow_large.
  $styles['article_slideshow_large'] = array(
    'label' => 'article_slideshow_large',
    'effects' => array(
      29 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 880,
          'height' => 425,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: article_slideshow_thumb.
  $styles['article_slideshow_thumb'] = array(
    'label' => 'Article Slideshow Thumb',
    'effects' => array(
      37 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 65,
          'height' => 52,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
