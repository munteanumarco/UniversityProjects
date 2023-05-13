import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HomeComponent } from './home/home.component';
import { LoginComponent } from './auth/login/login.component';
import { PanelSComponent } from './student/panel-s/panel-s.component';
import { ProfileSComponent } from './student/profile-s/profile-s.component';
import { PanelPComponent } from './professor/panel-p/panel-p.component';
import { GroupPageComponent } from './professor/group-page/group-page.component';
import { AddGroupComponent } from './professor/add-group/add-group.component';
import { GradeStudentComponent } from './professor/grade-student/grade-student.component';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    LoginComponent,
    PanelSComponent,
    ProfileSComponent,
    PanelPComponent,
    GroupPageComponent,
    AddGroupComponent,
    GradeStudentComponent,
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
