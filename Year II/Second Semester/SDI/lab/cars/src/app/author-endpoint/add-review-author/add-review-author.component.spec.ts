import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AddReviewAuthorComponent } from './add-review-author.component';

describe('AddReviewAuthorComponent', () => {
  let component: AddReviewAuthorComponent;
  let fixture: ComponentFixture<AddReviewAuthorComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ AddReviewAuthorComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(AddReviewAuthorComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
