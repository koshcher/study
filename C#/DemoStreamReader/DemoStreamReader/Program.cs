using System;
using System.IO;
using System.Text;

namespace DemoStreamReader
{
  internal class Program
  {
    public static void Main(string[] args)
    {
      //StreamReader r = File.OpenText("Demo.txt");
      //FileInfo fi = new FileInfo(@"Demo.txt");
      //Stream s = fi.Exists ? fi.Open(FileMode.Open) : fi.Create();

      foreach (string sss in Directory.GetFiles("D:\\")) 
      {
        Console.WriteLine(sss);
      }
      Console.WriteLine("");
      foreach (string sss in Directory.GetDirectories("D:\\")) 
      {
        Console.WriteLine(sss);
      }
      
      Stream stream = new FileStream("Demo.txt", FileMode.OpenOrCreate, FileAccess.Write, FileShare.Read);
      StreamWriter writer = new StreamWriter(stream, Encoding.UTF8);
      
      writer.WriteLine("Tra-la=la");
      writer.Close();
      
      stream = new FileStream("Demo.txt", FileMode.Open, FileAccess.Read, FileShare.Read);
      StreamReader reader = new StreamReader(stream, Encoding.UTF8);

      string str = reader.ReadLine();
      Console.WriteLine(str);
      reader.Close();
    }
  }
}