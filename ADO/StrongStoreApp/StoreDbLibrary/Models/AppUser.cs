using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StoreDbLibrary.Models
{
    public class AppUser
    {
        public int Id { get; set; }

        public int AppId { get; set; }
        public virtual App App { get; set; }

        public int UserId { get; set; }
        public virtual User User { get; set; }
    }
}
