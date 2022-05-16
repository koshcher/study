var header = document.getElementById("header");
header.innerText += `${localStorage.length})`;

var addForm = document.forms.add;
addForm.addEventListener('submit', () => {
    if(addForm.elements['text'].value == '') {
        alert("Task can not be empty");
    } else {
        localStorage.setItem(
            addForm.elements['text'].value, JSON.stringify
            ({
                date:addForm.elements['date'].value,
                completed:false
            })
        );
    }
});

let taskList = document.getElementById('taskList');
let keys = Object.keys(localStorage);

for (let i = 0; i < keys.length; i++) {
    let info = JSON.parse(window.localStorage.getItem(keys[i]));
    if(info.completed == false) {
        taskList.innerHTML += 
        `
        <form class="list-group-item d-flex justify-content-between align-items-center">
            <div>
                <h5 class="mb-0">${keys[i]}</h5>
                ${ info.date != '' ? `<small class="text-muted">${info.date}</small>` : ''}
            </div>
            <div>
                <button  class="btn btn-success"
                onclick="
                    localStorage.setItem('${keys[i]}', JSON.stringify
                    ({
                        date:'${info.date}',
                        completed:true
                    }));
                ">
                    <i class="bi bi-check"></i>
                </button>
                <button class="btn btn-danger" disabled>
                    <i class="bi bi-trash"></i>
                </button>
            </div>
        </form>
        `
    }
}

for (let i = 0; i < keys.length; i++) {
    let info = JSON.parse(window.localStorage.getItem(keys[i]));
    if(info.completed == true) {
        taskList.innerHTML += 
        `
        <form class="list-group-item d-flex justify-content-between align-items-center">
            <div>
                <h5 class="mb-0 text-decoration-line-through">${keys[i]}</h5>
                ${ info.date != '' ? `<small class="text-muted">${info.date}</small>` : ''}
            </div>
            <div>
                <button  class="btn btn-success" disabled>
                    <i class="bi bi-check"></i>
                </button>
                <button class="btn btn-danger"
                onclick="localStorage.removeItem('${keys[i]}')">
                    <i class="bi bi-trash"></i>
                </button>
            </div>
        </form>
        `
    }
}