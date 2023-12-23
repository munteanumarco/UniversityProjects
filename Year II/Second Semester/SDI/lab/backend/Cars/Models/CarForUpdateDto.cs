namespace Cars.Models
{
    public class CarForUpdateDto
    {
        public string? Model { get; set; }
        public string? Manufacturer { get; set; }
        public string? Color { get; set; }
        public int FabricationYear { get; set; }
    }
}
