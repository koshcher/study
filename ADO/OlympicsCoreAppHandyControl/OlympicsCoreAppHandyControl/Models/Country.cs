using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OlympicsCoreAppHandyControl.Models
{
    public class Country
    {
        public int Id { get; set; }

        public string Name { get; set; }

        public virtual ICollection<Participant> Participants { get; set; }

        public virtual ICollection<Olympiad> Olympiads { get; set; }
    }
}
