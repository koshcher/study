using System.Collections.Generic;

namespace SmartMenu
{
    internal class Program
    {
        public static void Main(string[] args)
        {
        }
    }

    public class MyMenu
    {
        private List<MenuItem> _items = new List<MenuItem>();

        public void Add(string str, MyMenuDelegate d)
        {
            MenuItem item = _items.Find(x => x.MenuString == str);
            if (item == null)
            {
                _items.Add(new MenuItem(str, d));
            }
            else
            {
                item._action += d;
            }
        }
    }
}