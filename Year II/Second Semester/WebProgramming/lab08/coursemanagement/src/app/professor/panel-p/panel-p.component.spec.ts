import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PanelPComponent } from './panel-p.component';

describe('PanelPComponent', () => {
  let component: PanelPComponent;
  let fixture: ComponentFixture<PanelPComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ PanelPComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(PanelPComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
