﻿// <auto-generated />
using InfoAPI.Contexts;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace InfoAPI.Migrations
{
    [DbContext(typeof(InfoContext))]
    partial class InfoContextModelSnapshot : ModelSnapshot
    {
        protected override void BuildModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .HasAnnotation("ProductVersion", "7.0.7")
                .HasAnnotation("Relational:MaxIdentifierLength", 63);

            NpgsqlModelBuilderExtensions.UseIdentityByDefaultColumns(modelBuilder);

            modelBuilder.Entity("InfoAPI.Entities.City", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("integer");

                    NpgsqlPropertyBuilderExtensions.UseIdentityByDefaultColumn(b.Property<int>("Id"));

                    b.Property<string>("Country")
                        .IsRequired()
                        .HasColumnType("text");

                    b.Property<string>("Name")
                        .IsRequired()
                        .HasColumnType("text");

                    b.HasKey("Id");

                    b.ToTable("Cities");
                });

            modelBuilder.Entity("InfoAPI.Entities.Link", b =>
                {
                    b.Property<int>("IdLink")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("integer");

                    NpgsqlPropertyBuilderExtensions.UseIdentityByDefaultColumn(b.Property<int>("IdLink"));

                    b.Property<int>("Distance")
                        .HasColumnType("integer");

                    b.Property<int>("Duration")
                        .HasColumnType("integer");

                    b.Property<int>("IdCity1")
                        .HasColumnType("integer");

                    b.Property<int>("IdCity2")
                        .HasColumnType("integer");

                    b.HasKey("IdLink");

                    b.HasIndex("IdCity1");

                    b.HasIndex("IdCity2");

                    b.ToTable("Links");
                });

            modelBuilder.Entity("InfoAPI.Entities.Link", b =>
                {
                    b.HasOne("InfoAPI.Entities.City", null)
                        .WithMany()
                        .HasForeignKey("IdCity1")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.HasOne("InfoAPI.Entities.City", null)
                        .WithMany()
                        .HasForeignKey("IdCity2")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();
                });
#pragma warning restore 612, 618
        }
    }
}