import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'newinpipe'
})
export class NewinpipePipe implements PipeTransform {

  transform(value: unknown, ...args: unknown[]): unknown {
    return null;
  }

}
