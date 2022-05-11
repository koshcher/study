function lower(firstNum, secondNum) {
    return firstNum < secondNum ? firstNum : secondNum;
}

function pow(num, degree) {
    return num**degree;
}

function calc(firstNum, secondNum, option) {
    switch(option) {
        case '+':
            return firstNum + secondNum;
            break;
        case '-':
            return firstNum - secondNum;
            break;
        case '/':
            return firstNum / secondNum;
            break;
        case '*':
            return firstNum * secondNum;
            break;
    }
    return;
}

function isSimple(num) {
    for(let i = 2; i < num/2; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

function table(num) {
    for(let i = 1; i < 10; i++) {
        console.log(`${num} * ${i} = ${num * i}`);
    }
}

function remainder(firstNum, secondNum) {
    return firstNum - (Math.floor(firstNum/secondNum) * secondNum);
}

