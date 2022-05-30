var div = document.getElementById('list');

class ShoppingList {
	constructor(arr) {
	  this.arr = arr;
	}
  
	show() {
	  this.arr.sort((a, b) => a.isCompl == b.isCompl ? 0 : a.isCompl === true ? 1 : -1);
	  var ol = document.createElement('ol');
      div.appendChild(ol);
     
      for(var i = 0;i <this.arr.length; i++){
      	var li = document.createElement('li');
      	li.innerHTML=`Name: ${this.arr[i].value};   Count: ${this.arr[i].count};   ISCompleted: ${this.arr[i].isCompl};`;
      	ol.appendChild(li);
      }
	}
   
	add(name, num, isc){
		if((typeof name=='string')&&(typeof num=='number')&&(typeof isc=='boolean')){	
		   var flag=0;

           for(var i=0; i<this.arr.length; i++){   
		  	   if(this.arr[i].value.toUpperCase()===name.toUpperCase()){
               this.arr[i].count+=num;
			   this.arr[i].isCompl=isc;
			   flag++; 
		       }
		    }
            if(flag==0){
				var temp={
					value: name,
					count: num,
					isCompl: isc
				}
				this.arr.push(temp);
			}

	    }
	   else{
		alert('При додаванні об"єкту стлася помилка не відповідності типів даних');
	   }
	}

	bought(name){
		for(var i=0; i<this.arr.length; i++){
			if(this.arr[i].value.toUpperCase()===name.toUpperCase()){
    		this.arr[i].isCompl=true;
			}
		}
	}
}
  
  let mas1=[
	{
	  value:"Яблука",
	  count:4,
	  isCompl:true
	},
	{
	  value:"Молоко",
	  count:1,
	  isCompl:false
	},
	{
	  value:"Хліб",
	  count:2,
	  isCompl:false
	},
	{
	  value:"Яйця",
	  count:10,
	  isCompl:true
	},
	{
	  value:"Сіль",
	  count:1,
	  isCompl:false
	}
  ]
  
  let list = new ShoppingList(mas1);
  list.show();
 list.add("хліб", 2, false);
 list.add("Цукор", 1, false);
 list.add(1, 1, 1);
 list.show();
  list.bought("хліб");
  list.show();
////////////////////////////////////
  var p=document.createElement('p');
  p.innerHTML="------------------------";
  div.appendChild(p);
////////////////////////////////////

class Chek{
	constructor(mas){
         this.mas=mas;
	}

	print(){
	  
      var ol1 = document.createElement('ol');
      div.appendChild(ol1);
      for(var i = 0;i <this.mas.length; i++){
      	var li = document.createElement('li');
      	li.innerHTML=`Value: ${this.mas[i].value}; Count: ${this.mas[i].count}; Price: ${this.mas[i].price};`;
      	ol1.appendChild(li);
      }
	}

	sum(){
		var sum=0;
		for(var i=0; i<this.mas.length; i++){
           sum+=this.mas[i].count*this.mas[i].price;
		}
		
		var p=document.createElement('p');
		p.innerHTML=`Sum: ${sum}`;
		div.appendChild(p);
	
	}
     
     biggest(){
     	var big=this.mas[0];
     	for(var i=0; i<this.mas.length; i++){
     		if((big.price*big.count)<(this.mas[i].price*this.mas[i].count)){
     			big=this.mas[i];
     		}
     	}
     	 var p=document.createElement('p');
     	 p.innerHTML=`Value: ${big.value}; Count: ${big.count}; Price: ${big.price}`;
		 div.appendChild(p);
     }

	 stoimost(){
		 var sum=0;
		 var count=0;
		 for(var i=0; i<this.mas.length; i++){
          count+=this.mas[i].count;
          sum+=this.mas[i].price*this.mas[i].count;
		 }
		 sum=sum/count;
		 var p=document.createElement('p');
     	 p.innerHTML=`Середня ціна одного продукта-${sum}`;
		 div.appendChild(p);
	 }
	
}

let mas=[{
	value:"Яблука",
	count:3,
	price:10
},
{
	value:"Молоко",
	count:1,
	price:36
},
{
	value:"Хліб",
	count:2,
	price:28
},
{
	value:"Яйця",
	count:10,
	price:1
},
{
	value:"Сіль",
	count:1,
	price:20
}
];

let ch = new Chek(mas);
ch.print();
ch.sum();
ch.biggest();
ch.stoimost();
///////////////////////////////
var p1=document.createElement('p');
p1.innerHTML="------------------------";
div.appendChild(p1);
//////////////////////////////////
/*
let group=[
	{
       name: "BV012",
	   count:18,
	   faculty:"Mathematicians" 
    },
	{
     name:"PP011",
	 count:18,
	 faculty:"Philological"
    },
	{
		name1:"KD012",
		count1:7,
		faculty1:"Physicist"
	}
]
*/
class Academia{
	constructor(aud){
    this.aud=aud;
	}

	print() {
		let ol=document.createElement('ol');
		div.appendChild(ol);
		for (let i = 0; i < this.aud.length; i++) {
			let li=document.createElement('li');
			li.innerHTML=`Name auditorii: ${this.aud[i].name}; Count: ${this.aud[i].count};  Faculty: ${this.aud[i].faculty}; `;
			ol.appendChild(li);
		}
	}
}


let auditoria=[
	{
	   name:"First" ,
	   count: 12 ,
	   faculty: "Chemistry" 
	},
	{
	  name: "Second",
	  count: 15,
	  faculty:"Mathematicians" 
  },
  {
	  name: "Third",
	  count: 17,
	  faculty:"Biology" 
  },
  {
	  name: "Fourth",
	  count: 18,
	  faculty: "Physicist"
  },
  {
	  name:"Fifth" ,
	  count: 20,
	  faculty: "Philological"
  },
  {
	  name:"Sixth" ,
	  count: 18,
	  faculty: "Philological"
  }
];

let audd= new Academia(auditoria);
audd.print();