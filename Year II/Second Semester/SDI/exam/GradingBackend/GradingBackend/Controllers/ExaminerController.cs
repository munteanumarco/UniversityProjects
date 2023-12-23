using GradingBackend.Contexts;
using GradingBackend.Entities;
using GradingBackend.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace GradingBackend.Controllers;

[ApiController]
[Route("examiner")]
public class ExaminerController : ControllerBase
{
    private readonly ExamContext _context;
    
    public ExaminerController(ExamContext context)
    {
        _context = context;
    }

    [HttpGet("{id}")]
    public async Task<ActionResult<Examiner>> GetExaminer(int id)
    {
        var examiner = await _context.Examiners.FirstOrDefaultAsync(e => e.Id == id);
        if (examiner == null)
        {
            return NotFound();
        }

        return Ok(examiner);
    }

    [HttpPost]
    public async Task<ActionResult<Examiner>> AddExaminer(ExaminerAddDto examiner)
    {
        Random rnd = new Random();
        var examinerEntity = new Examiner()
        {
            Id = rnd.Next(0, 999999),
            Name = examiner.Name
        };
        
        _context.Examiners.Add(examinerEntity);
        await _context.SaveChangesAsync();

        return Ok(examinerEntity);
    }
    
}