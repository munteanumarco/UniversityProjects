using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Text;
using AutoMapper;
using Microsoft.AspNetCore.Mvc;
using Microsoft.IdentityModel.Tokens;
using WebApplication1.DbContexts;
using WebApplication1.Entities;
using WebApplication1.Models;
using WebApplication1.Repositories;
using JwtRegisteredClaimNames = Microsoft.IdentityModel.JsonWebTokens.JwtRegisteredClaimNames;

namespace WebApplication1.Controllers;

[ApiController]
[Route("api/auth")]
public class AuthController : ControllerBase
{

    private readonly ManagementContext _context;
    private readonly IMapper _mapper;
    
    public AuthController(ManagementContext context, IMapper mapper)
    {
        _context = context;
        _mapper = mapper;
    }
    
    
    [HttpPost("login")]
    public IActionResult Login([FromBody] LoginModel login)
    {
        IActionResult response = Unauthorized();

        var user = AuthenticateUser(login);

        if (user != null)
        {
            var tokenString = GenerateJSONWebToken(user);
            response = Ok(new { token = tokenString });
        }

        return response;
    }
    
    private string GenerateJSONWebToken(User userInfo)
    {
        var securityKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes("mysecretkey"));

        var claims = new[]
        {
            new Claim(JwtRegisteredClaimNames.Sub, userInfo.Username),
            new Claim(ClaimTypes.Role, userInfo.UserRole),
            new Claim("role", userInfo.UserRole),
            new Claim("user_id", userInfo.Id.ToString()),
            new Claim(JwtRegisteredClaimNames.Jti, Guid.NewGuid().ToString())
        };

        var token = new JwtSecurityToken(
            "marco",
            "managers",
            claims,
            expires: DateTime.Now.AddDays(1));

        return new JwtSecurityTokenHandler().WriteToken(token);
    }
    
    private User AuthenticateUser(LoginModel login)
    {
        return _context.Users.FirstOrDefault(u => u.Username == login.Username && u.Password == login.Password);
    }
}