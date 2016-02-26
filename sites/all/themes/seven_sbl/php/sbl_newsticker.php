<?php
header('Content-Type: application/javascript');
function find_image($var) {
$pattern = '/resource=\"(.*?)\?/';
preg_match($pattern, $var, $matches);
return $matches[1];
}
?>

document.write('<div class="panel panel-default"><div class="panel-heading"> <span class="glyphicon glyphicon-list-alt"></span><b>Schachbundesliga News</b></div><div class="panel-body"><div class="row"><div class="col-xs-12"><ul class="demo">');
<?php
$xml=simplexml_load_file("http://schachbundesliga.de/aktuell.xml") or die("Fehler: Feed konnte nicht geladen werden");
for($i=0;$i<=5;$i++) {
$title=substr($xml->channel->item[$i]->title,50). "[...]";
$link=$xml->channel->item[$i]->link;
$description=$xml->channel->item[$i]->description;
$bild=find_image($description);
?>
document.write('<li class="news-item"><table cellpadding="4"><tr><td><img src="<?=$bild?>" width="60" style="margin:0px 5px 0;" /></td><td><a href="<?=$link?>"><?=$title?></a></td></tr></table></li>');
<?php
}
?>
document.write('</ul></div></div></div><div class="panel-footer"><img src="images/logo.png" style="margin-left:5px;" /></div></div>');

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
