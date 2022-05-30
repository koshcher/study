class Check {
  constructor(list) {
    this.list = list;
  }

  show() {
    let output = '<il>';
    this.list.forEach(item => {
      output += `<li>${item.name} * ${item.count} = ${item.count * item.price}$</li>`;
    });
    output += `</il><hr>All price: ${this.sum()}$<br>`;
    return output;
  }

  sum() {
    let sum = 0;
    this.list.forEach(item => {
      sum  += item.count * item.price;
    });
    return sum;
  }

  mostExpensive() {
    let most = this.list[0];
    for (let i = 0; i < this.list.length; i++) {
      const item = this.list[i];
      if(item.count*item.price > most.count*most.price) {
        most = item;
      }
    }
    return most;
  }

  average() {
    // one item
    let sum = 0;
    this.list.forEach(item => {
      sum  += item.price;
    });
    return sum / this.list.length;
  }
}

class CheckItem {
  constructor(name, count, price) {
    this.name = name;
    this.count = count;
    this.price = price;
  }
}

let check = new Check([
  new CheckItem('Apple', 4, 6),
  new CheckItem('Milk', 1, 25),
  new CheckItem('Bread', 5, 13),
  new CheckItem('Egg', 20, 2),
]);



document.getElementById('checkBtn').addEventListener('click', (event) => {
  let resDiv = document.getElementById('res');
  resDiv.innerHTML = '';
  resDiv.innerHTML += check.show();
  let mostExpensive = check.mostExpensive();
  resDiv.innerHTML += `<p>Most expansive ${mostExpensive.name} ${mostExpensive.count * mostExpensive.price}$</p>`
  resDiv.innerHTML += `<p>Average ${check.average()}$</p>`
});