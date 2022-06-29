import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class HttpService {
  constructor(private http: HttpClient) { }


  key = "ab7b4d47";

  getUsers() {
    return this.http.get("https://jsonplaceholder.typicode.com/users")
  }

  getQwerty() {
    return this.http.get("https://genkey-api.herokuapp.com/divided/?topKeys=qwertyuiop&homeKeys=asdfghjkl%3B%27&botKeys=zxcvbnm,./&topFingers=0123344567&homeFingers=01233445677&botFingers=0123344567")
  }

  getMovie(title: string, plot = "short", year: number = -1) {
    let movie = {
      title: "",
      year: 0,
      rating: "",
      duration: "",
      producer: "",
      actors: "",
      plot: "",
      img: ""
    }

    let url = `http://www.omdbapi.com/?apikey=${this.key}&t=${title}&plot=${plot}`;
    if (year != -1) {
      url += `&y=${year}`
    }

    this.http.get(url)
      .subscribe((data: any) => {
        movie.title = data.Title;
        movie.year = data.Year;
        movie.duration = data.Runtime;
        movie.producer = data.Writer;
        movie.actors = data.Actors;
        movie.plot = data.Plot;
        for (let i = 0; i < data.Ratings.length; i++) {
          movie.rating += `${data.Ratings[i].Value}`
          movie.rating += i == data.Ratings.length - 1 ? '' : ', ';
        }
        movie.img = data.Poster;
        console.log(data)
      })
    return movie;
  }
}
