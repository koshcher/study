import { TestBed } from '@angular/core/testing';

import { RandService } from './rand.service';

describe('RandService', () => {
  let service: RandService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(RandService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
