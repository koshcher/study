import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'nodouble'
})
export class NodoublePipe implements PipeTransform {

  transform(value: unknown, ...args: unknown[]): unknown {
    return null;
  }

}
