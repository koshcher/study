class Obj {
  constructor(data) {
    this.data = data;
  }

  showProperties() {
    let output = '<ol>';
    for (const key in this.data) {
      document.write(`<li>${key}</li>`);
    }
    output += '</ol>'
    document.write(output);
  }

  deleteProperty(property) {
    if(this.data.hasOwnProperty(property)) {
      delete this.data[property]; 
      return true;
    }
    return false;
  }

  showValues() {
    document.write(Object.values(this.data));
  }

  get map() {
    let res = new Map();
    for (const key in this.data) {
      if (this.data.hasOwnProperty(key)) {
        res.set(key, this.data[key]);
      }
    }
    return res;
  }

  get reverseMap() {
    let res = new Map();
    for (const key in this.data) {
      if (this.data.hasOwnProperty(key)) {
        res.set(this.data[key], key);
      }
    }
    return res;
  }
}
getMethods = (obj) => Object.getOwnPropertyNames(obj).filter(item => typeof obj[item] === 'function');

class Library {
  constructor(books) {
    this.books = books;
  }

  getByStatus(status = 'progress') {
    let statusBooks = [];
    if(status == 'progress') {
      this.books.forEach(element => {
        statusBooks.push({
          author: element['author'],
          title: element['title'],
          readingStatus: 'progress'
        }); 
      });
    } else {
      statusBooks = this.books.filter((book) => book['readingStatus'] == status);
    }
    return statusBooks;
  }
}

class Circle {
  constructor(radius) {
    this.radius = radius;
  }

  get square() {
    return Math.PI * this.radius * this.radius;
  }

  get perimeter() {
    return 2 * Math.PI * this.radius;
  }
}

class MyArray {
  constructor(data) {
    this.data = data;
  }

  sort() {
    return this.data.sort();
  }

  showSorted() {
    document.write(`<h2>${this.sort()}</h2>`);
  }
}

let student = new Obj({
  name : "Ivan Petrov",
  class : "8",
  "roll-no": 12,

  m() {
    return 1;
  }
});
student.showProperties();
student.deleteProperty("roll-no");
student.showProperties();

let circle = new Circle(5);
document.write(`<h2>${circle.square}</h2>`);
document.write(`<h2>${circle.perimeter}</h2>`);


let library = new Library([
  {author: 'Bill Gates',title: 'The Road Ahead',readingStatus: true},
  {author: 'Steve Jobs',title: 'Walter Isaacson',readingStatus: true},
  {author: 'Suzanne Collins',title:  'CAT KID comic club',readingStatus: false}
]);
let books = library.getByStatus();

student.showValues();
let map = student.map;
let revMap = student.reverseMap;

let nums = new MyArray([6,4,0,3,-2,1]);
nums.showSorted();