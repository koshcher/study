using DbContextLibrary;
using ModelsLibrary;
using System.Linq;
using System.Windows;

namespace GameCenterWpfApp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private GamesDbContext db;

        public MainWindow()
        {
            InitializeComponent();
            db = new GamesDbContext();
        }

        private void AddGame(object sender, RoutedEventArgs e)
        {
            int num = 0;
            if (isMultiplayerCheckBox.IsChecked != null && int.TryParse(soldCopiesCountTextBox.Text, out num))
            {
                db.Games.Add(new Game
                {
                    Title = titleTextBox.Text,
                    Studio = studioTextBox.Text,
                    ReleaseDate = releaseDateTextBox.DisplayDate.Date,
                    Genre = genreTextBox.Text,
                    IsMultiplayer = isMultiplayerCheckBox.IsChecked.Value,
                    SoldCopiesCount = num
                });
                db.SaveChanges();
            }
            else
            {
                MessageBox.Show("Введённые данные некорректны");
            }
        }

        private void ShowGames(object sender, RoutedEventArgs e)
        {
            showDataGrid.ItemsSource = db.Games.ToList();
        }
    }
}