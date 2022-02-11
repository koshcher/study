using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OlympicsCoreAppHandyControl.Models
{
    public class Result
    {
        public int Id { get; set; }

        public int OlympiadId { get; set; }
        public virtual Olympiad Olympiad { get; set; }

        public int Participantd { get; set; }
        public virtual Participant Participant { get; set; }

        public int Place { get; set; }

        public int Sporttd { get; set; }
        public virtual Sport Sport { get; set; }
    }
}
