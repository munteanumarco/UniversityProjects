using GradingBackend.Contexts;
using GradingBackend.Entities;
using GradingBackend.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace GradingBackend.Controllers;

[ApiController]
[Route("examination")]
public class ExaminationController : ControllerBase
{
    private readonly ExamContext _context;
    
    public ExaminationController(ExamContext context)
    {
        _context = context;
    }

    [HttpPost]
    public async Task<ActionResult<Examination>> AddExamination(ExaminationAddDto examination)
    {
        Random rnd = new Random();
        var examEntity = new Examination()
        {
            Id = rnd.Next(0, 999999),
            Title = examination.Title,
            FirstExaminer = examination.FirstExaminer,
            SecondExaminer = examination.SecondExaminer,
            ThirdExaminer = examination.ThirdExaminer,
        };
        
        _context.Examinations.Add(examEntity);
        await _context.SaveChangesAsync();

        return Ok(examEntity);
    }

    [HttpGet("{id}")]
    public async Task<ActionResult<Examination>> GetExamination(int id)
    {
        var examination = await _context.Examinations.FirstOrDefaultAsync(e => e.Id == id);
        if (examination == null)
        {
            return NotFound();
        }

        return Ok(examination);
    }
    
    [HttpGet("{id}/include-ids")]
    public async Task<ActionResult<ExaminationWithIds>> GetExaminationWithIds(int id)
    {
        var examination = await _context.Examinations.FirstOrDefaultAsync(e => e.Id == id);
        if (examination == null)
        {
            return NotFound();
        }

        var exWithID = new ExaminationWithIds()
        {
            Id = examination.Id,
            Title = examination.Title,
            FirstExaminer = examination.FirstExaminer,
            SecondExaminer = examination.SecondExaminer,
            ThirdExaminer = examination.ThirdExaminer,
            FirstId = GetExId(examination.FirstExaminer),
            SecondId = GetExId(examination.SecondExaminer),
            ThirdId = GetExId(examination.ThirdExaminer)
        };

        return Ok(exWithID);
    }

    private int GetExId(string name)
    {
        return _context.Examiners.FirstOrDefault(e => e.Name == name).Id;
    }

    [HttpGet]
    public async Task<ActionResult<IEnumerable<Examination>>> GetExaminations()
    {
        return await _context.Examinations.ToListAsync();
    }

    [HttpGet("live")]
    public ActionResult Up()
    {
        return Ok(new {status = "up"});
    }
}