import { Component } from '@angular/core';
import { CarService } from '../car.service';
import { CarAdd } from '../models/carAdd';
import { Router } from '@angular/router';

@Component({
  selector: 'app-add-car',
  templateUrl: './add-car.component.html',
  styleUrls: ['./add-car.component.css']
})
export class AddCarComponent {
  modelInputValue!: string;
  manufacturerInputValue!: string;
  colorInputValue!: string;
  fabYearInputValue!: number;

  onSubmit(): void {
    if (this.modelInputValue && this.manufacturerInputValue && this.colorInputValue && this.fabYearInputValue) {
      const addedCar: CarAdd = {
        model: this.modelInputValue,
        manufacturer: this.manufacturerInputValue,
        color: this.colorInputValue,
        fabricationYear: this.fabYearInputValue
      };
      this.carService.addCar(addedCar).subscribe(
        response => {
          console.log(response);
          this.router.navigateByUrl("/cars");
        },
        error => {
          console.log(error);
          window.alert("Error , car was not added!");
        }
      );
    } 
    else {
      window.alert("Please fill in all fields!");
    }
  }

  constructor(private carService: CarService, private router: Router) {}
}
