using System;
using System.Collections.Generic;
using System.Text;

namespace demo_cards
{
    enum CardWeight { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUIN, KING, ACE };
    enum CardSuit { Spades, Clubs, Hearts, Diamonds };

    class Card
    {
        public static string[] Weight { get; } = { "TWO", "THREE", "FOUR", "FIVE", "SIX",
                        "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUIN", "KING", "ACE" };
        public static string[] Suits { get; } = { "Spades", "Clubs", "Hearts", "Diamonds" };

        private int _value;
        public Card(int value)
        {
            _value = value;
        }

        public CardWeight CardWeight { get => (CardWeight)(_value % 13); }

        public CardSuit CardSuit { get => (CardSuit)(_value / 13); }

        public override string ToString()
        {
            return $"{Suits[_value / 13]} {Weight[_value % 13]}";
        }

    }
}
