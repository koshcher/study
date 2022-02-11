using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;

namespace OlympicsCoreAppHandyControl
{
    class OlympicsDbContext : DbContext
    {
        public OlympicsDbContext()
        {
        }

        public OlympicsDbContext(DbContextOptions<OlympicsDbContext> options) : base(options)
        {
        }

        DbSet<Models.Country> Countries { get; set; }
        DbSet<Models.Olympiad> Olympiads { get; set; }
        DbSet<Models.Participant> Participants { get; set; }
        DbSet<Models.Result> Results { get; set; }
        DbSet<Models.Sport> Sports { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if(!optionsBuilder.IsConfigured)
            {
                optionsBuilder.UseSqlServer("Data Source=sqland.database.windows.net;Initial Catalog=OlympicsDB;Persist Security Info=True;User ID=sqlander;Password=5ql@nder");
            }
        }
    }
}
