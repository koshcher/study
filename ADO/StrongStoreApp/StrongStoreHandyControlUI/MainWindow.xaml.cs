using HandyControl.Controls;
using HandyControl.Themes;
using HandyControl.Tools;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using StoreDbLibrary;
using StoreDbLibrary.Models;
using System.Linq;
using System;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace StrongStoreHandyControlUI
{
    public partial class MainWindow
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
            if (registerUserPassword.Password == registerUserConfirmPassword.Password && registerUserName.Text != "" && registerUserEmail.Text != "")
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
                HandyControl.Controls.MessageBox.Show("Input is incorrect");
            }
        }

        private void RegisterPublisher(object sender, RoutedEventArgs e)
        {
            if (registerPublisherPassword.Password == registerPublisherConfirmPassword.Password && registerPublisherName.Text != "" && registerPublisherEmail.Text != "")
            {
                db.Publishers.Add(new Publisher
                {
                    Name = registerPublisherName.Text,
                    Email = registerPublisherEmail.Text,
                    Description = registerPublisherDescription.Text,
                    Password = registerPublisherPassword.Password
                });
                db.SaveChanges();
            }
            else
            {
                HandyControl.Controls.MessageBox.Show("Input is incorrect");
            }
        }

        private void Login(object sender, RoutedEventArgs e)
        {
            if (asUserRadioBtn.IsChecked == true)
            {
                var res = from user in db.Users
                          where user.Email == loginEmail.Text
                          select user;
                if (res.Count() > 0 && res.First().Password == loginPassword.Password)
                {
                    currentUserId = res.First().Id;
                    HandyControl.Controls.MessageBox.Show("WELCOME!");
                }
                else
                {
                    HandyControl.Controls.MessageBox.Show("Input is incorrect");
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
                    HandyControl.Controls.MessageBox.Show("WELCOME!");
                }
                else
                {
                    HandyControl.Controls.MessageBox.Show("Input is incorrect");
                }
            }
        }

        #region Change Theme
        private void ButtonConfig_OnClick(object sender, RoutedEventArgs e) => PopupConfig.IsOpen = true;

        private void ButtonSkins_OnClick(object sender, RoutedEventArgs e)
        {
            if (e.OriginalSource is Button button)
            {
                PopupConfig.IsOpen = false;
                if (button.Tag is ApplicationTheme tag)
                {
                    ((App)Application.Current).UpdateTheme(tag);
                }
                else if (button.Tag is Brush accentTag)
                {
                    ((App)Application.Current).UpdateAccent(accentTag);
                }
                else if (button.Tag is "Picker")
                {
                    var picker = SingleOpenHelper.CreateControl<ColorPicker>();
                    var window = new PopupWindow
                    {
                        PopupElement = picker,
                        WindowStartupLocation = WindowStartupLocation.CenterScreen,
                        AllowsTransparency = true,
                        WindowStyle = WindowStyle.None,
                        MinWidth = 0,
                        MinHeight = 0,
                        Title = "Select Accent Color"
                    };

                    picker.SelectedColorChanged += delegate
                    {
                        ((App)Application.Current).UpdateAccent(picker.SelectedBrush);
                        window.Close();
                    };
                    picker.Canceled += delegate { window.Close(); };
                    window.Show();
                }
            }
        }
        #endregion

        private void nav_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            switch(nav.SelectedIndex)
            {
                case 0:
                    listViewApps.ItemsSource = from app in db.Apps
                                               select app;
                    break;
                case 1:
                    break;
                case 2:
                    publishLanguageTransfer.ItemsSource = from lang in db.Languages
                                                   select lang;
                    publishAppRadioBtn.IsChecked = true;
                    break;
                case 3:
                    break;
            }
        }

        private void publishAppRadioBtn_Checked(object sender, RoutedEventArgs e)
        {
            publishCategoryTransfer.ItemsSource = from category in db.Categories
                                           where category.IsForGame == false
                                           select category;
        }

        private void publishGameRadioBtn_Checked(object sender, RoutedEventArgs e)
        {
            publishCategoryTransfer.ItemsSource = from category in db.Categories
                                           where category.IsForGame == true
                                           select category;
        }

        private void Publish(object sender, RoutedEventArgs e)
        {
            if(currentPublisherId == 0)
            {
                HandyControl.Controls.MessageBox.Show("You are not login as publisher");
                nav.SelectedIndex = 3;
            }
            else
            {
                double price;
                if(double.TryParse(publishPrice.Text, out price))
                {
                    db.Apps.Add(new StoreDbLibrary.Models.App
                    {
                        Name = publishName.Text,
                        Description = publishDescription.Text,
                        Rating = (int)publishRate.Value,
                        ReleaseDate = publishReleaseDate.DisplayDate,
                        IsGame = publishGameRadioBtn.IsChecked.Value,
                        Price = price,
                        PublisherId = currentPublisherId
                    });
                    db.SaveChanges();

                    int appId = (from app in db.Apps
                                orderby app.Id descending
                                select app.Id).FirstOrDefault();

                    foreach (var lang in publishLanguageTransfer.SelectedItems)
                    {
                        db.AppLanguages.Add(new AppLanguage { LanguageId = ((Language)lang).Id, AppId = appId });
                    }
                    foreach (var category in publishCategoryTransfer.SelectedItems)
                    {
                        db.AppCategories.Add(new AppCategory { CategoryId = ((Category)category).Id, AppId = appId });
                    }
                    db.SaveChanges();
                } 
                else
                {
                    HandyControl.Controls.MessageBox.Show("Price is incorrect");
                }
            }
        }
    }
}
