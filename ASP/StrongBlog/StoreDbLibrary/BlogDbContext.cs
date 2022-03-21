using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using BlogDbLibrary.Models;

namespace BlogDbLibrary
{
    public class BlogDbContext : DbContext
    {
        public BlogDbContext(DbContextOptions options) : base(options)
        {
        }

        public BlogDbContext()
        {
        }

        public DbSet<Post> Posts { get; set; }
    }
}

