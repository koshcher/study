using System;

namespace DemoDictionary
{
    public class MySet<TVal>: BaseTree<TVal> where TVal: IComparable<TVal>
    {
        public MySet() : base(true)
        {
        }
    }
    
    public class MyMultySet<TVal>: BaseTree<TVal> where TVal: IComparable<TVal>
    {
        public MyMultySet() : base(false)
        {
        }
    }
}