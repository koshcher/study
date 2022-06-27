import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { ClickerComponent } from './components/clicker/clicker.component';
import { HomeworkComponent } from './components/homework/homework.component';

@NgModule({
  declarations: [
    AppComponent,
    ClickerComponent,
    HomeworkComponent,
  ],
  imports: [
    BrowserModule,
    FormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
