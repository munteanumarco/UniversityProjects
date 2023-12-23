import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { TestapiComponent } from './testapi/testapi.component';
import { WelcomeComponent } from './welcome/welcome.component';
import { CarEndpointComponent } from './car-endpoint/car-endpoint.component';
import { UpdateCarComponent } from './car-endpoint/update-car/update-car.component';
import { AddCarComponent } from './car-endpoint/add-car/add-car.component';
import { LoaderComponent } from './loader/loader.component';
import { AuthorEndpointComponent } from './author-endpoint/author-endpoint.component';
import { ReviewEndpointComponent } from './review-endpoint/review-endpoint.component';
import { AddAuthorComponent } from './author-endpoint/add-author/add-author.component';
import { UpdateAuthorComponent } from './author-endpoint/update-author/update-author.component';
import { AddReviewComponent } from './review-endpoint/add-review/add-review.component';
import { RaceEndpointComponent } from './race-endpoint/race-endpoint.component';
import { ViewCarComponent } from './car-endpoint/view-car/view-car.component';
import { AddRaceComponent } from './car-endpoint/add-race/add-race.component';
import { AuthorsReportComponent } from './authors-report/authors-report.component';
import { ReviewsReportComponent } from './reviews-report/reviews-report.component';
import { ViewAuthorComponent } from './author-endpoint/view-author/view-author.component';
import { AddReviewAuthorComponent } from './author-endpoint/add-review-author/add-review-author.component';
import { LoginComponent } from './auth/login/login.component';
import { AuthGuard } from './auth/auth.guard';
import { UserProfileComponent } from './user-profile/user-profile.component';
import { RegisterComponent } from './auth/register/register.component';
import { ConfirmComponent } from './auth/confirm/confirm.component';

const routes: Routes = [
  {path: 'testapi', component: TestapiComponent, canActivate: [AuthGuard]},
  {path: 'update-car/:id', component: UpdateCarComponent, canActivate: [AuthGuard]},
  {path: 'add-race-to-car/:id', component: AddRaceComponent, canActivate: [AuthGuard]},
  {path: 'add-review/:id', component: AddReviewAuthorComponent, canActivate: [AuthGuard]},
  {path: 'view-car/:id', component: ViewCarComponent, canActivate: [AuthGuard]},
  {path: 'view-author/:id', component: ViewAuthorComponent, canActivate: [AuthGuard]},
  {path: 'update-author/:id', component: UpdateAuthorComponent, canActivate: [AuthGuard]},
  {path: 'cars', component: CarEndpointComponent, canActivate: [AuthGuard]},
  {path: 'authors', component: AuthorEndpointComponent, canActivate: [AuthGuard]},
  {path: 'authors-report', component: AuthorsReportComponent, canActivate: [AuthGuard]},
  {path: 'reviews-report', component: ReviewsReportComponent, canActivate: [AuthGuard]},
  {path: 'reviews', component: ReviewEndpointComponent, canActivate: [AuthGuard]},
  {path: 'races', component: RaceEndpointComponent, canActivate: [AuthGuard]},
  {path: 'add-car', component: AddCarComponent, canActivate: [AuthGuard]},
  {path: 'add-author', component: AddAuthorComponent, canActivate: [AuthGuard]},
  {path: 'add-review', component: AddReviewComponent, canActivate: [AuthGuard]},
  {path: 'loader', component: LoaderComponent, canActivate: [AuthGuard]},
  {path: 'login', component: LoginComponent},
  {path: 'register', component: RegisterComponent},
  {path: 'confirm', component: ConfirmComponent},
  {path: 'profile/:id', component: UserProfileComponent, canActivate: [AuthGuard]},
  {path: '', component: WelcomeComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
