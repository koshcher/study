
let styles = [
  {
    name:'margin',
    value:'50px'
  },
  {
    name:'font-size',
    value:'30px'
  },
  {
    name:'color',
    value:'#ebd534'
  },
]
 
function showStyledText(text, styles) {
  let output = '<p style="';
  styles.forEach(style => {
    output += `${style['name']}: ${style['value']}; `;
  });
  output += `">${text}</p>`;
  return output;
}


document.getElementById('cssStylesBtn').addEventListener('click', (event) => {
  let resDiv = document.getElementById('res');
  resDiv.innerHTML = '';
  resDiv.innerHTML += showStyledText('styled text', styles);
});