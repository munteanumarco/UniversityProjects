import { Component, Input } from '@angular/core';
import { CarAuthorReport } from 'src/app/car-endpoint/models/carAuthorReport';

@Component({
  selector: 'app-report-card',
  templateUrl: './report-card.component.html',
  styleUrls: ['./report-card.component.css']
})
export class ReportCardComponent {
  @Input() car!: CarAuthorReport;
}
