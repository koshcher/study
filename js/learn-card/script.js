const container = document.getElementById('container');

function StartPage() {
  let h1 = document.createElement('h1');
  h1.classList.add('text-center', 'mt-5');
  h1.innerText = 'Картки для вивчення англійських слів';

}


// task 2
// const WORDS_NUMBER = 20000;
// const API_URL = `https://random-word-api.herokuapp.com/word?number=${WORDS_NUMBER}`;

// fetch(API_URL)
// .then(response =>  response.json())
// .then(words => {
//   const starts = {
//     a:[], r:[], t:[], x:[], d:[]
//   };
//   words.forEach((word) => {
//     const start = word.at(0);
//     if(Object.keys(starts).includes(start) && starts[start].length < 10) {
//       starts[start].push(word);
//     }
//   });
//   return starts;
// })
// .then(starts => {
//   for (const key in starts) {
//     startsDiv.innerHTML += `
//     <div class="col">
//       <div class="card">
//         <div class="card-body">
//           <h5 class="card-title">${key.toUpperCase()}</h5>
//           <p class="card-text">${starts[key].join(', ')}</p>
//         </div>
//       </div>
//     </div>
//     `
//   }
// })
// .catch(error => console.log(error));

// // task 1
// const iPromiseLearnNextJs = new Promise(
//   (resolve, reject) => {
//    const learnedNextJs = true;
   
//    if(learnedNextJs) {
//     resolve(
//       {
//         todo:'write own web app',
//         praise: 'You did good job, you are cool',
//         respect: 100
//       }
//     );
//    } else {
//     reject([
//       'good salary',
//       'ability to make startup',
//       'become cool'
//     ]);
//    }
//   }
// );

// function motivate(reasons) {
//   header.innerText = 'JUST GET WORK DONE\nAnd you will get:\n';
//   reasons.forEach(reason => header.innerText +=  `${reason}\n`);
// }

// // iPromiseLearnNextJs
// // .then((future) => {
// //   header.innerText = `${future.praise}\nYour respect is ${future.respect}%\nNext goal: ${future.todo}`;
// // })
// // .catch((reasons) => {
// //   motivate(reasons);
// // });