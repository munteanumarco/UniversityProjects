import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable, finalize, tap } from 'rxjs';
import { LoginResponse } from './models/loginResponse';

@Injectable({
  providedIn: 'root'
})
export class AuthService {

  private readonly baseUrl: string = "http://localhost";

  constructor(private readonly http: HttpClient) { }

  login(username: string, password: string): Observable<LoginResponse> {
    const loginUrl = `${this.baseUrl}/loginOperation.php`;
    const body = {
      username: username,
      password: password
    };
    return this.http.post<LoginResponse>(loginUrl, body);
  }

  isLoggedIn(): boolean {
    if (localStorage.getItem('username')) {
      return true;
    } 
    return false;
  }

  logout() {
    localStorage.clear();
  }
}
