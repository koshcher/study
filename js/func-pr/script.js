function stringFrom() {
    let str = '';
    for(let i = 0; i < arguments.length; i++) {
        str += i == arguments.length - 1 ? arguments[i] : `${arguments[i]} `;
    }
    return str;
}

function min() {
    let min = 0;
    let minIndex = 0;
    while(typeof(arguments[minIndex]) != 'number' && minIndex < arguments.length) {
        minIndex++;
    }
    min = arguments[minIndex];
    for(let i = minIndex + 1; i < arguments.length; i++) {
        if(typeof(arguments[i]) == 'number' && arguments[i] < min ) min = arguments[i];
    }
    return min;
}

function numbers() {
    let numCount = 0;
    for(let i = 0; i < arguments.length; i++) {
        if(typeof(arguments[i]) == 'number') numCount++;
    }
    return numCount;
}

function mean() {
    let sum = 0;
    let count = 0;
    for(let i = 0; i < arguments.length; i++) {
        if(typeof arguments[i] == 'number') {
            sum += arguments[i];
            count++;
        }
    }
    return count == 0 ? 0 : sum/count;
}