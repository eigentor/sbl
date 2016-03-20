<?php
error_reporting(0);
$designs=Array("sbl","red","dark","green","blue");
$_GET["design"]=strtolower($_GET["design"]);
if(in_array($_GET["design"],$designs)) $helpicon="_".$_GET["design"];
else $helpicon="_sbl";
?>
<html lang="de" dir="ltr" version="HTML+RDFa 1.1">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <head>

<link rel="stylesheet" type="text/css" href="css/tooltipster.css" />
<script type="text/javascript" src="http://code.jquery.com/jquery-1.7.0.min.js"></script>
<script type="text/javascript" src="js/jquery.tooltipster.min.js"></script>

<link rel="stylesheet" type="text/css" href="css/dwz_rechner_css.php?design=<?=$_GET["design"]?>&bgcolor=<?=$_GET["bgcolor"]?>&bordercolor=<?=$_GET["bordercolor"]?>&header=<?=$_GET["header"]?>&headingcolor=<?=$_GET["headingcolor"]?>" />
<script type="text/javascript">
jQuery(function($) { // onDomReady

    // reset handler that clears the form
    $('form[name="sbl_elorechner"] input:reset').click(function () {
        $('form[name="sbl_elorechner"]')
            .find('textarea, :text, select').val('')

        return false;
    });

});
</script>

<script type="text/javascript">
 $(document).ready(function() {
            $('.tooltip').tooltipster({
                contentAsHTML: true
            });
        });
</script>

</head>

<body>

<form action="http://schachbundesliga.de/elo-rechner#auswertung" method="POST" target="_blank" name="sbl_elorechner">

<div class="header">ELO-Rechner</div>
<div class="dwzrechner">

<label for="alte_dwz"><strong>Bisherige ELO:</strong><img class="tooltip" src="images/help<?=$helpicon?>.png" title="Ihre aktuelle ELO. Wenn Sie noch keine haben, geben Sie hier bitte einfach 0 ein" /></label><input type="text" name="alte_elo" value="<?php echo isset($_POST["alte_elo"])?$_POST["alte_elo"]:""; ?>" class="elo" />
<hr /><label for="kfaktor"><strong>K-Faktor:</strong>
<img class="tooltip" src="images/help<?=$helpicon?>.png" title="<ul><li>40 für Spieler unter 18 Jahren mit einer ELO < 2300</li><li>10 für Spieler mit einer ELO > 2400</li><li>20 für alle anderen Spieler mit oder ohne ELO sowie für Blitz- und Schnellpartien</ul>" />
</label><select name="kfaktor" size="1">
<option value="10">10</option>
<option value="20" selected="selected">20</option>
<option value="40">40</option>
</select>
<hr /><label for="schnellberechnung_gegnerschnitt"><strong>Gegnerschnitt:</strong><img class="tooltip" src="images/help<?=$helpicon?>.png" title="Der ELO-Schnitt aller Ihrer Gegner. Partien gegen Spieler ohne ELO können nicht gewertet werden" /></label><input type="text" name="schnellberechnung_gegnerschnitt" value="<?=$_POST["schnellberechnung_gegnerschnitt"]?>" class="elo" /><br />
<label for="schnellberechnung_punkte"><strong>Erzielte Punkte:</strong><img class="tooltip" src="images/help<?=$helpicon?>.png" title="Die erzielten Punkte und die Anzahl der Partien gegen Gegner mit ELO. Partien gegen Spieler ohne ELO können nicht gewertet werden. Beispiel: 3,0/4" /></label><input type="text" name="schnellberechnung_punkte" value="<?=$_POST["schnellberechnung_punkte"]?>" class="punkte" /> / <input type="text" name="schnellberechnung_partien" value="<?=$_POST["schnellberechnung_partien"]?>" class="punkte" />
<hr /><div style="text-align:center;"><input type="submit" class="submit" name="berechnen" value="Berechnen!">&nbsp;&nbsp;<input type="reset" class="submit" name="reset" value="L&ouml;schen"></div>
<hr />
<div class="footer"><a href="http://www.schachbundesliga.de/elo-rechner" target="_blank"><img src='images/logo_powered.png' class="tooltip" title="Zum ausführlichen ELO-Rechner auf schachbundesliga.de"></div></div>
</form>
</body>
</html>


