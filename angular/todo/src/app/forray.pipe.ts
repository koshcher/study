import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'forray'
})
export class ForrayPipe implements PipeTransform {

  transform(value: any[], start?: number, end?: number): string {
    if (start === null) {
      return value.join(" | ")
    }

    if (end === null) {
      return value.slice(start).join(" | ")
    }

    return value.slice(start, end).join(" | ")
  }

}
