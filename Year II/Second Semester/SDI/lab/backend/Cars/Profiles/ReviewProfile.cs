using AutoMapper;
using Cars.Models;

namespace Cars.Profiles
{
    public class ReviewProfile : Profile
    {
        public ReviewProfile() 
        {
            CreateMap<Entities.Review, Models.ReviewDto>();
            CreateMap<Models.ReviewForCreationDto, Entities.Review>();
            CreateMap<Models.ReviewForUpdateDto, Entities.Review>();
        }
    }
}
