using System;
using System.Collections.Generic;
using System.IO;
using Newtonsoft.Json;

namespace DemoSerializationJSON
{
    internal class Program
    {
        static void Sepialize(City city)
        {
            StreamWriter writer = new StreamWriter(File.OpenWrite("D:\\tmp.json"));
            JsonSerializer serializer = new JsonSerializer();
            serializer.Serialize(writer, city, typeof(City));
            writer.Close();
        }
        
        static City DeSepialize()
        {
            StreamReader reader = new StreamReader(File.OpenRead("D:\\tmp.json"));
            JsonSerializer serializer = new JsonSerializer();
            City city = serializer.Deserialize<City>(new JsonTextReader(reader)) as City;
            reader.Close();
            return city;
        }
        
        public static void Main(string[] args)
        {
            City city = new City{Name = "Dnipro"};
            city.People = new List<Person>(new[]
            {
                new Person {FirstName = "Vasa", LastName = "Pupkin", Age = 18},
                new Person {FirstName = "Vadim", LastName = "Ivanov", Age = 20},
                new Person {FirstName = "Losha", LastName = "Kapustin", Age = 19}
            });
            Sepialize(city);
            city = DeSepialize();
            Console.Write(city.ToString());
        }
    }
}