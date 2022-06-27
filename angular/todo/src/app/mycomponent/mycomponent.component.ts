import { Component, OnInit } from '@angular/core';
import { Item } from 'src/models/item';

@Component({
  selector: 'app-mycomponent',
  templateUrl: './mycomponent.component.html',
  styleUrls: ['./mycomponent.component.css']
})
export class MycomponentComponent implements OnInit {
  item: Item = {
    login: 'admin',
    password: 'admin',
    id: 0,
    isComplete: true
  };

  array: number[] = [123, 421, 514, 5431, 6456, 5325, 62345]

  num: number = 14.35

  name: string = 'Roman';

  numStr: string = 'ds';

  dateDot: string = '2022.07.21';
  dateSlash: string = '12/07/98';

  constructor() { }

  ngOnInit(): void {
  }

}
