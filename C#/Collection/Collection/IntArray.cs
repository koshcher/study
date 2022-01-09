using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace Collection
{
    class IntArray : ICollection<int>, IEnumerator<int>
    {
        int[] _arr;
        int _count;
        int _currentIndex = -1;

        public bool IsReadOnly => false;
        public int Count
        {
            get => _count;
        }

        public int Current => _arr[_currentIndex];

        object IEnumerator.Current => Current;

        void CheckIndex(int index)
        {
            if(index < 0 || index >= _count)
            {
                throw new IndexOutOfRangeException();
            }
        }
        public int this[int index]
        {
            get
            {
                CheckIndex(index);
                return _arr[index];
            }
            set
            {
                CheckIndex(index);
                _arr[index] = value;
            }
        }
        public IntArray(int capacity = 100)
        {
            _arr = new int[capacity];
            _count = 0;
        }
        public void Add(int x)
        {
            CheckCapacity();
            _arr[_count++] = x;
        }
        void CheckCapacity()
        {
            if (_arr.Length == _count)
            {
                Array.Resize(ref _arr, _count * 3 / 2 + 1);
            }
        }
        public void Clear()
        {
            _count = 0;
        }

        public bool Contains(int value)
        {
            using (IEnumerator<int> ie = GetEnumerator())
            {
                while(ie.MoveNext())
                {
                    if(value == ie.Current)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        public void CopyTo(int[] array, int arrayIndex)
        {
            using (IEnumerator<int> ie = GetEnumerator())
            {
                while (ie.MoveNext())
                {
                    array[arrayIndex++] = ie.Current;
                }
            }
        }

        public bool Remove(int value)
        {
            int index = IndexOf(value);
            if(index < 0)
            {
                return false;
            }
            RemoveAt(index);
            return true;
        }
        public void RemoveAt(int index)
        {
            while(index < _count - 1)
            {
                _arr[index] = _arr[index + 1];
                ++index;
            }
            --_count;
        }
        public void InserrtAt(int index, int value)
        {
            CheckCapacity();
            for(int i =_count; i > index; i--)
            {
                _arr[i] = _arr[i - 1];
            }
            ++_count;
            _arr[index] = value;
        }
        public IEnumerator<int> GetEnumerator()
        {
            return this;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public bool MoveNext()
        {
            return ++_currentIndex < _count;
        }

        public void Reset()
        {
            _currentIndex = -1;
        }

        public void Dispose()
        {
            Reset();
        }

        public int IndexOf(int value)
        {
            for(int i = 0; i < _count; i++)
            {
                if(_arr[i] == value)
                {
                    return i;
                }
            }
            return -1;
        }
    }
}
