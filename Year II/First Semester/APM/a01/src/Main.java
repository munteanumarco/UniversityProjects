import Controller.Controller;
import Repository.ArrayRepo;
import Repository.MyRepo;
import View.View;

public class Main {
    public static void main(String[] args) {
        MyRepo repo = new ArrayRepo(64);
        Controller cont = new Controller(repo);
        View view = new View(cont);

        view.startApplication();
    }
}