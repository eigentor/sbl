<?php

class ImportPlayerMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    // Human-friendly description of your migration process. Be as detailed as
    // you like.
    $this->description =
      t('Import Schachbundesliga players from a CSV file');


    // Create a MigrateSource object, which manages retrieving the input data.
    $columns = array(
      0 => array('id', 'User ID'),
      3 => array('fname', 'First Name'),
      4 => array('lname', 'Last Name'),
    );
    $this->source = new MigrateSourceCSV('/sites/default/files/csv-import/players-1.csv', $columns);

    // Set up our destination
    $this->destination =
      new MigrateDestinationTerm('migrate_example_beer_styles');

    // Create a map object for tracking the relationships between source rows
    // and their resulting Drupal objects. We will use the MigrateSQLMap class,
    // which uses database tables for tracking. Pass the machine name (BeerTerm)
    // of this migration to use in generating map and message table names.
    // And, pass schema definitions for the primary keys of the source and
    // destination - we need to be explicit for our source, but the destination
    // class knows its schema already.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'style' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'Topic ID',
                          )
        ),
        MigrateDestinationTerm::getKeySchema()
      );
  }
}