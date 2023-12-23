namespace GradingBackend.Models;

public class ExaminationWithIds
{
    public int Id { get; set; }
    public string Title { get; set; } = string.Empty;
    public string FirstExaminer { get; set; } = string.Empty;
    public string SecondExaminer { get; set; } = string.Empty;
    public string ThirdExaminer { get; set; } = string.Empty;
    public int FirstId { get; set; }
    public int SecondId { get; set; }
    public int ThirdId { get; set; }
}