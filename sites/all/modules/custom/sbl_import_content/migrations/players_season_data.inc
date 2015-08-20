<?php

/**
 * Class ImportPlayerSeasondataMigration
 * Import the field collection for players season data into the 'spieler' content type
 */

class ImportPlayerSeasondataMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    // Human-friendly description of your migration process. Be as detailed as
    // you like.
    $this->description = t('Import Schachbundesliga players season data into a field collection inside the "spieler" content type from a CSV file');

    // Make sure there have been player nodes imported before the field collection
    $this->dependencies = array('import_players');

    // Choose the columns from the CSV file and write them into the $columns array
    $columns = array(
      0 => array('season', 'Saison'),
      //1 => array('team', 'VER'),
      2 => array('fide_id', 'ID_NUMBER'),
      3 => array('master_title', 'TITLE'),
      //4 => array('country', 'COUNTRY'),
      5 => array('elo_rating', 'RO'),
    );

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceCSV('sites/default/files/csv-import/players-season-data-1.csv', $columns, array('header_rows' => 1));

    // Set up our destination. We need to attach the field collection to our host entity type, in this case a node
    $this->destination = new MigrateDestinationFieldCollection(
      'field_sp_verein',
      array('host_entity_type' => 'node')
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'fide_id' => array('type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Fide ID',
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );

    // The link to the map field of the source migration: the Fide ID
    $this->addFieldMapping('host_entity_id', 'fide_id')->sourceMigration('import_players');
    // Field Mappings for the Field Collection fields
    $this->addFieldMapping('field_saison', 'season');
    //$this->addFieldMapping('field_fc_verein', 'team');
    $this->addFieldMapping('field_pl_master_title', 'master_title');
    //$this->addFieldMapping('field_pl_country', 'country');
    $this->addFieldMapping('field_pl_elo', 'elo_rating');

  }
}