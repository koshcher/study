using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StoreDbLibrary.Models
{
    public class AppCategory
    {
        public int Id { get; set; }

        public int AppId { get; set; }
        public virtual App App { get; set; }

        public int CategoryId { get; set; }
        public virtual Category Category { get; set; }
    }
}
