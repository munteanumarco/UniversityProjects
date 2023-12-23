import { Component, OnInit } from '@angular/core';
import { AuthorService } from '../author.service';
import { ActivatedRoute, Router } from '@angular/router';
import { AuthorUpdate } from '../models/authorUpdate';
import { Author } from '../models/author';

@Component({
  selector: 'app-update-author',
  templateUrl: './update-author.component.html',
  styleUrls: ['./update-author.component.css']
})
export class UpdateAuthorComponent implements OnInit {

  authorId!: number;
  author!: Author;
  fNameInputValue!: string;
  lNameInputValue!: string;
  emailInputValue!: string;
  phoneInputValue!: string;

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.authorId = params['id'];
      this.getAuthorDetails();
    });
  }

  getAuthorDetails() {
    this.authorService.getAuthor(this.authorId).subscribe(
      author => {
        this.author = author
        if (this.author) {
          this.fNameInputValue = this.author.firstName;
          this.lNameInputValue = this.author.lastName;
          this.emailInputValue = this.author.email;
          this.phoneInputValue = this.author.phone;
        }
      },
      error => {
        console.log(error);
        window.alert(`Car with id ${this.authorId} not found!`);
        this.router.navigateByUrl("/authors");
      }
    ); 
  }

  onSubmit(): void {
    if (this.fNameInputValue && this.lNameInputValue && this.emailInputValue && this.phoneInputValue) {
      const updatedAuthor: AuthorUpdate = {
        firstName: this.fNameInputValue,
        lastName: this.lNameInputValue,
        email: this.emailInputValue,
        phone: this.phoneInputValue
      };
      this.authorService.updateAuthor(this.authorId, updatedAuthor).subscribe(
        response => {
          console.log(response);
          this.router.navigateByUrl("/authors");
        },
        error => {
          console.log(error);
          window.alert("Error , car was not updated!");
        }
      );
    } 
    else {
      window.alert("Please fill in all fields!");
    }
  }

  constructor (private authorService: AuthorService, 
               private router: Router,
               private route: ActivatedRoute) {}
}
