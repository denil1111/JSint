function a(){
	var y;
	x = 1;
	b();
	y = 1;
	b();
	console.log(y)
	console.log(x)
}
var x;
function b(){
	x=x+1;
	y=y+1;
}
x = 10;
y = 10;
a();
b();

console.log(x+y);