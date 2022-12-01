package Repository;

import Model.Vehicle;

public interface MyRepo {
    public void add(Vehicle newVehicle) throws MyException;
    public void remove(Integer id) throws MyException;
    public Vehicle[] getVehicles() throws MyException;
    public Integer getCurrentSize() throws MyException;

    public Vehicle[] getVehiclesByColor(String color);
}
