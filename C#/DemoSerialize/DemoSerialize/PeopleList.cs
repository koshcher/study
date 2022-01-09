using System;
using System.Collections.Generic;

namespace DemoSerialize
{
    [Serializable]
    public class PeopleList<People> : List<People>
    {
        public PeopleList(IEnumerable<People> collection) : base(collection)
        {
        }
    }
}