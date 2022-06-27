import { Component, OnInit } from '@angular/core';
import Resume from 'src/models/resume';

@Component({
  selector: 'app-resume',
  templateUrl: './resume.component.html',
  styleUrls: ['./resume.component.css']
})
export class ResumeComponent implements OnInit {

  resume: Resume = {
    name: 'Roman',
    surname: 'Koshchei',
    patronymic: 'Vitaliyovich',
    phone: '+380667274905',
    town: 'Kramatorsk'
  }

  constructor() { }

  ngOnInit(): void {
  }

}
