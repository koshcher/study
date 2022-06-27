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
  change = () => {
    // const tmp = this.first;
    // this.first = this.second;
    // this.second = tmp;
    [this.first, this.second] = [this.second, this.first];

  }

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

  makeColor($event: MouseEvent) {
    let target = $event.target as Element;
    if (target != null && target.tagName == "TD") {
      target.setAttribute('style', 'background-color: red');
    }
  }

  unmakeColor($event: MouseEvent) {
    let target = $event.target as Element;
    if (target != null && target.tagName == "TD") {
      target.setAttribute('style', 'background-color: none');
    }
  }


  ngOnInit(): void {
  }

}
