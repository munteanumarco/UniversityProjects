using AutoMapper;

namespace Cars.Profiles
{
    public class RaceProfile : Profile
    {
        public RaceProfile() 
        {
            CreateMap<Entities.Race, Models.RaceWithoutCarsDto>();
            CreateMap<Models.RaceForCreationDto, Entities.Race>();
            CreateMap<Entities.Race, Models.RaceWithoutCarsDto>();
            CreateMap<Entities.Race, Models.RaceWithCarsDto>();
            CreateMap<Models.RaceForUpdateDto, Entities.Race>();
        }
    }
}
