using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OlympicsCoreAppHandyControl.Models
{
    public class Olympiad
    {
        public int Id { get; set; }

        public int Year { get; set; }

        public bool IsSummer { get; set; }

        public int CountryId { get; set; }
        public virtual Country Country { get; set; }

        public string City { get; set; }

        public virtual ICollection<Result> Results { get; set; }
    }
}
