using System.IO;

string[] en;
string[] ua;

const char level = 'c';

using (StreamReader sw = new StreamReader(level + "-level-words.txt"))
{
  en = sw.ReadToEnd().Split("\r\n");
}

using (StreamReader sw = new StreamReader(level + "-level-words-ua.txt"))
{
  ua = sw.ReadToEnd().Split("\r\n");
}

using (StreamWriter sw = new StreamWriter(level + "-translation.json"))
{
  sw.Write("[");

  for(int i = 0; i < en.Length; i++)
  {
    if (en[i].Length > 3)
    {
      sw.Write("{\"ua\":\"" + ua[i] + "\",\"en\":\"" + en[i] + "\"}");
      if (i < en.Length - 2)
      {
        sw.Write(",");
      }
    }
  }

  sw.Write("]");
}