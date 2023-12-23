namespace GradingBackend.Models;

public class ExaminationAddDto
{
    public string Title { get; set; } = string.Empty;
    public string FirstExaminer { get; set; } = string.Empty;
    public string SecondExaminer { get; set; } = string.Empty;
    public string ThirdExaminer { get; set; } = string.Empty;
}