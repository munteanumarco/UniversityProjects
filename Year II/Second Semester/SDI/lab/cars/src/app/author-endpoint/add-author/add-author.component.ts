import { Component } from '@angular/core';
import { AuthorService } from '../author.service';
import { Router } from '@angular/router';
import { AuthorAdd } from '../models/authorAdd';

@Component({
  selector: 'app-add-author',
  templateUrl: './add-author.component.html',
  styleUrls: ['./add-author.component.css']
})
export class AddAuthorComponent {
  fNameInputValue!: string;
  lNameInputValue!: string;
  emailInputValue!: string;
  phoneInputValue!: string;

  onSubmit(): void {
    if (this.fNameInputValue && this.lNameInputValue && this.emailInputValue && this.phoneInputValue) {
      const addedAuthor: AuthorAdd = {
        firstName: this.fNameInputValue,
        lastName: this.lNameInputValue,
        email: this.emailInputValue,
        phone: this.phoneInputValue
      };
      this.authorService.addAuthor(addedAuthor).subscribe(
        response => {
          console.log(response);
          this.router.navigateByUrl("/authors");
        },
        error => {
          console.log(error);
          window.alert("Error , car was not added!");
        }
      );
    } 
    else {
      window.alert("Please fill in all fields!");
    }
  }

  constructor(private authorService: AuthorService, private router: Router) {}
}
