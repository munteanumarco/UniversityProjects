import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AuthorEndpointComponent } from './author-endpoint.component';

describe('AuthorEndpointComponent', () => {
  let component: AuthorEndpointComponent;
  let fixture: ComponentFixture<AuthorEndpointComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ AuthorEndpointComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(AuthorEndpointComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
