// JavaScript Cheatsheet

// VARIABLES & DATA TYPES

// Variable Declarations
var name = "John";       // Function-scoped, can be redeclared
let age = 25;            // Block-scoped, can be reassigned
const PI = 3.14159;      // Block-scoped, cannot be reassigned

// Primitive Data Types
let str = "Hello World";
let template = `Hello ${name}`;
let num = 42;
let float = 3.14;
let scientific = 2e10;
let isTrue = true;
let isFalse = false;
let undefined_var;
let null_var = null;
let sym = Symbol('id');
let bigInt = 123n;

// OPERATORS

// Arithmetic
// + - * / % ** ++ --

// Comparison
// == === != !== > < >= <=

// Logical
// && || ! ??

// Assignment
// = += -= *= /=
// %= **= <<= >>= >>>= &= ^= |=

// CONTROL FLOW

// If statement
if (age > 18) {
  console.log("Adult");
} else {
  console.log("Minor");
}

// Ternary
let result = age > 18 ? "Adult" : "Minor";

// Switch
switch (age) {
  case 18:
    console.log("Just became adult");
    break;
  default:
    console.log("Any age");
}

// Loops
for (let i = 0; i < 5; i++) {
  console.log(i);
}

while (age > 0) {
  age--;
}

do {
  age++;
} while (age < 5);

// For...in and For...of
let obj = { a: 1, b: 2 };
for (let key in obj) {
  console.log(key);
}

let arr = [1, 2, 3];
for (let val of arr) {
  console.log(val);
}


// FUNCTIONS

function greet(name) {
  return `Hello, ${name}!`;
}

const greet2 = function(name) {
  return `Hello, ${name}!`;
};

const greet3 = (name) => `Hello, ${name}!`;
const greet4 = name => `Hello, ${name}!`;
const greet5 = () => "Hello, World!";

(function() {
  console.log("IIFE");
})();

// Function Features
function greetWithDefault(name = "World") {
  return `Hello, ${name}!`;
}

function sum(...numbers) {
  return numbers.reduce((a, b) => a + b, 0);
}

function greetWithObject({ name, age }) {
  return `Hello, ${name}! You are ${age} years old.`;
}


// ARRAYS

let arr2 = new Array(5);
let arr3 = Array.of(1, 2, 3);
arr[0];
arr[arr.length - 1];

// Mutating
arr.push(6);
arr.pop();
arr.unshift(0);
arr.shift();
arr.splice(1, 2, 'a', 'b');
arr.reverse();
arr.sort();

// Non-mutating
arr.slice(1, 3);
arr.concat([6, 7]);
arr.join(', ');
arr.indexOf(3);
arr.includes(3);

// Iteration
arr.forEach(item => console.log(item));
arr.map(item => item * 2);
arr.filter(item => item > 2);
arr.reduce((acc, item) => acc + item, 0);
arr.find(item => item > 2);
arr.findIndex(item => item > 2);
arr.some(item => item > 2);
arr.every(item => item > 0);

// ============
// OBJECTS
// ============

let person = {
  name: "John",
  age: 30,
  greet: function() {
    return `Hello, I'm ${this.name}`;
  }
};

person.name;
person['name'];
person.greet();

function Person(name, age) {
  this.name = name;
  this.age = age;
}

class PersonClass {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }
  greet() {
    return `Hello, I'm ${this.name}`;
  }
}

Object.keys(person);
Object.values(person);
Object.entries(person);
Object.assign({}, person);
Object.freeze(person);
Object.seal(person);

// STRING METHODS

let str2 = "Hello World";
str2.length;
str2.charAt(0);
str2.indexOf('o');
str2.lastIndexOf('o');
str2.includes('Hello');
str2.startsWith('Hello');
str2.endsWith('World');
str2.toLowerCase();
str2.toUpperCase();
str2.trim();
str2.replace('World', 'JavaScript');
str2.replaceAll('l', 'L');
str2.substring(0, 5);
str2.slice(0, 5);
str2.split(' ');

let greeting = `Hello, ${name}!`;

// DESTRUCTURING

let [a, b, c] = [1, 2, 3];
let [first, ...rest] = [1, 2, 3, 4, 5];
let [x, y, z = 0] = [1, 2];

let {name: fullName, age: userAge} = {name: "John", age: 30};
let {city = "Unknown"} = {};

// ES6+ FEATURES

let arr1 = [1, 2, 3];
let arr4 = [...arr1, 4, 5];
let obj1 = {a: 1, b: 2};
let obj2 = {...obj1, c: 3};

function addThree(a, b, c) {
  return a + b + c;
}
addThree(...[1, 2, 3]);

export const PI2 = 3.14159;
export function greetExport(name) {
  return `Hello, ${name}!`;
}
export default class Calculator {
  add(a, b) { return a + b; }
}

import { PI2, greetExport } from './math.js';
import Calculator from './calculator.js';
import * as math from './math.js';

// Promises
let promise = new Promise((resolve, reject) => {
  let success = true;
  if (success) resolve("Done");
  else reject("Error");
});

promise.then(console.log).catch(console.error).finally(() => console.log('Finished'));

async function fetchData() {
  try {
    let response = await fetch('https://api.example.com/data');
    let data = await response.json();
    return data;
  } catch (error) {
    console.error('Error:', error);
  }
}

// ============
// ERROR HANDLING
// ============

try {
  throw new Error("Oops!");
} catch (e) {
  console.error(e.message);
} finally {
  console.log("Always runs");
}

// TYPE CHECKING

let value = "test";
typeof value;
Array.isArray(value);
value instanceof String;
value === null;
value === undefined;
value == null;

// REGEX

let regex = /hello/i;
regex.test("Hello");
"Hello".match(regex);
"Hello".replace(regex, "Hi");
"Hello".search(regex);

// JSON

let jsonStr = '{"name": "John"}';
let jsonObj = JSON.parse(jsonStr);
let strJSON = JSON.stringify(jsonObj);
let formattedJSON = JSON.stringify(jsonObj, null, 2);

// DOM MANIPULATION

document.getElementById('myId');
document.querySelector('.myClass');

let element = document.createElement('div');
element.textContent = 'Hello';
document.body.appendChild(element);
element.addEventListener('click', e => console.log('Clicked!'));

// MATH, DATE, NUMBER

Math.random();
Math.floor(4.7);
Math.ceil(4.3);
Math.round(4.5);
Math.max(1, 2, 3);
Math.min(1, 2, 3);
Math.abs(-5);
Math.pow(2, 3);
Math.sqrt(16);

let now = new Date();
now.getFullYear();
now.getMonth();
now.getDate();
now.getTime();

let numVal = 42.567;
numVal.toFixed(2);
numVal.toPrecision(3);
parseInt('42');
parseFloat('42.5');
Number.isInteger(42);
Number.isNaN(NaN);
