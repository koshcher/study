using System;

namespace DemoMulticastDelegate
{
    delegate void DemoMulticast();
    
    class Program
    {
        static void Test_01()
        {
            Console.WriteLine("01");
        }
        static void Test_02()
        {
            Console.WriteLine("02");
        }
        static void Test_03()
        {
            Console.WriteLine("03");
        }
        static void Main(string[] args)
        {
            DemoMulticast @delegate = Test_01;
            @delegate += Test_02;
            @delegate += Test_03;
            @delegate += delegate ()
            {
                Console.WriteLine("04");
            };
            @delegate += () => Console.WriteLine("05");

            @delegate();
        }
    }
}