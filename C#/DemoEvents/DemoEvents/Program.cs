using System;

namespace DemoEvents
{
    public delegate void DemoDelegate(string str);
    class  SomeClass
    {
        public static event DemoDelegate DemoEvent;

        public static void DoWork(string str)
        {
            DemoEvent?.Invoke(str); // if(DemoEvent != null) DemoEvent(str)
        }
    }

    class SecondClass
    {
        private void ShowString(string str)
        {
            Console.WriteLine(str);
        }

        public SecondClass()
        {
            SomeClass.DemoEvent += ShowString;
        }

        public void Dispose()
        {
            SomeClass.DemoEvent -= ShowString;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            new SecondClass();
            new SecondClass();
            new SecondClass();
            new SecondClass();
            new SecondClass();
            
            SomeClass.DoWork("aaaa");
        }
    }
}