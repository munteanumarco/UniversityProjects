package Model;

public class Motorcycle implements Vehicle {

    private String color;
    private Integer id;

    public Motorcycle() { this.color = ""; this.id = 0; }
    public Motorcycle(String color, Integer id) { this.color = color; this.id = id; }

    @Override
    public String getColor() { return this.color; }

    @Override
    public String toString() { return "Id : " + this.id + ", Motorcycle, color : " + this.color + "\n"; }

    @Override
    public Integer getId() { return this.id; }
}
