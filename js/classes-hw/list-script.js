class List {
  constructor(values) {
    this.values = values;
  }

  printList() {
    this.values.sort();
    let output = '<ol>';
    this.values.forEach(element => {
      output += `<li>${element}</li>`;
    }); 
    output += '</ol>';

    document.write(output);
  }

  add(product) {
    this.values.push(product);
  }
}
const list = new List(['kiwi', 'potato', 'apple', 'sour cream', 'tomato', 'ice cream']);
list.printList();

list.add('pumpkin');
list.printList();

list.values = ['C#', 'JavaScript', 'HTML', 'PHP'];
list.printList();


