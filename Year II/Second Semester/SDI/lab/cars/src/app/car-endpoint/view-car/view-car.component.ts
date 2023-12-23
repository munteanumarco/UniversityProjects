import { Component, OnInit } from '@angular/core';
import { Car } from '../models/car';
import { CarService } from '../car.service';
import { ActivatedRoute, Router } from '@angular/router';
import { CarWithDetails } from '../models/carWithDetails';
import { Observable, catchError, concatMap, of, race, switchMap } from 'rxjs';
import { Race } from 'src/app/race-endpoint/models/race';

@Component({
  selector: 'app-view-car',
  templateUrl: './view-car.component.html',
  styleUrls: ['./view-car.component.css']
})
export class ViewCarComponent implements OnInit {
  carId!: number;
  car$!: Observable<CarWithDetails>;

  constructor (private carService: CarService, private router: Router, private route: ActivatedRoute) {}

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.carId = params['id'];
      this.getCarDetails();
    });
  }

  getCarDetails() {
    this.car$ = this.carService.getCar(this.carId);
  }

  onDeleteRaceFromCar(raceId: number) {
    this.car$ = this.car$.pipe(
      concatMap((car: CarWithDetails) => {
        return this.carService.deleteRaceFromCar(this.carId, raceId).pipe(
          switchMap(() => {
            console.log(`Race with id ${raceId} deleted from car with id ${this.carId}`);
            car.races = car.races.filter(race => race.id != raceId);
            return of(car);
          }),
          catchError((error) => {
            console.log(error);
            window.alert(`Delete failed!`);
            return of(car);
          })
        );
      })
    );
  }

  onAddRace(): void {
    this.router.navigateByUrl("/add-race-to-car/" + this.carId);
  }

}
