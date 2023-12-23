import { Component, EventEmitter, Input, Output } from '@angular/core';
import { Review } from 'src/app/review-endpoint/models/review';

@Component({
  selector: 'app-review-n-card',
  templateUrl: './review-n-card.component.html',
  styleUrls: ['./review-n-card.component.css']
})
export class ReviewNCardComponent {
  @Input() review!: Review;
  @Output() deleteReview = new EventEmitter<number>();
  showDeleteConfirm: boolean = false;

  toggleDelete(): void {
    this.showDeleteConfirm = !this.showDeleteConfirm;
  }

  onDelete(): void {
    this.deleteReview.emit(this.review.id);
  }
}
