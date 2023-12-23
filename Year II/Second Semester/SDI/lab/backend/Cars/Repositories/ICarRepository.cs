using Cars.Entities;
using Cars.Models;

namespace Cars.Repositories
{
    public interface ICarRepository
    {
        Task<IEnumerable<Car>> GetCarsAsync();
        Task<IEnumerable<Car>> GetCarsReviewsAsync();
        Task<Car?> GetCarAsync(int id);
        Task<Author?> GetAuthorAsync(int id);
        Task<Race?> GetRaceAsync(int id);
        Task<IEnumerable<Review>> GetReviewsAsync();
        Task<IEnumerable<Author>> GetAuthorsAsync();
        Task<IEnumerable<Race>> GetRacesAsync();
        void AddCar(Car car);
        void AddAuthor(Author author);
        void AddRace(Race race);
        void DeleteCar(Car car);
        void DeleteRace(Race race);
        void DeleteAuthor(Author author);
        void AddCarToRace(Race race, Car car);
        void AddRaceToCar(Car car, Race race);
        Task<bool> SaveChangesAsync();
        Task<bool> CarExistsAsync(int carId);
        Task<bool> AuthorExistsAsync(int authorId);
        Task<Review?> GetReviewAsync(int reviewId);
        void AddReview(Review review);
        void AddReviewToCar(Car car, Review review);
        void DeleteReview(Review review);
    }
}
