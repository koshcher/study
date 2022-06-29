import { Component, OnInit } from '@angular/core';
import { RandService } from 'src/app/services/rand.service';

@Component({
  selector: 'app-heads-or-tails',
  templateUrl: './heads-or-tails.component.html',
  styleUrls: ['./heads-or-tails.component.scss']
})
export class HeadsOrTailsComponent implements OnInit {

  constructor(private rnd: RandService) { }

  ngOnInit(): void {
  }

  coin = -1;
  throw() {
    this.coin = this.rnd.rand(1)
  }

}
