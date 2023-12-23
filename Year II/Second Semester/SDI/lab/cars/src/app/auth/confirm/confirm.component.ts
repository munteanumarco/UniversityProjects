import { Component, Input } from '@angular/core';
import { Router } from '@angular/router';
import { AuthorService } from 'src/app/author-endpoint/author.service';
import { AuthService } from '../auth.service';

@Component({
  selector: 'app-confirm',
  templateUrl: './confirm.component.html',
  styleUrls: ['./confirm.component.css']
})
export class ConfirmComponent {
  @Input() token!: string;

  constructor (private router: Router, private authService: AuthService) {}

  confirm(): void {
    console.log("Should confirm");
    this.authService.confirm(this.token).subscribe(
      () => this.router.navigateByUrl("/login") 
    );
  }
}
