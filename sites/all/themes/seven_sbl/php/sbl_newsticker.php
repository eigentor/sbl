<?php
header('content-type:application/x-javascript;charset=utf-8');
?>
document.write('<meta charset="utf-8" />');
<?php
function find_image($var) {
$pattern = '/resource=\"(.*?)\?/';
preg_match($pattern, $var, $matches);
return $matches[1];
}

function cleanup_text ($var) {
	#$var=utf8_decode($var);
	return $var;
}

function find_description($var) {
$matches=explode('<div class="field-item even">',$var);
return cleanup_text($matches[1]);
}
if($_GET["design"]=="full") $_GET["design"]="breit";
if($_GET["design"]=="headlines") $_GET["design"]="schmal";

if(!isset($_GET["anzahl_beitrage"]) || $_GET["anzahl_beitraege"] < 1 || $_GET["anzahl_beitraege"] > 5) $_GET["anzahl_beitrage"]=1;
if(strlen($_GET["headlinecolor"]) > 0) $_GET["headlinecolor"]="#".$_GET["headlinecolor"];
else $_GET["headlinecolor"]="#f5f5f5";
if(strlen($_GET["backgroundcolor"]) > 0) $_GET["backgroundcolor"]="#".$_GET["backgroundcolor"];
else $_GET["backgroundcolor"]="#f5f5f5";
if(!isset($_GET["design"])) $_GET["design"]="breit";
?>


document.write('<div class="panel panel-default"><div class="panel-heading"><b>Schachbundesliga News</b></div><div class="panel-body"><div class="row"><div class="col-xs-12"><ul class="demo">');
<?php
$xml=simplexml_load_file("http://schachbundesliga.de/aktuell.xml") or die("Fehler: Feed konnte nicht geladen werden");
for($i=0;$i<=5;$i++) {
$title=$xml->channel->item[$i]->title;
$link=$xml->channel->item[$i]->link;
$description=$xml->channel->item[$i]->description;
$bild=find_image($description);
$beschreibung=find_description($description);
?>
document.write('<li class="news-item"><table cellpadding="4" class="newstable">');
<?php if($_GET["design"]=="schmal") { ?>
document.write('<tr><td style="text-align:center;"><a href="<?=$link?>"><img src="<?=$bild?>" width="150" /></a></td></tr><tr><td style="background-color:<?=$_GET["headlinecolor"]?>" class="headline-cell"><a href="<?=$link?>"><?=cleanup_text($title)?></a></td></tr></table></li>');
<?php
}
else {
?>
document.write('<tr><td style="text-align:center;"><a href="<?=$link?>"><img src="<?=$bild?>" width="100" /></a></td></tr><tr><td style="background-color:<?=$_GET["headlinecolor"]?>" class="headline-cell"><a href="<?=$link?>"><?=cleanup_text($title)?></a></td></tr><tr><td class="headline-cell" style="background-color:<?=$_GET["background-color"]?>"><?php echo substr($beschreibung, 0, strpos($beschreibung, ' ', 150));?>... <a href="<?=$link?>">[mehr]</a></td></tr></table></li>');
<?php
}
}
?>
document.write('</ul></div></div></div><div class="panel-footer"><a href="http://www.schachbundesliga.de/aktuell" title="Mehr News"><img src="http://schachbundesliga.de/sites/all/themes/seven_sbl/php/images/logo.png" style="margin-left:5px;" /></a></div></div>');

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