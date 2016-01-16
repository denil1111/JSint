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
var foo4 = function foo3(a, b) {
    var c = a - b;
    return c;
}
console.log(foo4(1,2));

// anonymous function
var foo5 = function(a, b) {
    var c = a * b;
    return c;
}
console.log(foo5(1,2));

// recursion
function fact(n) {
    if (n == 1) return 1;
    else return n * fact(n - 1);
}
console.log(fact(4));

// function as return value
function outer() {
    return function inner() {
        console.log("inner");
    }
}
outer()();

// var hoisting
a = 1;
function foo6() {
    a = 2;
    var a = 3;
}
foo6();
console.log(a);
