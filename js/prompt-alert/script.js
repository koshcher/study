var button = document.getElementById('first');
button.addEventListener("click", () => {
    var userName = prompt("What's your name?");
    alert("Hello, " + userName + "!");
});

button = document.getElementById('second');
button.addEventListener("click", () => {
    var userYear = prompt("What's your birth year?");
    var date = new Date();
    alert("You are " + (date.getFullYear() - userYear) + " years old");
});

button = document.getElementById('third');
button.addEventListener("click", () => {
    var a = Number(prompt("Enter side of square length:"));
    alert("Perimeter is " + 4*a);
});

button = document.getElementById('four');
button.addEventListener("click", () => {
    var radius = Number(prompt("Enter radius:"));
    alert("Square are " + (Math.PI * radius * radius));
});

button = document.getElementById('five');
button.addEventListener("click", () => {
    var km = Number(prompt("Enter length in km:"));
    var time = Number(prompt("Enter time in hours:"));
    alert("Your speed must be " + (km / time) + " km/hour");
});

button = document.getElementById('six');
button.addEventListener("click", () => {
    const rate = 1.05;
    var dollars = Number(prompt("Enter dollars:"));
    alert("It's " + dollars*rate + " euro");
});

button = document.getElementById('seven');
button.addEventListener("click", () => {
    var gbs = Number(prompt("Enter GBs:"));
    alert("Disk can contain " + Math.floor(gbs*1024 / 820) + " files of 820 Mb");
});

button = document.getElementById('eight');
button.addEventListener("click", () => {
    var pocket = Number(prompt("Enter money you have:"));
    var cost = Number(prompt("Enter cost of chocolate plate:"));
    var chocolates = Math.floor(pocket / cost);
    alert("You can buy " + chocolates + " chocolate plates. Surrender = " + (pocket - chocolates*cost));
});

button = document.getElementById('ten');
button.addEventListener("click", () => {
    var num = Number(prompt("Enter number:"));
    num % 2 == 0 ? alert("Number is even") : alert("Number is odd");
});