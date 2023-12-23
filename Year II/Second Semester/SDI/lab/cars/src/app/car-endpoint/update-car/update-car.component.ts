import { Component, OnInit } from '@angular/core';
import { CarService } from '../car.service';
import { ActivatedRoute, Router } from '@angular/router';
import { Observable } from 'rxjs';
import { CarWithDetails } from '../models/carWithDetails';
import { CarUpdate } from '../models/carUpdate';

@Component({
  selector: 'app-update-car',
  templateUrl: './update-car.component.html',
  styleUrls: ['./update-car.component.css']
})
export class UpdateCarComponent implements OnInit {

  carId!: number;
  car!: CarWithDetails;
  modelInputValue!: string;
  manufacturerInputValue!: string;
  colorInputValue!: string;
  fabYearInputValue!: number;

  constructor(private carService: CarService, 
              private route: ActivatedRoute,
              private router: Router) {}

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.carId = params['id'];
      this.getCarDetails();
    });
  }

  getCarDetails() {
    this.carService.getCar(this.carId).subscribe(
      car => {
        this.car = car
        if (this.car) {
          this.modelInputValue = this.car.model;
          this.manufacturerInputValue = this.car.manufacturer;
          this.colorInputValue = this.car.color;
          this.fabYearInputValue = this.car.fabricationYear;
        }
      },
      error => {
        console.log(error);
        window.alert(`Car with id ${this.carId} not found!`);
        this.router.navigateByUrl("/cars");
      }
    ); 
  }

  onSubmit(): void {
    const updatedCar: CarUpdate = {
      model: this.modelInputValue,
      manufacturer: this.manufacturerInputValue,
      color: this.colorInputValue,
      fabricationYear: this.fabYearInputValue
    };

    this.carService.updateCar(this.carId, updatedCar).subscribe(
      () => {
        console.log("Car Updated successfully");
        this.router.navigateByUrl("/cars");
      },
      error => {
        window.alert("Update failed");
        console.log("Error while updateing car: ", error)
      }
    );
  }
}
