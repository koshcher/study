document.addEventListener('DOMContentLoaded', () => {
    let res = document.getElementById("res");
    let firstNum = document.getElementById("firstNum");
    let secondNum = document.getElementById("secondNum");

    let options = {
        '+': sum,
        '-': minus,
        '*': multyply,
        '/': divide,
    }

    const operationBtns = document.querySelectorAll('input.btn');
    operationBtns.forEach(btn => {
        btn.addEventListener('click', (event) => {
            res.textContent = doOperation(options[event.target.value]);
        });
    });
    
});

const sum = (firstNum, secondNum) => firstNum + secondNum;
const minus = (firstNum, secondNum) => firstNum - secondNum;
const divide = (firstNum, secondNum) => { return firstNum / secondNum };
const multyply = function (firstNum, secondNum) { return firstNum * secondNum };

function doOperation(operate) {
    let firstNumRightType = Number(firstNum.value);
    let secondNumRightType = Number(secondNum.value);
    if(typeof firstNumRightType == 'number' && typeof secondNumRightType == 'number') {
        return operate(firstNumRightType, secondNumRightType);
    } else {
        return 'Input is incorrect';
    }
};