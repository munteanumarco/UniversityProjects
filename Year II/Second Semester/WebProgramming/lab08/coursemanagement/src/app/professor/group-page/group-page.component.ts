import { Component, OnInit } from '@angular/core';
import { ProfessorService } from '../professor.service';
import { ActivatedRoute } from '@angular/router';
import { Observable, from, map, of } from 'rxjs';
import { StudentsFromGroup } from '../models/studentsFromGroup';

@Component({
  selector: 'app-group-page',
  templateUrl: './group-page.component.html',
  styleUrls: ['./group-page.component.css']
})
export class GroupPageComponent implements OnInit {

  courseId!: number;
  group!: number;
  students$!: Observable<StudentsFromGroup[]>; 
  pageSize = 4;
  currentPage = 1;
  totalRecords = 0;
  totalPages = 0;
  disablePrev: boolean = false;
  disableNext: boolean = false;

  constructor (private proffesorService: ProfessorService, private route: ActivatedRoute) {}

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.courseId = params['courseId'];
      this.group = params['group'];
    });
    this.proffesorService.getStudentsFromGroup(this.group, this.courseId).subscribe(
      (students) => {
        this.totalRecords = students.length;
        this.totalPages = Math.ceil(this.totalRecords / this.pageSize);
        this.updateStudents();
        this.updatePagination();
      }
    );
  }

  updateStudents() {
    this.students$ = this.proffesorService.getStudentsFromGroup(this.group, this.courseId).pipe(
      map(students => {
        const startIndex = (this.currentPage - 1) * this.pageSize;
        const endIndex = Math.min(startIndex + this.pageSize, this.totalRecords);
        return students.slice(startIndex, endIndex);
      })
    );
  }

  updatePagination() {
    if (this.currentPage == 1) {
      this.disablePrev = true;
      this.disableNext = false;
    } else if (this.currentPage > 1 && this.currentPage < this.totalPages) {
      this.disablePrev = false;
      this.disableNext = false;
    } else if (this.currentPage == this.totalPages) {
      this.disableNext = true;
      this.disablePrev = false;
    }
  }

  prev() {
    if (this.currentPage > 1) {
      console.log("should go prev: ");
      this.currentPage--;
      this.updateStudents();
      this.updatePagination();
    } 
  }

  next() {
    if (this.currentPage < this.totalPages) {
      console.log("should go next: ");
      this.currentPage++;
      this.updateStudents();
      this.updatePagination();
    } 
  }

}
