import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Course } from './models/Course';
import { Observable, filter } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class CourseService {

  private readonly baseUrl: string = "http://localhost";

  constructor (private readonly http: HttpClient) { }


  getCourse(id: number): Observable<Course[]> {
    const requestUrl = `${this.baseUrl}/getCourses.php`;
    return this.http.get<Course[]>(this.baseUrl);
  }
}
