using Cars.Entities;

namespace Cars.Models
{
    /// <summary>
    /// Cars ordered by the number of authors that reviewd them?
    /// </summary>
    public class StatisticalReportAuthors
    {
        public int Id { get; set; }
        public string? Model { get; set; }
        public string? Manufacturer { get; set; }
        public string? Color { get; set; }
        public int FabricationYear { get; set; }
        public int NoOfAuthors { get; set; }
    }
}
