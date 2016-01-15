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
var a = function foo3(a, b) {
    var c = a - b;
    return c;
}
console.log(a(1,2));

// anonymous
var b = function(a, b) {
    var c = a * b;
    return c;
}
console.log(b(1,2));
