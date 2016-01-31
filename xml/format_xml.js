<script type="text/javascript">
var xmlDoc;
var xmlFile="aktuell.xml";

if(typeof window.DOMParser != "undefined") {
    xmlhttp=new XMLHttpRequest();
    xmlhttp.open("GET",xmlFile,false);
    if (xmlhttp.overrideMimeType){
        xmlhttp.overrideMimeType('text/xml');
    }
    xmlhttp.send();
    xmlDoc=xmlhttp.responseXML;
}
else{
    xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
    xmlDoc.async="false";
    xmlDoc.load(xmlFile);
}
var tagObj=xmlDoc.getElementsByTagName("item");
var titleValue = tagObj[0].getElementsByTagName("title")[0].childNodes[0].nodeValue;
var descriptionValue = tagObj[0].getElementsByTagName("description")[0].childNodes[0].nodeValue;
alert(titleValue);
</script>