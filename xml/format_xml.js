<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
    <script type="text/javascript">
    $(document).ready(function () {
        $.ajax({
            type: "GET",
            url: "../aktuell.xml",
            cache: false,
            dataType: "xml",
            success: function(xml) {
                $(xml).find('items').each(function(){
                    var name = $(this).find("title").text()
                    alert(name);
                });
            }
        });
    });
	</script>