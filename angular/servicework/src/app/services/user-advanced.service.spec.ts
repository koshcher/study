import { TestBed } from '@angular/core/testing';

import { UserAdvancedService } from './user-advanced.service';

describe('UserAdvancedService', () => {
  let service: UserAdvancedService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(UserAdvancedService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
