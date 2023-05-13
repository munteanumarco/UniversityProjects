import { Component, OnInit } from '@angular/core';
import { StudentService } from '../student.service';
import { StudentProfile } from '../models/studentProfile';
import { Observable } from 'rxjs';

@Component({
  selector: 'app-profile-s',
  templateUrl: './profile-s.component.html',
  styleUrls: ['./profile-s.component.css']
})
export class ProfileSComponent implements OnInit {

  profile$!: Observable<StudentProfile>;
  id!: number;

  constructor (private readonly studentService: StudentService) {}

  ngOnInit(): void {
    this.id = parseInt(localStorage.getItem('user_id') ?? '2');
    this.profile$ = this.studentService.getStudentProfile(this.id);
  }
}
