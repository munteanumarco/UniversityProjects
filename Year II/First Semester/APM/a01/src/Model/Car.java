package Model;
public class Car implements Vehicle {
    private String color;
    private Integer id;

    public Car() { this.color = ""; this.id = 0; }
    public Car(String color, Integer id) { this.color = color; this.id = id; }

    @Override
    public String getColor() { return this.color; }

    @Override
    public String toString() { return "Id : " + this.id + ", Car, color : " + this.color + ".\n"; }

    @Override
    public Integer getId() { return this.id; }

}
