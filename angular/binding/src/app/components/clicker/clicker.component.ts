import { Component, NgModule, OnInit } from '@angular/core';

@Component({
  selector: 'app-clicker',
  templateUrl: './clicker.component.html',
  styleUrls: ['./clicker.component.scss']
})
export class ClickerComponent implements OnInit {

  count = 0;
  step = 1;
  increment = () => this.count += this.step;
  decrement = () => {
    if (this.count > 0) this.count -= this.step;
  }
  isChecked = false;

  key: string = "";
  enter = (event: KeyboardEvent) => {
    this.key += event.key;
  }

  isHidden: boolean = false;
  changeHidden() {
    this.isHidden = !this.isHidden;
  }

  constructor() { }

  ngOnInit(): void {
  }

}
