import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'headsOrTails'
})
export class HeadsOrTailsPipe implements PipeTransform {

  transform(value: number): string {
    return value == 1 ? "heads" : value == 0 ? "tails" : "...";
  }

}
