import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'math'
})
export class MathPipe implements PipeTransform {

  transform(value: string): string {
    return `${value}=${eval(value)}`;
  }

}
