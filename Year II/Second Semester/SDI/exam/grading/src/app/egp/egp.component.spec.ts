import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EgpComponent } from './egp.component';

describe('EgpComponent', () => {
  let component: EgpComponent;
  let fixture: ComponentFixture<EgpComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ EgpComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(EgpComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
