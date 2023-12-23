using AutoMapper;
using WebApplication1.Repositories;
using Microsoft.AspNetCore.Mvc;


namespace WebApplication1.Controllers;

[ApiController]
[Route("api/courses")]
public class CourseController : ControllerBase
{
    private readonly ICourseRepository _courseRepository;
    private readonly IMapper _mapper;

    public CourseController(ICourseRepository courseRepository, IMapper mapper)
    {
        _courseRepository = courseRepository;
        _mapper = mapper;
    }

    [HttpGet]
    public IActionResult HelloWorld()
    {
        return Ok("Hello, World!");
    }
}