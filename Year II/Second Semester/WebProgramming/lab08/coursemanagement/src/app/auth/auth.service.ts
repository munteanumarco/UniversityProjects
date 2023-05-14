import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable, finalize, tap } from 'rxjs';
import { LoginResponse } from './models/loginResponse';
import { JwtHelperService } from '@auth0/angular-jwt';

@Injectable({
  providedIn: 'root'
})
export class AuthService {

  private readonly baseUrl: string = "http://localhost";
  private readonly jwtHelper = new JwtHelperService();

  constructor(private readonly http: HttpClient) { }

  login(username: string, password: string): Observable<LoginResponse> {
    const loginUrl = `${this.baseUrl}/loginOperation.php`;
    const body = {
      username: username,
      password: password
    };
    return this.http.post<LoginResponse>(loginUrl, body).pipe(
      tap((result) => {
        localStorage.setItem('access_token', result.token);
        const decodedToken = this.jwtHelper.decodeToken(result.token);
        const user_id = decodedToken['user_id'];
        const role = decodedToken['role'];
        const username = decodedToken['username'];
        localStorage.setItem('username', username);
        localStorage.setItem('user_id', user_id);
        localStorage.setItem('role', role);
        console.log(result.token);
      })
    );
  }

  isLoggedIn(): boolean {
    const token = localStorage.getItem('access_token');
    return token ? !this.jwtHelper.isTokenExpired(token) : false;
  }

  logout() {
    localStorage.removeItem('access_token');
  }
}
