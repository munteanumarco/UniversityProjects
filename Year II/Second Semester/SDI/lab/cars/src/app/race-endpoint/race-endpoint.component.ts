import { Component } from '@angular/core';
import { Race } from './models/race';
import { BehaviorSubject, EMPTY, Observable, Subject, catchError, concatMap, of, race, switchMap, tap } from 'rxjs';
import { RaceService } from './race.service';
import { Router } from '@angular/router';
import { Page } from '../car-endpoint/models/page';

@Component({
  selector: 'app-race-endpoint',
  templateUrl: './race-endpoint.component.html',
  styleUrls: ['./race-endpoint.component.css']
})
export class RaceEndpointComponent {
  pageTitle: string = "Car Endpoint"
  showSortedCars: boolean = false;

  //reports$: Observable<CarReport[]> = this.carService.reports$;

  currentPageNumber: number = 1;
  racePage$ = this.raceService.getRacePage(this.currentPageNumber);

  idInputValue!: number;
  foundRace$!: Observable<Race>;

  searchErrorSubject = new Subject<string>();
  searchError$ = this.searchErrorSubject.asObservable();

  searchToggle$ = new BehaviorSubject<boolean>(false);


  constructor(private raceService: RaceService, private router: Router) {}

  onDeleteRace(raceId: number): void {
    this.racePage$ = this.racePage$.pipe(
      concatMap((page: Page<Race>) => {
        return this.raceService.deleteRace(raceId).pipe(
          switchMap(() => {
            console.log(`Race with ID ${raceId} has been deleted`);
            page.content = page.content.filter((race: Race) => race.id !== raceId);
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
    this.foundRace$ = this.raceService.getRace(this.idInputValue).pipe(
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
    this.router.navigateByUrl("/add-race");
  }

  ngOnInit(): void {
  }

  changePage(page: number): void {
    this.currentPageNumber = page;
    this.racePage$ = this.raceService.getRacePage(page);
  }
}
