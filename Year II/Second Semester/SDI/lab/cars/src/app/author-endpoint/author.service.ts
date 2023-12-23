import { HttpClient, HttpErrorResponse, HttpParams } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Author } from './models/author';
import { Page } from '../car-endpoint/models/page';
import { Observable, catchError, tap, throwError } from 'rxjs';
import { AuthorAdd } from './models/authorAdd';
import { AuthorUpdate } from './models/authorUpdate';
import { AuthorWithDetails } from './models/authorWithDetails';

@Injectable({
  providedIn: 'root'
})
export class AuthorService {

  authorUrl = "https://carsinfoapi.azurewebsites.net/api/authors/"

  constructor(private http: HttpClient) { }

  getAuthorPage(pageNumber: number): Observable<any> {
    let pageSize = localStorage.getItem('elements') ?? "20";
    let params = new HttpParams()
    .set('pageNumber', pageNumber.toString())
    .set('pageSize', pageSize.toString());
    return this.http.get<Page<Author>>(this.authorUrl, { params }).pipe(
      catchError(error => {
        console.log(error);
        return error;
      })
    );
  }

  getAuthor(authorId: number): Observable<AuthorWithDetails> {
    
      const getUrl = `${this.authorUrl}${authorId}`;
      return this.http.get<AuthorWithDetails>(getUrl).pipe(
          tap(data => console.log("Targeted author:", JSON.stringify(data))),
          catchError(this.handleError)
      );
  }

  addAuthor(addedAuthor: AuthorAdd): Observable<any> {
    return this.http.post(this.authorUrl, addedAuthor).pipe(
        tap(data => console.log("add data " + data)),
        catchError(error => {
            console.log("error while adding a author:", error);
             return error
        })
    );
  }

  updateAuthor(authorId: number, updatedAuthor: AuthorUpdate): Observable<any> {
    const updateUrl = `${this.authorUrl}${authorId}`;
    return this.http.put(updateUrl, updatedAuthor).pipe(
        catchError(error => {
            console.log("error while updating a author:", error);
             return error
        })
    );
  }

  deleteAuthor(authorId: number): Observable<any> {
    return this.http.delete(this.authorUrl + authorId).pipe(
        catchError(error => {
            console.log("error deleteing an author:", error);
             return error
        })
    );
  }

  private handleError(err: HttpErrorResponse): Observable<never> {
    let errorMessage: string;
    if (err.error instanceof ErrorEvent) {
      // A client-side or network error occurred. Handle it accordingly.
      errorMessage = `An error occurred: ${err.error.message}`;
    } else {
      // The backend returned an unsuccessful response code.
      // The response body may contain clues as to what went wrong,
      errorMessage = `Backend returned code ${err.status}: ${err.message}`;
    }
    console.error(err);
    return throwError(() => errorMessage);
  }

}
