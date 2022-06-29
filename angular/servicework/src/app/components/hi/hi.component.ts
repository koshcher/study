import { Component, OnInit } from '@angular/core';
import { HiService } from 'src/app/services/hi.service';

@Component({
  selector: 'app-hi',
  templateUrl: './hi.component.html',
  styleUrls: ['./hi.component.scss']
})
export class HiComponent implements OnInit {

  constructor(hi: HiService) {
    //alert(hi.sayHi());
  }

  ngOnInit(): void {
  }

}
