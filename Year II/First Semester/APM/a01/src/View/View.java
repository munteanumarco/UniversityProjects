package View;

import Controller.Controller;
import Model.Bicycle;
import Model.Car;
import Model.Motorcycle;
import Model.Vehicle;
import Repository.MyException;

import java.util.Scanner;

public class View {
    private Controller cont;
    public View(Controller cont) { this.cont = cont; }

    public void displayMenu() {
        System.out.println("Choose one option :\n 0. Exit the app\n 1. Add new vehicle\n 2. Remove existing vehicle\n 3. Update existing vehicle\n 4.List all vehicles\n 5.Display vehicles by color");
    }

    public void addNewVehicle() throws MyException{
        System.out.println("What vehicle do you want to add ?\n 1.Car\n 2.Motorcycle\n 3.Bicycle");
        Scanner scanner = new Scanner(System.in);
        Integer vehicleOption = scanner.nextInt();
        System.out.println("Insert the id:");
        Integer id = scanner.nextInt();
        System.out.println("Insert the colour:");
        String colour = scanner.next();

        Vehicle newVehicle;
        switch (vehicleOption) {
            case 1:
                newVehicle = new Car(colour, id);
                this.cont.add(newVehicle);
                break;
            case 2:
                newVehicle = new Motorcycle(colour, id);
                this.cont.add(newVehicle);
                break;
            case 3:
                newVehicle = new Bicycle(colour, id);
                this.cont.add(newVehicle);
                break;
            default:
                break;
        }
    }

    public void listAllVehicles() throws MyException {
        Vehicle[] vehicles = this.cont.getVehicles();
        for (int i = 0; i < this.cont.getCurrentSize(); i++) {
            System.out.print(vehicles[i]);
        }
    }

    public void deleteVehicle() throws MyException {
        System.out.println("Insert the id of the vehicle:");
        Scanner scanner = new Scanner(System.in);
        Integer id = scanner.nextInt();
        this.cont.remove(id);
    }

    public void setupData() throws MyException {
        Vehicle c1 = new Car("red",12);
        Vehicle c2 = new Car("blue",13);
        Vehicle m1 = new Motorcycle("red",14);
        Vehicle m2 = new Motorcycle("yellow",15);
        Vehicle b1 = new Bicycle("blue",16);
        Vehicle b2 = new Bicycle("yellow",17);
        this.cont.add(c1);
        this.cont.add(c2);
        this.cont.add(m1);
        this.cont.add(m2);
        this.cont.add(b1);
        this.cont.add(b2);
    }

    public void listVehiclesByColor() {
        System.out.println("Insert the color :");
        Scanner scanner = new Scanner(System.in);
        String color = scanner.next();
        Vehicle[] selectedVehicles =  this.cont.getVehiclesByColor(color);
        boolean ok = false;
        for (int i = 0; i < selectedVehicles.length; i++) {
            if (selectedVehicles[i] != null) {
                ok = true;
                System.out.println(selectedVehicles[i]);
            }
        }
        if (!ok) {
            System.out.println("No vehicles with the given color :( ");
        }
    }
    public void startApplication() {
        System.out.println("===== Vehicle management application =====");
        Scanner scanner = new Scanner(System.in);
       try {
           this.setupData();
       } catch (MyException ex){
            System.out.println(ex);
        }
        while (true) {
            try {
                this.displayMenu();
                Integer userOption = scanner.nextInt();
                switch (userOption) {
                    case 0:
                        return;
                    case 1:
                        this.addNewVehicle();
                        break;
                    case 2:
                        this.deleteVehicle();
                        break;
                    case 3:
                        break;
                    case 4:
                        this.listAllVehicles();
                        break;
                    case 5:
                        this.listVehiclesByColor();
                        break;
                    default:
                        break;
                }
            } catch (MyException ex) {
                System.out.println(ex);
            }
        }
    }

}
