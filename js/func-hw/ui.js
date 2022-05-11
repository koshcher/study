function firstBiggerUI() {
    let firstNum = Number(prompt("Enter first num:"));
    let secondNum = Number(prompt("Enter second num:"));
    let isFirstBigger = firstBigger(firstNum, secondNum);
    alert(isFirstBigger == 1 ? 'First number is bigger' : isFirstBigger == 0 ? 'First number equals second' : 'Second is bigger');
}

function factorialUI() {
    alert(`Factorial = ${factorial(Number(prompt("Enter num:")))}`);
}

function glueTogetherUI() {
    alert(glueTogether(Number(prompt("Enter first num:")),
    Number(prompt("Enter second num:")),
    Number(prompt("Enter third num:"))));
}

function squareUI() {
    alert(`Square = ${square(Number(prompt('Enter width')), Number(prompt('Enter height')))}`);
}

function isIdealUI() {
    isIdeal(Number(prompt("Enter num:"))) ?
    alert("Num is ideal") : alert("Num is not ideal");
}

function idealFromRangeUI() {
    let ideals = idealFromRange(Number(prompt("Enter min:")), Number(prompt("Enter max:")));
    alert(ideals.toString());
}

function formatTimeUI() {
    alert(formatTime(Number(prompt("Enter hours:")),
    Number(prompt("Enter minutes:")),
    Number(prompt("Enter seconds:"))));
}

function inSecondsUI() {
    alert(`${inSeconds(Number(prompt("Enter hours:")),
    Number(prompt("Enter minutes:")),
    Number(prompt("Enter seconds:")))} seconds`);
}

function secondsToTimeUI() {
    alert(secondsToTime(Number(prompt("Enter seconds:"))));
}

function datesDifferenceUI() {
    alert(datesDifference(
        Number(prompt("Enter first date hours:")),
        Number(prompt("Enter first date minutes:")),
        Number(prompt("Enter first date seconds:")),
        Number(prompt("Enter second date hours:")),
        Number(prompt("Enter second date minutes:")),
        Number(prompt("Enter second date seconds:"))
    ));
}