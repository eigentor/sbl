<?php
header('content-type:application/x-javascript;charset=utf-8');
?>
document.write('<meta charset="utf-8" />');
<?php
function transform_link($linktext,$saison) {
	$linktext=str_replace("schachbundesliga.de/","schachbundesliga.de/verein/",$linktext);
	$linktext.="/".$saison;
	echo $linktext;
}
?>
document.writeln('<link rel="stylesheet" href="http://schachbundesliga.de/sites/all/themes/seven_sbl/php/css/custom_tabelle.css"/>');

document.write('<div class="panel panel-default"><div class="panel-body-table"><table class="views-table cols-3 footable">');
document.write('<thead><tr><th colspan="3" class="panel-heading-table">Schachbundesliga Tabelle</th></tr>');
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
document.write('<tr<?php echo bcmod($i,2)==0?" class=\"odd\"":" class=\"even\"";?>><td class="views-field views-field-counter"><?=$rang?></td><td class="team_text_left"><a href="<?php transform_link($linktext,$aktuelle_saison); ?>" class="link_to_team"><?=$mannschaft?></a></td>');
document.write('<td class="views-field views-field-php-2"><?=$mapu?></td>');

<?php
}
?>
document.write('<tr><td colspan="3" class="panel-footer-table"><img src="http://schachbundesliga.de/sites/all/themes/seven_sbl/php/images/logo.png" style="margin-left:5px;" /></td></tr></table><br /><div style="text-align:right"><img src="http://schachbundesliga.de/sites/all/themes/seven_sbl/php/images/arrow.png"> <a href="http://www.schachbundesliga.de/tabelle/<?=$aktuelle_saison?>" class="orange">Zur ausführlichen Tabelle</a></div></div></div>');
