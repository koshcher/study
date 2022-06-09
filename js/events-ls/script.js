let randP = document.getElementById('randP');
let randNum;

document.getElementById('randBtn').addEventListener('click', (e) =>
  randP.innerText = Math.floor((Math.random() * 100))
);

let hideShowP = document.getElementById('hideShowP');
document.getElementById('hideShowBtn').addEventListener('click', (e) => 
  hideShowP.hidden = !hideShowP.hidden
);

let likeI = document.getElementById('likeI');
let likeCount = 0;
document.getElementById('likeBtn').addEventListener('click', (e) => {
  likeI.innerText = `Like: ${++likeCount}`;
});

let tabBtns = document.getElementsByName('tabBtn');
let tabContent = document.getElementById('tabContent');
tabs = {
  'HTML':"The HyperText Markup Language or HTML is the standard markup language for documents designed to be displayed in a web browser. It can be assisted by technologies such as Cascading Style Sheets (CSS) and scripting languages such as JavaScript. HTML. (HyperText Markup Language)",
  'CSS':"Cascading Style Sheets (CSS) is a style sheet language used for describing the presentation of a document written in a markup language such as HTML.[1] CSS is a cornerstone technology of the World Wide Web, alongside HTML and JavaScript.",
  'JS':"JavaScript (/ˈdʒɑːvəskrɪpt/),[10] often abbreviated JS, is a programming language that is one of the core technologies of the World Wide Web, alongside HTML and CSS.[11] Over 97% of websites use JavaScript on the client side for web page behavior,[12] often incorporating third-party libraries."
}
tabBtns.forEach(btn => {
  btn.addEventListener('click', (e) => 
    tabContent.innerText =  tabs[e.target.innerText]
  );
});

