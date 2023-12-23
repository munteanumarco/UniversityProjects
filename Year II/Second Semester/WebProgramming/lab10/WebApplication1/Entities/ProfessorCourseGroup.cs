using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace WebApplication1.Entities;

public class ProfessorCourseGroup
{
    [ForeignKey("ProfessorId")]
    public Professor? Professor { get; set; }
    public int ProfessorId { get; set; }
    
    [Key]
    [ForeignKey("CourseId")]
    public Course? Course { get; set; }
    public int CourseId { get; set; }
    
    [Key]
    public int FacultyGroup { get; set; }
}