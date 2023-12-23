using Microsoft.EntityFrameworkCore;
using WebApplication1.Entities;

namespace WebApplication1.DbContexts;

public class ManagementContext : DbContext
{
    public DbSet<Course> Courses { get; set; }
    public DbSet<User> Users { get; set; }
    public DbSet<Student> Students { get; set; }
    public DbSet<Professor> Professors { get; set; }
    public DbSet<Catalog> Catalogs { get; set; }
    public DbSet<ProfessorCourseGroup> Managements { get; set; }

    public ManagementContext(DbContextOptions<ManagementContext> options) : base(options)
    {
    }
    
    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        
    }
    
}