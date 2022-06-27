import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { PhonePipe } from './pipes/phone.pipe';
import { MainComponent } from './components/main/main.component';
import { NamePipe } from './pipes/name.pipe';
import { StudentPipe } from './pipes/student.pipe';
import { MathPipe } from './pipes/math.pipe';

@NgModule({
  declarations: [
    AppComponent,
    PhonePipe,
    MainComponent,
    NamePipe,
    StudentPipe,
    MathPipe
  ],
  imports: [
    BrowserModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
