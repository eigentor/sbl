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
      1 => array('team', 'VER'),
      2 => array('fide_id', 'ID_NUMBER'),
      3 => array('master_title', 'TITLE'),
      //4 => array('country', 'COUNTRY'),
      5 => array('elo_rating', 'RO'),
      6 => array('year_id', 'Jahres-ID'),
    );

    $module_path = drupal_get_path('module', 'sbl_import_content');

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceCSV($module_path . '/csv/players-season-data-2014.csv', $columns, array('header_rows' => 1));

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
    $this->addFieldMapping('field_fc_verein', 'team')
      ->callbacks(array($this, 'replaceTeamname'));
    $this->addFieldMapping('field_pl_master_title', 'master_title');
    //$this->addFieldMapping('field_pl_country', 'country');
    $this->addFieldMapping('field_pl_elo', 'elo_rating');
    $this->addFieldMapping('field_year_id', 'year_id');

  }

  /**
   * Function to replace team name Abbrevations with the full names
   */
  protected function replaceTeamname($value) {
    $team_mapping = array (
      'BAD' => 'OSG Baden-Baden',
      'BAY' => 'FC Bayern München',
      'DOR' => 'SC Hansa Dortmund',
      'DRE' => 'USV TU Dresden',
      'EMS' => 'SK Turm Emsdetten',
      'EPP' => 'SC Eppingen',
      'ERF' => 'Erfurter SK',
      'GRI' => 'SV Griesheim',
      'HOC' => 'SV 1930 Hockenheim',
      'HSK' => 'Hamburger SK',
      'KAT' => 'SF Katernberg',
      'MUL' => 'SV Mülheim Nord',
      'NOR' => 'SK Norderstedt 1975',
      'ROS' => 'SSC Rostock 07',
      'SFB' => 'SF Berlin 1903',
      'SHA' => 'SK Schwäbisch Hall',
      'SOL' => 'SG Solingen',
      'TRI' => 'SG Trier',
      'WBR' => 'Werder Bremen',
    );
    if(array_key_exists($value, $team_mapping)) {
      $value = $team_mapping[$value];
    }
    // Get the Verein Node IDs from the node titles
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'mannschaft')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyCondition('title', $value)
      ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

    $result = $query->execute();

    if (isset($result['node'])) {
      $mannschaft_nids = array_keys($result['node']);
      $value = $mannschaft_nids[0];
    }

    return $value;
  }
}