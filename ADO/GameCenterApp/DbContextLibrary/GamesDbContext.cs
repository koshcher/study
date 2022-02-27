using Microsoft.EntityFrameworkCore;
using ModelsLibrary;

namespace DbContextLibrary
{
    public class GamesDbContext : DbContext
    {
        public GamesDbContext()
        {
        }

        public GamesDbContext(DbContextOptions<GamesDbContext> options) : base(options)
        {
        }

        public DbSet<Game> Games { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
                optionsBuilder.UseSqlServer("Data Source=sqland.database.windows.net;Initial Catalog=GamesDb;Persist Security Info=True;User ID=sqlander;Password=5ql@nder");
            }
        }
    }
}