import { Component, EventEmitter, Input, Output } from '@angular/core';
import { Car } from '../models/car';

@Component({
  selector: 'app-car-card',
  templateUrl: './car-card.component.html',
  styleUrls: ['./car-card.component.css']
})
export class CarCardComponent {
  @Input() car!: Car;
  @Output() deleteCar = new EventEmitter<number>();
  showDeleteConfirm: boolean = false;

  toggleDelete(): void {
    this.showDeleteConfirm = !this.showDeleteConfirm;
  }

  onDelete(): void {
    this.deleteCar.emit(this.car.id);
  }
}
