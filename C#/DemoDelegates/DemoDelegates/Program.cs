using System;
using System.Collections.Generic;
using System.Globalization;
using System.Threading;

namespace DemoDelegates
{
    class Program
    {
        delegate void MyDelegate(int a, int b);
        static void MyMethod(int x, int y)
        {
            Console.WriteLine(x + y);
        }

        delegate float MathDelegate(float a, float b);
        
        static float add(float a, float b)
        {
            return a + b;
        }
        static float sub(float a, float b)
        {
            return a - b;
        }
        static float mul(float a, float b)
        {
            return a * b;
        }
        static float div(float a, float b)
        {
            return a / b;
        }

        delegate bool CompareDelegate(int x, int y);

        static void DemoSort(int[] mas, CompareDelegate del)
        {
            int size = mas.Length;
            while (--size > 0)
            {
                for (int i = 0; i < size; i++)
                {
                    if (del(mas[i], mas[i + 1]))
                    {
                        int tmp = mas[i];
                        mas[i] = mas[i + 1];
                        mas[i + 1] = tmp;
                    }
                }
            }
        }

        static bool Compare(int x, int y)
        {
            return x > y;
        }
        
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-us");
            Thread.CurrentThread.CurrentUICulture = new CultureInfo("en-us");
            
            MathDelegate[] mathFuncs = new MathDelegate[] {add, sub, mul, div};

            int choise = 0;
            float a = 0;
            float b = 0;
            while (choise != -1)
            {
                Console.WriteLine("Enter 1-st num:");
                a = Single.Parse(Console.ReadLine()); // float.Parse()
                Console.WriteLine("Enter 2-st num:");
                b = Single.Parse(Console.ReadLine());
                
                Console.WriteLine("[0] add");
                Console.WriteLine("[1] sub");
                Console.WriteLine("[2] mul");
                Console.WriteLine("[3] div");
                choise = Convert.ToInt32(Console.ReadLine());

                try
                {
                   Console.WriteLine(mathFuncs[choise](a, b)); 
                }
                catch
                {
                    choise = -1;
                }
            }
            Console.WriteLine("Goodbye");
        }
    }
}