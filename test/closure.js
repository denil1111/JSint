x = 5;
foo = function()
{
	var x = 3;
	return function()
	{
		console.log(x);
	}
}
foo()();
