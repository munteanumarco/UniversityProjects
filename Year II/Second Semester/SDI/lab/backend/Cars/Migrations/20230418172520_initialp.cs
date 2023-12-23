using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

#pragma warning disable CA1814 // Prefer jagged arrays over multidimensional

namespace Cars.Migrations
{
    /// <inheritdoc />
    public partial class initialp : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Authors",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    FirstName = table.Column<string>(type: "text", nullable: false),
                    LastName = table.Column<string>(type: "text", nullable: false),
                    Email = table.Column<string>(type: "text", nullable: false),
                    Phone = table.Column<string>(type: "text", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Authors", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "Cars",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Model = table.Column<string>(type: "text", nullable: false),
                    Manufacturer = table.Column<string>(type: "text", nullable: false),
                    Color = table.Column<string>(type: "text", nullable: false),
                    FabricationYear = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Cars", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "Races",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Name = table.Column<string>(type: "text", nullable: false),
                    City = table.Column<string>(type: "text", nullable: false),
                    Country = table.Column<string>(type: "text", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Races", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "Reviews",
                columns: table => new
                {
                    Id = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Title = table.Column<string>(type: "text", nullable: false),
                    Description = table.Column<string>(type: "text", nullable: false),
                    Score = table.Column<int>(type: "integer", nullable: false),
                    Date = table.Column<DateTime>(type: "timestamp with time zone", nullable: false),
                    CarId = table.Column<int>(type: "integer", nullable: false),
                    AuthorId = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Reviews", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Reviews_Authors_AuthorId",
                        column: x => x.AuthorId,
                        principalTable: "Authors",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_Reviews_Cars_CarId",
                        column: x => x.CarId,
                        principalTable: "Cars",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "CarRace",
                columns: table => new
                {
                    CarsId = table.Column<int>(type: "integer", nullable: false),
                    RacesId = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_CarRace", x => new { x.CarsId, x.RacesId });
                    table.ForeignKey(
                        name: "FK_CarRace_Cars_CarsId",
                        column: x => x.CarsId,
                        principalTable: "Cars",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_CarRace_Races_RacesId",
                        column: x => x.RacesId,
                        principalTable: "Races",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.InsertData(
                table: "Authors",
                columns: new[] { "Id", "Email", "FirstName", "LastName", "Phone" },
                values: new object[,]
                {
                    { 1, "johndoe@gmail.com", "John", "Doe", "0712356723" },
                    { 2, "frankhuber@gmail.com", "Frank", "Huber", "0720152323" },
                    { 3, "simonjones@gmail.com", "Simon", "Jones", "0720144723" },
                    { 4, "steveburnley@gmail.com", "Steve", "Burnley", "0745156723" },
                    { 5, "andreisava@email.com", "Andrei", "Sava", "0712356723" },
                    { 6, "simbotinpopescu@email.com", "Simbotin", "Popescu", "0720152323" },
                    { 7, "lucianjones@email.com", "Lucian", "Jones", "0720144723" },
                    { 8, "jamessoftle@email.com", "James", "Softle", "0745156723" },
                    { 9, "sorindica@email.com", "Sorin", "Dica", "0745156723" },
                    { 10, "tudorpopescu@email.com", "Tudor", "Popescu", "0745156723" }
                });

            migrationBuilder.InsertData(
                table: "Cars",
                columns: new[] { "Id", "Color", "FabricationYear", "Manufacturer", "Model" },
                values: new object[,]
                {
                    { 1, "Blue", 2020, "BMW", "M4" },
                    { 2, "Grey", 2018, "Audi", "RS6" },
                    { 3, "Black", 2021, "Volkswagen", "Golf GTI" },
                    { 4, "Red", 2016, "Mercedes-Benz", "AMG" },
                    { 5, "White", 2022, "BMW", "Series 5" },
                    { 6, "Blue", 2018, "Ford", "Mustang" },
                    { 7, "Red", 2020, "Mazda", "CX5" },
                    { 8, "Grey", 2013, "Volvo", "V40" },
                    { 9, "Black", 1998, "Volkswagen", "Golf 3 Cabrio" },
                    { 10, "Green", 2019, "Volkswagen", "ID3" }
                });

            migrationBuilder.InsertData(
                table: "Races",
                columns: new[] { "Id", "City", "Country", "Name" },
                values: new object[,]
                {
                    { 1, "Indiana", "USA", "Indianapolis 500" },
                    { 2, "Le Mans", "France", "24 Hours of Le Mans" },
                    { 3, "Daytona", "USA", "Daytona 500" },
                    { 4, "Dakar", "Saudi Arabia", "Dakar Rally" },
                    { 5, "Monaco", "Monaco", "Monaco Grand Prix" },
                    { 6, "Colorado", "USA", "Pikes Peak Hill Climb" },
                    { 7, "Bathurst", "Australia", "Bathurst 1000" },
                    { 8, "Finnish Lakeland", "Finland", "Rally Finland" },
                    { 9, "Monte Carlo", "France", "Monte Carlo Rally" },
                    { 10, "Budapest", "Hungary", "Hungarian GP" }
                });

            migrationBuilder.InsertData(
                table: "Reviews",
                columns: new[] { "Id", "AuthorId", "CarId", "Date", "Description", "Score", "Title" },
                values: new object[,]
                {
                    { 1, 10, 1, DateTime.UtcNow, "is a reliable and efficient car with a comfortable interior, making it perfect for commuting or road trips.", 10, "Very good car!" },
                    { 2, 9, 2, DateTime.UtcNow, "The Honda Civic is a reliable and affordable sedan that's perfect for city driving, but it lacks the power and excitement of its sportier competitors.", 4, "Must drive at least once in a lifetime!" },
                    { 3, 8, 3, DateTime.UtcNow, "s a classic American muscle car that delivers an impressive blend of power and handling, but its fuel economy leaves something to be desired.", 4, "Could be better!" },
                    { 4, 7, 4, DateTime.UtcNow, "luxury sedan that offers an incredible driving experience with lightning-fast acceleration and cutting-edge technology.", 4, "Decent!" },
                    { 5, 6, 5, DateTime.UtcNow, "comfortable and practical midsize sedan that's great for families, but it can be a bit bland to drive.", 4, "This is a good car!" },
                    { 6, 1, 6, DateTime.UtcNow, "is a legendary sports car that continues to impress with its exhilarating performance and stunning design.", 6, "Not that great, could be better!" },
                    { 7, 2, 7, DateTime.UtcNow, "The Chevrolet Corvette Stingray is a powerful and agile sports car that's sure to turn heads, but its interior quality can be underwhelming.", 5, "Best SUV I drove so far !" },
                    { 8, 3, 8, DateTime.UtcNow, "well-rounded luxury sedan that offers a comfortable ride, upscale features, and impressive fuel efficiency.", 4, "Shame on the manufacturer!" },
                    { 9, 4, 9, DateTime.UtcNow, "a rugged and capable off-road vehicle that's perfect for adventurous drivers, but its on-road comfort and practicality can be lacking.", 5, "Best car ever" },
                    { 10, 5, 10, DateTime.UtcNow, "a versatile crossover that's perfect for outdoor enthusiasts, thanks to its all-wheel drive and generous cargo space.", 4, "Well Done Volkswagen" }
                });

            migrationBuilder.CreateIndex(
                name: "IX_CarRace_RacesId",
                table: "CarRace",
                column: "RacesId");

            migrationBuilder.CreateIndex(
                name: "IX_Reviews_AuthorId",
                table: "Reviews",
                column: "AuthorId");

            migrationBuilder.CreateIndex(
                name: "IX_Reviews_CarId",
                table: "Reviews",
                column: "CarId");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "CarRace");

            migrationBuilder.DropTable(
                name: "Reviews");

            migrationBuilder.DropTable(
                name: "Races");

            migrationBuilder.DropTable(
                name: "Authors");

            migrationBuilder.DropTable(
                name: "Cars");
        }
    }
}
