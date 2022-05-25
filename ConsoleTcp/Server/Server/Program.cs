using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace Server
{
    class Program
    {
        static void Main(string[] args)
        {
            IPAddress ip = IPAddress.Parse("127.0.0.1");
            IPEndPoint ep = new IPEndPoint(ip, 4006);

            TcpListener server = new TcpListener(ep);
            try
            {
                server.Start();
                while (true)
                {
                    Console.WriteLine("Ожидаем подключений....");
                    TcpClient client = server.AcceptTcpClient();
                    Console.WriteLine("Клиент Подключился ждем запрос");
                    NetworkStream stream = client.GetStream();
                    string message = String.Format("В {0} от {1} получена строка: Привет, клиент!", DateTime.Now.ToShortTimeString(), ip);
                    byte[] data = Encoding.UTF8.GetBytes(message);
                    stream.Write(data, 0, data.Length);
                    Console.WriteLine("Сообщение отправлено");
                    StringBuilder response = new StringBuilder();
                    do
                    {
                        int bytes = stream.Read(data, 0, data.Length);
                        response.Append(Encoding.UTF8.GetString(data, 0, bytes));
                    } while (stream.DataAvailable);
                    Console.WriteLine(response.ToString());
                    stream.Close();
                    client.Close();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                server.Stop();
            }
            
        }
    }
}
