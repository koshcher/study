using System;
using System.Collections.Generic;
using System.Text;

namespace interface_hw
{
    interface IDrawable
    {
        ConsoleColor Color { set; }
        void Draw();
    }

    interface IShape
    {
        int X { get; set; }
        int Y { get; set; }
        int Width { get; set; }
        int Height { get; set; }
    }

    abstract class Shape : IShape, IDrawable
    {
        public ConsoleColor Color { protected get; set; }
        public int X { get; set; }
        public int Y { get; set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public abstract void Draw();
    }

    class Rectangle : Shape, IShape, IDrawable
    {
        public override void Draw()
        {
            Console.ForegroundColor = Color;
            Console.WriteLine("I am Rectangle");
            Console.ResetColor();
        }
    }
    class Triangle : Shape, IShape, IDrawable
    {
        public override void Draw()
        {
            Console.ForegroundColor = Color;
            Console.WriteLine("I am Triangle");
            Console.ResetColor();
        }
    }

    class Ellipce : Shape, IShape, IDrawable
    {
        public override void Draw()
        {
            Console.ForegroundColor = Color;
            Console.WriteLine("I am Ellipce");
            Console.ResetColor();
        }
    }
}
