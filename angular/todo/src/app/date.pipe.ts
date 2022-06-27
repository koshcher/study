import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'date'
})
export class DatePipe implements PipeTransform {

  // 18.07.10
  transform(value: string): string {
    let separator: string | null = null;

    if (value.indexOf('.') != -1) {
      separator = '.';
    }
    else if (value.indexOf('/') != -1) {
      separator = '/';
    }

    return separator != null ? value.split(separator).reverse().join('-') : value;
  }

}
