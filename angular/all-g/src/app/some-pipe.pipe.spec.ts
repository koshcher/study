import { SomePipePipe } from './some-pipe.pipe';

describe('SomePipePipe', () => {
  it('create an instance', () => {
    const pipe = new SomePipePipe();
    expect(pipe).toBeTruthy();
  });
});
