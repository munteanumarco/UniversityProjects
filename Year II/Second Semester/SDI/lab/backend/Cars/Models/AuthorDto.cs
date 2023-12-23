namespace Cars.Models
{
    public class AuthorDto
    {
        public int Id { get; set; }
        public string FirstName { get; set; } = string.Empty;
        public string LastName { get; set; } = string.Empty;
        public string Email { get; set; } = string.Empty;
        public string Phone { get; set; } = string.Empty;

        public ICollection<ReviewDto> Reviews { get; set; } = new List<ReviewDto>();
    }
}
