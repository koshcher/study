let button = document.getElementById('first');
button.addEventListener("click", () => {
    let firstBorder = Number(prompt("Enter first border:"));
    let secondBorder = Number(prompt("Enter second border:"));

    if (firstBorder > secondBorder) {
        let tmp = firstBorder;
        firstBorder = secondBorder;
        secondBorder = tmp;
    }
    let sum = 0;
    for(; firstBorder <= secondBorder; firstBorder++) {
        sum += firstBorder;
    }
    alert(`Sum = ${sum}`);
});

button = document.getElementById('second');
button.addEventListener("click", () => {
    let firstNum = Number(prompt("Enter first number:"));
    let secondNum = Number(prompt("Enter second number:"));

    if (firstBorder > secondBorder) {
        let tmp = firstBorder;
        firstBorder = secondBorder;
        secondBorder = tmp;
    }

    if(secondNum % firstNum == 0) {
        alert(`gcd = ${firstNum}`);
        return;
    }

    let gcd = 1;
    for(let i = 2; i <= secondNum/2; i++) {
        if(firstNum % i == 0 && secondNum % i == 0) {
            gcd = i;
        }
    }
    alert(`gcd = ${gcd}`);
});

button = document.getElementById('third');
button.addEventListener("click", () => {
    let num = Number(prompt("Enter number:"));

    let dividersStr = "1";
    for(let i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            dividersStr += ` ${i}`;
        }
    }
    dividersStr += ` ${num}`;
    alert(`dividers: ${dividersStr}`);
});

button = document.getElementById('five');
button.addEventListener("click", () => {
    let numsStr = prompt("Enter 10 numbers devided by ',' like: 12, 10, ...");
    let nums = numsStr.split(',').map(Number);

    let stats = {
        'positive':0,
        'negative':0,
        'zero':0,
        'even':0,
        'odd':0
    };

    for(num of nums) {
        if(num > 0) {
            stats.positive++;
        } else if (num == 0) {
            stats.zero++;
        } else {
            stats.negative++;
        }

        if(num % 2 == 0) {
            stats.even++;
        } else {
            stats.odd++;
        }
    }
    alert(`positive = ${stats.positive}, negative = ${stats.negative}, zeros = ${stats.zero}, even = ${stats.even}, odd = ${stats.odd}`);
});

button = document.getElementById('six');
button.addEventListener("click", () => {
    let run = true;
    while(run) {
        let firstNum = Number(prompt("Enter first number:"));
        let secondNum = Number(prompt("Enter second number:"));
        let sign = prompt("Enter sign + - / *");
        switch(sign) {
            case "+":
                alert(`${firstNum} + ${secondNum} = ${firstNum + secondNum}`);
                break;
            case "-":
                alert(`${firstNum} - ${secondNum} = ${firstNum - secondNum}`);
                break;
            case "/":
                alert(`${firstNum} / ${secondNum} = ${firstNum / secondNum}`);
                break;
            case "*":
                alert(`${firstNum} * ${secondNum} = ${firstNum * secondNum}`);
                break;
            default:
                alert("Unsupported sign");
                break;
        }
        let oneMore = prompt("One more time? y/n");
        if(oneMore != "y" && oneMore != "yes" && oneMore != "Yes") {
            run = false;
        }
    }
});

button = document.getElementById('eight');
button.addEventListener("click", () => {
    let days = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturaday', 'Sunday'];
    let currentDay = Number(prompt('Enter number of currend day of week:'));
    if(currentDay < 1 || currentDay > 7) {
        alert("Input is incorrect");
    }
    let run = true;
    while (run) {  
        if(confirm(`Current day is ${days[currentDay - 1]}. Show next day?`)) {
            currentDay == 7 ? currentDay = 1 : currentDay++;
        } else {
            run = false;
        }
    }
});

button = document.getElementById('nine');
button.addEventListener("click", () => {
    let table = document.getElementById('multiplicationTable');
    table.innerHTML = '';

    for(let f = 2; f < 10; f++) {
        let col = document.createElement("div");
        col.style.margin = "10px";
        for(let s = 1; s < 11; s++) {
            let p = document.createElement("p");
            let text = document.createTextNode(`${f} * ${s} = ${f*s}`);
            p.appendChild(text);
            col.appendChild(p);    
        }
        table.appendChild(col);
    }
});

// guessing game
let firstBorder = 0;
let secondBorder = 100;
let currentNum = 50;
let game = document.getElementById("game");
let ask = document.getElementById('ask');

button = document.getElementById('ten');
button.addEventListener("click", () => {
    firstBorder = 0;
    secondBorder = 100;
    game.hidden = false;
    
    ask.textContent = `Is it number: ${currentNum}`;
});

let less = document.getElementById('less');
less.addEventListener("click", () => {
    secondBorder = currentNum;
    currentNum = Math.floor((secondBorder - firstBorder)/2 + firstBorder);
    ask.textContent = `Is it number: ${currentNum}`;
});

let equal = document.getElementById('equal');
equal.addEventListener("click", () => {
    game.hidden = true;
    alert(`You guessed the number: ${currentNum}`);
});

let more = document.getElementById('more');
more.addEventListener("click", () => {
    firstBorder = currentNum;
    currentNum = Math.floor((secondBorder - firstBorder)/2 + firstBorder);
    ask.textContent = `Is it number: ${currentNum}`;
});