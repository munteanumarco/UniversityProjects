using System.ComponentModel.DataAnnotations;

namespace Cars.Models
{
    public class ReviewForUpdateDto
    {
        public string Title { get; set; } = string.Empty;
        public string Description { get; set; } = string.Empty;

        [Range(0, 10)]
        public int Score { get; set; }
        public DateTime Date { get; set; }
    }
}
