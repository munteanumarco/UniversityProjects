using AutoMapper;
using Cars.Entities;
using Cars.Models;
using Cars.Repositories;
using Microsoft.AspNetCore.Mvc;


namespace Cars.Controllers
{
    [Route("api/reviews")]
    [ApiController]
    public class ReviewsController : ControllerBase
    {
        private readonly ICarRepository _repository;
        private readonly IMapper _mapper;

        public ReviewsController(ICarRepository repository, IMapper mapper) 
        {
            _repository = repository ?? throw new ArgumentNullException(nameof(repository));
            _mapper = mapper ?? throw new ArgumentNullException(nameof(mapper));
         }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<ReviewDto>>> GetReviews(int? threshold)
        {
            var reviews = await _repository.GetReviewsAsync();

            if (threshold != null)
            {
                var filteredReviews = reviews.Where(r => r.Score > threshold).ToList();
                return Ok(_mapper.Map<IEnumerable<ReviewDto>>(filteredReviews)); 
            }
            return Ok(_mapper.Map<IEnumerable<ReviewDto>>(reviews));
        }

        [HttpGet("{reviewId}", Name = "GetReview")]
        public async Task<ActionResult<ReviewDto>> GetReview(int reviewId)
        {
            
            var reviewForCar = await _repository.GetReviewAsync(reviewId);

            if (reviewForCar == null)
            {
                return NotFound();
            }

            return Ok(_mapper.Map<ReviewDto>(reviewForCar));
        }

        [HttpPost]
        public async Task<ActionResult<ReviewDto>> CreateReview(ReviewForCreationDto review)
        {
            if (!await _repository.CarExistsAsync(review.CarId))
            {
                return NotFound();
            }

            if (!await _repository.AuthorExistsAsync(review.AuthorId))
            {
                return NotFound();
            }

            var reviewEntity = _mapper.Map<Review>(review);

            _repository.AddReview(reviewEntity);

            await _repository.SaveChangesAsync();

            var createdReviewToReturn = _mapper.Map<ReviewDto>(reviewEntity);

            return CreatedAtRoute("GetReview", new { reviewId = createdReviewToReturn.Id }, createdReviewToReturn);
        }

        [HttpPut("{reviewId}")]
        public async Task<ActionResult> UpdateReview(int reviewId, ReviewForUpdateDto review)
        {
            var reviewEntity = await _repository.GetReviewAsync(reviewId);

            if (reviewEntity == null)
            {
                return NotFound();
            }

            _mapper.Map(review, reviewEntity);

            await _repository.SaveChangesAsync();

            return NoContent();

        }


        [HttpDelete("{reviewId}")]
        public async Task<ActionResult> DeleteReview(int reviewId)
        {
            var reviewEntity = await _repository.GetReviewAsync(reviewId);

            if (reviewEntity == null)
            {
                return NotFound();
            }

            _repository.DeleteReview(reviewEntity);

            await _repository.SaveChangesAsync();

            return NoContent();
        }

    }
}
