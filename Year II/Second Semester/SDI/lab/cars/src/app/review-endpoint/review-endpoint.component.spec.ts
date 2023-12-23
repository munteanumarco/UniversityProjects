import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ReviewEndpointComponent } from './review-endpoint.component';

describe('ReviewEndpointComponent', () => {
  let component: ReviewEndpointComponent;
  let fixture: ComponentFixture<ReviewEndpointComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ReviewEndpointComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ReviewEndpointComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
