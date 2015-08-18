<?php

class ImportPlayerMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    // Human-friendly description of your migration process. Be as detailed as
    // you like.
    $this->description =
      t('Import Schachbundesliga players from a CSV file');
  }
}