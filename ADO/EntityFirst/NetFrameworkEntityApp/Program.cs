using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NetFrameworkEntityApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StationeryFirmEntities db = new StationeryFirmEntities();   

            db.BuyerFirms.Add(new BuyerFirm { Name="Jojojo"});
        }
    }
}
