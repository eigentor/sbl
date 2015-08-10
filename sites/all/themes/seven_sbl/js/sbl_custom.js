
/**
 *
 * custom js code
 * 
*/



jQuery(document).ready(
    function()
    {
        jQuery("#article-node-form").submit(update_field);

        function update_field()
        {
		var pgn_location=jQuery('a[href$=".pgn"]:first').attr('href');
		if(pgn_location && pgn_location.length > 5) {
		var pgn='[pgn pgnData=' + pgn_location + ']<a href=' + pgn_location + '>PGN</a>[/pgn]';
		jQuery("#edit-field-pgn-implementierung-und-0-value").val(pgn);
		}
		else jQuery("#edit-field-pgn-implementierung-und-0-value").val("");
        }
    }
);
