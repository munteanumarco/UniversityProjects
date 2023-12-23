using AutoMapper;
using Cars.Entities;

namespace Cars.Profiles
{
    public class AuthorProfile : Profile
    {
        public AuthorProfile() 
        {
            CreateMap<Entities.Author, Models.AuthorWithoutReviewsDto>();
            CreateMap<Entities.Author, Models.AuthorDto>();
            CreateMap<Models.AuthorForCreationDto, Entities.Author>();
            CreateMap<Models.AuthorForUpdateDto, Entities.Author>();
        }
    }
}
