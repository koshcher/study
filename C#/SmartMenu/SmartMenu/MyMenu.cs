using System;
using System.Dynamic;
using System.Windows.Forms;

namespace SmartMenu
{
    public delegate void MyMenuDelegate(object obj);
    public class MenuItem: IComparable<MenuItem>
    {
        public string MenuString { get; }
        public event MyMenuDelegate _action;

        public MenuItem(string str, MyMenuDelegate action)
        {
            MenuString = str;
            _action += action;
        }

        public int CompareTo(MenuItem other)
        {
            return MenuString.CompareTo(other.MenuString);
        }

        public void DoWork(object obj)
        {
            _action?.Invoke(obj);
        }
    }
}