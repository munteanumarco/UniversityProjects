import { Component, EventEmitter, Input, Output } from '@angular/core';
import { Review } from '../models/review';

@Component({
  selector: 'app-review-card',
  templateUrl: './review-card.component.html',
  styleUrls: ['./review-card.component.css']
})
export class ReviewCardComponent {
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
