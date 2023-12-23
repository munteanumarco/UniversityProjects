using System.Text;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using WebApplication1.DbContexts;
using WebApplication1.Entities;
using WebApplication1.Repositories;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllers(options =>
    options.ReturnHttpNotAcceptable = true);

builder.Services.AddEndpointsApiExplorer();

builder.Services.AddSwaggerGen();

builder.Services.AddCors(options =>
{
    options.AddPolicy("CorsPolicy",
        builder => builder.WithOrigins("http://localhost:4200") // Replace with the Angular app's domain
            .AllowAnyMethod()
            .AllowAnyHeader()
            .AllowCredentials());
});

builder.Services.AddDbContext<ManagementContext>(
    options => options.UseNpgsql("Server=localhost;Database=coursemgmt;Port=5432;User Id=marcomunteanu;Password=carp04"));

builder.Services.AddScoped<ICourseRepository, CourseRepository>();
builder.Services.AddAutoMapper(AppDomain.CurrentDomain.GetAssemblies());

builder.Services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
    .AddJwtBearer(options =>
    {
        options.TokenValidationParameters = new TokenValidationParameters
        {
            ValidIssuer = "marco",
            ValidAudience = "managers",
            IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes("mysecretkey")),
        };
    });

builder.Services.AddAuthorization(options =>
{
    options.AddPolicy("ProfessorPolicy", policy =>
    {
        policy.RequireRole("professor");
    });
});

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.UseCors("CorsPolicy");

app.UseAuthentication();

app.UseAuthorization();

app.MapControllers();

app.Run();