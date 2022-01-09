using System;
using System.Collections.Generic;
using System.Text;

namespace PeopleClassLibrary
{
    public class PeopleClass
    {
        string Name;
        string Surname;
        int Age;
        public PeopleClass() : this("", "") {}

        public PeopleClass(string name, string surname)
        {
            Name = name;
            Surname = surname;
        }

        public PeopleClass(int age)
        {
            Age = age;
        }

        public string name
        {
            get
            {
                return Name;
            }
            set
            {
                Name = value;
            }
        }

        public string surname
        {
            get
            {
                return Surname;
            }
            set
            {
                Surname = value;
            }
        }

        public int age
        {
            get
            {
                return Age;
            }
            set
            {
                Age = value;
            }
        }

        public override string ToString()
        {
            return $"{Surname} {Name} {Age}";
        }
    }
}
