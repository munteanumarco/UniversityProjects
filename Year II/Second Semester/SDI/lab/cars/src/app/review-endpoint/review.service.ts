import { Injectable } from "@angular/core";
import { HttpClient, HttpErrorResponse, HttpParams } from "@angular/common/http"
import { Observable, catchError, of, shareReplay, tap, throwError } from "rxjs";
import { Review } from "./models/review";
import { Page } from "../car-endpoint/models/page";
import { ReviewAdd } from "./models/reviewAdd";



@Injectable({
    providedIn: "root"
})
export class ReviewService {
  reviewsUrl = "https://carsinfoapi.azurewebsites.net/api/reviews/";

  constructor(private http: HttpClient) {}

  getReviewPage(pageNumber: number): Observable<Page<Review>> {
    let pageSize = localStorage.getItem('elements') ?? "20";
    let params = new HttpParams()
      .set("pageNumber", pageNumber.toString())
      .set("pageSize", pageSize.toString());
    return this.http.get<Page<Review>>(this.reviewsUrl, { params });  
  }

  addReview(addedReview: ReviewAdd): Observable<any> {
    return this.http.post(this.reviewsUrl, addedReview).pipe(
        tap(data => console.log("add data " + data)),
        catchError(error => {
            console.log("error while adding a review:", error);
             return error
        })
    );
  }
}