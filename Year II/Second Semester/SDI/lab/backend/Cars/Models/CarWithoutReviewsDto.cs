namespace Cars.Models
{
    public class CarWithoutReviewsDto
    {
        public int Id { get; set; }
        public string? Model { get; set; }
        public string? Manufacturer { get; set; }
        public string? Color { get; set; }
        public int FabricationYear { get; set; }
    }
}
