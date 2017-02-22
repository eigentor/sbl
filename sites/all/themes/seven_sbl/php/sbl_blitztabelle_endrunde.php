<?php
header('content-type:application/x-javascript;charset=utf-8');
$bgcolor=strlen($_GET["bgcolor"])>=3?str_replace("#","",$_GET["bgcolor"]):"f18000";
$linkcolor=strlen($_GET["linkcolor"])>=3?str_replace("#","",$_GET["linkcolor"]):"f18000";
$headingcolor=strlen($_GET["headingcolor"])>=3?str_replace("#","",$_GET["headingcolor"]):"ffffff";
$bordercolor=strlen($_GET["bordercolor"])>=3?str_replace("#","",$_GET["bordercolor"]):"f18000";
$target=strlen($_GET["target"])>=3?$_GET["target"]:"_self";
?>
document.write('<meta charset="utf-8" />');
<?php
/*
bgcolor: Die Hintergrundfarbe des Headers und Footers der Tabelle.
linkcolor: Die Farbe der Links, also der Vereinsnamen und des Links "Zur ausführlichen Tabelle"
headingcolor: Die Farbe der Tabellenüberschrift. Diese ist aktuell weiß, aber wenn Sie für bgcolor einen hellen Farbton wählen, müssen Sie die Tabellenüberschrift entsprechend dunkler machen, da man sie sonst nicht mehr sieht.
*/

function transform_link($linktext,$saison) {
	$linktext=str_replace("schachbundesliga.de/","schachbundesliga.de/verein/",$linktext);
	$linktext.="/".$saison;
	echo $linktext;
}
?>
document.writeln('<link rel="stylesheet" href="http://schachbundesliga.de/sites/all/themes/seven_sbl/php/css/custom_tabelle.css"/>');

document.write('<div class="panel panel-default" style="border:1px solid #<?=$bordercolor?> !important;"><div class="panel-body-table"><table class="views-table cols-3 footable">');
document.write('<thead><tr><th colspan="3" class="panel-heading-table" style="background-color:#<?=$bgcolor?>;color:#<?=$headingcolor?>">Tabelle</th></tr>');
document.write('<tr><th class="views-field views-field-counter">Pl.</th><th class="views-field views-field-php-2">Team</th><th class="views-field views-field-php-3">MP</th></tr>');
document.write('</thead>');

<?php
$xml=simplexml_load_file("http://www.schachbundesliga.de/tabelle.xml") or die("Fehler: Feed konnte nicht geladen werden");
$saisonstring=explode("/",$xml->channel->link[0]);
$aktuelle_saison=$saisonstring[4];
#echo $aktuelle_saison;
for($i=0;$i<=15;$i++) {
$rang=$xml->channel->item[$i]->title;
$linktext=$xml->channel->item[$i]->link;
$mannschaft=$xml->channel->item[$i]->description;
$mapu=$xml->channel->item[$i]->guid;
#$brepu=$xml->channel->item[$i]->pubDate;
?>
document.write('<tr<?php echo bcmod($i,2)==0?" class=\"odd\"":" class=\"even\"";?>><td class="views-field views-field-counter"><?=$rang?></td><td class="team_text_left"><a href="<?php transform_link($linktext,$aktuelle_saison); ?>" class="link_to_team" style="color:#<?=$linkcolor?> !important;" target="<?=$target?>"><?=$mannschaft?></a></td>');
document.write('<td class="views-field views-field-php-2"><?=$mapu?></td></tr>');

<?php
}
?>
document.write('</table></div></div>');
