using System.ComponentModel.DataAnnotations.Schema;

namespace ModelsLibrary
{
    public class Game
    {
        public int Id { get; set; }
        public string Title { get; set; }
        public string Studio { get; set; }
        public string Genre { get; set; }

        [Column(TypeName = "Date")]
        public DateTime ReleaseDate { get; set; }

        public bool IsMultiplayer { get; set; }
        public int SoldCopiesCount { get; set; }
    }
}