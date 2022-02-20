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
using StoreDbLibrary;
using StoreDbLibrary.Models;

namespace StrongStoreUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        StoreDbContext db;
        int currentUserId = 0;
        int currentPublisherId = 0;

        public MainWindow()
        {
            InitializeComponent();
            db = new StoreDbContext();    
           registerUserBirthDate.DisplayDate = DateTime.Now;
        }

        private void RegisterUser(object sender, RoutedEventArgs e)
        {
            if(registerUserPassword.Password == registerUserConfirmPassword.Password && registerUserName.Text != "" && registerUserEmail.Text != "")
            {
                db.Users.Add(new User
                {
                    UserName = registerUserName.Text,
                    Email = registerUserEmail.Text,
                    Password = registerUserPassword.Password,
                    BirthDate = registerUserBirthDate.DisplayDate
                });
                db.SaveChanges();
            } 
            else
            {
                MessageBox.Show("Input is incorrect");
            }
        }

        private void RegisterPublisher(object sender, RoutedEventArgs e)
        {
            if (registerPublisherPassword.Password == registerPublisherConfirmPassword.Password && registerPublisherName.Text != "" && registerPublisherEmail.Text != "")
            {
                db.Publishers.Add(new Publisher
                {
                    Name = registerPublisherName.Text,
                    Email= registerPublisherEmail.Text,
                    Description = registerPublisherDescription.Text,
                    Password= registerPublisherPassword.Password
                });
                db.SaveChanges();
            }
            else
            {
                MessageBox.Show("Input is incorrect");
            }
        }

        private void Login(object sender, RoutedEventArgs e)
        {
            if(asUserRadioBtn.IsChecked == true)
            {
                var res = from user in db.Users
                          where user.Email == loginEmail.Text
                          select user;
                if (res.Count() > 0 && res.First().Password == loginPassword.Password)
                {
                    currentUserId = res.First().Id;
                    MessageBox.Show("WELCOME!");
                }
                else
                {
                    MessageBox.Show("Input is incorrect");
                }
            } 
            else if (asPublisherRadioBtn.IsChecked == true)
            {
                var res = from publisher in db.Publishers
                          where publisher.Email == loginEmail.Text
                          select publisher;
                if (res.Count() > 0 && res.First().Password == loginPassword.Password)
                {
                    currentPublisherId = res.First().Id;
                    MessageBox.Show("WELCOME!");
                }
                else
                {
                    MessageBox.Show("Input is incorrect");
                }
            }
        }
    }
}
