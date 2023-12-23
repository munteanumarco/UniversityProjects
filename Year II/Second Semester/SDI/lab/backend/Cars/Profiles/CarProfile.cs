using AutoMapper;
using Cars.Entities;
using Cars.Models;

namespace Cars.Profiles
{
    public class CarProfile : Profile
    {
        public CarProfile() 
        {
            CreateMap<Entities.Car, Models.CarDto>();
            CreateMap<Models.CarForCreationDto, Entities.Car>();
            CreateMap<Models.CarForUpdateDto, Entities.Car>();
            CreateMap<Entities.Car, Models.CarWithoutReviewsDto>();
            CreateMap<Entities.Car, Models.StatisticalReportCars>()
                .ForMember(destinationMember => destinationMember.AverageReviewScore, opt => opt.MapFrom(src=> 5));
        }
    }
}
