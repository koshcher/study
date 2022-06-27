import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'infolder'
})
export class InfolderPipe implements PipeTransform {

  transform(value: unknown, ...args: unknown[]): unknown {
    return null;
  }

}
