import { HttpClient, HttpParams } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { StudentGrades } from './models/studentGrades';
import { StudentProfile } from './models/studentProfile';

@Injectable({
  providedIn: 'root'
})
export class StudentService {

  constructor(private readonly http: HttpClient) { }

  private readonly baseUrl: string = "http://localhost";

  getStudentGrades(id: number): Observable<StudentGrades[]> {
    const requestUrl = `${this.baseUrl}/studentPanelRequest.php`;
    let params = new HttpParams()
    .set('user_id', id.toString());
    return this.http.get<StudentGrades[]>(requestUrl, { params });
  }

  getStudentProfile(id: number): Observable<StudentProfile> {
    const requestUrl = `${this.baseUrl}/profileStudentRequest.php`;
    let params = new HttpParams()
    .set('user_id', id.toString());
    return this.http.get<StudentProfile>(requestUrl, { params });
  }

}
