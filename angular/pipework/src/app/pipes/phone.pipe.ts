import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'phone'
})
export class PhonePipe implements PipeTransform {

  transform(value: string): string {
    if (value.length == 10) {
      return `(${value.slice(0, 3)}) ${value.slice(3, 5)} - ${value.slice(5, 7)} - ${value.slice(7)}`

    }
    return value
  }

}
