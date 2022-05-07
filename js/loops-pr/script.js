const btnLovedLaptops = document.getElementById("btnLovedLaptops");
btnLovedLaptops.addEventListener('click', () => {
    let selectLaptops = document.formLaptops.selectLaptops;
    let lovedLaptops = [];

    for(let i = 0; i < selectLaptops.options.length; i++) {
        if(selectLaptops.options[i].selected) {
            lovedLaptops.push(selectLaptops.options[i].innerText);
        }
    }

    let lovedLaptopsP = document.getElementById('lovedLaptops'); 
    lovedLaptopsP.innerText = "";
    for(let i = 0; i < lovedLaptops.length; i++) {
        lovedLaptopsP.innerText += ` ${lovedLaptops[i]}`;
    }
});

const url = 'https://jsonplaceholder.typicode.com/todos';
const todosDiv = document.getElementById('todosDiv');
fetch(url)
.then(function(response) {    
    return response.json();
})
.then((data) => {
    const todos = data;
    console.log(todos);

    for (const propName in todos) {
        const element = todos[propName];
        const title = element.title;
        const completed = element.completed;

        var p = document.createElement("p");
        var text = document.createTextNode((completed ? "Completed " : "") + `Title: ${title}`);
        p.appendChild(text);
        todosDiv.appendChild(p);
    }
})
.catch((error) => {
    console.log(error);
});