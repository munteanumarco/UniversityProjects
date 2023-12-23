import { Component, Input } from '@angular/core';
import { CarReviewReport } from 'src/app/car-endpoint/models/carReviewReport';

@Component({
  selector: 'app-review-report-card',
  templateUrl: './review-report-card.component.html',
  styleUrls: ['./review-report-card.component.css']
})
export class ReviewReportCardComponent {
  @Input() car!: CarReviewReport;
}
