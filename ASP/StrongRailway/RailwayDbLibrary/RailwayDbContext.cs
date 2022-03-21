using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using RailwayDbLibrary.Models;
using Pomelo.EntityFrameworkCore.MySql;

namespace RailwayDbLibrary
{
    public class RailwayDbContext : DbContext
    {
        public RailwayDbContext()
        {
        }

        public RailwayDbContext(DbContextOptions<RailwayDbContext> options) : base(options)
        {
        }

        public DbSet<Station> Stations { get; set; }   

        /*
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
               // optionsBuilder.UseMySQL();
              //  optionsBuilder.UseSqlServer("Data Source=sqland.database.windows.net;Initial Catalog=StoreDb;Persist Security Info=True;User ID=sqlander;Password=5ql@nder");
            }
        }
        */
    }
}
