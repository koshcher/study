import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class RandService {

  constructor() { }

  generate(start: number, end: number, count: number) {
    let nums: number[] = []
    for (let i = 0; i < count; i++) {
      nums.push(Math.floor(Math.random() * (end - start) + start + 1))
    }
    return nums;
  }

  rand(max: number) {
    return Math.floor(Math.random() * (max + 1))
  }
}
