import { Component, EventEmitter, Input, OnInit, Output } from '@angular/core';
import { LoadingService } from 'src/app/loader/loading.service';

@Component({
  selector: 'pagination',
  templateUrl: './pagination.component.html',
  styleUrls: ['./pagination.component.css'],
})
export class PaginationComponent implements OnInit {
  @Input() currentPage: number = 1;
  @Input() totalElements: number = 0;
  @Input() totalPages: number = 1;
  @Input() limit: number = 20;
  @Output() changePage = new EventEmitter<number>();

  pages: number[] = [];
  last_pages: number[] = [];
  ngOnInit(): void {

    let start = Math.floor(this.currentPage / 20) * 20;
    let end;
    if (start < 20) {
      start = 1;
      end = 19;
    } else {
      start -= 1;
      end =  21;
    }
    this.pages = this.range(start, end);
  }

  range(start: number, end: number): number[] {
    let result = [];
    for (let i = 0; i <= end; i++) {
      result[i] = start++;
    }
    return result;
  }
}
