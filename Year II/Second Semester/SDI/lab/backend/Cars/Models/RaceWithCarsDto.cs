using Cars.Entities;

namespace Cars.Models
{
    public class RaceWithCarsDto
    {
        public int Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string City { get; set; } = string.Empty;
        public string Country { get; set; } = string.Empty;

        public ICollection<CarWithoutReviewsDto> Cars { get; set; } = new List<CarWithoutReviewsDto>(); 
    }
}
