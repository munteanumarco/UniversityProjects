import { Component, OnInit } from '@angular/core';
import { ExamService } from '../exam.service';
import { ActivatedRoute, Router } from '@angular/router';
import { Observable } from 'rxjs';
import { Examination } from 'src/models/examination';
import { ExaminationWithId } from 'src/models/examinationWithId';

@Component({
  selector: 'app-edp',
  templateUrl: './edp.component.html',
  styleUrls: ['./edp.component.css']
})
export class EdpComponent implements OnInit {

  id!: string;
  examination$!: Observable<ExaminationWithId>;
  constructor(private examService: ExamService, private router: Router, private route: ActivatedRoute) {}
  link1!: string;
  link2!: string;
  link3!: string;
  ngOnInit(): void {
    this.id = this.route.snapshot.paramMap.get('id') ?? "";
    this.examination$ = this.examService.getExaminationWithIds(this.id);
  }

}
