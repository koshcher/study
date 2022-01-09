using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO.Enumeration;

namespace DemoDictionary
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<String, String> dictionary = new Dictionary<string, string>();

            int choise = 0;
            String word;
            while(choise != -1)
            {
                Console.Write("Enter word: ");
                word = Console.ReadLine();
                
                if(dictionary.ContainsKey(word) == )
            }
            Console.ReadKey();
        }
    }
}
