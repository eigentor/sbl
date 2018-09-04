<html>

<head>
<?php
$bgcolor=strlen($_GET["bgcolor"])>=3?str_replace("#","",$_GET["bgcolor"]):"f18000";
$headingcolor=strlen($_GET["headingcolor"])>=3?str_replace("#","",$_GET["headingcolor"]):"ffffff";
$bordercolor=strlen($_GET["bordercolor"])>=3?str_replace("#","",$_GET["bordercolor"]):"f18000";
$bodycolor=strlen($_GET["bodycolor"])>=3?str_replace("#","",$_GET["bodycolor"]):"ffffff";
?>
<meta charset="utf-8" />
<link rel="stylesheet" href="https://www.schachbundesliga.de/sites/all/themes/seven_sbl/php/css/custom.css"/>
<link rel="stylesheet" href="https://www.schachbundesliga.de/sites/all/themes/seven_sbl/php/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script>
<script type="text/javascript" src="https://www.schachbundesliga.de/sites/all/themes/seven_sbl/php/js/jquery.bootstrap.newsbox.js"></script>
</head>


<?php
function find_image($var) {
$pattern = '/resource=\"(.*?)\?/';
preg_match($pattern, $var, $matches);
$image=str_replace("medium","article_list",$matches[1]);
#if(ereg("articles",$matches[1])) return $matches[1];
#else {
#$image="https://schachbundesliga.de/sites/all/themes/seven_sbl/php/images/placeholder.jpg";
return $image;
}



function find_description($var) {
$matches=explode('<div class="field-item even">',$var);
$b=$matches[1];
#@mail("marc.lang@gobsy.de","",$b);
return $b;
}
if($_GET["design"]=="full") $_GET["design"]="breit";
if($_GET["design"]=="headlines") $_GET["design"]="schmal";

if(!isset($_GET["anzahl_beitrage"]) || $_GET["anzahl_beitraege"] < 1 || $_GET["anzahl_beitraege"] > 5) $_GET["anzahl_beitrage"]=1;
if(!isset($_GET["design"])) $_GET["design"]="breit";
?>

<body style="background-color:#<?=$bodycolor?>;">

<div class="panel panel-default" style="border:1px solid #<?=$bordercolor?> !important;"><div class="panel-heading" style="background-color:#<?=$bgcolor?>;color:#<?=$headingcolor?>"><b>Schachbundesliga News</b></div><div class="panel-body"><div class="row"><div class="col-xs-12"><ul class="demo">
<?php
$xml=simplexml_load_file("https://schachbundesliga.de/aktuell_extern.xml") or die("Fehler: Feed konnte nicht geladen werden");
for($i=0;$i<=5;$i++) {
$title=$xml->channel->item[$i]->title;
$link=$xml->channel->item[$i]->link;
$description=$xml->channel->item[$i]->description;
$bild=find_image($description);
$beschreibung=find_description($description);
?>
<li class="news-item"><table cellpadding="4" class="newstable">
<?php if($_GET["design"]=="schmal") { ?>
<tr><td style="text-align:center;"><a href="<?=$link?>" target="_blank"><img src="<?=$bild?>" width="150" /></a></td></tr><tr><td style="background-color:<?=$_GET["headlinecolor"]?>" class="headline-cell"><a href="<?=$link?>" target="_blank"><?=$title?></a></td></tr></table></li>
<?php
}
else {
?>
<tr><td style="text-align:center;"><a href="<?=$link?>" target="_blank"><img src="<?=$bild?>" width="150" /></a></td></tr><tr><td style="background-color:<?=$_GET["headlinecolor"]?>" class="headline-cell"><a href="<?=$link?>" target="_blank"><?=$title?></a></td></tr><tr><td class="headline-cell" style="background-color:<?=$_GET["background-color"]?>"><?php echo strlen($beschreibung) >=100?substr($beschreibung, 0, strpos($beschreibung, ' ', 100)):$beschreibung;?>... <a href="<?=$link?>" target="_blank">[mehr]</a></td></tr></table></li>
<?php
}
}
?>
</ul></div></div></div><div class="panel-footer" style="background-color:#<?=$bgcolor?>"><a href="https://www.schachbundesliga.de/aktuell" title="Mehr News" target="_blank"><img src="https://schachbundesliga.de/sites/all/themes/seven_sbl/php/images/logo.png" style="margin-left:5px;" /></a></div></div>

<script type="text/javascript">
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
</script>

</body>

</html>

