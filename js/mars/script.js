document.addEventListener('DOMContentLoaded', () => {
  const apiKey = "Tw9nOqwS1PfdWTN6F3owMcmTxeTEmpsDdyk2Pqxc";

  const operationBtns = document.querySelectorAll('input.btn');
  operationBtns.forEach(btn => {
      btn.addEventListener('click', (event) => {
          getData(`https://api.nasa.gov/mars-photos/api/v1/rovers/${event.target.value.toLowerCase()}/photos?sol=1000&api_key=${apiKey}`);
      });
  });
  
});

function getDataXml(url) {
    let xhr = new XMLHttpRequest();
    
    xhr.open("GET", url, false);

    xhr.send();
    if(xhr.status == 200) {
        let data = JSON.parse(xhr.response);
        show(data);
    }
}

async function getData(url) {
    const response = await fetch(url);
    if(response.ok) {
        const photos = await response.json();
        show(photos);
    }
}

function show(data) {
    let table = document.getElementById("table");
    table.innerHTML = '';
    for(const photo of data.photos) {
      table.innerHTML += 
        `
        <div class="col">
          <div class="card">
            <img src="${photo.img_src}" class="card-img-top">
            <div class="card-body">
              <h5 class="card-title">${photo.camera.name} (${photo.camera.full_name})</h5>
              <p class="card-text">${photo.earth_date}</p>
            </div>
          </div>
        </div>
        `;
    }
}

