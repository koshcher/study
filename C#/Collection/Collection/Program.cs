using System;
using System.Collections.Generic;

namespace Collection
{
    class Program
    {
        static Random _rnd = new Random();
        static void Main(string[] args)
        {
            IntArray arr = new IntArray(10);
            for(int i = 0; i < 10; i++)
            {
                arr.Add(_rnd.Next(100));
            }
            for (int i = 0; i < arr.Count; i++)
            {
               Console.WriteLine($"arr [ {i} ] = {arr[i]}");
            }

            using (IEnumerator<int> ie = arr.GetEnumerator())
            {
                while(ie.MoveNext())
                {
                    Console.WriteLine(ie.Current);
                }
            }
        }
    }
}
