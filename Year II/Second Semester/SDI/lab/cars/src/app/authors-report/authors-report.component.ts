import { Component } from '@angular/core';
import { CarService } from '../car-endpoint/car.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-authors-report',
  templateUrl: './authors-report.component.html',
  styleUrls: ['./authors-report.component.css']
})
export class AuthorsReportComponent {
  pageTitle: string = "Authors Report Endpoint"


  currentPageNumber: number = 1;
  reportPage$ = this.carService.getAuthorsReportPage(this.currentPageNumber);


  constructor(private carService: CarService, private router: Router) {}

  ngOnInit(): void {

  }

  changePage(page: number): void {
    this.currentPageNumber = page;
    this.reportPage$ = this.carService.getAuthorsReportPage(page);
  }
}
