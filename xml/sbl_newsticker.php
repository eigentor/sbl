<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title>jQuery Bootstrap News Box Plugin Demos</title>
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

<?php

function find_image($var) {
$pattern = '/resource=\"(.*?)\?/';
preg_match($pattern, $var, $matches);
return $matches[1];
}
?>

</head>

<body>

<div class="panel panel-default">
<div class="panel-heading"> <span class="glyphicon glyphicon-list-alt"></span><b>Schachbundesliga News</b></div>
<div class="panel-body">
<div class="row">
<div class="col-xs-12">
<ul class="demo">

<?php
$xml=simplexml_load_file("aktuell.xml") or die("Fehler: Feed konnte nicht geladen werden");
for($i=0;$i<=5;$i++) {
$title=$xml->channel->item[$i]->title;
$link=$xml->channel->item[$i]->link;
$description=$xml->channel->item[$i]->description;
$bild=find_image($description);
?>
<li class="news-item">
<table cellpadding="4">
<tr>
<td><img src="<?=$bild?>" width="60" style="margin:0px 5px 0;" /></td>
<td><a href="<?=$link?>"><?=$title?></a></td>
</tr>
</table>
</li>
<?php
}
?>

</ul>
</div>
</div>
</div>
<div class="panel-footer"><img src="images/logo.png" style="margin-left:5px;" />
</div>

<script type="text/javascript">
$(function () {
$(".demo").bootstrapNews({
newsPerPage: 3,
navigation: true,
autoplay: true,
direction:'up', // up or down
animationSpeed: 'normal',
newsTickerInterval: 8000, //8 secs
pauseOnHover: true,
onStop: null,
onPause: null,
onReset: null,
onPrev: null,
onNext: null,
onToDo: null
});
});
</script>

