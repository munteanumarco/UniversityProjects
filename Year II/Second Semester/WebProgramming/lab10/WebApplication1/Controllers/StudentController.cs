using Microsoft.AspNetCore.Authorization;
using AutoMapper;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WebApplication1.DbContexts;
using WebApplication1.Entities;
using WebApplication1.Models;

namespace WebApplication1.Controllers;

[Authorize(Roles = "Professor, Student")]
[ApiController]
[Route("api/students")]
public class StudentController : ControllerBase
{
    private readonly ManagementContext _context;
    private readonly IMapper _mapper;

    public StudentController(ManagementContext context, IMapper mapper)
    {
        _context = context;
        _mapper = mapper;
    }
    
    [HttpGet("grades")]
    public async Task<ActionResult<StudentGrades>> GetGrades(int id)
    {
        var catalogs = await _context.Catalogs
            .Include(c => c.Course)
            .Where(c => c.StudentId == id)
            .ToListAsync();

        var result = new List<StudentGrades>();

        foreach (var catalog in catalogs)
        {
            var ent = new StudentGrades
            {
                CourseId = catalog.CourseId,
                Name = "Databases",
                Credits = 5,
                Grade = catalog.Grade
            };
            result.Add(ent);
        }

        return Ok(result);
    }

    [HttpGet("profile")]
    public async Task<ActionResult<StudentProfile>> GetProfile(int id)
    {
        var student = await _context.Students
            .FirstOrDefaultAsync(s => s.StudentId == id);

        return Ok(new StudentProfile
        {
            FirstName = student.FirstName,
            LastName = student.LastName,
            Group = student.FacultyGroup
        });

    }
}