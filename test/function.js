// simple function
function foo1() {}
foo1();

// function with parameters
function foo2(a, b) {
    var c = a + b;
    return c;
}
console.log(foo2(1,2));

// function expression
var d = function foo3(e, f) {
    var g = e - f;
    return g;
}
console.log(d(1,2));

// anonymous
var h = function(i, j) {
    var k = i * j;
    return k;
}
console.log(h(1,2));
