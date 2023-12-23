import { Component } from '@angular/core';
import { AuthService } from '../auth.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent {
  username!: string;
  password!: string;
  confirmPassword!: string; 
  isFormValid: boolean = false;
  passwordMatch: boolean = true;
  lengthMatch: boolean = true;
  token!: string;

  constructor(private readonly authService: AuthService, private readonly router: Router) {}


  login(): void {
    this.router.navigateByUrl("/login");
  }

  checkFormValidity(): void {
    if (this.password === this.confirmPassword) {
      this.passwordMatch = true;
    } else {
      this.passwordMatch = false;
    }

    if (this.password.length < 6) {
      this.lengthMatch = false;
    } else {
      this.lengthMatch = true;
    }

    if (this.lengthMatch == true && this.passwordMatch == true) {
      this.isFormValid = true;
    }
  }

  register(): void {
    this.authService.register(this.username, this.password).subscribe(
      (response) => {
        this.token = response.token;
      } 
    );
  }

}
