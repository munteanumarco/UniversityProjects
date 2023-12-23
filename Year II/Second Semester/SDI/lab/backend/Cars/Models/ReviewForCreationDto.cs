using System.ComponentModel.DataAnnotations;

namespace Cars.Models
{
    public class ReviewForCreationDto
    {
        public string Title { get; set; } = string.Empty;
        public string Description { get; set; } = string.Empty;

        [Range(0, 10)]
        public int Score { get; set; }
        public int AuthorId { get; set; }
        public int CarId { get; set; }
        public DateTime Date { get; set; }
    }
}
