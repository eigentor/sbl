$(document).ready(function(){
 $.get("aktuell",{},function(xml){
  $('item',xml).each(function(i) {
	  var title = $(this).find("title").text();
	  var description = $(this).find("description").text();
	  var output = '<div style="border:1px solid #c0c0c0; margin:10px;">';	
		output += '<b>'+ title + '</b><br />';
		output += '<u>'+ description + '<br />';	
		output += '</div>';
		document.write(output):
  }
 }
}