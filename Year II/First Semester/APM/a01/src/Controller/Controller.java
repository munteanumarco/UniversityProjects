package Controller;

import Model.Vehicle;
import Repository.MyException;
import Repository.MyRepo;

public class Controller {
    private MyRepo repo;

    public Controller(MyRepo repo) { this.repo = repo; }

    public void add(Vehicle newVehicle) throws MyException {
        //todo check for duplicates
        this.repo.add(newVehicle);
    }

    public void remove(Integer id) throws MyException {
        this.repo.remove(id);
    }

    public Vehicle[] getVehicles()  throws MyException {
        return this.repo.getVehicles();
    }

    public Integer getCurrentSize()  throws MyException {
        return this.repo.getCurrentSize();
    }

    public Vehicle[] getVehiclesByColor(String color) {
        return this.repo.getVehiclesByColor(color);
    }
}
