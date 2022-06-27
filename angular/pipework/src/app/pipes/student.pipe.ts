import { Pipe, PipeTransform } from '@angular/core';
import { Student } from '../interfaces/student';

@Pipe({
  name: 'student'
})
export class StudentPipe implements PipeTransform {

  transform(value: Student): string {
    return `${value.surname} ${value.name[0]}.`
  }

}
