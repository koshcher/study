let textToType = '';
let inputText = '';
let textToTypeP = document.getElementById('textToTypeP');
let inputTextP = document.getElementById('inputTextP');
let levels = ['a', 'b', 'c'];
let words;
var difficultySlider = document.getElementById("difficultyRange");
var difficultyOutput = document.getElementById("difficultyValue");

function highlightKey(e) {
  let currentKey = document.getElementById(`${e.code}`);
  if(currentKey != null) {
   currentKey.style.border = "2px solid white";
  }
}

function highlightFutureKey(e) {
  textToType[inputText.length - 1]
}

function offKey(e) {
  let currentKey = document.getElementById(`${e.code}`);
  if(currentKey != null) {
    currentKey.style.border = "none";
  }
}

function nextWord() {
  textToType = words[Math.floor(Math.random() * (words.length - 1))];
  textToTypeP.innerText = textToType;
}

function loadTextToType(level) {
  fetch(`https://raw.githubusercontent.com/roman-koshchei/english-word-lists/main/${level}-level-words.txt`)
  .then(file => file.text())
  .then( text => { 
    words = text.split('\n');
    nextWord();
  });
}

function sliderChange(e) {
  let value = e.target.value;
  difficultyOutput.innerHTML = value;
  loadTextToType(levels[value - 1]);
}

function changeInputText(e) {
  
    if(e.code == 'Backspace') {
      inputText = inputText.slice(0, -1);
    } else {
      if(document.getElementById(`${e.code}`) != null )
        inputText += e.key;
    }
    
    inputTextP.innerText = inputText;

    if(inputText.trimStart() == textToType) {
      inputText = '';
      inputTextP.innerText = '';
      nextWord();
    }
  
} 

function buildListeners() {
  document.addEventListener('keydown', highlightKey);
  document.addEventListener('keydown', changeInputText);
  document.addEventListener('keyup', offKey);
  difficultySlider.addEventListener("input", sliderChange);
}

function build() {
  loadTextToType('a');
  buildListeners();
}

build();