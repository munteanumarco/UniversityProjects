import { Component, OnInit } from '@angular/core';
import { Review } from 'src/app/review-endpoint/models/review';
import { AuthorService } from '../author.service';
import { ReviewService } from 'src/app/review-endpoint/review.service';
import { ActivatedRoute, Router } from '@angular/router';
import { ReviewAdd } from 'src/app/review-endpoint/models/reviewAdd';

@Component({
  selector: 'app-add-review-author',
  templateUrl: './add-review-author.component.html',
  styleUrls: ['./add-review-author.component.css']
})
export class AddReviewAuthorComponent implements OnInit {
  authorId!: number;

  titleInputValue!: string;
  descriptionInputValue!: string;
  scoreInputValue!: number;
  dateInputInputValue!: string;

  onSubmit(): void {
    if (this.titleInputValue && this.descriptionInputValue && this.scoreInputValue && this.dateInputInputValue) {
      const addedReview: ReviewAdd = {
        title: this.titleInputValue,
        description: this.descriptionInputValue,
        score: this.scoreInputValue,
        date: this.dateInputInputValue,
        carId: 100,
        authorId: 100,
      };
      this.reviewService.addReview(addedReview).subscribe(
        response => {
          console.log(response);
          this.router.navigateByUrl("/view-auhtor" + this.authorId);
        },
        error => {
          console.log(error);
          window.alert("Error , review was not added!");
        }
      );
    } 
    else {
      window.alert("Please fill in all fields!");
    }
  }

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.authorId = params['id'];
    });
  }

  constructor (private authorService: AuthorService,
               private reviewService: ReviewService,
               private router: Router,
               private route: ActivatedRoute) {}
}
