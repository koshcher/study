import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'inpipe'
})
export class InpipePipe implements PipeTransform {

  transform(value: unknown, ...args: unknown[]): unknown {
    return null;
  }

}
