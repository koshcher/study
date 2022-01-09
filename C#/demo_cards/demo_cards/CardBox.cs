using System;
using System.Collections.Generic;
using System.Text;

namespace demo_cards
{
    class CardBox
    {
        public static Random _rnd = new Random();
        private int[] _cards = new int[52];
        private int _counter = 0;
    
        public CardBox()
        {
            for(int i = 0; i < _cards.Length; i++)
            {
                _cards[i] = i;
            }

            Shuffle();
        }

        public void Shuffle()
        {
            for (int i = 0; i < _cards.Length; i++)
            {
                int rnd = _rnd.Next(_cards.Length);
                int tmp = _cards[i];
                _cards[i] = _cards[rnd];
                _cards[rnd] = tmp;
            }
        }

        public Card GetNextCard()
        {
            if(_counter == _cards.Length)
            {
                _counter = 0;
                Shuffle();
            }
            return new Card(_cards[_counter++]);
        }
    }
}
