import { Component } from '@angular/core';
import { LoadingService } from './loader/loading.service';
import { AuthService } from './auth/auth.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'CarsInfoAPI';
  constructor(public loadingService: LoadingService, 
              private readonly authService: AuthService,
              private readonly router: Router) {}

  logout(): void {
    this.authService.logout();
    this.router.navigateByUrl("/login");
  }

  isLoggedIn(): boolean {
    return this.authService.isAuthenticated();
  }

  myProfile() {
    const id = localStorage.getItem('id');
    this.router.navigateByUrl("/profile/" + id);
  }
}
