import { Component, OnInit } from '@angular/core';
import { ExamService } from '../exam.service';
import { ActivatedRoute, Route } from '@angular/router';
import { Observable } from 'rxjs';
import { Examination } from 'src/models/examination';
import { Examiner } from 'src/models/examiner';

@Component({
  selector: 'app-egp',
  templateUrl: './egp.component.html',
  styleUrls: ['./egp.component.css']
})
export class EgpComponent implements OnInit {

  gid!: string;
  exid!: string;
  error!: boolean;

  examination$!: Observable<Examination>;
  examiner$!: Observable<Examiner>;
  name!: string;
  constructor (private readonly examService: ExamService, private readonly route: ActivatedRoute) {}

  ngOnInit(): void {
    this.gid = this.route.snapshot.paramMap.get('gid') ?? "";
    this.exid = this.route.snapshot.paramMap.get('exid') ?? "";
    this.error = false;
    // this.examiner$ = this.examService.getExaminer(this.exid);
    this.examService.getExaminer(this.exid).subscribe(
      (examiner: Examiner) => {this.name = examiner.name},
      (err) => {
        this.error = true;
      }
    );
    this.examService.getExamination(this.gid).subscribe(
      () => {},
      (err) => {
        this.error = true;
      }
    )
    this.examService.getExamination {
      
    }
  }

}
