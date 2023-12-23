import { Component } from '@angular/core';
import { CarService } from '../car-endpoint/car.service';

@Component({
  selector: 'app-reviews-report',
  templateUrl: './reviews-report.component.html',
  styleUrls: ['./reviews-report.component.css']
})
export class ReviewsReportComponent {
  pageTitle: string = "Authors Report Endpoint"


  currentPageNumber: number = 1;
  reportPage$ = this.carService.getReviewsReportPage(this.currentPageNumber);


  constructor(private carService: CarService) {}


  changePage(page: number): void {
    this.currentPageNumber = page;
    this.reportPage$ = this.carService.getReviewsReportPage(page);
  }
}
