using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace createWordList
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> wordList = new List<string> { }; // list of words

            using (StreamReader sr = new StreamReader("toeC.txt"))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    int slashIndex = line.IndexOf(" /");
                    if(slashIndex != -1 && Char.IsUpper(line[0]) == false)
                    {
                        wordList.Add(line.Substring(0, slashIndex));
                    }
                }
            }

            using (StreamWriter sw = new StreamWriter("wordsC.txt"))
            {
                foreach (string word in wordList)
                {
                   sw.WriteLine(word);
                }
            }
        }
    }
}
