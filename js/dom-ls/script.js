let addColorBtn = document.getElementById('addColorBtn');
let colorBlockDiv = document.getElementById('colorBlockDiv');
let colorTextP = document.getElementById('colorTextP');
let numP = document.getElementById('numP');
let commentsUl = document.getElementById('commentsUl');
let titleInput = document.getElementById('titleInput');
let descriptionInput = document.getElementById('descriptionInput');
let addCommentBtn = document.getElementById('addCommentBtn');

let colors = ["red", "green","blue","yellow","coral", "darkkhaki"];
let colorBlockIds = [];
let maxId = 0;
let num = 0;

function getRandNum(max) {
    return Math.floor(Math.random() * max);
}

function colorBlockClick(e) {
    colorBlockIds.splice(colorBlockIds.indexOf(Number(e.target.id)), 1);
    e.target.remove();
}

function colorBlockMouseOver(e) {
    colorTextP.style.color = e.target.style.backgroundColor;
}

addColorBtn.addEventListener('click', (e) => {
    colorBlockDiv.innerHTML += `<div id="${maxId}" style="background-color: ${colors[getRandNum(colors.length - 1)]};" class="colorBlock"></div>`;
    colorBlockIds.push(maxId);
    maxId++;

    colorBlockIds.forEach(id => {
        let colorBlock = document.getElementById(`${id}`);
        colorBlock.addEventListener('mouseenter', colorBlockMouseOver);
        colorBlock.addEventListener('click', colorBlockClick);
    });
});

document.getElementById('numUp').addEventListener('click', (e) => {
    num++;
    numP.innerText = num;
});

document.getElementById('numDown').addEventListener('click', (e) => {
    if(num > 0) {
        num--;
        numP.innerText = num;
    }
});

addCommentBtn.addEventListener('click', () => {
    if(titleInput.value == '') {
        alert("Title can not be empty");
    } else {
        commentsUl.innerHTML += 
        `<li class="list-group-item">
        <h5 class="mb-1">${titleInput.value}</h5>
        <p class="mb-1">${descriptionInput.value}</p>
        </li>`;
    }
});