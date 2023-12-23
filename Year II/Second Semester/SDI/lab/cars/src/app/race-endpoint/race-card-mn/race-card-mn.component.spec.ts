import { ComponentFixture, TestBed } from '@angular/core/testing';

import { RaceCardMnComponent } from './race-card-mn.component';

describe('RaceCardMnComponent', () => {
  let component: RaceCardMnComponent;
  let fixture: ComponentFixture<RaceCardMnComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ RaceCardMnComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(RaceCardMnComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
