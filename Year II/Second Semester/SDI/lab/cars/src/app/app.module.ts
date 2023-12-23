import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { TestapiComponent } from './testapi/testapi.component';
import { WelcomeComponent } from './welcome/welcome.component';
import { CarEndpointComponent } from './car-endpoint/car-endpoint.component';
import { HTTP_INTERCEPTORS, HttpClientModule } from '@angular/common/http';
import { CarCardComponent } from './car-endpoint/car-card/car-card.component';
import { ReportCardComponent } from './authors-report/report-card/report-card.component';
import { UpdateCarComponent } from './car-endpoint/update-car/update-car.component';
import { AddCarComponent } from './car-endpoint/add-car/add-car.component';
import { LoaderComponent } from './loader/loader.component';
import { LoadingInterceptor } from './loader/loading.interceptor';
import { ReviewEndpointComponent } from './review-endpoint/review-endpoint.component';
import { AuthorEndpointComponent } from './author-endpoint/author-endpoint.component';
import { AuthorCardComponent } from './author-endpoint/author-card/author-card.component';
import { ReviewCardComponent } from './review-endpoint/review-card/review-card.component';
import { AddAuthorComponent } from './author-endpoint/add-author/add-author.component';
import { UpdateAuthorComponent } from './author-endpoint/update-author/update-author.component';
import { AddReviewComponent } from './review-endpoint/add-review/add-review.component';
import { RaceEndpointComponent } from './race-endpoint/race-endpoint.component';
import { RaceCardComponent } from './race-endpoint/race-card/race-card.component';
import { ViewCarComponent } from './car-endpoint/view-car/view-car.component';
import { AddRaceComponent } from './car-endpoint/add-race/add-race.component';
import { RaceCardMnComponent } from './race-endpoint/race-card-mn/race-card-mn.component';
import { PaginationComponent } from './pagination/components/pagination/pagination.component';
import { AuthorsReportComponent } from './authors-report/authors-report.component';
import { ReviewsReportComponent } from './reviews-report/reviews-report.component';
import { ReviewReportCardComponent } from './reviews-report/review-report-card/review-report-card.component';
import { ViewAuthorComponent } from './author-endpoint/view-author/view-author.component';
import { ReviewNCardComponent } from './author-endpoint/review-n-card/review-n-card.component';
import { AddReviewAuthorComponent } from './author-endpoint/add-review-author/add-review-author.component';
import { JwtModule } from '@auth0/angular-jwt';
import { AuthModule } from './auth/auth.module';
import { UserProfileComponent } from './user-profile/user-profile.component';

@NgModule({
  declarations: [
    AppComponent,
    TestapiComponent,
    WelcomeComponent,
    CarEndpointComponent,
    CarCardComponent,
    ReportCardComponent,
    UpdateCarComponent,
    AddCarComponent,
    LoaderComponent,
    ReviewEndpointComponent,
    AuthorEndpointComponent,
    AuthorCardComponent,
    ReviewCardComponent,
    AddAuthorComponent,
    UpdateAuthorComponent,
    AddReviewComponent,
    RaceEndpointComponent,
    RaceCardComponent,
    ViewCarComponent,
    AddRaceComponent,
    RaceCardMnComponent,
    PaginationComponent,
    AuthorsReportComponent,
    ReportCardComponent,
    ReviewsReportComponent,
    ReviewReportCardComponent,
    ViewAuthorComponent,
    ReviewNCardComponent,
    AddReviewAuthorComponent,
    UserProfileComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    FormsModule,
    AuthModule
  ],
  providers: [
    {
      provide: HTTP_INTERCEPTORS,
      useClass: LoadingInterceptor,
      multi: true,
    },
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
