using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Xml.Serialization;

namespace DemoSerializationXML
{
    internal class Program
    {
        static void Sepialize(City city)
        {
            Stream stream = File.OpenWrite("D:\\tmp.xml");
            XmlSerializer serializer = new XmlSerializer(typeof(City));
            serializer.Serialize(stream, city);
            stream.Close();
        }
        
        static City DeSepialize()
        {
            Stream stream = File.OpenRead("D:\\tmp.xml");
            XmlSerializer serializer = new XmlSerializer(typeof(City));
            City city = serializer.Deserialize(stream) as City;
            stream.Close();
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