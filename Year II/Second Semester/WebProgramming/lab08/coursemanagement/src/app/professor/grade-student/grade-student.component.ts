import { Component, OnInit } from '@angular/core';
import { ProfessorService } from '../professor.service';
import { ActivatedRoute, Router } from '@angular/router';
import { EMPTY, Observable, map } from 'rxjs';
import { StudentProfile } from 'src/app/student/models/studentProfile';
import { StudentService } from 'src/app/student/student.service';
import { StudentGrades } from 'src/app/student/models/studentGrades';

@Component({
  selector: 'app-grade-student',
  templateUrl: './grade-student.component.html',
  styleUrls: ['./grade-student.component.css']
})
export class GradeStudentComponent implements OnInit {

  courseId!: number;
  studentId!: number; 
  student$!: Observable<StudentProfile>;
  grade$!: Observable<StudentGrades>;
  storedGrade!: number | null;
  givenGrade!: number;
  alreadyGraded!: string;

  constructor (private professorService: ProfessorService, 
               private studentService: StudentService,
               private router: Router,
               private route: ActivatedRoute) {}

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.courseId = params['courseId'];
      this.studentId = params['studentId'];
      this.getStudent();
      this.getGrade();
    });
  }

  getStudent() {
    this.student$ = this.studentService.getStudentProfile(this.studentId);
  }

  getGrade() {
    this.grade$ = this.studentService.getStudentGrades(this.studentId).pipe(
      map(
        (grades) => {
          let foundGrade = grades.filter(grade => grade.courseId == this.courseId)[0] ?? EMPTY;
          this.storedGrade = foundGrade.grade;
          return foundGrade;
        }
      )
    )
  }

  gradeStudent() {
    if (this.givenGrade < 1 || this.givenGrade > 10) {
      window.alert("Grade should be between 1 and 10");
      return;
    }

    if (this.storedGrade === undefined) {
      this.alreadyGraded = 'false';
    } else{
      this.alreadyGraded = 'true';
    }
    this.professorService.gradeStudent(this.studentId, this.courseId, this.givenGrade, this.alreadyGraded).subscribe(
      () => {
        this.getGrade();
      }
    );
  }

  removeGrade() {
    let status = window.confirm("Are you sure ?");
    if (status) {
      this.confirmedRemoveGrade();
    }  
  }

  confirmedRemoveGrade() {
    this.professorService.removeGrade(this.studentId, this.courseId).subscribe(
      () => {
        this.getGrade();
      }
    )
  }
}
