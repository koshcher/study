import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class UsersService {
  constructor() { }

  users = [
    { name: "Roman" },
    { name: "Vitaliy" },
    { name: "Maria" },
    { name: "Dimon" },
  ]

  getUsers() {
    return this.users;
  }

  addUser(name: string) {
    this.users.push({ name })
  }

  removeUser(name: string) {
    const userIndex = this.users.findIndex(user => user.name == name);
    if (userIndex != -1) {
      this.users.splice(userIndex, 1)
    }
  }

}
