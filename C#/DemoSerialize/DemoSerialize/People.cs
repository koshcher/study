using System;
using System.Runtime.Serialization;

namespace DemoSerialize
{
    [Serializable]
    public class People: IDeserializationCallback
    {
        [NonSerialized] private static Random rnd = new Random();
        private int r;
        public People()
        {
            r = rnd.Next(100);
        }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public int Age { get; set; }
        public override string ToString()
        {
            return $"{r} {FirstName} {LastName}, {Age} year old";
        }

        public void OnDeserialization(object sender)
        {
            throw new NotImplementedException();
        }
    }
}