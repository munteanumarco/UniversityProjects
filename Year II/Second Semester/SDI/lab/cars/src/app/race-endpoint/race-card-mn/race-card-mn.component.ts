import { Component, EventEmitter, Input, Output } from '@angular/core';
import { Race } from '../models/race';

@Component({
  selector: 'app-race-card-mn',
  templateUrl: './race-card-mn.component.html',
  styleUrls: ['./race-card-mn.component.css']
})
export class RaceCardMnComponent {
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
