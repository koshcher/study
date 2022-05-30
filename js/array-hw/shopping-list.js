class ShoppingList {
  constructor(list) {
    this.list = list;
  }

  sort() {
    this.list.sort((a, b) => a['isCompl'] == b['isCompl'] ? 0 : a['isCompl'] == false ? 1 : -1);
  }

  show() {
    let output = '<il>';
    this.sort();
    this.list.forEach(item => {
      output += `<li>${item['value']} * ${item['count']} <input type="checkbox" ${item['isCompl'] ? "checked" : ""}></li>`;
    });
    output += '</ol><hr>';
    return output;
  }

  add(newItem) {
    for (let i = 0; i < this.list.length; i++) {
      const item = this.list[i];
      if(newItem['value'] == item['value']) {
        item['count'] += newItem['count'];
        return;
      }
    }
    this.list.push(newItem);
  }

  buy(value) {
    const i = this.list.findIndex((item) => item['value'] == value);
    this.list[i]['isCompl'] = true;
  }
}

let list = new ShoppingList(
  [
    {
      value:"Apple",
      count:4,
      isCompl:true
    },
    {
      value:"Milk",
      count:1,
      isCompl:false
    },
    {
      value:"Bread",
      count:2,
      isCompl:false
    },
    {
      value:"Eggs",
      count:10,
      isCompl:true
    },
    {
      value:"Solt",
      count:1,
      isCompl:false
    }
  ]
);

document.getElementById('shoppingListBtn').addEventListener('click', (event) => {
  let resDiv = document.getElementById('res');
  resDiv.innerHTML = '';
  resDiv.innerHTML += list.show();
  // add the existed item
  list.add({
    value:"Solt",
    count:5,
    isCompl:false
  });
  // add new item
  list.add({
    value:"Potato",
    count:10,
    isCompl:true
  });
  resDiv.innerHTML += list.show();
  list.buy("Solt");
  resDiv.innerHTML += list.show();
});