(function($, Drupal)
{
	// Our function name is prototyped as part of the Drupal.ajax namespace, adding to the commands:
	Drupal.ajax.prototype.commands.reload_chosen = function(ajax, response, status)
	{
		alert('Hello');
	};
}(jQuery, Drupal));