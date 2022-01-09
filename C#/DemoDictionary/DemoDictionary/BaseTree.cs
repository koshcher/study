using System;

namespace DemoDictionary
{
    public class BaseTree<T>: Tree<T, BaseComparer<T>> where T:IComparable<T>
    {
        public BaseTree(bool isUnique=false) : base(isUnique)
        {
            
        }
    }
}