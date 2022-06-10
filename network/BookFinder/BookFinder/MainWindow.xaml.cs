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
using System.Net;
using System.IO;

namespace BookFinder
{
  /// <summary>
  /// Interaction logic for MainWindow.xaml
  /// </summary>
  public partial class MainWindow : Window
  {
    public MainWindow()
    {
      InitializeComponent();
    }

    private string? GetBookPageLink(string data)
    {
      int booklinkIndex = data.IndexOf("booklink");
      if(booklinkIndex > -1)
      {
        data = data.Substring(booklinkIndex);
        int hrefIndex = data.IndexOf("href=\"") + 6;
        string link = "";
        while(data[hrefIndex] != '\"')
        {
          link += data[hrefIndex];
          hrefIndex++;
        }
        return link;
      }
      return null;
    }

    private string? GetBookTextLink(string data)
    {
      int textlinkIndex = data.IndexOf("title=\"Download\">Plain Text UTF-8");
      if (textlinkIndex > -1)
      {
        data = data.Substring(0, textlinkIndex);
        int hrefIndex = data.LastIndexOf("href=\"") + 6;
        string link = "";
        while (data[hrefIndex] != '\"')
        {
          link += data[hrefIndex];
          hrefIndex++;
        }
        return link;
      }
      return null;
    }

    private string GetBookText(string link)
    {
      HttpWebRequest request = (HttpWebRequest)WebRequest.Create(string.Format("https://www.gutenberg.org{0}", link));
      HttpWebResponse response = (HttpWebResponse)request.GetResponse();
      using (StreamReader reader = new StreamReader(response.GetResponseStream()))
      {
        return reader.ReadToEnd();
      }
    }


    private void FindBtn_Click(object sender, RoutedEventArgs e)
    {
      if(searchTextBox.Text.Trim().Length > 0)
        {
        string requestUrl = string.Format("https://www.gutenberg.org/ebooks/search/?query={0}&submit_search=Go", searchTextBox.Text.ToLower());
        HttpWebRequest request = (HttpWebRequest)WebRequest.Create(requestUrl);
        request.Method = "GET";
        HttpWebResponse response = (HttpWebResponse)request.GetResponse();

        using (StreamReader reader = new StreamReader(response.GetResponseStream()))
        {
          string data = reader.ReadToEnd(); // html page
        
          string? bookPageLink = GetBookPageLink(data);
          if(bookPageLink != null)
          {
            HttpWebRequest pageRequest = (HttpWebRequest)WebRequest.Create(string.Format("https://www.gutenberg.org{0}", bookPageLink));
            HttpWebResponse pageResponse = (HttpWebResponse)pageRequest.GetResponse();
            using (StreamReader pageReader = new StreamReader(pageResponse.GetResponseStream()))
            {
              outputTextBlock.Text = GetBookText(GetBookTextLink(pageReader.ReadToEnd()));
            }
          }
          else
          {
            outputTextBlock.Text = "Book are not found";
          }
        }
      } else
      {
        outputTextBlock.Text = "Please enter something";
      }
    }

    /*
    private void AddToOutput(string message)
    {
      Dispatcher.BeginInvoke(() =>
      {
        //messageTextBlock.Text += Environment.NewLine;
        outputTextBox.Text += string.Format("{0}\n", message);
      }, null);
    }*/
  }
}
