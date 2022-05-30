class Acedemy {
  constructor(audiences) {
    this.audiences = audiences;
  }

  showAll() {
    let output = '<il>';
    this.audiences.forEach(item => {
      output += `<li>${item.name} places: ${item.count} faculty: ${item.faculty}</li>`;
    });
    output += `</il><hr>`;
    return output;
  }

  showByFaculty(faculty) {
    let output = `<h3>Faculty: ${faculty}</h3><il>`;
    this.audiences.forEach(item => {
      if(item.faculty == faculty) {
        output += `<li>${item.name} places: ${item.count} faculty: ${item.faculty}</li>`;
      }
    });
    output += `</il><hr>`;
    return output;
  }

  showForGroup(group) {
    let output = `<h3>Group: ${group.name}</h3><il>`;
    this.audiences.forEach(item => {
      if(item.faculty == group.faculty && item.count >= group.count) {
        output += `<li>${item.name} places: ${item.count} faculty: ${item.faculty}</li>`;
      }
    });
    output += `</il><hr>`;
    return output;
  }

  sortByCount() {
    this.audiences.sort((a, b) => a.count == b.count ? 0 : a.count > b.count ? 1 : -1);
  }

  sortByName() {
    this.audiences.sort((a, b) => a.name == b.name ? 0 : a.name > b.name ? 1 : -1);
  }
}

let audiences = [
  {
    name:'ZU12',
    count: 13,
    faculty: 'Math'
  },
  {
    name:'WK32',
    count: 20,
    faculty: 'Math'
  },
  {
    name:'GH71',
    count: 17,
    faculty: 'Biology'
  }
]

document.getElementById('audienceBtn').addEventListener('click', (event) => {
  let resDiv = document.getElementById('res');
  resDiv.innerHTML = '';
  let acedemy = new Acedemy(audiences);
  resDiv.innerHTML += acedemy.showAll();
  resDiv.innerHTML += acedemy.showByFaculty('Math');
  resDiv.innerHTML += acedemy.showForGroup({
    name:'G1',
    count:14,
    faculty:'Math'
  });
  acedemy.sortByCount();
  resDiv.innerHTML += acedemy.showAll();
  acedemy.sortByName();
  resDiv.innerHTML += acedemy.showAll();
});