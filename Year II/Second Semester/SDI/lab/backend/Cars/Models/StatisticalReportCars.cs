namespace Cars.Models
{
    public class StatisticalReportCars /// all cars ordered by the average of their reviews score
    {
        public int Id { get; set; }
        public string? Model { get; set; }
        public string? Manufacturer { get; set; }
        public string? Color { get; set; }
        public int FabricationYear { get; set; }
        public float AverageReviewScore { get; set; } 
    }
}
