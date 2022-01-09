using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	class Program
	{

		static void Main(string[] args)
		{
			Console.OutputEncoding = Encoding.UTF8;

			Console.BackgroundColor = ConsoleColor.DarkBlue;
			Console.ForegroundColor = ConsoleColor.Yellow;
			Console.Clear();

			Console.WriteLine("Введите стоимость");
			string str = Console.ReadLine();
			decimal cost = Convert.ToDecimal(str);
			Console.WriteLine("Стоимость {0}", cost);

			while (Console.ReadKey().Key != ConsoleKey.Escape) ;
		}
	}
}
