using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace Client
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                TcpClient client = new TcpClient();
                client.Connect("127.0.0.1", 4006);
                byte[] data = new byte[256];
                StringBuilder response = new StringBuilder();
                NetworkStream stream = client.GetStream();
                do
                {
                    int bytes = stream.Read(data, 0, data.Length);
                    response.Append(Encoding.UTF8.GetString(data, 0, bytes));
                } while (stream.DataAvailable);

                Console.WriteLine(response.ToString());
                string message = String.Format("В {0} от {1} получена строка: Привет, сервер!", DateTime.Now.ToShortTimeString(), "127.0.0.1");
                //data = new byte[256];
                data = Encoding.UTF8.GetBytes(message);
                stream.Write(data, 0, data.Length);
                Console.WriteLine("Сообщение отправлено");
                stream.Close();
                client.Close();
            }
            catch(SocketException ex)
            {
                Console.WriteLine(ex.Message);
            }
            catch (Exception ex)
            {

                Console.WriteLine(ex.Message);
            }
            Console.ReadKey();
        }
    }
}
