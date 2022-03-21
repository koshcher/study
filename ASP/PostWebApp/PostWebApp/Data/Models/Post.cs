using System.ComponentModel.DataAnnotations;

namespace PostWebApp.Data.Models
{
    public class Post
    {
        [Key]
        public int Id { get; set; }
        public string Title { get; set; }
        public string Text { get; set; }
        public DateTime CreatedDateTime { get; set; } = DateTime.Now;
        public string Creator { get; set; }
    }
}
