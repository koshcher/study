import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { SomePipePipe } from './some-pipe.pipe';
import { SomeComponent } from './some/some.component';

@NgModule({
  declarations: [
    AppComponent,
    SomePipePipe,
    SomeComponent
  ],
  imports: [
    BrowserModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
