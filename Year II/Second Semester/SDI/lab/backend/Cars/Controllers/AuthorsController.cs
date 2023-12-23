using AutoMapper;
using Cars.Entities;
using Cars.Models;
using Cars.Repositories;
using Microsoft.AspNetCore.Mvc;

namespace Cars.Controllers
{
    [ApiController]
    [Route("api/authors")]
    public class AuthorsController : ControllerBase
    {
        private readonly ICarRepository _carRepository;
        private readonly IMapper _mapper;

        public AuthorsController(ICarRepository carRepository, IMapper mapper) 
        {
            _carRepository = carRepository ?? throw new ArgumentNullException(nameof(carRepository));
            _mapper = mapper ?? throw new ArgumentNullException(nameof(mapper));
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<AuthorWithoutReviewsDto>>> GetAuthors()
        {
            var authors = await _carRepository.GetAuthorsAsync();
            return Ok(_mapper.Map<IEnumerable<AuthorWithoutReviewsDto>>(authors));
        }

        [HttpGet("{id}", Name = "GetAuthor")]
        public async Task<ActionResult<AuthorDto?>> GetAuthor(int id)
        {
            var author = await _carRepository.GetAuthorAsync(id);

            if (author == null)
            {
                return NotFound();
            }

            return Ok(_mapper.Map<AuthorDto>(author));

        }

        [HttpPost]
        public async Task<ActionResult<AuthorDto>> CreateAuthor(AuthorForCreationDto author)
        {
            var authorEntity = _mapper.Map<Author>(author);
            
            _carRepository.AddAuthor(authorEntity); 

            await _carRepository.SaveChangesAsync();

            var authorToReturn = _mapper.Map<AuthorDto>(authorEntity);

            return CreatedAtRoute("GetAuthor", new { id = authorToReturn.Id }, authorToReturn);

        }

        [HttpDelete("{id}")]
        public async Task<ActionResult> DeleteAuthor(int id)
        {
            var author = await _carRepository.GetAuthorAsync(id);

            if (author == null)
            {
                return NotFound();
            }

            _carRepository.DeleteAuthor(author);

            await _carRepository.SaveChangesAsync();

            return NoContent();
        }

        [HttpPut("{id}")]
        public async Task<ActionResult> UpdateAuthor(int id, AuthorForUpdateDto newAuthor)
        {
            var author = await _carRepository.GetAuthorAsync(id);
            
            if (author == null) 
            {
                return NotFound(); 
            }

            _mapper.Map(newAuthor, author);

            await _carRepository.SaveChangesAsync();

            return NoContent();

        }

    }
}
