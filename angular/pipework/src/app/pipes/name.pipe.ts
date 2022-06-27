import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'name'
})
export class NamePipe implements PipeTransform {

  transform(value: string): string {
    let res: string = '';
    for (const char of value) {
      res += `${char}${char}`
    }
    return res
  }

}
