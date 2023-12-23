using Cars.Entities;
using Cars.Models;
using Microsoft.EntityFrameworkCore;

namespace Cars.DbContexts
{
    public class CarContext : DbContext
    {
        public DbSet<Car> Cars { get; set; }

        public DbSet<Review> Reviews { get; set; }

        public DbSet<Author> Authors { get; set; }

        public DbSet<Race> Races { get; set; }

        public CarContext(DbContextOptions<CarContext> options) 
            : base(options)
        {
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {

            modelBuilder.Entity<Car>().HasData(
              new Car("M4", "BMW")
              {
                  Id = 1,
                  Color = "Blue",
                  FabricationYear = 2020
              },
               new Car("RS6", "Audi")
               {
                   Id = 2,
                   Color = "Grey",
                   FabricationYear = 2018
               },
               new Car("Golf GTI", "Volkswagen")
               {
                   Id = 3,
                   Color = "Black",
                   FabricationYear = 2021
               },
               new Car("AMG", "Mercedes-Benz")
               {
                   Id = 4,
                   Color = "Red",
                   FabricationYear = 2016
               },
               new Car("Series 5", "BMW")
               {
                   Id = 5,
                   Color = "White",
                   FabricationYear = 2022
               },
               new Car("Mustang", "Ford")
               {
                   Id = 6,
                   Color = "Blue",
                   FabricationYear = 2018
               },
               new Car("CX5", "Mazda")
               {
                   Id = 7,
                   Color = "Red",
                   FabricationYear = 2020
               },
               new Car("V40", "Volvo")
               {
                   Id = 8,
                   Color = "Grey",
                   FabricationYear = 2013
               },
               new Car("Golf 3 Cabrio", "Volkswagen")
               {
                   Id = 9,
                   Color = "Black",
                   FabricationYear = 1998
               },
               new Car("ID3", "Volkswagen")
               {
                   Id = 10,
                   Color = "Green",
                   FabricationYear = 2019
               }
           );

            modelBuilder.Entity<Author>().HasData(
                new Author("John", "Doe")
                {
                    Id = 1,
                    Email = "johndoe@gmail.com",
                    Phone = "0712356723"
                },
                new Author("Frank", "Huber")
                {
                    Id = 2,
                    Email = "frankhuber@gmail.com",
                    Phone = "0720152323"
                },
                new Author("Simon", "Jones")
                {
                    Id = 3,
                    Email = "simonjones@gmail.com",
                    Phone = "0720144723"
                },
                new Author("Steve", "Burnley")
                {
                    Id = 4,
                    Email = "steveburnley@gmail.com",
                    Phone = "0745156723"
                },
                new Author("Andrei", "Sava")
                {
                    Id = 5,
                    Email = "andreisava@email.com",
                    Phone = "0712356723"
                },
                new Author("Simbotin", "Popescu")
                {
                    Id = 6,
                    Email = "simbotinpopescu@email.com",
                    Phone = "0720152323"
                },
                new Author("Lucian", "Jones")
                {
                    Id = 7,
                    Email = "lucianjones@email.com",
                    Phone = "0720144723"
                },
                new Author("James", "Softle")
                {
                    Id = 8,
                    Email = "jamessoftle@email.com",
                    Phone = "0745156723"
                },
                new Author("Sorin", "Dica")
                {
                    Id = 9,
                    Email = "sorindica@email.com",
                    Phone = "0745156723"
                },
                new Author("Tudor", "Popescu")
                {
                    Id = 10,
                    Email = "tudorpopescu@email.com",
                    Phone = "0745156723"
                }
                );

            modelBuilder.Entity<Review>().HasData(
                new Review("Very good car!", "is a reliable and efficient car with a comfortable interior, making it perfect for commuting or road trips.")
                {
                    Id = 1,
                    Score = 10,
                    Date = new DateTime(2023, 01, 01),
                    CarId = 1,
                    AuthorId = 10,
                },
                new Review("Must drive at least once in a lifetime!", "The Honda Civic is a reliable and affordable sedan that's perfect for city driving, but it lacks the power and excitement of its sportier competitors.")
                {
                    Id = 2,
                    Score = 4,
                    Date = new DateTime(2020, 01, 01),
                    CarId = 2,
                    AuthorId = 9,
                },
                new Review("Could be better!", "s a classic American muscle car that delivers an impressive blend of power and handling, but its fuel economy leaves something to be desired.")
                {
                    Id = 3,
                    Score = 4,
                    Date = new DateTime(2019, 11, 01),
                    CarId = 3,
                    AuthorId = 8,
                },
                new Review("Decent!", "luxury sedan that offers an incredible driving experience with lightning-fast acceleration and cutting-edge technology.")
                {
                    Id = 4,
                    Score = 4,
                    Date = new DateTime(2023, 12, 10),
                    CarId = 4,
                    AuthorId = 7,
                },
                new Review("This is a good car!", "comfortable and practical midsize sedan that's great for families, but it can be a bit bland to drive.")
                {
                    Id = 5,
                    Score = 4,
                    Date = new DateTime(2023, 03, 04),
                    CarId = 5,
                    AuthorId = 6,
                },
                new Review("Not that great, could be better!", "is a legendary sports car that continues to impress with its exhilarating performance and stunning design.")
                {
                    Id = 6,
                    Score = 6,
                    Date = new DateTime(2022, 05, 11),
                    CarId = 6,
                    AuthorId = 1,
                },
                new Review("Best SUV I drove so far !", "The Chevrolet Corvette Stingray is a powerful and agile sports car that's sure to turn heads, but its interior quality can be underwhelming.")
                {
                    Id = 7,
                    Score = 5,
                    Date = new DateTime(2021, 11, 21),
                    CarId = 7,
                    AuthorId = 2,
                },
                new Review("Shame on the manufacturer!", "well-rounded luxury sedan that offers a comfortable ride, upscale features, and impressive fuel efficiency.")
                {
                    Id = 8,
                    Score = 4,
                    Date = new DateTime(2019, 10, 04),
                    CarId = 8,
                    AuthorId = 3,
                },
                new Review("Best car ever", "a rugged and capable off-road vehicle that's perfect for adventurous drivers, but its on-road comfort and practicality can be lacking.")
                {
                    Id = 9,
                    Score = 5,
                    Date = new DateTime(2020, 09, 23),
                    CarId = 9,
                    AuthorId = 4,
                },
                new Review("Well Done Volkswagen", "a versatile crossover that's perfect for outdoor enthusiasts, thanks to its all-wheel drive and generous cargo space.")
                {
                    Id = 10,
                    Score = 4,
                    Date = new DateTime(2021, 08, 04),
                    CarId = 10,
                    AuthorId = 5,
                }
                );


            modelBuilder.Entity<Race>().HasData(
                new Race("Indianapolis 500", "USA")
                {
                    Id = 1,
                    City = "Indiana"
                },
                new Race("24 Hours of Le Mans", "France")
                {
                    Id = 2,
                    City = "Le Mans"
                },
                new Race("Daytona 500", "USA")
                {
                    Id = 3,
                    City = "Daytona"
                },
                new Race("Dakar Rally", "Saudi Arabia")
                {
                    Id = 4,
                    City = "Dakar"
                },
                new Race("Monaco Grand Prix", "Monaco")
                {
                    Id = 5,
                    City = "Monaco"
                },
                new Race("Pikes Peak Hill Climb", "USA")
                {
                    Id = 6,
                    City = "Colorado"
                },
                new Race("Bathurst 1000", "Australia")
                {
                    Id = 7,
                    City = "Bathurst"
                },
                new Race("Rally Finland", "Finland")
                {
                    Id = 8,
                    City = "Finnish Lakeland"
                },
                new Race("Monte Carlo Rally", "France")
                {
                    Id = 9,
                    City = "Monte Carlo"
                },
                new Race("Hungarian GP", "Hungary")
                {
                    Id = 10,
                    City = "Budapest"
                }
            );

            base.OnModelCreating(modelBuilder);
        }
    }
}
