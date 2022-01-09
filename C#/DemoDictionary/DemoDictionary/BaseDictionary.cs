using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace DemoDictionary
{
    public class BaseDictionaryComparer<TKey, TVal> : IComparer<KeyValuePair<TKey, TVal>> where TKey : IComparable<TKey>
    {
        public int Compare(KeyValuePair<TKey, TVal> x, KeyValuePair<TKey, TVal> y)
        {
            return x.Key.CompareTo(y.Key);
        }
    }

    public class BaseDictionary<TKey, TVal>
        : Tree<KeyValuePair<TKey, TVal>,
                BaseDictionaryComparer<TKey, TVal>>,    
            IDictionary<TKey, TVal>
        where TKey : IComparable<TKey>
    {
        public BaseDictionary(bool isUnique) : base(isUnique)
        {
        }

        public TVal this[TKey key]
        {
            get
            {
                TreeItem item = GetItem(new KeyValuePair<TKey, TVal>(key, default(TVal)));
                if (item == null) { throw new IndexOutOfRangeException(); }
                return item._value.Value;

            }
            set
            {
                TreeItem item = GetItem(new KeyValuePair<TKey, TVal>(key, default(TVal)));
                if (item == null) { throw new IndexOutOfRangeException(); }
                item._value = new KeyValuePair<TKey, TVal>(key, value);
            }
        }

        public ICollection<TKey> Keys
        {
            get
            {
                List<TKey> keys = new List<TKey>();
                using (IEnumerator<KeyValuePair<TKey, TVal>> en = GetEnumerator())
                {
                    while (en.MoveNext())
                    {
                        keys.Add(en.Current.Key);
                    }
                }
                return keys;
            }
        }

        public ICollection<TVal> Values {
            get
            {
                List<TVal> values = new List<TVal>();
                using (IEnumerator<KeyValuePair<TKey, TVal>> en = GetEnumerator())
                {
                    while (en.MoveNext())
                    {
                        values.Add(en.Current.Value);
                    }
                }
                return values;
            }
        }

        public void Add(TKey key, TVal value)
        {
            Add(new KeyValuePair<TKey, TVal>(key, value));
        }

        public bool ContainsKey(TKey key)
        {
            return base.Contains(new KeyValuePair<TKey, TVal>(key, default(TVal)));
        }

        public bool Remove(TKey key)
        {
            return base.Remove(new KeyValuePair<TKey, TVal>(key, default(TVal)));
        }

        public bool TryGetValue(TKey key, out TVal value)
        {
            TreeItem item = base.GetItem(new KeyValuePair<TKey, TVal>(key, default(TVal)), _root);
            if (item == null)
            {
                value = default(TVal);
                return false;
            }
            else
            {
                value = item._value.Value;
                return true;
            }
        }
    }
}