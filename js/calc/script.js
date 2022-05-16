let res = document.getElementById("res");
let firstNum = document.getElementById("firstNum");
let secondNum = document.getElementById("secondNum");

const sum = (firstNum, secondNum) => firstNum + secondNum;
const minus = (firstNum, secondNum) => firstNum - secondNum;
const divide = (firstNum, secondNum) => { return firstNum / secondNum };
const multyply = function (firstNum, secondNum) { return firstNum * secondNum };

function doOperation(operate) {
    let firstNumRightType = Number(firstNum.value);
    let secondNumRightType = Number(secondNum.value);
    if(typeof firstNumRightType == 'number' && typeof secondNumRightType == 'number') {
        res.innerText = operate(firstNumRightType, secondNumRightType);
    } else {
        alert('Input is incorrect');
    }
};

/*
function sum(firstNum, secondNum) {
    return firstNum + secondNum;
};

function minus(firstNum, secondNum) {
    return firstNum - secondNum;
};

function divide(firstNum, secondNum) {
    return firstNum / secondNum;
};

function multyply(firstNum, secondNum) {
    return firstNum * secondNum;
};
*/