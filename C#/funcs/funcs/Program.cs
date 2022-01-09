using System;

namespace funcs
{
    class Program
    {
        static void Func(out int x)
        {
            Console.Write("Enter x:  \b");
            x = Convert.ToInt32(Console.ReadLine());
        }

        /*
         static void Func(ref int x) { ... }
        */


        static void Main(string[] args)
        {
            int x = 0;
            Func(out x);
            Console.WriteLine(x);

            var val = new { x = 100, first = "Roman", last="Koshchey" };
            Console.WriteLine(val.GetType());
        }
    }
}
