using Microsoft.EntityFrameworkCore;
using PostWebApp.Data.Models;

namespace PostWebApp.Data
{
    public class PostsDbContext : DbContext
    {
        public PostsDbContext()
        {
        }

        public PostsDbContext(DbContextOptions options) : base(options)
        {
        }

        DbSet<Post> Posts { get; set; }
    }
}
