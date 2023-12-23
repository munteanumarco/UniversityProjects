using Microsoft.AspNetCore.Mvc;

namespace PersonCourses.Controllers;

public class Test : Controller
{
    // GET
    public IActionResult Index()
    {
        return View();
    }
}