import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Examination } from 'src/models/examination';
import { ExaminationAdd } from 'src/models/examinationAdd';
import { ExaminationWithId } from 'src/models/examinationWithId';
import { Examiner } from 'src/models/examiner';

@Injectable({
  providedIn: 'root'
})
export class ExamService {

  baseUrl = "https://localhost:7023";

  constructor(private http: HttpClient) { }

  addExamination(title: string, first: string, second: string, third: string) {
    const reqBody = {
      title: title,
      firstExaminer: first,
      secondExaminer: second,
      thirdExaminer: third
    };
    const requestUrl = `${this.baseUrl}/examination`;
    return this.http.post<Examination>(requestUrl, reqBody);
  }

  addExaminer(name: string) {
    const reqBody = {
      name: name
    };
    const requestUrl = `${this.baseUrl}/examiner`;
    return this.http.post<Examiner>(requestUrl, reqBody);
    
  }

  getExamination(id: string) {
    const reqUrl = `${this.baseUrl}/examination/${id}`;
    return this.http.get<Examination>(reqUrl);
  }

  getExaminationWithIds(id: string) {
    const reqUrl = `${this.baseUrl}/examination/${id}/include-ids`;
    return this.http.get<ExaminationWithId>(reqUrl);
  }

  getExaminer(id: string) {
    const requestUrl = `${this.baseUrl}/examiner/${id}`;
    return this.http.get<Examiner>(requestUrl);
  }

  getExaminations() {
    const requestUrl = `${this.baseUrl}/examination`;
    return this.http.get<Examination[]>(requestUrl);
  }

  testLiveness() {
    return this.http.get(this.baseUrl);
  }

}
