import { HttpClient, HttpParams } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { ProfessorGroups } from './models/professorGroups';
import { Observable, catchError } from 'rxjs';
import { StudentsFromGroup } from './models/studentsFromGroup';
import { Course } from './models/course';
import { Group } from './models/group';

@Injectable({
  providedIn: 'root'
})
export class ProfessorService {

  private readonly baseUrl: string = "http://localhost";

  constructor(private readonly http: HttpClient) { }

  getProfessorGroups(id: number): Observable<ProfessorGroups[]> {
    const requestUrl = `${this.baseUrl}/getProfessorGroups.php`;
    let params = new HttpParams()
    .set('user_id', id.toString());
    return this.http.get<ProfessorGroups[]>(requestUrl, { params });
  }

  removeGroup(group: number, courseId: number, user_id: number) {
    const requestUrl = `${this.baseUrl}/removeProfGroup.php`;
    let params = new HttpParams()
    .set('user_id', user_id.toString())
    .set('group', group.toString())
    .set('course_id', courseId.toString());

    return this.http.get(requestUrl, { params });
  }

  getStudentsFromGroup(group: number, courseId: number): Observable<StudentsFromGroup[]> {
    const requestUrl = `${this.baseUrl}/getStudentsFromGroup.php`;
    let params = new HttpParams()
    .set('group', group.toString())
    .set('courseId', courseId.toString());
    return this.http.get<StudentsFromGroup[]>(requestUrl, { params });
  }

  getAvailableCourses(): Observable<Course[]> {
    const requestUrl = `${this.baseUrl}/getCourses.php`;
    return this.http.get<Course[]>(requestUrl);
  }

  getAvailableGroups(): Observable<Group[]> {
    const requestUrl = `${this.baseUrl}/getGroups.php`;
    return this.http.get<Group[]>(requestUrl);
  }

  addCourseToGroup(courseId: number, group: number) {
    let professorId = parseInt(localStorage.getItem('user_id') ?? '1');
    const requestUrl = `${this.baseUrl}/addProfGroupReq.php`;
    let params = new HttpParams()
    .set('group', group.toString())
    .set('course', courseId.toString())
    .set('user_id', professorId.toString())
    return this.http.get(requestUrl, { params });
  }

  gradeStudent(studentId: number, courseId: number, grade: number, alreadyGraded: string) {
    const requestUrl = `${this.baseUrl}/gradeStudentRequest.php`;
    let params = new HttpParams()
    .set('studentId', studentId.toString())
    .set('courseId', courseId.toString())
    .set('grade', grade.toString())
    .set('alreadyGraded', alreadyGraded);
    return this.http.get(requestUrl, { params });
  }

  removeGrade(studentId: number, courseId: number) {
    const requestUrl = `${this.baseUrl}/removeGrade.php`;
    let params = new HttpParams()
    .set('studentId', studentId.toString())
    .set('courseId', courseId.toString())
    return this.http.get(requestUrl, { params });
  }

}
