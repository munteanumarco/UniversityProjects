import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { JwtModule } from '@auth0/angular-jwt';
import { LoginComponent } from './login/login.component';
import { FormsModule } from '@angular/forms';
import { RegisterComponent } from './register/register.component';
import { ConfirmComponent } from './confirm/confirm.component';

export function tokenGetter() {
  return localStorage.getItem('access_token');
}

@NgModule({
  declarations: [
  
    LoginComponent,
       RegisterComponent,
       ConfirmComponent
  ],
  imports: [
    CommonModule,
    FormsModule,
    JwtModule.forRoot({
      config: {
        tokenGetter: tokenGetter,
        allowedDomains: ['carsinfoapi.azurewebsites.net'],
        disallowedRoutes: [],
      }
    }),
  ],
  exports: [JwtModule]
})
export class AuthModule { }
