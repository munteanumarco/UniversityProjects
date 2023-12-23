using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace WebApplication1.Entities;

public class Catalog
{
    [Key]
    [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
    public int GradeId { get; set; }
    
    [ForeignKey("StudentId")]
    public Student? Student { get; set; }
    public int StudentId { get; set; }
    
    [ForeignKey("CourseId")]
    public Course? Course { get; set; }
    public int CourseId { get; set; }
    
    public int Grade { get; set; }
    
}