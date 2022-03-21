using GroupDocs.Search;
using GroupDocs.Search.Dictionaries;

string query = "make";
DictionaryRepository dr = new GroupDocs.Search.Index().Dictionaries;
SynonymDictionary sd = dr.SynonymDictionary;
string[] synonyms = sd.GetSynonyms(query);
Console.WriteLine("Synonyms for '" + query + "':");

for (int i = 0; i < synonyms.Length; i++)
{
    Console.WriteLine("- " + synonyms[i]);
}