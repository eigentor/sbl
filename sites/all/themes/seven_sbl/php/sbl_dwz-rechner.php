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
<script type="text/javascript" src="https://code.jquery.com/jquery-1.7.0.min.js"></script>
<script type="text/javascript" src="js/jquery.tooltipster.min.js"></script>

<link rel="stylesheet" type="text/css" href="css/dwz_rechner_css.php?design=<?=$_GET["design"]?>&bgcolor=<?=$_GET["bgcolor"]?>&bordercolor=<?=$_GET["bordercolor"]?>&header=<?=$_GET["header"]?>&headingcolor=<?=$_GET["headingcolor"]?>" />
<script type="text/javascript">
jQuery(function($) { // onDomReady

    // reset handler that clears the form
    $('form[name="sbl_dwzrechner"] input:reset').click(function () {
        $('form[name="sbl_dwzrechner"]')
            .find('textarea, :text, select').val('')

        return false;
    });

});
</script>

<script type="text/javascript">
 $(document).ready(function() {
            $('.tooltip').tooltipster();
        });
</script>

</head>

<body>

<form action="https://schachbundesliga.de/dwz-rechner#auswertung" method="POST" target="_blank" name="sbl_dwzrechner">

<div class="header">DWZ-Rechner</div>
<div class="dwzrechner">

<label for="alte_dwz"><strong>Bisherige DWZ:</strong><img class="tooltip" src="images/help<?=$helpicon?>.png" title="Ihre aktuelle DWZ. Wenn Sie noch keine haben, geben Sie hier bitte einfach 0 ein" /></label><input type="text" name="alte_dwz" value="<?php echo isset($_POST["alte_dwz"])?$_POST["alte_dwz"]:""; ?>" class="elo" />
<hr /><label for="geburtsjahr"><strong>Alter:</strong></label><select name="geburtsjahr" size="1">
<option value="1990">älter als 25</option>
<option value="<?php echo (date("Y",time()) - 22); ?>">21-25</option>
<option value="<?php echo (date("Y",time()) - 10); ?>">20 oder jünger</option>
</select>
<hr /><label for="schnellberechnung_gegnerschnitt"><strong>Gegnerschnitt:</strong><img class="tooltip" src="images/help<?=$helpicon?>.png" title="Der DWZ-Schnitt aller Ihrer Gegner. Partien gegen Spieler ohne DWZ können nicht gewertet werden" /></label><input type="text" name="schnellberechnung_gegnerschnitt" value="<?=$_POST["schnellberechnung_gegnerschnitt"]?>" class="elo" /><br />
<label for="schnellberechnung_punkte"><strong>Erzielte Punkte:</strong><img class="tooltip" src="images/help<?=$helpicon?>.png" title="Die erzielten Punkte und die Anzahl der Partien gegen Gegner mit DWZ. Partien gegen Spieler ohne DWZ können nicht gewertet werden. Beispiel: 3,0/4" /></label><input type="text" name="schnellberechnung_punkte" value="<?=$_POST["schnellberechnung_punkte"]?>" class="punkte" /> / <input type="text" name="schnellberechnung_partien" value="<?=$_POST["schnellberechnung_partien"]?>" class="punkte" />
<hr /><div style="text-align:center;"><input type="submit" class="submit" name="berechnen" value="Berechnen!">&nbsp;&nbsp;<input type="reset" class="submit" name="reset" value="L&ouml;schen"></div>
<hr />
<div class="footer"><a href="https://www.schachbundesliga.de/dwz-rechner" target="_blank"><img src='images/logo_powered.png' class="tooltip" title="Zum ausführlichen DWZ-Rechner auf schachbundesliga.de"></div></div>
</form>
</body>
</html>


