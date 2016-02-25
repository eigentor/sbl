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
<table cellpadding="4">
<tr>
<th>RNG</th>
<th>Teamn</th>

</tr>
<?php
$xml=simplexml_load_file("http://www.schachbundesliga.de/tabelle.xml") or die("Fehler: Feed konnte nicht geladen werden");
print_r($xml);
for($i=0;$i<=15;$i++) {
$platz=$xml->tabelle->platz[$i]->rng;
$team=$xml->tabelle->platz[$i]->team;
?>
<tr>
<td><?=$platz?>.</td>
<td><?=$team?></td>
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


