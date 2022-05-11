function firstBigger(firstNum, secondNum) {
    return firstNum < secondNum ? -1 : secondNum == firstNum ? 0 : 1; 
}

function factorial(num) {
    if(num < 0) {
        return;
    }
    let res = 1;
    for(let i = 2; i <= num; i++) {
        res = res*i;
    }
    return res;
}

function glueTogether(firstNum, secondNum, thirdNum) {
    return firstNum*100 + secondNum*10 + thirdNum;
}

function square(width, height=width) {
    return width*height;
}

function isIdeal(num) {
    // ideal nums start from 6: 6, 28, 496,...
    if(num <= 0) return false; 
    let dividerSum = 0;
    for(let i = 1; i <= num/2; i++) {
        if(num % i == 0) {
            dividerSum += i;
        }
    }
    return num == dividerSum;
}

function idealFromRange(min, max) {
    let ideals = [];
    for(; min <= max; min++) {
        if(isIdeal(min)) ideals.push(min);
    }
    return ideals;
}

function formatTime(hours, minutes=0, seconds=0) {
    let res = "";
    res += hours/10 < 1 ? `0${hours}:` : `${hours}:`;
    res += minutes/10 < 1 ? `0${minutes}:` : `${minutes}:`;
    res += seconds/10 < 1 ? `0${seconds}` : `${seconds}`;
    return res;
}

function inSeconds(hours, minutes, seconds) {
    return hours*3600 + minutes*60 + seconds;
}

function secondsToTime(seconds) {
    let hours = Math.floor(seconds/3600);
    seconds -= hours*3600;
    let minutes = Math.floor(seconds/60);
    seconds -= minutes*60;
    return formatTime(hours, minutes, seconds);
}

function datesDifference(firstHours, firstMinutes, firstSeconds, 
    secondHours, secondMinutes, secondSeconds) {
    let first = inSeconds(firstHours, firstMinutes, firstSeconds);
    let second = inSeconds(secondHours, secondMinutes, secondSeconds);
    return secondsToTime(first < second ? second - first : first - second);
}