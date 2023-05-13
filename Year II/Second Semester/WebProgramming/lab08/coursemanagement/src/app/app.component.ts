import { Component } from '@angular/core';
import { AuthService } from './auth/auth.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'coursemanagement';

  constructor (private authService: AuthService, private router: Router) {}

  isLoggedIn(): boolean {
    return this.authService.isLoggedIn();
  }

  isStudent(): boolean {
    return this.isLoggedIn() && localStorage.getItem('role') == 'student';
  }

  isProfessor(): boolean {
    return this.isLoggedIn() && localStorage.getItem('role') == 'professor';
  }
  
  logout(): void {
    this.authService.logout();
    this.router.navigateByUrl("/login");
  }

}
