using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfAppFirst
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        List<string> colors = new List<string> { "Navy", "Blue", "Aqua", "Teal", "Olive", "Green", "Lime",
        "Yellow", "Orange", "Red", "Maroon", "Fuchsia", "Purple", "Black", "Silver", "Gray", "White" };


        public MainWindow()
        {
            InitializeComponent();
            foreach(string color in colors)
            {
                wrapPanel.Children.Add(new Button
                {
                    Margin = new Thickness { Left = 2, Bottom = 2, Right = 2, Top = 2 },
                    Foreground = new SolidColorBrush((Color)ColorConverter.ConvertFromString(color)),
                    Content = color
                }) ;
            }
        }
    }
}
