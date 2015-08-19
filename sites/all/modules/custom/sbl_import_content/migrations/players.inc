<?php

class ImportPlayerMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    // Human-friendly description of your migration process. Be as detailed as
    // you like.
    $this->description = t('Import Schachbundesliga players from a CSV file');


    // Create a MigrateSource object, which manages retrieving the input data.
    $columns = array(
      0 => array('last_name', 'Nachname'),
      1 => array('first_name', 'First Name'),
      2 => array('acad_title', 'Akad. Titel'),
      3 => array('combined_name', 'Kombinierter Name'),
      4 => array('fide_id', 'ID_NUMBER'),
    );
    $this->source = new MigrateSourceCSV('sites/default/files/csv-import/players-1.csv', $columns, array('header_rows' => 1));

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

      // Trim the Fide ID and convert to Number
      protected function cleanFideid($value) {
       $value = trim($value, '1');
        return $value;
      }
  }
}