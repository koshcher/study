using System;

namespace DemoExceptions
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Program p = new Program();
            
            try
            {
                Console.Write("Enter array size => _\b");
                int size = Int32.Parse(Console.ReadLine());
                int[] array = new int[size];
                Console.Write("Enter array index => _\b");
                int index = Int32.Parse(Console.ReadLine());
                Console.Write("Enter value => _\b");
                int value = Int32.Parse(Console.ReadLine());
                array[index] = value;
            }
            catch(IndexOutOfRangeException e)
            {
                Console.WriteLine(e.Message);
            }           
            catch(ArithmeticException e)
            {
                Console.WriteLine(e.Message);
            }
            catch(FormatException e)
            {
                Console.WriteLine(e.Message);
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}