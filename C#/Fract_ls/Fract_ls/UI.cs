using System;
using System.Collections.Generic;
using System.Text;

namespace Fract_ls
{
    class UI
    {
        Fract fract1;
        Fract fract2;

        public UI()
        {
            fract1 = new Fract();
            fract2 = new Fract();
        }

        public void InputFract()
        {
            Console.WriteLine("Enter ch of 1 fract");
            fract1[0] = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter zn of 1 fract");
            fract1[1] = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Enter ch of 2 fract");
            fract2[0] = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter zn of 2 fract");
            fract2[1] = Convert.ToInt32(Console.ReadLine());
        }

        public void Start()
        {
            int i = -1;
            while(i != 0)
            {
                InputFract();
                Console.WriteLine("Choose function:");
                Console.WriteLine("[1] +");
                Console.WriteLine("[2] -");
                Console.WriteLine("[3] /");
                Console.WriteLine("[4] *");
                Console.WriteLine("[5] compare");

                try 
                {
                    i = Convert.ToInt32(Console.ReadLine());
                    switch (i)
                    {
                        case 1:
                            Console.WriteLine((fract1 + fract2).ToString());
                            break;
                        case 2:
                            Console.WriteLine((fract1 - fract2).ToString());
                            break;
                        case 3:
                            Console.WriteLine((fract1 / fract2).ToString());
                            break;
                        case 4:
                            Console.WriteLine((fract1 * fract2).ToString());
                            break;
                        case 5:
                            if(fract1 > fract2)
                            {
                                Console.WriteLine(fract1.ToString() + " > " + fract2.ToString());
                            } 
                            else if(fract1 == fract2)
                            {
                                Console.WriteLine(fract1.ToString() + " = " + fract2.ToString());
                            } 
                            else
                            {
                                Console.WriteLine(fract1.ToString() + " < " + fract2.ToString());
                            }
                            break;
                        default:
                            i = 0;
                            break;
                    }
                }
                catch(Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
             
            }
        }
    }
}
