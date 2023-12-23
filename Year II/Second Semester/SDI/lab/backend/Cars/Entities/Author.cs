using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Cars.Entities
{
    public class Author
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int Id { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Email { get; set; } = string.Empty;
        public string Phone { get; set; } = string.Empty;
        public ICollection<Review> Reviews { get; set; } = new List<Review>();

        public Author(string firstName, string lastName)
        {
            FirstName = firstName;
            LastName = lastName;
        }
    }
}
