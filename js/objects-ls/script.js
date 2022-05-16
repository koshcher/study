let rect = {
    'xStart': 10,
    'yStart': 20,
    'xEnd': 60,
    'yEnd': 30
}

function info(rect) {
    alert(`left upper = (${rect.xStart},${rect.yStart}); right down = (${rect.xEnd},${rect.yEnd});`);
}

const width = (rect) => rect.xEnd - rect.xStart;

const height = (rect) => rect.yEnd - rect.yStart;

const square = (rect) => height(rect) * width(rect);

const perimeter = (rect) => 2*height(rect) + 2*width(rect);

const set = (rect, x1, y1, x2, y2) => {
    rect.xStart = x1;
    rect.yStart = y1;
    rect.xEnd = x2;
    rect.yEnd = y2;
} 