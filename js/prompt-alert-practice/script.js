
let lamp = document.getElementById("lamp");
lamp.addEventListener("click", () => {
    if (lamp.src.includes("off")) {
        lamp.src = "on.jpg";
    } else {
        lamp.src = "off.jpg";
    }
});

let titleChangeBtn = document.getElementById("titleChange");
titleChangeBtn.addEventListener("click", () => {
    let titleH = document.getElementById('title');
    let userTitle = prompt("Enter new title:");
    titleH.textContent = userTitle;
});

var button = document.getElementById('second');
button.addEventListener("click", () => {
    let firstNum = Number(prompt("Enter first number:"));
    let secondNum = Number(prompt("Enter second number:"));
    alert("Avarage is " + ((firstNum + secondNum) / 2));
});

button = document.getElementById('four');
button.addEventListener("click", () => {
    const kmInMile = 0.621371; 
    let kms = Number(prompt("Enter kilometers:"));
    alert("It's " + (kms * kmInMile) + " miles");
});

button = document.getElementById('five');
button.addEventListener("click", () => {
    let firstNum = Number(prompt("Enter first number:"));
    let secondNum = Number(prompt("Enter second number:"));
    alert(firstNum + " + " + secondNum + " = " + (firstNum + secondNum));
    alert(firstNum + " - " + secondNum + " = " + (firstNum - secondNum));
    alert(firstNum + " * " + secondNum + " = " + (firstNum * secondNum));
    alert(firstNum + " / " + secondNum + " = " + (firstNum / secondNum));
});

button = document.getElementById('six');
button.addEventListener("click", () => {
    let a = Number(prompt("Enter a:"));
    let b = Number(prompt("Enter b:"));
    alert("x = " + (-1 * b / a));
});

button = document.getElementById('seven');
button.addEventListener("click", () => {
    let hours = Number(prompt("Enter current hours:"));
    let mins = Number(prompt("Enter minutes:"));
    if (mins == 0) {
        alert("To next day " + (24 - hours) + " hours");
    } else {
        alert("To next day " + (23 - hours) + " hours and " + (60 - mins) + " minutes");
    }
});

button = document.getElementById('ten');
button.addEventListener("click", () => {
    var sales = Number(prompt("Enter monthly sales amount:"));
    alert("Your salary is " + (250 + 0.1*sales));
});