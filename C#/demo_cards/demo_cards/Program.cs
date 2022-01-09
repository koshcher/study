using System;

namespace demo_cards
{
    class Program
    {
        static void Main(string[] args)
        {
            CardBox box = new CardBox();

            while(true)
            {
                if(Console.ReadKey(true).Key == ConsoleKey.Escape)
                {
                    return;
                }

                Console.WriteLine(box.GetNextCard());
            }
        }
    }
}
