function include(filename, onload) {
    var head = document.getElementsByTagName('head')[0];
    var script = document.createElement('script');
    script.src = filename;
    script.type = 'text/javascript';
    script.onload = script.onreadystatechange = function() {
        if (script.readyState) {
            if (script.readyState === 'complete' || script.readyState === 'loaded') {
                script.onreadystatechange = null;                                                  
                onload();
            }
        } 
        else {
            onload();          
        }
    };
    head.appendChild(script);
}

include('http://ajax.googleapis.com/ajax/libs/jquery/1.7.0/jquery.min.js', function() {
    $(document).ready(function() {
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
    });
});
