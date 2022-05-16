// See https://aka.ms/new-console-template for more information

using SimpleTCP;

int port = 8005;
SimpleTcpServer server = new SimpleTcpServer();
server.StringEncoder = System.Text.Encoding.UTF8;

server.Delimiter = 0x13;//enter
server.Start(System.Net.IPAddress.Parse("127.0.0.1"), port);

Console.WriteLine("Server is started");
server.DataReceived += Server_DataReciver;

void Server_DataReciver(object sender, SimpleTCP.Message e)
{
    Console.WriteLine(e.MessageString + "\n");
    e.ReplyLine(string.Format("Text: {0}", e.MessageString));
}