package Repository;

import Model.Vehicle;

public class ArrayRepo implements MyRepo {
    private Vehicle[] vehicles;
    private Integer currentSize;
    private Integer maxSize;

    public ArrayRepo() {
        this.maxSize = 10;
        this.vehicles = new Vehicle[maxSize];
        this.currentSize = 0;
    }

    public ArrayRepo(int maxSize) {
        this.maxSize = maxSize;
        this.vehicles = new Vehicle[maxSize];
        currentSize = 0;
    }

    @Override
    public void add(Vehicle newVehicle) throws MyException {
        if (currentSize == maxSize) { throw new MyException("Array repo is full !"); }
        this.vehicles[this.currentSize] = newVehicle;
        currentSize++;
    }

    @Override
    public void remove(Integer id) throws MyException{
        int index = -1;
        for (int i = 0; i < this.currentSize; i++) {
            if (vehicles[i].getId() == id) {
                index = i;
            }
        }
        if (index == -1) {
            throw new MyException("Element with id " + id + " doesn't exist!");
        }
        else {
            for (int i = index; i < this.currentSize - 1; i++) {
                this.vehicles[i] = this.vehicles[i+1];
            }
            this.currentSize--;
        }
    }

    @Override
    public Vehicle[] getVehicles() throws MyException{
        return this.vehicles;
    }

    @Override
    public Integer getCurrentSize() throws MyException{
        return this.currentSize;
    }

    @Override
    public Vehicle[] getVehiclesByColor(String color) {
        Vehicle[] result = new Vehicle[this.maxSize];
        int index = 0;
        for (int i = 0; i < this.currentSize; i++) {
            if (this.vehicles[i].getColor().equals(color)) {
                result[index] = this.vehicles[i];
                index++;
            }
        }
        return result;
    }
}
