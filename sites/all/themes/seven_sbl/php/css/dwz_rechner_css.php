<?php
    header("Content-type: text/css; charset: UTF-8");
	$bordercolor=$_GET["bordercolor"];
	$bgcolor=$_GET["bgcolor"];
	$header=$_GET["header"];
	$headingcolor=$_GET["headingcolor"];
	if(strlen($_GET["design"]) > 0) {
	switch($_GET["design"]) {
	case "sbl":
	$_GET["bordercolor"]="c7c7c7";
	$_GET["bgcolor"]="f7f7f7";
	$_GET["header"]="f18000";	
	$_GET["headingcolor"]="ffffff";
	break;
	case "blue":
	$_GET["bordercolor"]="1c56ad";
	$_GET["bgcolor"]="f7f7f7";
	$_GET["header"]="1c56ad";	
	$_GET["headingcolor"]="ffffff";
	break;
	case "dark":
	$_GET["bordercolor"]="3b3b3b";
	$_GET["bgcolor"]="ffffff";
	$_GET["header"]="3b3b3b";	
	$_GET["headingcolor"]="ffffff";
	break;
	case "green":
	$_GET["bordercolor"]="249122";
	$_GET["bgcolor"]="f7f7f7";
	$_GET["header"]="249122";	
	$_GET["headingcolor"]="ffffff";
	break;
	case "red":
	$_GET["bordercolor"]="bd2926";
	$_GET["bgcolor"]="ffffff";
	$_GET["header"]="bd2926";	
	$_GET["headingcolor"]="ffffff";
	break;
	default:
	$_GET["bordercolor"]="c7c7c7";
	$_GET["bgcolor"]="f7f7f7";
	$_GET["header"]="f18000";	
	$_GET["headingcolor"]="ffffff";
	break;
	}
	}
	if(strlen($bordercolor) > 3) $_GET["bordercolor"]=$bordercolor;
	if(strlen($bgcolor) > 3) $_GET["bgcolor"]=$bgcolor;
	if(strlen($header) > 3) $_GET["header"]=$header;
	if(strlen($headingcolor) > 3) $_GET["headingcolor"]=$headingcolor;
?>

body,html {
	font-size:12px;
	font-family:Arial, Helvetica, sans-serif;
	line-height:2.5em;
	
}

.header {
	background-color:#<?=$_GET["header"]?>;
	width:95%;
	padding:3px;
	height:30px;
	color:#<?=$_GET["headingcolor"]?>;
	font-weight:bold;
	font-size:14px;
	text-align:center;
	-moz-box-sizing: border-box;
	box-sizing: border-box;
}

.dwzrechner {
	background-color:#<?=$_GET["bgcolor"]?>;
	width:95%;
	padding:5px;
	height:auto;
	border:1px solid #<?=$_GET["bordercolor"]?>;
	-moz-box-sizing: border-box;
  box-sizing: border-box;
}

input.elo {
	width:100px;
	border:1px solid #<?=$_GET["bordercolor"]?>;
	text-align:right;
}

input.punkte {
	width:45px;
	border:1px solid #<?=$_GET["bordercolor"]?>;
	text-align:right;
}

select {
	width:100px;
	border:1px solid #<?=$_GET["bordercolor"]?>;
}

label {
	width:120px;
	display:inline-block;
}

hr {
  border:none;
  border-top:1px dotted #b0b0b0;
  color:#b0b0b0;
  background-color:#fff;
  height:1px;
  width:100%;
}

img.tooltip {
	vertical-align:middle;
	margin-left:5px;
}

.submit {
	-moz-box-shadow:inset 0px 1px 0px 0px #ffffff;
	-webkit-box-shadow:inset 0px 1px 0px 0px #ffffff;
	box-shadow:inset 0px 1px 0px 0px #ffffff;
	background:-webkit-gradient( linear, left top, left bottom, color-stop(0.05, #ededed), color-stop(1, #dfdfdf) );
	background:-moz-linear-gradient( center top, #ededed 5%, #dfdfdf 100% );
	filter:progid:DXImageTransform.Microsoft.gradient(startColorstr='#ededed', endColorstr='#dfdfdf');
	background-color:#ededed;
	-webkit-border-top-left-radius:6px;
	-moz-border-radius-topleft:6px;
	border-top-left-radius:6px;
	-webkit-border-top-right-radius:6px;
	-moz-border-radius-topright:6px;
	border-top-right-radius:6px;
	-webkit-border-bottom-right-radius:6px;
	-moz-border-radius-bottomright:6px;
	border-bottom-right-radius:6px;
	-webkit-border-bottom-left-radius:6px;
	-moz-border-radius-bottomleft:6px;
	border-bottom-left-radius:6px;
	text-indent:0;
	border:1px solid #dcdcdc;
	display:inline-block;
	color:black;
	font-family:arial;
	font-size:13px;
	font-weight:bold;
	font-style:normal;
	height:30px;
	line-height:30px;
	width:100px;
	text-decoration:none;
	text-align:center;
	text-shadow:1px 1px 0px #ffffff;
}

.footer {
	text-align:center;
background: rgb(238,238,238); /* Old browsers */
background: -moz-linear-gradient(top, rgba(238,238,238,1) 0%, rgba(255,255,255,1) 0%, rgba(224,224,224,1) 100%); /* FF3.6-15 */
background: -webkit-linear-gradient(top, rgba(238,238,238,1) 0%,rgba(255,255,255,1) 0%,rgba(224,224,224,1) 100%); /* Chrome10-25,Safari5.1-6 */
background: linear-gradient(to bottom, rgba(238,238,238,1) 0%,rgba(255,255,255,1) 0%,rgba(224,224,224,1) 100%); /* W3C, IE10+, FF16+, Chrome26+, Opera12+, Safari7+ */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#eeeeee', endColorstr='#e0e0e0',GradientType=0 ); /* IE6-9 */
border:1px solid #c7c7c7;
}