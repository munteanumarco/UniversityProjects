import { Injectable } from '@angular/core';
import { Observable, catchError, race, tap, throwError } from 'rxjs';
import { Race } from './models/race';
import { RaceUpdate } from './models/raceUpdate';
import { RaceAdd } from './models/raceAdd';
import { Page } from '../car-endpoint/models/page';
import { HttpClient, HttpErrorResponse, HttpParams } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class RaceService {

  racesUrl = "https://carsinfoapi.azurewebsites.net/api/races/";

    // reports$: Observable<CarReport[]> = this.http.get<CarReport[]>(this.reportsUrl).pipe(
    //     shareReplay(1)
    // );

    deleteRace(raceId: number): Observable<any> {
        return this.http.delete(this.racesUrl + raceId).pipe(
            catchError(error => {
                console.log("error deleteing a race:", error);
                 return error
            })
        );
    }

    getRace(raceId: number): Observable<Race> {
        const getUrl = `${this.racesUrl}${raceId}`;
        return this.http.get<Race>(getUrl).pipe(
            tap(data => console.log("Targeted race:", JSON.stringify(data))),
            catchError(this.handleError)
        );
    }

    updateRace(raceId: number, updatedRace: RaceUpdate): Observable<any> {
        const updateUrl = `${this.racesUrl}${race}`;
        return this.http.put(updateUrl, raceId).pipe(
            catchError(error => {
                console.log("error while updating a race:", error);
                 return error
            })
        );
    }

    addCar(addedRace: RaceAdd): Observable<any> {
        return this.http.post(this.racesUrl, addedRace).pipe(
            tap(data => console.log("add data " + data)),
            catchError(error => {
                console.log("error while adding a race:", error);
                 return error
            })
        );
    }

    getRacePage(pageNumber: number): Observable<Page<Race>> {
      let pageSize = localStorage.getItem('elements') ?? "20";
        let params = new HttpParams()
        .set('pageNumber', pageNumber.toString())
        .set('pageSize', pageSize.toString());
        return this.http.get<Page<Race>>(this.racesUrl, { params });
    }

    getRacesByName(match: string): Observable<Race[]> {
      let params = new HttpParams()
        .set('match', match);
      return this.http.get<Race[]>(this.racesUrl + "name", { params });
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

    constructor(private http: HttpClient) {}
}
