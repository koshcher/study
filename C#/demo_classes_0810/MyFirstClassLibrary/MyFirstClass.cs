using System;

namespace MyFirstClassLibrary
{
    public class MyFirstClass : Object
    {
        int x;
        int y;

        public int X
        {
            get
            {
                return x;
            }
            set
            {
                x = value;
            }
        }

        public MyFirstClass() : this(0) { }

        public MyFirstClass(int x) : this(x, 0) { }

        public MyFirstClass(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        ~MyFirstClass() // не деструктор, а финализатор
        {
        }
        public void MyFunc()
        {
            Console.WriteLine("I AM FUNCTION !!!");
        }

        public override string ToString()
        {
            return $"{x}:{y}";
        }
    }
}
