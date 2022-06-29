import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class UserAdvancedService {
  constructor() { }

  private users = [
    { name: "Roman", lastName: "Koshchei" },
    { name: "Maria", lastName: "Shcherbak" },
    { name: "Dimon", lastName: "Flud" },
    { name: "Vitaliy", lastName: "Litvinenko" },
  ]

  getUsers() {
    return this.users;
  }

  addUser(name: string, lastName: string) {
    this.users.push({
      name, lastName
    })
  }
}
