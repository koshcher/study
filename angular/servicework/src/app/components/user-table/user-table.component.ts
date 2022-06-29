import { Component, OnInit } from '@angular/core';
import { UserAdvancedService } from 'src/app/services/user-advanced.service';

@Component({
  selector: 'app-user-table',
  templateUrl: './user-table.component.html',
  styleUrls: ['./user-table.component.scss']
})
export class UserTableComponent implements OnInit {

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
