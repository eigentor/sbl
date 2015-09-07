<?php
/**
 * @file
 * sbl_kontext.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function sbl_kontext_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aktuell';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aktuell' => 'aktuell',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-klubnews-block_1' => array(
          'module' => 'views',
          'delta' => 'klubnews-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-topic_cuture-block_2' => array(
          'module' => 'views',
          'delta' => 'topic_cuture-block_2',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'simplenews-120' => array(
          'module' => 'simplenews',
          'delta' => '120',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['aktuell'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aktuell_bundesliga';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aktuell/bundesliga' => 'aktuell/bundesliga',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-latest_news-block_3' => array(
          'module' => 'views',
          'delta' => 'latest_news-block_3',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'simplenews-120' => array(
          'module' => 'simplenews',
          'delta' => '120',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['aktuell_bundesliga'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aktuell_interviews';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aktuell/interviews' => 'aktuell/interviews',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-latest_news-block_4' => array(
          'module' => 'views',
          'delta' => 'latest_news-block_4',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'simplenews-120' => array(
          'module' => 'simplenews',
          'delta' => '120',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['aktuell_interviews'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aktuell_klubnews';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aktuell/klubnews' => 'aktuell/klubnews',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-latest_news-block_5' => array(
          'module' => 'views',
          'delta' => 'latest_news-block_5',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'simplenews-120' => array(
          'module' => 'simplenews',
          'delta' => '120',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['aktuell_klubnews'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aktuell_kolumnen';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aktuell/kolumnen' => 'aktuell/kolumnen',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'simplenews-120' => array(
          'module' => 'simplenews',
          'delta' => '120',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['aktuell_kolumnen'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aktuell_schachnews';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aktuell/schachnews' => 'aktuell/schachnews',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-latest_news-block_6' => array(
          'module' => 'views',
          'delta' => 'latest_news-block_6',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'simplenews-120' => array(
          'module' => 'simplenews',
          'delta' => '120',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['aktuell_schachnews'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aktuell_spielberichte';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aktuell/spielberichte' => 'aktuell/spielberichte',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-latest_news-block_2' => array(
          'module' => 'views',
          'delta' => 'latest_news-block_2',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'simplenews-120' => array(
          'module' => 'simplenews',
          'delta' => '120',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['aktuell_spielberichte'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aktuell_ulis_kommentar';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aktuell/kolumnen' => 'aktuell/kolumnen',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'simplenews-120' => array(
          'module' => 'simplenews',
          'delta' => '120',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['aktuell_ulis_kommentar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aktuell_ullis_randnotizen';
  $context->description = '';
  $context->tag = 'article';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aktuell/ullis-randnotizen' => 'aktuell/ullis-randnotizen',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-video-block_1' => array(
          'module' => 'views',
          'delta' => 'video-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'simplenews-120' => array(
          'module' => 'simplenews',
          'delta' => '120',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('article');
  $export['aktuell_ullis_randnotizen'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact';
  $context->description = 'Layout des Kontaktformulars';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'schachbundesliga/kontakt' => 'schachbundesliga/kontakt',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-16' => array(
          'module' => 'block',
          'delta' => '16',
          'region' => 'content',
          'weight' => '-25',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout des Kontaktformulars');
  t('pages');
  $export['contact'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home-default';
  $context->description = 'Layout der Startseite';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-article_slider_large-block' => array(
          'module' => 'views',
          'delta' => 'article_slider_large-block',
          'region' => 'submenu',
          'weight' => '-10',
        ),
        'views-article_slider_large-block_1' => array(
          'module' => 'views',
          'delta' => 'article_slider_large-block_1',
          'region' => 'submenu',
          'weight' => '-9',
        ),
        'views-topic_trending-block_1' => array(
          'module' => 'views',
          'delta' => 'topic_trending-block_1',
          'region' => 'content_bottom_first',
          'weight' => '-10',
        ),
        'views-klubnews-block_1' => array(
          'module' => 'views',
          'delta' => 'klubnews-block_1',
          'region' => 'content_bottom_first',
          'weight' => '-9',
        ),
        'views-video-block' => array(
          'module' => 'views',
          'delta' => 'video-block',
          'region' => 'content_bottom_first',
          'weight' => '-8',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-19' => array(
          'module' => 'block',
          'delta' => '19',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout der Startseite');
  t('home');
  $export['home-default'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'partien';
  $context->description = '';
  $context->tag = 'pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'partien/*' => 'partien/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-photos-block_1' => array(
          'module' => 'views',
          'delta' => 'photos-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('pages');
  $export['partien'] = $context;

  return $export;
}
