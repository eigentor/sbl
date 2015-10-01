
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
		var pgn="<script> var viewer = new CHESS.PgnViewer({ pgn_uri: '"+pgn_location+"', piece_set: '/sites/all/themes/quatro/js/img/pieces/merida/',";
		pgn+="square_uri_dark: '/sites/all/themes/quatro/js/img/themes/wood/square_dark.jpg', square_uri_light: '/sites/all/themes/quatro/js/img/themes/wood/square_light.jpg' });</script>";
		jQuery("#edit-field-pgn-implementierung-und-0-value").val(pgn);
		}
		else {
			jQuery("#edit-field-pgn-implementierung-und-0-value").val("");
			}
        };
		
		jQuery("#partiendownload-node-form").submit(update_field2);
        function update_field2()
        {
		var pgn_location2=jQuery('a[href$=".pgn"]:first').attr('href');
		if(pgn_location2 && pgn_location2.length > 5) {
		var pgn2='[canvas]' + pgn_location2 + '[/canvas]';
		jQuery("#edit-field-gesamt-pgn-implementierung-und-0-value").val(pgn2);
		}
		else {
		jQuery("#edit-field-gesamt-pgn-implementierung-und-0-value").val("");
		}
        }
    }

);
