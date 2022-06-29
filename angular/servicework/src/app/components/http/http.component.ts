import { Component, OnInit } from '@angular/core';
import { HttpService } from 'src/app/services/http.service';

@Component({
  selector: 'app-http',
  templateUrl: './http.component.html',
  styleUrls: ['./http.component.scss']
})
export class HttpComponent implements OnInit {
  constructor(private http: HttpService) { }

  users: any
  qwerty: any

  title = "cat"
  year = null
  plot = "short"
  movie: any = null

  ngOnInit(): void {
    this.http.getUsers().subscribe(data => this.users = data)
    this.http.getQwerty().subscribe(data => this.qwerty = data)
  }

  getMovie() {
    if (this.year != null) {
      this.movie = this.http.getMovie(this.title.toLowerCase(), this.plot, this.year)
    } else {
      this.movie = this.http.getMovie(this.title.toLowerCase(), this.plot)
    }
  }



}
