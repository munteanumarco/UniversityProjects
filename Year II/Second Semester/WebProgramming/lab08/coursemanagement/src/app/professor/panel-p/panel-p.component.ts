import { Component, OnInit } from '@angular/core';
import { ProfessorGroups } from '../models/professorGroups';
import { Observable, concatMap, filter, tap } from 'rxjs';
import { ProfessorService } from '../professor.service';

@Component({
  selector: 'app-panel-p',
  templateUrl: './panel-p.component.html',
  styleUrls: ['./panel-p.component.css']
})
export class PanelPComponent implements OnInit {

  groups$!: Observable<ProfessorGroups[]>;
  id!: number;

  constructor (private readonly professorService: ProfessorService) {}
  ngOnInit(): void {
    this.id = parseInt(localStorage.getItem('user_id') ?? '2');
    this.fetchGroups();
  }

  fetchGroups() {
    this.groups$ = this.professorService.getProfessorGroups(this.id).pipe(
      tap(data => console.log(JSON.stringify(data)))
    );
  }


  removeGroup(group: number, courseId: number) {
    let status = window.confirm("Are you sure ?");
    if (status) {
      this.confirmedRemoveGroup(group, courseId);
    }  
  }

  confirmedRemoveGroup(group: number, courseId: number) {
    this.professorService.removeGroup(group, courseId, this.id).subscribe(
      () => {
        console.log("deleted!");
        this.fetchGroups();
      }
    );
  }

}
