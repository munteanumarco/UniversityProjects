using AutoMapper;
using Cars.Entities;
using Cars.Models;
using Cars.Repositories;
using Microsoft.AspNetCore.Mvc;

namespace Cars.Controllers
{
    [Route("api/races")]
    [ApiController]
    public class RacesController : ControllerBase
    {
        private readonly ICarRepository _repository;
        private readonly IMapper _mapper;

        public RacesController(ICarRepository repository, IMapper mapper)
        {
            _repository = repository ?? throw new ArgumentNullException(nameof(repository));
            _mapper = mapper ?? throw new ArgumentNullException(nameof(mapper));
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<RaceWithoutCarsDto>>> GetRaces()
        {
            var races = await _repository.GetRacesAsync();

            return Ok(_mapper.Map<IEnumerable<RaceWithoutCarsDto>>(races));
        }

        [HttpGet("{id}", Name = "GetRace")]
        public async Task<ActionResult<RaceWithCarsDto?>> GetRace(int id)
        {
            var race = await _repository.GetRaceAsync(id);

            if (race == null)
            {
                return NotFound();
            }

            return Ok(_mapper.Map<RaceWithCarsDto>(race));

        }

        [HttpPost]
        public async Task<ActionResult<RaceWithoutCarsDto>> CreateRace(RaceForCreationDto race)
        {
            var raceEntity = _mapper.Map<Race>(race);

            _repository.AddRace(raceEntity);

            await _repository.SaveChangesAsync();

            var raceDto = _mapper.Map<RaceWithoutCarsDto>(raceEntity);

            return CreatedAtRoute("GetRace", new { id = raceDto.Id }, raceDto);

        }

        [HttpDelete("{id}")]
        public async Task<ActionResult> DeleteRace(int id)
        {
            var race = await _repository.GetRaceAsync(id);

            if (race == null)
            {
                return NotFound();
            }

            _repository.DeleteRace(race);

            await _repository.SaveChangesAsync();

            return NoContent();
        }

        [HttpGet("{id}/cars")]
        public async Task<ActionResult<IEnumerable<CarWithoutReviewsDto>>> GetCarsForRace(int id)
        {
            var race = await _repository.GetRaceAsync(id);

            if (race == null)
            {
                return NotFound();
            }
            return Ok(_mapper.Map<IEnumerable<CarWithoutReviewsDto>>(race.Cars));
        }

        [HttpPost("{id}/cars")]
        public async Task<ActionResult> AddCarToRace(int id, CarForRaceAddDto car)
        {
            var race = await _repository.GetRaceAsync(id);

            if (race == null)
            {
                return NotFound();
            }

            var carToAdd = await _repository.GetCarAsync(car.Id);

            if (carToAdd == null)
            {
                return NotFound();
            }

            _repository.AddCarToRace(race, carToAdd);

            await _repository.SaveChangesAsync();
            return Ok();
        }

        [HttpPost("{id}/cars-bulk")]
        public async Task<ActionResult> AddCarsToRace(int id, CarsForRaceAddDto carIds)
        {
            var race = await _repository.GetRaceAsync(id);

            if (race == null)
            {
                return NotFound();
            }

            foreach(var currCarId in carIds.carIds)
            {
                var carToAdd = await _repository.GetCarAsync(currCarId);

                if (carToAdd == null)
                {
                    return NotFound();
                }

                _repository.AddCarToRace(race, carToAdd);

                await _repository.SaveChangesAsync();
            }
            return Ok();
        }

        [HttpPut("{id}")]
        public async Task<ActionResult> UpdateRace(int id, RaceForUpdateDto newRace)
        {
            var race = await _repository.GetRaceAsync(id);  

            if (race == null)
            {
                return NotFound();  
            }

            _mapper.Map(newRace, race);

            await _repository.SaveChangesAsync();

            return NoContent();
        }

    }
}
