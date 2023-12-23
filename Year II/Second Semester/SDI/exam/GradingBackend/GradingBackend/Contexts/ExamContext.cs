using GradingBackend.Entities;
using Microsoft.EntityFrameworkCore;

namespace GradingBackend.Contexts;

public class ExamContext : DbContext
{
    public ExamContext(DbContextOptions<ExamContext> options)
        : base(options)
    {
    }
    
    public DbSet<Examination> Examinations { get; set; }
    public DbSet<Examiner> Examiners { get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        
    }
    
}