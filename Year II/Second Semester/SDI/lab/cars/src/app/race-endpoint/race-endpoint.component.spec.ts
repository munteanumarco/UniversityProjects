import { ComponentFixture, TestBed } from '@angular/core/testing';

import { RaceEndpointComponent } from './race-endpoint.component';

describe('RaceEndpointComponent', () => {
  let component: RaceEndpointComponent;
  let fixture: ComponentFixture<RaceEndpointComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ RaceEndpointComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(RaceEndpointComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
