import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { LoginComponent } from './auth/login/login.component';
import { AuthGuard } from './auth/auth.guard';
import { PanelSComponent } from './student/panel-s/panel-s.component';
import { ProfileSComponent } from './student/profile-s/profile-s.component';
import { PanelPComponent } from './professor/panel-p/panel-p.component';
import { GroupPageComponent } from './professor/group-page/group-page.component';
import { AddGroupComponent } from './professor/add-group/add-group.component';
import { GradeStudentComponent } from './professor/grade-student/grade-student.component';

const routes: Routes = [
  {path: 'login', component: LoginComponent},
  {path: 'spanel', component: PanelSComponent, canActivate: [AuthGuard]},
  {path: 'ppanel', component: PanelPComponent, canActivate: [AuthGuard]},
  {path: 'sprofile', component: ProfileSComponent, canActivate: [AuthGuard]},
  {path: 'group/:courseId/:group', component: GroupPageComponent, canActivate: [AuthGuard]},
  {path: 'grade/:courseId/:studentId', component: GradeStudentComponent, canActivate: [AuthGuard]},
  {path: 'add-group', component: AddGroupComponent, canActivate: [AuthGuard]},
  {path: '', component: HomeComponent, canActivate: [AuthGuard]},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
