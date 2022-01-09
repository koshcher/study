using System;
using System.Collections.Generic;
using System.Text;

namespace DemoSerializationXML
{
    public class City
    {
        public string Name;
        public List<Person> People;
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder($"City: {Name} has next people:\n");
            foreach (var person in People)
            {
                sb.AppendLine(person.ToString());
            }

            return sb.ToString();
        }
    }
}