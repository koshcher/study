import { ComponentFixture, TestBed } from '@angular/core/testing';

import { HobbyComponentComponent } from './hobby-component.component';

describe('HobbyComponentComponent', () => {
  let component: HobbyComponentComponent;
  let fixture: ComponentFixture<HobbyComponentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ HobbyComponentComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(HobbyComponentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
