import { Component, EventEmitter, Input, Output } from '@angular/core';
import { Race } from '../models/race';

@Component({
  selector: 'app-race-card',
  templateUrl: './race-card.component.html',
  styleUrls: ['./race-card.component.css']
})
export class RaceCardComponent {
  @Input() race!: Race;
  @Output() deleteRace = new EventEmitter<number>();
  showDeleteConfirm: boolean = false;

  toggleDelete(): void {
    this.showDeleteConfirm = !this.showDeleteConfirm;
  }

  onDelete(): void {
    this.deleteRace.emit(this.race.id);
  }
}
