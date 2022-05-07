var button = document.getElementById('first');
button.addEventListener("click", () => {
    let num = Number(prompt("Enter number:"));
    if (num == 0) {
        alert("Number is zero");
    } else if (num > 0) {
        alert("Number > 0");
    } else {
        alert("Number < 0");
    }
});

button = document.getElementById('second');
button.addEventListener("click", () => {
    let age = Number(prompt("Enter your age:"));
    if(age < 0 || age > 120) {
        alert("Age is incorrect");
    }
    else {
        alert("Age is correct");
    }
});

button = document.getElementById('four');
button.addEventListener("click", () => {
    let hours = Number(prompt("Enter current hours:"));
    let mins = Number(prompt("Enter current mins:"));
    let seconds = Number(prompt("Enter current seconds:"));
    if(hours > 24) {
        alert("Hours are incorrect");
    }
    if(mins > 59) {
        alert("Minutes are incorrect");
    } 
    if(seconds > 59) {
        alert("Seconds are incorrect");
    }
    if(hours == 24 && (mins > 0 || seconds > 0)) {
        alert("Too much time");
    }
});

button = document.getElementById('five');
button.addEventListener("click", () => {
    let x = Number(prompt("Enter x:"));
    let y = Number(prompt("Enter y:"));
    if(x == 0) {
        alert("Point is on OY");
        return;
    }
    if(y == 0) {
        alert("Point is on OX");
        return;
    }

    if(x > 0) {
        if(y > 0) {
            alert("First quoter");
        } else {
            alert("Four quoter");
        }
    } else {
        if(y > 0) {
            alert("Second quoter");
        } else {
            alert("Third quoter");
        }
    }
});

button = document.getElementById('six');
button.addEventListener("click", () => {
    let month = Number(prompt("Enter month:"));
    switch(month) {
        case 1:
            alert("January");
            break;
        case 2:
            alert("February");
            break;
        case 3:
            alert("March");
            break;
        case 4:
            alert("April");
            break;
        case 5:
            alert("May");
            break;
        case 6:
            alert("June");
            break;
        case 7:
            alert("Jule");
            break;
        case 8:
            alert("August");
            break;
        case 9:
            alert("September");
            break;
        case 10:
            alert("October");
            break;
        case 11:
            alert("November");
            break;
        case 12:
            alert("December");
            break;
        default:
            alert("Incorrect input");
            break;
    }
});

button = document.getElementById('seven');
button.addEventListener("click", () => {
    let firstNum = Number(prompt("Enter first num:"));
    let secondNum = Number(prompt("Enter second:"));
    let toDo = prompt("+ - * /:");
    switch(toDo) {
        case "+":
            alert(firstNum + secondNum);
            break;
        case "-":
            alert(firstNum - secondNum);
            break;
        case "*":
            alert(firstNum * secondNum);
            break;
        case "/":
            if(secondNum == 0) {
                alert("Input is incorrect");
                return;
            }
            alert(firstNum / secondNum);
            break;
        default:
            alert("Incorrect input");
            break;
    }
});