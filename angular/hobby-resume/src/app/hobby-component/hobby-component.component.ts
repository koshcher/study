import { Component, OnInit } from '@angular/core';
import Hobby from '../../models/hobby'

@Component({
  selector: 'app-hobby-component',
  templateUrl: './hobby-component.component.html',
  styleUrls: ['./hobby-component.component.css']
})
export class HobbyComponentComponent implements OnInit {

  hobby: Hobby = {
    name: 'penspinning',
    description: 'spin moded pen between fingers with a lot of ways',
    preview: '../../assets/preview.jpg',
    person: 'https://i.ytimg.com/vi/_bvANJshV1Y/maxresdefault.jpg'
  }

  constructor() { }

  ngOnInit(): void {
  }

}
