import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { HiComponent } from './components/hi/hi.component';
import { UsersComponent } from './components/users/users.component';
import { HiService } from './services/hi.service';
import { UsersService } from './services/users.service';
import { UserListComponent } from './components/user-list/user-list.component';
import { UserTableComponent } from './components/user-table/user-table.component';
import { RandComponent } from './components/rand/rand.component';
import { RandService } from './services/rand.service';
import { HttpComponent } from './components/http/http.component';
import { HttpClientModule } from '@angular/common/http';
import { HttpService } from './services/http.service';
import { HeadsOrTailsComponent } from './components/heads-or-tails/heads-or-tails.component';
import { HeadsOrTailsPipe } from './pipes/heads-or-tails.pipe';


@NgModule({
  declarations: [
    AppComponent,
    HiComponent,
    UsersComponent,
    UserListComponent,
    UserTableComponent,
    RandComponent,
    HttpComponent,
    HeadsOrTailsComponent,
    HeadsOrTailsPipe
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpClientModule
  ],
  providers: [
    HiService,
    UsersService,
    RandService,
    HttpService
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
