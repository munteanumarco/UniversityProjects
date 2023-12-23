namespace Cars.Models
{
    public class ReviewDto
    {
        public int Id { get; set; }
        public string Title { get; set; } = string.Empty;
        public string Description { get; set; } = string.Empty; 
        public int Score { get; set; }
        public DateTime Date { get; set; }
        public int CarId { get; set; }
        public int AuthorId { get; set; }


    }
}
