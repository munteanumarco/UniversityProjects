import { HttpClient, HttpParams } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable, retryWhen, shareReplay } from 'rxjs';
import { UserProfile } from './models/userProfile';
import { ProfileStats } from './models/profileStats';

@Injectable({
  providedIn: 'root'
})
export class UserService {

  private userUrl: string = 'https://carsinfoapi.azurewebsites.net/api/users';


  getUserProfile(id: number): Observable<UserProfile> {
    const requestUrl = `${this.userUrl}/${id}`;
    let params = new HttpParams()
    .set('userId', id)
    return this.http.get<UserProfile>(requestUrl, { params });
  }

  getUserProfileStats(id: number): Observable<ProfileStats> {
    const requestUrl =  `${this.userUrl}/${id}/stats`;
    let params = new HttpParams()
    .set('userId', id)
    return this.http.get<ProfileStats>(requestUrl, { params }).pipe(
      shareReplay(1)
    );
  }


  constructor(private readonly http: HttpClient) { }
}
