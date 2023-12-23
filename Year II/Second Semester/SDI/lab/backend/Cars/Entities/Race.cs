using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Cars.Entities
{
    public class Race
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int Id { get; set; }
        public string Name { get; set; }
        public string City { get; set; } = string.Empty;
        public string Country { get; set; }
        public ICollection<Car> Cars { get; set; } = new List<Car>();

        public Race(string Name, string Country) 
        {
            this.Name = Name;   
            this.Country = Country;
        }
    }
}
