import { Component, OnInit } from '@angular/core';
import { Observable, tap } from 'rxjs';
import { StudentGrades } from '../models/studentGrades';
import { StudentService } from '../student.service';

@Component({
  selector: 'app-panel-s',
  templateUrl: './panel-s.component.html',
  styleUrls: ['./panel-s.component.css']
})
export class PanelSComponent implements OnInit {

  grades$!: Observable<StudentGrades[]>;
  id!: number;

  constructor (private readonly studentService: StudentService) {}
  ngOnInit(): void {
    this.id = parseInt(localStorage.getItem('user_id') ?? '2');
    this.grades$ = this.studentService.getStudentGrades(this.id).pipe(
      tap(data => console.log(JSON.stringify(data)))
    );
  }
  
}
