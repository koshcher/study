using System;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap;
using System.Collections.Generic;

namespace DemoSerialize
{
    internal class Program
    {
        static void DemoSerializeBinary()
        {
            People p = new People{ FirstName = "Vasa", LastName = "Pupkin", Age = 18};

            Stream stream = File.OpenWrite("D://tmp.bin");
            BinaryFormatter bf = new BinaryFormatter();
            bf.Serialize(stream, p);
            stream.Close();
        }
        
        static void DemoDeSerializeBinary()
        {
            Stream stream = File.OpenWrite("D://tmp.bin");
            BinaryFormatter bf = new BinaryFormatter();
            People p = bf.Deserialize(stream) as People;
            Console.WriteLine(p);
            stream.Close();
        }
        
        static void DemoSerializeSoap()
        {
           MySerializableList p = new MySerializableList( new []
            {
               new People{ FirstName = "Vasa", LastName = "Pupkin", Age = 18},
               new People{ FirstName = "Dima", LastName = "Ivanov", Age = 18},
               new People{ FirstName = "Petya", LastName = "Li Ci Cin", Age = 18},
            });

            Stream stream = File.OpenWrite("D://tmp.soap");
            SoapFormatter sf = new SoapFormatter();
            sf.Serialize(stream, p);
            stream.Close();
        }
        
        static void DemoDeSerializeSoap()
        {
            Stream stream = File.OpenWrite("D://tmp.bin");
            SoapFormatter sf = new SoapFormatter();
            MySerializableList peoples = sf.Deserialize(stream) as MySerializableList;
            stream.Close();

            foreach (var people in peoples)
            {
                Console.WriteLine(people);
            }
        }
        
        public static void Main(string[] args)
        {
            //People p = new People{ FirstName = "Vasa", LastName = "Pupkin", Age = 18};
            DemoSerializeBinary();
            DemoSerializeSoap();
        }
    }
}