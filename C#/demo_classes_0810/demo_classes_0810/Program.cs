using System;
using PeopleClassLibrary;
using MyFirstClassLibrary; 

namespace demo_classes_0810
{
    class Program
    {
        static void Main(string[] args)
        {
            MyFirstClass fs = new MyFirstClass();
            fs.MyFunc();
            fs.X = 10;

            PeopleClass p = new PeopleClass();
            p.age = 15;
            p.name = "Roma";
            p.surname = "Koshchey";
            Console.WriteLine(p.ToString());

            string s1 = "ABCDE";
            string s2 = "ABCDE";

            if(Object.ReferenceEquals(s1, s2))
            {
                Console.WriteLine("EQUALS");
            }
            else
            {
                Console.WriteLine("NOT EQUALS");
            }

            s1 = "Strasse";
            s2 = "Straße";

            if (s1 == s2)
            {
                Console.WriteLine("EQUALS =");
            } 
            if(s1.Equals(s2))
            {
                Console.WriteLine("EQUALS Eq");
            }
            if (s1.CompareTo(s2) == 0)
            {
                Console.WriteLine("EQUALS Comp");
            }

            PeopleClass[] children = new PeopleClass[3];
            Random rnd = new Random();
            for (int i = 0; i < children.Length; i++)
            {
                children[i] = new PeopleClass();
                children[i].name = "Roma";
                children[i].age = rnd.Next(100);
                children[i].surname = "Oppa";
            }
            for (int i = 0; i < children.Length; i++)
            {
                Console.WriteLine(children[i].ToString());
            }
        }
    }
}
