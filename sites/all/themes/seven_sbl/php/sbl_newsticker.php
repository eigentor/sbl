<?php
header('Content-Type: application/javascript');
function find_image($var) {
$pattern = '/resource=\"(.*?)\?/';
preg_match($pattern, $var, $matches);
return $matches[1];
}

function find_description($var) {
$pattern = '/field-item even\">/';
preg_match($pattern, $var, $matches);
return $matches[1];
}
if(!isset($_GET["anzahl_beitrage"]) || $_GET["anzahl_beitraege"] < 1 || $_GET["anzahl_beitraege"] > 5) $_GET["anzahl_beitrage"]=1;
if(strlen($_GET["headlinecolor"]) > 0) $_GET["headlinecolor"]="#".$_GET["headlinecolor"];
else $_GET["headlinecolor"]="#CCCCCC";
if(strlen($_GET["backgroundcolor"]) > 0) $_GET["backgroundcolor"]="#".$_GET["backgroundcolor"];
else $_GET["backgroundcolor"]="#f5f5f5";
if(!isset($_GET["design"])) $_GET["design"]="schmal";
?>

document.write('<div class="panel panel-default"><div class="panel-heading"> <span class="glyphicon glyphicon-list-alt"></span><b>Schachbundesliga News</b></div><div class="panel-body"><div class="row"><div class="col-xs-12"><ul class="demo">');
<?php
$xml=simplexml_load_file("http://schachbundesliga.de/aktuell.xml") or die("Fehler: Feed konnte nicht geladen werden");
for($i=0;$i<=5;$i++) {
$title=$xml->channel->item[$i]->title;
$link=$xml->channel->item[$i]->link;
$description=$xml->channel->item[$i]->description;
$bild=find_image($description);
$beschreibung=find_description($description);
?>
document.write('<li class="news-item"><table cellpadding="4">');
<?php if($_GET["design"]=="schmal") { ?>
document.write('<tr><td style="text-align:center;"><a href="<?=$link?>"><img src="<?=$bild?>" width="120" /></a></td></tr><tr><td style="background-color:<?=$_GET["headlinecolor"]?>"><a href="<?=$link?>"><?=$title?></a></td></tr></table></li>');
<?php
}
else {
?>
document.write('<tr><td><a href="<?=$link?>"><img src="<?=$bild?>" width="60" /></a></td><td style="background-color:<?=$_GET["headlinecolor"]?>"><a href="<?=$link?>"><?=$title?></a></td></tr><tr><td colspan="2" style="background-color:<?=$_GET["background-color"]?>"><?=substr($beschreibung,30)?></td></tr></table></li>');
<?php
}
}
?>
document.write('</ul></div></div></div><div class="panel-footer"><img src="http://schachbundesliga.de/sites/all/themes/seven_sbl/php/images/logo.png" style="margin-left:5px;" /></div></div>');

$(function () {
$(".demo").bootstrapNews({
newsPerPage: <?=$_GET["anzahl_beitraege"]?>,
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