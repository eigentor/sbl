<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title>Schachbundesliga Blitztabelle</title>
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<link rel="stylesheet" href="http://netdna.bootstrapcdn.com/bootstrap/3.1.0/css/bootstrap.min.css">
<link rel="stylesheet" href="http://netdna.bootstrapcdn.com/bootstrap/3.1.0/css/bootstrap-theme.min.css">
<link href="css/site.css" rel="stylesheet" type="text/css" />
<link href="http://www.jqueryscript.net/css/jquerysctipttop.css" rel="stylesheet" type="text/css">
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script>
<script src="scripts/jquery.bootstrap.newsbox.min.js" type="text/javascript"></script>

<style type="text/css">
.glyphicon {
margin-right: 4px !important; /*override*/
}
.pagination .glyphicon {
margin-right: 0px !important; /*override*/
}
.pagination a {
color: #555;
}
.panel ul {
padding: 0px;
margin: 0px;
list-style: none;
}
.news-item {
padding: 4px 4px;
margin: 0px;
border-bottom: 1px dotted #555;
}
</style>

</head>

<body>

<div class="panel panel-default">
<div class="panel-heading"> <span class="glyphicon glyphicon-list-alt"></span><b>Schachbundesliga Tabelle</b></div>
<div class="panel-body">
<div class="row">
<div class="col-xs-12">
<table class="views-table cols-4 footable">
<thead>
<tr>
<th class="views-field views-field-counter">Pl.</th>
<th class="views-field views-field-php-2">Team</th>
<th class="views-field views-field-php-3">MP</th>
<th class="views-field views-field-php-4">BP</th>

</tr>
</thead>
<?php
$xml=simplexml_load_file("http://www.schachbundesliga.de/tabelle.xml") or die("Fehler: Feed konnte nicht geladen werden");
$saisonstring=explode("/",$xml->channel->link[0]);
$aktuelle_saison=$saisonstring[4];
echo $aktuelle_saison;
for($i=0;$i<=15;$i++) {
$rang=$xml->channel->item[$i]->title;
$mannschaft=$xml->channel->item[$i]->description;
$mapu=$xml->channel->item[$i]->guid;
$brepu=$xml->$xml->channel->item[$i]->pubDate;
?>
<tr<?php echo bcmod($i,2)==0?" class='odd'":"class='even'";?>>
<td class="views-field views-field-counter"><?=$rang?></td>
<td class="text-left"><?=$mannschaft?></td>
<td class="views-field views-field-php-2"><?=$mapu?></td>
<td class="views-field views-field-php-3"><?=$brepu?></td>
</tr>
<?php
}
?>


</table>
</div>
</div>
</div>
<div class="panel-footer"><img src="images/logo.png" style="margin-left:5px;" />
</div>

