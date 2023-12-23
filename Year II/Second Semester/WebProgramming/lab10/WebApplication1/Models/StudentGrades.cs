namespace WebApplication1.Models;

public class StudentGrades
{
    public int CourseId { get; set; }
    public string Name { get; set; } = string.Empty;
    public int Credits { get; set; }
    public int Grade { get; set; }
}