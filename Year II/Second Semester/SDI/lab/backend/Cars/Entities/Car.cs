using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Cars.Entities
{
    public class Car
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int Id { get; set; }
        public string Model { get; set; }
        public string Manufacturer { get; set; }
        public string Color { get; set; } = string.Empty;
        public int FabricationYear { get; set; }

        public ICollection<Review> Reviews { get; set; } = new List<Review>();
        public ICollection<Race> Races { get; set; } = new List<Race>();   
        public Car(string model, string manufacturer)
        {
            this.Model = model;
            this.Manufacturer = manufacturer;
        }
    }
}
