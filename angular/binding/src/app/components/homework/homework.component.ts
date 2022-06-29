import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-homework',
  templateUrl: './homework.component.html',
  styleUrls: ['./homework.component.scss']
})
export class HomeworkComponent implements OnInit {

  constructor() { }

  first = "";
  second = "";
  change = () => [this.first, this.second] = [this.second, this.first];

  inputCount = 0;
  res: string[] = [];
  generate() {
    this.res = this.inputCount.toString().split('');
  }

  matrixStr = "";
  matrix: string[][] = []
  createMatrix() {
    let row = 0;
    this.matrix[row] = [];

    for (const str of this.matrixStr) {
      if (str == '\n') {
        row++;
        this.matrix[row] = [];
        continue;
      }
      this.matrix[row].push(str);
    }
  }

  settings = {
    width: 50,
    height: 50,
    rotate: 0
  }

  colors: string[] = ['red', 'blue', 'yellow', 'brown']
  getRandomInt(max: number) {
    return Math.floor(Math.random() * max);
  }

  blocks: string[] = []
  addBlock() {
    this.blocks.push(this.colors[this.getRandomInt(this.colors.length)]);
  }


  makeColor($event: MouseEvent) {
    let target = $event.target as Element;
    if (target != null && target.tagName == "TD") {
      target.setAttribute('style', `background-color: ${this.colors[this.getRandomInt(this.colors.length)]}`);
    }
  }
  unmakeColor($event: MouseEvent) {
    let target = $event.target as Element;
    if (target != null && target.tagName == "TD") {
      target.setAttribute('style', 'background-color: none');
    }
  }

  mosts: any = {
    car: "Car 'The American Dream' now measures 30.54 metres",
    aircraft: "Aircraft 'Antonov An-225 Mriya'",
    ship: "Ship 'Seawise Giant'"
  }
  most = "";
  changeMost(type: string) {
    this.most = this.mosts[type];
  }
  changeMostE(e: Event) {
    const target = e.target as Element;
    if (target != null && target.tagName == "BUTTON") {
      this.most = this.mosts[target.innerHTML];
    }
  }


  ngOnInit(): void {
  }

}
