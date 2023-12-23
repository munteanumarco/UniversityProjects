import { Component, OnInit } from '@angular/core';
import { ExamService } from '../exam.service';
import { Observable } from 'rxjs';
import { Examination } from 'src/models/examination';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit {

  examintaions$!: Observable<Examination[]>;

  constructor(private examService: ExamService) {}

  ngOnInit(): void {
    this.examintaions$ = this.examService.getExaminations();
  }
  

}
