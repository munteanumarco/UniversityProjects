import { Component } from '@angular/core';
import { ReviewService } from '../review.service';
import { Router } from '@angular/router';
import { ReviewAdd } from '../models/reviewAdd';

@Component({
  selector: 'app-add-review',
  templateUrl: './add-review.component.html',
  styleUrls: ['./add-review.component.css']
})
export class AddReviewComponent {
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
          this.router.navigateByUrl("/reviews");
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

  constructor(private reviewService: ReviewService, private router: Router) {}
}
