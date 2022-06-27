import { Component, OnInit } from '@angular/core';
import { Student } from 'src/app/interfaces/student';

@Component({
  selector: 'app-main',
  templateUrl: './main.component.html',
  styleUrls: ['./main.component.css']
})
export class MainComponent implements OnInit {

  date: Date = new Date(2005, 7, 12)

  phone: string = '0667274905';
  name: string = 'Roma'
  students: Student[] = [
    { name: 'Roma', surname: 'Koshchei' },
    { name: 'Dmitry', surname: 'Flud' },
    { name: 'Maria', surname: 'Sherbak' }
  ]

  fruit: string = "apple";
  sayHowCoolIam: boolean = true;

  constructor() { }

  ngOnInit(): void {
  }

}
