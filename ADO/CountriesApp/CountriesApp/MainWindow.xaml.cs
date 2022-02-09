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
using System.Data.Linq;

namespace CountriesApp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        DataClasses1DataContext db;

        public MainWindow()
        {
            InitializeComponent();
            db = new DataClasses1DataContext();
            Task2ComboBox.SelectedIndex = 0;
            Task3ComboBox.SelectedIndex = 0;
            Task4ComboBox.SelectedIndex = 0;
        }

        private void Task2Btn_Click(object sender, RoutedEventArgs e)
        {
            switch(Task2ComboBox.SelectedIndex)
            {
                case 0:
                    ShowDataGrid.ItemsSource = from country in db.Countries
                                               select country;
                    break;
                case 1:
                    ShowDataGrid.ItemsSource = db.Countries.Select(country => country.Name);
                    break;
                case 2:
                    ShowDataGrid.ItemsSource = from city in db.MajorCities
                                               where city.Capital == true
                                               select new
                                               {
                                                   Name = city.Name,
                                               };
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
            }
        }

        private void Task3Btn_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Task4Btn_Click(object sender, RoutedEventArgs e)
        {

        }
    }
}
