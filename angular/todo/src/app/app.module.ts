import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { MycomponentComponent } from './mycomponent/mycomponent.component';
import { ImageComponent } from './image/image.component';
import { FormatPipe } from './format.pipe';
import { ForrayPipe } from './forray.pipe';
import { DatePipe } from './date.pipe';
import { AddPipe } from './add.pipe';
import { NodoublePipe } from './nodouble.pipe';
import { InfolderPipe } from './infolder.pipe';
import { InpipePipe } from './pipes/inpipe.pipe';
import { NewinpipePipe } from './pipes/newinpipe.pipe';

@NgModule({
  declarations: [
    AppComponent,
    MycomponentComponent,
    ImageComponent,
    FormatPipe,
    ForrayPipe,
    DatePipe,
    AddPipe,
    NodoublePipe,
    InfolderPipe,
    InpipePipe,
    NewinpipePipe
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
