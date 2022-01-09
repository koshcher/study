using System;

namespace Fract_ls
{

    class Fract
    {
        int _ch;
        int _zn;

        public Fract(int ch = 0, int zn = 1) 
        {
            _ch = ch;
            _zn = zn;
        }

        
        private void Correct()
        {
            int nod = Nod(Math.Abs(_ch), Math.Abs(_zn));
            _ch = _ch / nod;
            _zn = _zn / nod;
        }

        public static int Nod(int a, int b)
        {
            while(a!=b)
            {
                if(a > b) { a -= b; }
                if(b > a) { b -= a; }
            }
            return a;
        }

        public void Parse(string str)
        {
            if (!TryParse(str))
            {
                throw new Exception("There is not /");
            }
        }
        public bool TryParse(string str)
        {
            int slash = str.IndexOf("/");
            if(slash == -1)
            {
                return false;
            }

            string ch_str = "";
            for(int i = 0; i < slash; i++)
            {
                ch_str += str[i];
            }

            string zn_str = "";
            for (int i = slash + 1; i < str.Length; i++)
            {
                zn_str += str[i];
            }

            _ch = Convert.ToInt32(ch_str);
            _zn = Convert.ToInt32(zn_str);

            return true;   
        }

        public static Fract operator +(Fract a, Fract b)
        {
            return new Fract(a._ch * b._zn + b._ch * a._zn, a._zn * b._zn);
        }
        public static Fract operator -(Fract a, Fract b)
        {
            return new Fract(a._ch * b._zn - b._ch * a._zn, a._zn * b._zn);
        }
        public static Fract operator *(Fract a, Fract b)
        {
            return new Fract(a._ch * b._ch, a._zn * b._zn);
        }
        public static Fract operator /(Fract a, Fract b)
        {
            return new Fract(a._ch * b._zn, a._zn * b._ch);
        }

        public override string ToString()
        {
            Correct();
            return $"{_ch}/{_zn}";
        }

        public static Fract operator -(Fract a)
        {
            return new Fract(-a._ch, a._zn);
        }
        public static bool operator ==(Fract a, Fract b)
        {
            return a._ch * b._zn == b._ch * a._zn;
        }
        public static bool operator !=(Fract a, Fract b)
        {
            return a._ch * b._zn != b._ch * a._zn;
        }

        public static bool operator <(Fract a, Fract b)
        {
            return a._ch * b._zn < b._ch * a._zn;
        }
        public static bool operator >(Fract a, Fract b)
        {
            return a._ch * b._zn > b._ch * a._zn;
        }
        public static bool operator <=(Fract a, Fract b)
        {
            return a._ch * b._zn <= b._ch * a._zn;
        }
        public static bool operator >=(Fract a, Fract b)
        {
            return a._ch * b._zn >= b._ch * a._zn;
        }
        public static bool operator true(Fract a)
        {
            return a._ch != 0;
        }
        public static bool operator false(Fract a)
        {
            return a._ch == 0;
        }
        public static Fract operator ++(Fract a)
        {
            return new Fract(a._ch + 1, a._zn);
        }
        public static Fract operator --(Fract a)
        {
            return new Fract(a._ch - 1, a._zn);
        }
        public int this[int index]
        {
           get
            {
                if(index == 0) { return _ch; }
                if(index == 1) { return _zn; }
                throw new IndexOutOfRangeException("Index must be 1 or 0");
            }
            set
            {
                if (index == 0) { _ch = value; }
                if (index == 1) { _zn = value; }
               // throw new IndexOutOfRangeException("Index must be 1 or 0");
            }
        }

        public static explicit operator int(Fract a)
        {
            return a._ch / a._zn;
        }

        public static implicit operator double(Fract a)
        {
            return a._ch / (double)a._zn;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            UI app = new UI();
            // app.Start();

            Fract fract1 = new Fract();
            try
            {
                string str = Console.ReadLine();
                fract1.Parse(str);
                Console.WriteLine(fract1.ToString());
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
