import { Component } from '@angular/core';
import { AuthorService } from './author.service';
import { Router } from '@angular/router';
import { BehaviorSubject, EMPTY, Observable, Subject, catchError, concatMap, of, switchMap, tap } from 'rxjs';
import { Author } from './models/author';
import { Page } from '../car-endpoint/models/page';

@Component({
  selector: 'app-author-endpoint',
  templateUrl: './author-endpoint.component.html',
  styleUrls: ['./author-endpoint.component.css']
})
export class AuthorEndpointComponent {
  pageTitle: string = "Author Endpoint"

  currentPageNumber: number = 1;
  authorPage$: Observable<Page<Author>> = this.authorService.getAuthorPage(this.currentPageNumber).pipe(
    tap(data => console.log(data.content))
  );

  idInputValue!: number;
  foundAuthor$!: Observable<Author>;

  searchErrorSubject = new Subject<string>();
  searchError$ = this.searchErrorSubject.asObservable();

  searchToggle$ = new BehaviorSubject<boolean>(false);

  constructor(private authorService: AuthorService, private router: Router) {}

  onDeleteAuthor(authorId: number): void {
    console.log("OnDelete!");
    this.authorPage$ = this.authorPage$.pipe(
      concatMap((page: Page<Author>) => {
        return this.authorService.deleteAuthor(authorId).pipe(
          switchMap(() => {
            console.log(`Car with ID ${authorId} has been deleted`);
            page.content = page.content.filter((author: Author) => author.id !== authorId);
            return of(page);
          }),
          catchError((error) => {
            console.log(error);
            window.alert(`Delete failed!`);
            return of(page);
          })
        );
      })
    );
  }

  onSearch() {
    this.foundAuthor$ = this.authorService.getAuthor(this.idInputValue).pipe(
      tap(() => {
        this.searchErrorSubject.next("");
      }),
      catchError(err => {
        this.searchErrorSubject.next(err);
        return EMPTY;
      },
    ));
  }

  onAdd(): void {
    this.router.navigateByUrl("/add-author");
  }

  ngOnInit(): void {
    console.log(this.currentPageNumber);
  }

  changePage(page: number): void {
    this.currentPageNumber = page;
    this.authorPage$ = this.authorService.getAuthorPage(page);
  }
}
