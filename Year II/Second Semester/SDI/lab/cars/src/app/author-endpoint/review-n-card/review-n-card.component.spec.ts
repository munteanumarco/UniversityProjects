import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ReviewNCardComponent } from './review-n-card.component';

describe('ReviewNCardComponent', () => {
  let component: ReviewNCardComponent;
  let fixture: ComponentFixture<ReviewNCardComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ReviewNCardComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ReviewNCardComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
