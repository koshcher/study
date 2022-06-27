import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'add'
})
export class AddPipe implements PipeTransform {

  transform(value: string): number | null {
    const a = value.match(/\d+/g);

    if (a) {
      return a.map(str => Number.parseFloat(str)).reduce((prev, curr) => prev + curr, 0);

    }

    return null;
  }

}
