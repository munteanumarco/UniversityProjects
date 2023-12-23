using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Cars.Entities
{
    public class Review
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int Id { get; set; }
        public string Title { get; set; }
        public string Description { get; set; }
        public int Score { get; set; }
        public DateTime Date { get; set; }

        [ForeignKey("CarId")]
        public Car? Car { get; set; }
        public int CarId { get; set; }

        [ForeignKey("AuthorId")]
        public Author? Author { get; set; }
        public int AuthorId { get; set; }

        public Review(string title, string description)
        {
            Title = title;
            Description = description;
        }
    }
}
