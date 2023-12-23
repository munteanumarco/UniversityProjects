using AutoMapper;
using Cars.Entities;
using Cars.Models;
using Cars.Repositories;
using Microsoft.AspNetCore.Mvc;
using Microsoft.VisualBasic;

namespace Cars.Controllers
{
    [ApiController]
    [Route("api/cars")]
    public class CarsController : ControllerBase
    {

        private readonly ICarRepository _carRepository;
        private readonly IMapper _mapper;

        public CarsController(ICarRepository carRepository,
            IMapper mapper) 
        {
            _carRepository = carRepository ?? throw new ArgumentNullException(nameof(carRepository));
            _mapper = mapper ?? throw new ArgumentNullException(nameof(mapper));
        }
        /// <summary>
        /// Get all the cars from the database
        /// </summary>
        [HttpGet]
        public async Task<IActionResult> GetCars()
        {
            var carEntities = await _carRepository.GetCarsAsync();

            return Ok(_mapper.Map<IEnumerable<CarWithoutReviewsDto>>(carEntities));
        }
        /// <summary>
        /// Get a specific car with its reviews and races
        /// </summary>
        [HttpGet("{id}", Name = "GetCar")]
        public async Task<ActionResult<CarDto>> GetCar(int id)
        {
            var carEntity = await _carRepository.GetCarAsync(id);  

            if (carEntity == null)
            {
                return NotFound();
            }

        
            return Ok(_mapper.Map<CarDto>(carEntity));
           
        }
        [HttpPost]
        public async Task<ActionResult<CarDto>> CreateCar(CarForCreationDto car)
        {
            //map from CreationDto to Entity
            var carEntity = _mapper.Map<Car>(car);
            
            _carRepository.AddCar(carEntity);

            await _carRepository.SaveChangesAsync();

            //map from Entity to Dto
            var carDto = _mapper.Map<CarDto>(carEntity);

            return CreatedAtRoute("GetCar", new { id = carDto.Id }, carDto);
        }

        [HttpPut("{id}")]
        public async Task<ActionResult> UpdateCar(int id, CarForUpdateDto car)
        {
            var carToUpdate = await _carRepository.GetCarAsync(id);

            if (carToUpdate == null)
            {
                return NotFound();
            }

            _mapper.Map(car, carToUpdate);

            await _carRepository.SaveChangesAsync();

            return NoContent();
        }

        [HttpDelete("{id}")]
        public async Task<ActionResult> DeleteCar(int id) 
        {
            var carToDelete = await _carRepository.GetCarAsync(id);

            if (carToDelete == null)
            {
                return NotFound();
            }

            _carRepository.DeleteCar(carToDelete);
            
            await _carRepository.SaveChangesAsync();

            return NoContent();
        }

        [HttpGet("{id}/races")]
        public async Task<ActionResult<IEnumerable<RaceWithoutCarsDto>>> GetRacesForCar(int id)
        {
            var car = await _carRepository.GetCarAsync(id);

            if (car == null)
            {
                return NotFound();
            }

            return Ok(_mapper.Map<IEnumerable<RaceWithoutCarsDto>>(car.Races));

        }
        [HttpPost("{id}/races")]
        public async Task<ActionResult> AddRaceToCar(int id, RaceForCarAddDto race)
        {
            var car = await _carRepository.GetCarAsync(id);

            if (car == null)
            {
                return NotFound();
            }

            var raceToAdd = await _carRepository.GetRaceAsync(race.Id);

            if (raceToAdd == null)
            {
                return NotFound();
            }

            _carRepository.AddRaceToCar(car, raceToAdd);
            await _carRepository.SaveChangesAsync();

            return Ok();

        }

        [HttpGet("stats-cars")]
        public async Task<ActionResult<IEnumerable<StatisticalReportCars>>> GetReport()
        {
            var cars = await _carRepository.GetCarsReviewsAsync();
            var result = new List<StatisticalReportCars>();
            foreach (var car in cars) 
            {
                if (car.Reviews.Count > 0) 
                { 
                    int score = 0;
                    foreach(var review in car.Reviews)
                    {
                        score += review.Score;
                    }
                    var report = new StatisticalReportCars()
                    {
                        Id = car.Id,
                        Model = car.Model,
                        Manufacturer = car.Manufacturer,
                        FabricationYear = car.FabricationYear,
                        Color = car.Color,
                        AverageReviewScore = (float)score / (float)car.Reviews.Count
                    };
                    result.Add(report);
                }
            }

            var ordered = result.OrderBy(s => s.AverageReviewScore);

            return Ok(ordered);

        }

        [HttpGet("stats-authors")]
        public async Task<ActionResult<IEnumerable<StatisticalReportAuthors>>> GetAuthorsReport()
        {
            var cars = await _carRepository.GetCarsReviewsAsync();
            List<StatisticalReportAuthors> stats = new List<StatisticalReportAuthors>();
            foreach(var car in cars) 
            {
                int count = 0;

                foreach (var review in car.Reviews)
                {
                    if (review.Author != null)
                    {
                        if (review.Author.FirstName.Contains("n"))
                        {
                            count += 1;
                        }
                    }
                }

                stats.Add(new StatisticalReportAuthors()
                {
                    Id  = car.Id,
                    Model = car.Model,
                    Manufacturer = car.Manufacturer,
                    Color = car.Color,
                    FabricationYear = car.FabricationYear,
                    NoOfAuthors = count
                });
            }
            var ordered = stats.OrderBy(s => s.NoOfAuthors);
            return Ok(ordered);
        }
    }
}
