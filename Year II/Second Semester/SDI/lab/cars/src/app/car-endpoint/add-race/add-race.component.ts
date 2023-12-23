import { Component, OnInit } from '@angular/core';
import { CarService } from '../car.service';
import { BehaviorSubject, EMPTY, Observable, Subject, catchError, race, tap, windowWhen } from 'rxjs';
import { CarWithDetails } from '../models/carWithDetails';
import { ActivatedRoute, Router } from '@angular/router';
import { Car } from '../models/car';
import { RaceService } from 'src/app/race-endpoint/race.service';
import { Race } from 'src/app/race-endpoint/models/race';

@Component({
  selector: 'app-add-race',
  templateUrl: './add-race.component.html',
  styleUrls: ['./add-race.component.css']
})
export class AddRaceComponent implements OnInit {

  carId!: number;
  selectedOption!: string;

  nameInputValue!: string;
  foundCar$!: Observable<CarWithDetails>;
  races!: Race[];

  searchErrorSubject = new Subject<string>();
  searchError$ = this.searchErrorSubject.asObservable();

  searchToggle$ = new BehaviorSubject<boolean>(false);

  result!: string[];

  onSearch() {
    this.result = Array(3).fill(this.nameInputValue);
    this.raceService.getRacesByName(this.nameInputValue).subscribe(
      races => this.races = races
    );
  }

  onAdd(): void {
    if (this.selectedOption) {
      console.log(this.selectedOption);
      this.carService.addRaceToCar(this.carId, parseInt(this.selectedOption)).subscribe(
        () => {
          console.log(`Race with id ${this.selectedOption} was added to the car ${this.carId}`);
          let redir = "/view-car/" + this.carId;
          this.router.navigateByUrl(redir);
        }
      )
    } else {
      window.alert("Please select an option from the dropdown!");
    }
  }

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.carId = params['id'];
    });
  }

  constructor (private raceService: RaceService,
               private carService: CarService,
               private router: Router,
               private route: ActivatedRoute) {}
}
