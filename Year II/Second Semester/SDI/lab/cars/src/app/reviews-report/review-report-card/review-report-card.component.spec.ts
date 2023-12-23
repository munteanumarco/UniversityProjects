import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ReviewReportCardComponent } from './review-report-card.component';

describe('ReviewReportCardComponent', () => {
  let component: ReviewReportCardComponent;
  let fixture: ComponentFixture<ReviewReportCardComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ReviewReportCardComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ReviewReportCardComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
