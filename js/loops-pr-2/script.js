let btn = document.getElementById("first");
btn.addEventListener('click', () => {
    let answer = 0;
    do {
        answer = Number(prompt("2 + 2 * 2"));
    } while(answer != 6);
});

btn = document.getElementById("second");
btn.addEventListener('click', () => {
    let num = 1000;
    let count = 0;
    do {
        num = num / 2;
        count++;
    } while(num >= 50);
    alert(`Number = ${num}, count = ${count}`);
});

btn = document.getElementById("five");
btn.addEventListener('click', () => {
    let num = Number(prompt("Enter number:"));
    for(let i = 2; i < num/2; i++) {
        if(num % i == 0) {
            alert(`${num} is not simple`);
            return;
        }
    }
    alert(`${num} is simple`);
});