import { Component, OnInit } from '@angular/core';
import { ProfessorService } from '../professor.service';
import { Observable, finalize, tap } from 'rxjs';
import { Course } from '../models/course';
import { Group } from '../models/group';
import { Router } from '@angular/router';

@Component({
  selector: 'app-add-group',
  templateUrl: './add-group.component.html',
  styleUrls: ['./add-group.component.css']
})
export class AddGroupComponent implements OnInit {

  $courses!: Observable<Course[]>;
  $groups!: Observable<Group[]>;

  selectedGroup!: number;
  selectedCourse!: number;

  constructor (private professorService: ProfessorService,
               private router: Router) {}

  ngOnInit(): void {
    this.$groups = this.professorService.getAvailableGroups();
    this.$courses = this.professorService.getAvailableCourses();
  }

  add(): void {
    this.professorService.addCourseToGroup(this.selectedCourse, this.selectedGroup).subscribe(
      () => {
        console.log("added !");
        this.router.navigateByUrl("/ppanel");
      }
    );
  }

}
