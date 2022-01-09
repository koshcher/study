using System;
using System.IO;
using System.Text;

namespace DemoFiles
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            /*
            using (Stream stream = new FileStream("file.txt", FileMode.OpenOrCreate, FileAccess.Write, FileShare.Read))
            {
                Console.WriteLine("Enter your name -> _\b");
                string str = $"Hello! {Console.ReadLine()}!";
                
                stream.SetLength(0);
                
                byte[] buffer = Encoding.GetEncoding(65001).GetBytes(str);
                stream.Write(buffer, 0, buffer.Length);
            }
            */
            Console.WriteLine("Enter file path, that will be copied");
            string source = Console.ReadLine();
            Console.WriteLine("Enter new file path");
            string dest = Console.ReadLine();
            CopyFile(dest, source);
        }

        public static long CopyFile(string destName, string sourceName)
        {
            using (Stream dest = new FileStream(destName, FileMode.OpenOrCreate, FileAccess.Write))
            using (Stream source = new FileStream(sourceName, FileMode.Open, FileAccess.Read))
            {
                    return CopyFile(dest, source);
            }
        }

        public static long CopyFile(Stream dest, Stream source)
        {
            byte[] buffer = new byte[4096];
            while (source.Length != source.Position)
            {
                int readed = source.Read(buffer, 0, buffer.Length);
                dest.Write(buffer, 0, readed);
            }
            return source.Length;
        }
    }
}