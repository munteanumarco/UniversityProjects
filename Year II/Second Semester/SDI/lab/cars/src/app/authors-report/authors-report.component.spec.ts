import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AuthorsReportComponent } from './authors-report.component';

describe('AuthorsReportComponent', () => {
  let component: AuthorsReportComponent;
  let fixture: ComponentFixture<AuthorsReportComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ AuthorsReportComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(AuthorsReportComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
