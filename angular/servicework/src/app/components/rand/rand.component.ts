import { Component, OnInit } from '@angular/core';
import { RandService } from 'src/app/services/rand.service';

@Component({
  selector: 'app-rand',
  templateUrl: './rand.component.html',
  styleUrls: ['./rand.component.scss']
})
export class RandComponent implements OnInit {

  constructor(private rand: RandService) { }

  start = 0;
  end = 100;
  count = 5;

  nums: number[] = []

  ngOnInit(): void {
  }


  generate() {
    this.nums = this.rand.generate(this.start, this.end, this.count)
  }
}
