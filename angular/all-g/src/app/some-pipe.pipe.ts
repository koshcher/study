import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'somePipe'
})
export class SomePipePipe implements PipeTransform {

  transform(value: unknown, ...args: unknown[]): unknown {
    return null;
  }

}
