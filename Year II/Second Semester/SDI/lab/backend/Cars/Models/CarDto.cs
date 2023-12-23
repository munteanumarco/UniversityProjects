using Cars.Entities;

namespace Cars.Models
{
    public class CarDto
    {
        public int Id { get; set; }
        public string? Model { get; set; }
        public string? Manufacturer { get; set; }
        public string? Color { get; set; }
        public int FabricationYear { get; set; }
        public int NumberOfReviews 
        {
            get
            {
                return Reviews.Count;
            }
        }
        public ICollection<ReviewDto> Reviews { get; set; } = new List<ReviewDto>();
        public ICollection<RaceWithoutCarsDto> Races { get; set; } = new List<RaceWithoutCarsDto>();
    }
}
