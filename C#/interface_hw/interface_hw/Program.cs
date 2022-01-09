using System;

namespace interface_hw
{
    interface IPeople
    {
        string FirstName { get; }
        string MiddleName { get; }
        string LastName { get; }
        int Age { get; }
    }

    class People:IPeople
    {
        public string FirstName { get; set; }
        public string MiddleName { get; set; }
        public string LastName { get; set; }
        public int Age { get; set; }
    }

    interface ICar
    {
        string Name { get; }
        string Color { get; }
        string Model { get; }
        string Mark { get; }
        void Go();
    }

    class Car: ICar
    {
        public string Name { get; set; }
        public string Color { get; set; }
        public string Model { get; set; }
        public string Mark { get; set; }
        public void Go()
        {
            Console.WriteLine("I am going Brm-brm-brm");

        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            IDrawable[] arr = new IDrawable[]
            {
                new Rectangle{Color=ConsoleColor.White, X=10, Y=10, Width=10, Height=10 },
                new Triangle{Color=ConsoleColor.White, X=10, Y=10, Width=10, Height=10 },
                new Elipse{Color=ConsoleColor.White, X=10, Y=10, Width=10, Height=10 }
            };

            ICar[] cars = new ICar[]
            {
                new Car { Color = "green", Mark = "BMW", Model = "M5", Name = "Lastochka" },
                new Car { Color = "red", Mark = "Audi", Model = "A8", Name = "Pushka" },
                new Car { Color = "blue", Mark = "Shkoda", Model = "Fabia", Name = "Ptichka" },
                new Car { Color = "black", Mark = "Toyota", Model = "Supra", Name = "SLAV car" }
            };
              
            foreach(Car x in cars)
            {
                x.Go();
            }


        }
    }
}
