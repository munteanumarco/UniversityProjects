using System.ComponentModel.DataAnnotations;

namespace Cars.Models
{
    public class AuthorForUpdateDto
    {
        [RegularExpression(@"^[a-zA-Z]+$", ErrorMessage = "Use letters only please")]
        public string FirstName { get; set; } = string.Empty;

        [RegularExpression(@"^[a-zA-Z]+$", ErrorMessage = "Use letters only please")]
        public string LastName { get; set; } = string.Empty;

        [EmailAddress(ErrorMessage = "Invalid email address")]
        public string Email { get; set; } = string.Empty;
        public string Phone { get; set; } = string.Empty;
    }
}
