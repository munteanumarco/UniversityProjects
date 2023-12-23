import { Component, OnInit } from '@angular/core';
import { Author } from '../models/author';
import { Observable } from 'rxjs';
import { CarService } from 'src/app/car-endpoint/car.service';
import { ActivatedRoute, Router } from '@angular/router';
import { AuthorService } from '../author.service';
import { AuthorWithDetails } from '../models/authorWithDetails';

@Component({
  selector: 'app-view-author',
  templateUrl: './view-author.component.html',
  styleUrls: ['./view-author.component.css']
})
export class ViewAuthorComponent implements OnInit {

  authorId!: number;
  author$!: Observable<AuthorWithDetails>;

  constructor (private authorService: AuthorService, private router: Router, private route: ActivatedRoute) {}

  ngOnInit(): void {
    this.route.params.subscribe(params => {
      this.authorId = params['id'];
      this.getAuthorDetails();
    });
  }

  getAuthorDetails() {
    this.author$ = this.authorService.getAuthor(this.authorId);
  }

  onDeleteReviewFromAuthor(raceId: number) {
    // this.author$ = this.author$.pipe(
    //   concatMap((author: AuthorWithDetails) => {
    //     return this.authorService.deleteAuthor(this.au, raceId).pipe(
    //       switchMap(() => {
    //         console.log(`Race with id ${raceId} deleted from car with id ${this.carId}`);
    //         car.races = car.races.filter(race => race.id != raceId);
    //         return of(car);
    //       }),
    //       catchError((error) => {
    //         console.log(error);
    //         window.alert(`Delete failed!`);
    //         return of(car);
    //       })
    //     );
    //   })
    // );
  }

  onAddReview(): void {
    this.router.navigateByUrl("/add-review/" + this.authorId);
  }
}
