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

using System.Data;
using System.Data.SqlClient;
using System.Configuration;

namespace StationeryFirmApp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SqlConnection conn;
        SqlDataAdapter dataAdapter;
        //DataSet dataSet;
        SqlCommandBuilder cmdBuilder;


        public MainWindow()
        {
            InitializeComponent();
            //showComboBox.SelectedIndex = 0;
            conn = new SqlConnection(ConfigurationManager.ConnectionStrings["AzureStationeryFirmConnString"].ConnectionString);
        }

        void UpdateData()
        {
           // dataAdapter.Update(dataSet);
        }

        
        void ExecuteRequest(string request)
        {
            try
            {
                DataSet dataSet = new DataSet();
                dataAdapter = new SqlDataAdapter(request, conn);
                dataGrid.ItemsSource = null;
                cmdBuilder = new SqlCommandBuilder(dataAdapter);
                dataAdapter.Fill(dataSet);

                dataGrid.ItemsSource = dataSet.Tables[0].DefaultView;
            }
            catch
            {
                MessageBox.Show("Преблема при выполнении запроса");
            }
        }


        

        private void Show(object sender, RoutedEventArgs e)
        {
            int num;
            switch (showComboBox.SelectedIndex)
            {
                case 0:
                    ExecuteRequest("select * from Stationery");
                    break;
                case 1:
                    ExecuteRequest("select * from StationeryTypes");
                    break;
                case 2:
                    ExecuteRequest("select * from Managers");
                    break;
                case 3:
                    ExecuteRequest("SELECT TOP 1 Name, Count FROM Stationery ORDER BY Count DESC");
                    break;
                case 4:
                    ExecuteRequest("SELECT TOP 1 Name, Count FROM Stationery ORDER BY Count ASC");
                    break;
                case 5:
                    ExecuteRequest("SELECT TOP 1 Name, CostPrice FROM Stationery ORDER BY CostPrice ASC");
                    break;
                case 6:
                    ExecuteRequest("SELECT TOP 1 Name, CostPrice FROM Stationery ORDER BY CostPrice DESC");
                    break;

                case 7:
                    if(int.TryParse(showTextBox.Text, out num))
                    {
                        ExecuteRequest("SELECT * FROM Stationery WHERE Type=" + num);
                    } 
                    else
                    {
                        MessageBox.Show("Введены некорретные данные");
                    }
                    break;
                case 8:
                    if (int.TryParse(showTextBox.Text, out num))
                    {
                        ExecuteRequest(@"SELECT Stationery.*
                            FROM Sales
                            JOIN Stationery 
                            ON Stationery.Id=Sales.Stationery
                            WHERE Sales.Manager=" + num.ToString());
                    }
                    else
                    {
                        MessageBox.Show("Введены некорретные данные");
                    }
                    break;
                case 9:
                    if (int.TryParse(showTextBox.Text, out num))
                    {
                        ExecuteRequest(@"SELECT Stationery.Name
                            FROM Sales
                            JOIN Stationery 
                            ON Stationery.Id=Sales.Stationery
                            WHERE Sales.BuyerFirm=" + num.ToString());
                    }
                    else
                    {
                        MessageBox.Show("Введены некорретные данные");
                    }
                    break;

                case 10:
                    ExecuteRequest("SELECT TOP 1 * FROM Sales ORDER BY Date DESC");
                    break;
                case 11:
                    ExecuteRequest(@"SELECT StationeryTypes.Name, AVG(Stationery.Count) as 'Среднее кол-во'
                            FROM Stationery
                            JOIN StationeryTypes 
                            ON StationeryTypes.Id=Stationery.Type
                            GROUP BY StationeryTypes.Name");
                    break;
            }
        }

        private void showComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(showComboBox.SelectedIndex > 6 && showComboBox.SelectedIndex < 10)
            {
                showTextBox.IsEnabled = true;
                MessageBox.Show("Введите индекс предмета поиска в TextBox возле меню");
            } 
            else
            {
                showTextBox.IsEnabled = false;
            }
        }
        
    }
}
