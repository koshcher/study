using System;

namespace DemoDictionary
{
    public class MyMap<TKey, TVal>: BaseDictionary<TKey, TVal> where TKey: IComparable<TKey>
    {
        public MyMap() : base(true)
        {
        }
    }
    
    public class MyMultyMap<TKey, TVal>: BaseDictionary<TKey, TVal> where TKey: IComparable<TKey>
    {
        public MyMultyMap() : base(false)
        {
        }
    }
}