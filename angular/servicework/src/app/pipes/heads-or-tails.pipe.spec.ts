import { HeadsOrTailsPipe } from './heads-or-tails.pipe';

describe('HeadsOrTailsPipe', () => {
  it('create an instance', () => {
    const pipe = new HeadsOrTailsPipe();
    expect(pipe).toBeTruthy();
  });
});
