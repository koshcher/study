const apiUrl = "https://jsonplaceholder.typicode.com/posts";


getData(apiUrl);

function getDataXml() {
    let xhr = new XMLHttpRequest();
    
    xhr.open("GET", apiUrl, false);

    xhr.send();
    if(xhr.status == 200) {
        let data = JSON.parse(xhr.response);
        show(data);
    }
}

async function getData(url) {
    const response = await fetch(url);
    if(response.ok) {
        const posts = await response.json();
        show(posts);
    }
}

function show(posts) {
    let accordion = document.getElementById("accordion");
    for(const post of posts) {
        accordion.innerHTML += 
        `
        <div class="accordion-item">
          <h2 class="accordion-header" id="heading${post.id}">
            <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#collapse${post.id}" aria-expanded="true" aria-controls="collapse${post.id}">
              ${post.title}
            </button>
          </h2>
          <div id="collapse${post.id}" class="accordion-collapse collapse" aria-labelledby="heading${post.id}" data-bs-parent="#accordion">
            <div class="accordion-body">
              ${post.body}
            </div>
          </div>
        </div>
        `;
    }
}

