document.addEventListener('DOMContentLoaded', () => {
  let loadBtn = document.getElementById('loadBtn');
  loadBtn.addEventListener('click', (e) => {
    let userPostCount = getUserPostCount();
    let usersData = getDataXml('https://jsonplaceholder.typicode.com/users');
    if(usersData != null && userPostCount != null) {
      buildUsers(usersData, userPostCount);
    } else {
      buildError();
    }
  });

});

function getUserPostCount() {
  let userPostCount = {};
  let postsData = getDataXml('https://jsonplaceholder.typicode.com/posts');
  if(postsData != null) {
    for(const post of postsData) {
      if(post.title.length > 35) {
        if(userPostCount.hasOwnProperty(`${post.userId}`)) {
          userPostCount[`${post.userId}`] += 1;
        } else {
          userPostCount[`${post.userId}`] = 1;
        }
      }
    }
    return userPostCount;
  } else {
    // error
    return null;
  }
}

function getDataXml(url) {
  let xhr = new XMLHttpRequest();
  
  xhr.open("GET", url, false);
  xhr.send();
  if(xhr.status == 200) {
    return JSON.parse(xhr.response);
  }
  return null;
}

function buildUsers(usersData, userPostCount) {
    let table = document.getElementById("table");
    table.innerHTML = '';
    for(const user of usersData) {

      let col = document.createElement('div');
      col.classList.add('col');

      let card = document.createElement('div');
      card.classList.add('card', 'box-shadow');

      let img = document.createElement('img');
      img.classList.add('card-img-top');
      img.src = `https://picsum.photos/id/${user.id * 10}/300/150`;

      let cardBody = document.createElement('div');
      cardBody.classList.add('card-body');
      
      let cardHeader = document.createElement('h5');
      cardHeader.classList.add('card-title');
      cardHeader.innerText = `${user.name} (${user.username})`;
      
      let cardText = document.createElement('p');
      cardText.classList.add('card-text');
      cardText.innerHTML = `Email: ${user.email}<br>Company: ${user.company.name}<br>Website: ${user.website}`;
      
      let bottomDiv = document.createElement('div');
      bottomDiv.classList.add('d-flex', 'justify-content-between', 'align-items-center');
      let deleteBtn = document.createElement('button');
      deleteBtn.classList.add('btn','btn-sm','btn-outline-dark');
      deleteBtn.innerText = "Delete";
      deleteBtn.addEventListener('click', (e) => {
        col.remove();
      });
      let postCount = document.createElement('small');
      postCount.classList.add('text-muted');
      postCount.innerText = `${userPostCount[`${user.id}`]} posts`;

      bottomDiv.appendChild(deleteBtn);
      bottomDiv.appendChild(postCount);

      cardBody.appendChild(cardHeader);
      cardBody.appendChild(cardText);
      cardBody.appendChild(bottomDiv);

      card.appendChild(img);
      card.appendChild(cardBody);
      col.appendChild(card);
      table.appendChild(col);

      // table.innerHTML += 
      //   `
      //   <div class="col">
      //     <div class="card box-shadow">
      //       <img src="https://picsum.photos/id/${user.id * 10}/300/150" class="card-img-top">
      //       <div class="card-body">
      //         <h5 class="card-title">${user.name} (${user.username})</h5>
      //         <p class="card-text">
      //           Email: ${user.email}<br>Company: ${user.company.name}<br>Website: ${user.website}
      //         </p>
      //         <div class="d-flex justify-content-between align-items-center">
      //           <button type="button" class="btn btn-sm btn-outline-dark" id="deleteBtn${user.id}">Delete</button>
      //           <small class="text-muted">${userPostCount[`${user.id}`]} posts</small>
      //         </div>
      //       </div>
      //     </div>
      //   </div>
      //   `;
      //deleteBtn = document.getElementById(`deleteBtn${user.id}`);
    }
}

function buildError() {  
  let table = document.getElementById("table");
  table.innerHTML = `
  <div class="col">
    <div class="card box-shadow">
      <div class="card-body">
        <h5 class="card-title">Cannot load users</h5>
        <p class="card-text">Please try later</p>
      </div>
    </div>
  </div>
  `;
}


// async function getData(url) {
//   const response = await fetch(url);
//   if(response.ok) {
//       const photos = await response.json();
//       buildUsers(photos);
//   }
// }