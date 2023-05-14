import { Component } from '@angular/core';
import { AuthService } from '../auth.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent {

  usernameInput!: string;
  passwordInput!: string;

  constructor (private readonly authService: AuthService, private readonly router: Router) {}


  login(): void {
    this.authService.login(this.usernameInput, this.passwordInput).subscribe(
      () => {
        this.router.navigateByUrl('');
      }
    )
  }
}
