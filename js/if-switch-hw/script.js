var button = document.getElementById('first');
button.addEventListener("click", () => {
    let userAge = Number(prompt("Enter user age:"));
    if(userAge >= 0 && userAge < 12) {
        alert("Child");
    } else if(userAge >= 12 && userAge < 18) {
        alert("Teenager");
    } else if(userAge >= 18 && userAge < 60) {
        alert("Adult");
    } else if(userAge >= 60) {
        alert("Retired");
    } else {
        alert("Incorrect input");
    }
});

button = document.getElementById('second');
button.addEventListener("click", () => {
    let num = Number(prompt("Enter number from 0 to 9"));
    if(num < 0 || num > 9) {
        alert("Number is not in range");
        return;
    }
    const symbols = [')', '!', '@', '#', '$', '%', '^', '&', '*', '('];
    alert(symbols[num]);
});

button = document.getElementById('four');
button.addEventListener("click", () => {
    let year = Number(prompt("Enter year:"));
    if(year % 400 == 0) {
        alert(`${year} year is leap`);
    } else if (year % 100 == 0) {
        alert(`${year} year isn't leap`);
    } else if (year % 4 == 0) {
        alert(`${year} year is leap`);
    } else {
        alert(`${year} year isn't leap`);
    }
});

button = document.getElementById('seven');
button.addEventListener("click", () => {
    let purchase = Number(prompt("Enter purchase amount:"));

      purchase >= 200 && purchase < 300 ? alert(`Amount to pay is ${purchase - purchase*0.03}`)
    : purchase >= 300 && purchase < 500 ? alert(`Amount to pay is ${purchase - purchase*0.05}`)
    : purchase >= 500 ? alert(`Amount to pay is ${purchase - purchase*0.07}`)
    : alert(`Amount to pay is ${purchase}`);
});

button = document.getElementById('nine');
button.addEventListener("click", () => {
    let res = 0;
    let first = Number(prompt("What is form of Earth? [1] - round, [2] - flat, [3] - cube"));
    if(first == 1) {res+=2};
    let second = Number(prompt("How many meters in kilometer? [1] - 100m, [2] - 10000m, [3] - 1000m"));
    if(second == 3) {res+=2};
    let third = Number(prompt("What is normal temperature of human body? [1] - 39.2C, [2] - 34.6C, [3] - 36.6C"));
    if(third == 3) {res+=2};
    alert(`You earned ${res} points`)
});

button = document.getElementById('convert');
button.addEventListener("click", () => {
    let usd = document.getElementById("usd").value;
    let currency = document.getElementById("currency").value;
    switch(currency) {
        case "eur":
            alert(`${usd} USD = ${usd*0.95} EUR`);
            break;
        case "uah":
            alert(`${usd} USD = ${usd*29.44} UAH`);
            break;
        case "azn":
            alert(`${usd} USD = ${usd*1.7} AZN`);
            break;
    };
});