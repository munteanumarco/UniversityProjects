import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ProfileSComponent } from './profile-s.component';

describe('ProfileSComponent', () => {
  let component: ProfileSComponent;
  let fixture: ComponentFixture<ProfileSComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ProfileSComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ProfileSComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
