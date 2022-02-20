using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StoreDbLibrary.Models
{
    public class Category
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public bool IsForGame { get; set; }

        public virtual ICollection<AppCategory> AppCategories { get; set; }
    }
}
