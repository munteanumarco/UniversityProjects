import { Component, OnInit } from '@angular/core';
import { UserProfile } from './models/userProfile';
import { Observable, finalize, takeUntil } from 'rxjs';
import { UserService } from './user.service';
import { ActivatedRoute, Router } from '@angular/router';
import { ProfileStats } from './models/profileStats';

@Component({
  selector: 'app-user-profile',
  templateUrl: './user-profile.component.html',
  styleUrls: ['./user-profile.component.css']
})
export class UserProfileComponent implements OnInit {

  user$!: Observable<UserProfile>; 
  stats$!: Observable<ProfileStats>;
  id!: number;
  username!: string | null;
  statsLoading!: boolean;

  elementsPerPage!: number;

  constructor (private readonly userService: UserService,
               private readonly route: ActivatedRoute) {}

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.id = params['id'];
      this.getUserProfile();
      this.getProfileStats();
    });
    this.username = localStorage.getItem('username');
  }

  getUserProfile(): void {
    if (this.id) {
      this.user$ = this.userService.getUserProfile(this.id);
    }
  }
  getProfileStats(): void {
    this.statsLoading = true;
    if (this.id) {
      this.stats$ = this.userService.getUserProfileStats(this.id).pipe(
        finalize(() => this.statsLoading = false)
      );
    }
  }

  save(): void {
    if (this.elementsPerPage >= 1 && this.elementsPerPage <= 20) {
      localStorage.setItem('elements', this.elementsPerPage.toString());
      window.alert('Elements per page saved successfully!');
    } else {
      window.alert('Value should be between 1 and 20');
    }
  }
}
