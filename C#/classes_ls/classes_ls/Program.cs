using System;

namespace classes_ls
{
    class Student
    {
        private int _birthDayYear;
        public string FirstName { get; }
        public string LastName { get; }
        public int Age { 
            get {
                return DateTime.Now.Year - _birthDayYear;
            }
            set
            {
                _birthDayYear = DateTime.Now.Year - value;
            }
        }
        public Student(): this(String.Empty , String.Empty, 0) {}
        public Student (string firstName, string lastName, int age)
        {
            FirstName = firstName;
            LastName = lastName;
            Age = age;
        }

        public override string ToString()
        {
            return $"Student {FirstName} {LastName} {Age}";
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int demo_exeption = 0;
            try
            {
                switch (demo_exeption)
                {
                    case 0:
                        throw new Exception("OMG It's 0");
                        break;
                    default:
                        Console.WriteLine("Not 0");
                        break;
                }

                checked
                {
                    unchecked
                    {

                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                Console.WriteLine("Finally");
            }

            string str = null;
            int? len = str?.Length;
            Console.WriteLine($"{len}");
        }
    }
}
