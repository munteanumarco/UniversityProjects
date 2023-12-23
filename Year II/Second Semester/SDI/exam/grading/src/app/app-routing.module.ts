import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { EcpComponent } from './ecp/ecp.component';
import { EdpComponent } from './edp/edp.component';
import { EgpComponent } from './egp/egp.component';

const routes: Routes = [
  {path: "", component: HomeComponent},
  {path: "examination/create", component: EcpComponent},
  {path: "examination/dashboard/:id", component: EdpComponent},
  {path: "examination/session/:gid/grading/:exid", component: EgpComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
