using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WebApplication1.DbContexts;
using WebApplication1.Entities;
using WebApplication1.Models;

namespace WebApplication1.Controllers;

[Authorize(Roles = "Professor")]
[ApiController]
[Route("api/professors")]
public class ProfessorController : ControllerBase
{
    private readonly ManagementContext _context;

    public ProfessorController(ManagementContext context)
    {
        _context = context;
    }

    [HttpGet("groups")]
    public async Task<ActionResult> GetGroups(int id)
    {
        var professorCourseGroups = await _context.Managements
            .Include(pcg => pcg.Course)
            .Include(pcg => pcg.Professor)
            .Where(pcg => pcg.Professor.UserId == id)
            .ToListAsync();

        if (professorCourseGroups == null)
        {
            return NotFound();
        }

        var result = professorCourseGroups.Select(pcg => new CourseModel
        {
            CourseId = pcg.Course.Id,
            CourseName = pcg.Course.Name,
            Group = pcg.FacultyGroup
        }).ToList();

        return Ok(result);
    }

    [HttpGet("student-groups")]
    public async Task<ActionResult<IEnumerable<StudentFromGroup>>> GetStudentFromGroups(int groupId, int courseId)
    {
        var students = await _context.Students
            .Where(s => s.FacultyGroup == groupId)
            .ToListAsync();

        var result = new List<StudentFromGroup>();

        foreach (var student in students)
        {
            var catalog = await _context.Catalogs
                .FirstOrDefaultAsync(c => c.CourseId == courseId && c.StudentId == student.StudentId);

            int grade = 0;

            if (catalog != null)
            {
                grade = catalog.Grade;
            }

            var ent = new StudentFromGroup
            {
                FirstName = student.FirstName,
                LastName = student.LastName,
                Grade = grade,
                StudentId = student.StudentId
            };

            result.Add(ent);
        }

        return Ok(result);
    }

    [HttpGet("grade")]
    public async Task<ActionResult> GradeStudent(int studentId, int courseId, int grade, bool alreadyGraded)
    {
        if (alreadyGraded)
        {
            var catalog = await _context.Catalogs
                .FirstOrDefaultAsync(c => c.StudentId == studentId && c.CourseId == courseId);
            catalog.Grade = grade;
            await _context.SaveChangesAsync();

        }
        else
        {
            var newCatalogEntry = new Catalog
            {
                StudentId = studentId,
                CourseId = courseId,
                Grade = grade
            };

            _context.Catalogs.Add(newCatalogEntry);
            await _context.SaveChangesAsync();
        }

        return Ok();
    }

    [HttpGet("remove-grade")]
    public async Task<ActionResult> RemoveGradeStudent(int studentId, int courseId)
    {
        var catalog = await _context.Catalogs
            .FirstOrDefaultAsync(c => c.StudentId == studentId && c.CourseId == courseId);

        _context.Catalogs.Remove(catalog);
        await _context.SaveChangesAsync();

        return Ok();
    }

    [HttpGet("available-courses")]
    public async Task<ActionResult<IEnumerable<AvCourse>>> GetAvailableCourses()
    {
        var courses = await _context.Courses.ToListAsync();

        var avCourses = courses.Select(course => new AvCourse
        {
            CourseId = course.Id,
            CourseName = course.Name
        });

        return Ok(avCourses);
    }
    
    [HttpGet("available-groups")]
    public async Task<ActionResult<IEnumerable<AvGroup>>> GetAvailableGroups()
    {
        var facultyGroups = await _context.Students
            .Select(s => s.FacultyGroup)
            .Distinct()
            .ToListAsync(); 
        
        var avGroups = facultyGroups.Select(group => new AvGroup
        {
            FacultyGroup = group
        }).ToList();

        return Ok(avGroups);
    }

    private async Task<int> FindProfessorId(int userId)
    {
        var professor = await _context.Professors
            .FirstOrDefaultAsync(p => p.UserId == userId);

        return professor.ProfessorId;
    }
    
    [HttpGet("add-group")]
    public async Task<ActionResult> AddGroupToProfessor(int group, int course, int id)
    {
        int profId = await FindProfessorId(id);
        var ent = new ProfessorCourseGroup
        {
            CourseId = course,
            FacultyGroup = group,
            ProfessorId = profId
        };
        _context.Managements.Add(ent);
        await _context.SaveChangesAsync();
        return Ok();
    }
    
    [HttpGet("remove-group")]
    public async Task<ActionResult> RemoveProfFromGroup(int id, int group, int course)
    {
        int profId = await FindProfessorId(id);
        var profGroup = await _context.Managements
            .FirstOrDefaultAsync(
                pcg => pcg.FacultyGroup == group && pcg.CourseId == course && pcg.ProfessorId == profId);
        _context.Managements.Remove(profGroup);
        await _context.SaveChangesAsync();
        return Ok();
    }

}