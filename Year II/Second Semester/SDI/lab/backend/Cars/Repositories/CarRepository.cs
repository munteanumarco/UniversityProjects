using Cars.DbContexts;
using Cars.Entities;
using Cars.Models;
using Microsoft.EntityFrameworkCore;

namespace Cars.Repositories
{
    public class CarRepository : ICarRepository
    {
        private readonly CarContext _context;
        public CarRepository(CarContext context)
        {
            _context = context ?? throw new ArgumentNullException(nameof(context));
        }

        public async Task<IEnumerable<Car>> GetCarsAsync()
        {
            return await _context.Cars.ToListAsync();
        }

        public async Task<IEnumerable<Car>> GetCarsReviewsAsync()
        {
            return await _context.Cars
                .Include(c => c.Reviews)
                    .ThenInclude(r => r.Author)
                .ToListAsync();
        }

        public async Task<IEnumerable<Race>> GetRacesAsync()
        {
            return await _context.Races.ToListAsync();
        }

        public async Task<Car?> GetCarAsync(int id)
        {

            return await _context.Cars
            .Include(c => c.Reviews)
            .Include(c => c.Races)
            .Where(c => c.Id == id)
            .FirstOrDefaultAsync();

        }

        public async Task<Race?> GetRaceAsync(int id)
        {
            return await _context.Races
                 .Include(race => race.Cars)
                .Where(race => race.Id == id)
                .FirstOrDefaultAsync();
        }

        public async Task<Author?> GetAuthorAsync(int id)
        {
            return await _context.Authors
                .Include(a => a.Reviews)
                .Where(a => a.Id == id) 
                .FirstOrDefaultAsync();
        }

        public async Task<bool> CarExistsAsync(int carId)
        {
            return await _context.Cars.AnyAsync(c => c.Id == carId);
        }

        public async Task<bool> AuthorExistsAsync(int authorId)
        {
            return await _context.Reviews.AnyAsync(a => a.Id == authorId);
        }
        
        public async Task<IEnumerable<Author>> GetAuthorsAsync()
        {
            return await _context.Authors.ToListAsync();
        }

        public void AddCar(Car car)
        {
            _context.Cars.Add(car);
        }

        public void AddAuthor(Author author)
        {
            _context.Authors.Add(author);   
        }

        public void DeleteAuthor(Author author)
        {
            _context.Authors.Remove(author);
        }

        public void AddRace(Race race)
        {
            _context.Races.Add(race);   
        }

        public void AddCarToRace(Race race, Car car)
        {
            var carExists = race.Cars.FirstOrDefault(c => c.Id == car.Id); 
            if (carExists == null) 
            {
                race.Cars.Add(car);
            }
        }

        public void AddRaceToCar(Car car, Race race)
        {
            car.Races.Add(race);
        }

        public void DeleteCar(Car car)
        {
            _context.Cars.Remove(car);
        }

        public void DeleteRace(Race race)
        {
            _context.Races.Remove(race);
        }

        public async Task<bool> SaveChangesAsync()
        {
            return await _context.SaveChangesAsync() >= 0;
        }

        public async Task<IEnumerable<Review>> GetReviewsAsync()
        {
            return await _context.Reviews.ToListAsync();   
        }

        public async Task<Review?> GetReviewAsync(int reviewId)
        {
            return await _context.Reviews
                .Where(r => r.Id == reviewId)
                .FirstOrDefaultAsync();
        }

        public void AddReview(Review review)
        {
            _context.Reviews.Add(review);
        }

        public void AddReviewToCar(Car car,Review review)
        {
            car.Reviews.Add(review);
        }

        public void DeleteReview(Review review)
        {
            _context.Reviews.Remove(review);
        }
    }
}
