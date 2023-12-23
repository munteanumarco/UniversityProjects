import { ComponentFixture, TestBed } from '@angular/core/testing';

import { CarEndpointComponent } from './car-endpoint.component';

describe('CarEndpointComponent', () => {
  let component: CarEndpointComponent;
  let fixture: ComponentFixture<CarEndpointComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ CarEndpointComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(CarEndpointComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
