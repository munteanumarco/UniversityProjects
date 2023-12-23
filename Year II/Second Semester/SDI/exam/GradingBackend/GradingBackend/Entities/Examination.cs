using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace GradingBackend.Entities;

public class Examination
{
    [Key]
    public int Id { get; set; }
    public string Title { get; set; } = string.Empty;
    public string FirstExaminer { get; set; } = string.Empty;
    public string SecondExaminer { get; set; } = string.Empty;
    public string ThirdExaminer { get; set; } = string.Empty;
}