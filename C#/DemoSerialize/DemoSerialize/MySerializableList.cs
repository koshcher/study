using System;
using System.Collections.Generic;

namespace DemoSerialize
{
    [Serializable]
    public class MySerializableList : List<People> 
    {
        public MySerializableList(IEnumerable<People> arr):base(arr)
        {
        }
    }
}