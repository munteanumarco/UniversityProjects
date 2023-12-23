import { Component, EventEmitter, Input, Output } from '@angular/core';
import { Author } from '../models/author';

@Component({
  selector: 'app-author-card',
  templateUrl: './author-card.component.html',
  styleUrls: ['./author-card.component.css']
})
export class AuthorCardComponent {
  @Input() author!: Author;
  @Output() deleteAuthor = new EventEmitter<number>();
  showDeleteConfirm: boolean = false;

  toggleDelete(): void {
    this.showDeleteConfirm = !this.showDeleteConfirm;
  }

  onDelete(): void {
    console.log("should emmit delete!");
    this.deleteAuthor.emit(this.author.id);
  }
}
