import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PanelSComponent } from './panel-s.component';

describe('PanelSComponent', () => {
  let component: PanelSComponent;
  let fixture: ComponentFixture<PanelSComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ PanelSComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(PanelSComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
