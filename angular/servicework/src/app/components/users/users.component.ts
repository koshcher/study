import { Component, OnInit } from '@angular/core';
import { UsersService } from 'src/app/services/users.service';

@Component({
  selector: 'app-users',
  templateUrl: './users.component.html',
  styleUrls: ['./users.component.scss']
})
export class UsersComponent implements OnInit {
  constructor(private uservice: UsersService) { }

  users: any[] = [];
  newUser: string = ""

  addNewUser() {
    if (this.newUser != "") {
      this.uservice.addUser(this.newUser);
      this.getUsers();
      this.newUser = "";
    }
  }

  getUsers() {
    this.users = this.uservice.getUsers();
  }

  removeUser(name: string) {
    this.uservice.removeUser(name);
    this.getUsers();
  }

  ngOnInit(): void {
    this.getUsers();
  }


}
