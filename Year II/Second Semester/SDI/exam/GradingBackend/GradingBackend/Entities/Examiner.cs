using System.ComponentModel.DataAnnotations;

namespace GradingBackend.Entities;

public class Examiner
{
    [Key]
    public int Id { get; set; }
    public string Name { get; set; } = string.Empty;
}