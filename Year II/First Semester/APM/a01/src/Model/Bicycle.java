package Model;

public class Bicycle implements Vehicle {

    private String color;
    private Integer id;

    public Bicycle() { this.color = ""; this.id = 0; }
    public Bicycle(String color, Integer id) { this.color = color; this.id = id; }

    @Override
    public String getColor() { return this.color; }

    @Override
    public String toString() { return "Id : " + this.id + ", Bicycle, color : " + this.color + "\n"; }

    @Override
    public Integer getId() { return this.id; }
}
