import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EcpComponent } from './ecp.component';

describe('EcpComponent', () => {
  let component: EcpComponent;
  let fixture: ComponentFixture<EcpComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ EcpComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(EcpComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
