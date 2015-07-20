<article<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
     <div class="header-info">
        <div class="article-create-date"><i class="fa fa-clock-o themecolor-text"></i><span class="label"><?php print t("Create"); ?>: </span><?php print date('m/d/Y - H:i',$node->created); ?></div>
        <div class="article-author"><i class="fa fa-user themecolor-text"></i><span class="label"><?php print t("Author"); ?>: </span><?php print $node->name; ?></div>
        <div class="article-addthis"><?php print render($content['field_addthis']); ?></div>
        
      </div>  
  <?php endif; ?>  
  
  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_addthis']);
      print render($content);
    ?>
  </div>
  
  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
</article>
