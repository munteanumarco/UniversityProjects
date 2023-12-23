import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http'

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HomeComponent } from './home/home.component';
import { EcpComponent } from './ecp/ecp.component';
import { EdpComponent } from './edp/edp.component';
import { EgpComponent } from './egp/egp.component';
import { TestCompComponent } from './test-comp/test-comp.component';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    EcpComponent,
    EdpComponent,
    EgpComponent,
    TestCompComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    HttpClientModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
