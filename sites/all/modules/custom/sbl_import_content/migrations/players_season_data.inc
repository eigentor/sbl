<?php

class ImportPlayerSeasondataMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    // Human-friendly description of your migration process. Be as detailed as
    // you like.
    $this->description = t('Import Schachbundesliga players season data into a field collection inside the "spieler" content type from a CSV file');


    // Create a MigrateSource object, which manages retrieving the input data.
    $columns = array(
      0 => array('season', 'Saison'),
      1 => array('team', 'VER'),
      3 => array('master_title', 'TITLE'),
      4 => array('country', 'COUNTRY'),
      5 => array('elo_rating', 'RO'),
    );
    $this->source = new MigrateSourceCSV('sites/default/files/csv-import/players-season-data-1.csv', $columns, array('header_rows' => 1));

    // Set up our destination. Since we migrate to a content type, the content type machine name "spieler" is given as an attribute.
    $this->destination = new MigrateDestinationNode('spieler');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'fide_id' => array('type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Fide ID',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('field_pl_last_name', 'last_name');
    $this->addFieldMapping('field_pl_first_name', 'first_name');
    $this->addFieldMapping('field_pl_acad_title', 'acad_title');
    $this->addFieldMapping('title', 'combined_name');
    $this->addFieldMapping('field_fide_id', 'fide_id')
      ->callbacks(array($this, 'cleanFideid'));

  }
  // Trim the Fide ID and convert to Number
  protected function cleanFideid($value) {
    // Make sure there are no White Spaces before and after the Fide IDs when importing
    $value = trim($value);
    $value = preg_replace('/\s+/', '', $value);
    return $value;
  }
}