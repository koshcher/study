import { Component, OnInit } from '@angular/core';
import { UserAdvancedService } from 'src/app/services/user-advanced.service';

@Component({
  selector: 'app-user-list',
  templateUrl: './user-list.component.html',
  styleUrls: ['./user-list.component.scss']
})
export class UserListComponent implements OnInit {
  constructor(private uservice: UserAdvancedService) { }

  users: any[] = []

  newUser = {
    name: "",
    lastName: ""
  }

  ngOnInit(): void {
    this.getUsers();
  }

  getUsers() {
    this.users = this.uservice.getUsers()
  }

  addUser() {
    this.uservice.addUser(this.newUser.name, this.newUser.lastName);
  }



}
