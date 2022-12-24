package View;

import Controller.Controller;
import Model.ADT.MyDictionary;
import Model.ADT.MyHeap;
import Model.ADT.MyList;
import Model.ADT.MyStack;
import Model.Expression.*;
import Model.ProgramState.ProgramState;
import Model.Statement.*;
import Model.Type.BoolType;
import Model.Type.IntType;
import Model.Type.RefType;
import Model.Type.StringType;
import Model.Value.BoolValue;
import Model.Value.IntValue;
import Model.Value.StringValue;
import Model.Value.Value;
import Repository.IRepository;
import Repository.Repository;

import java.sql.Ref;

public class Interpreter {
    public static  void main(String[] args) {
        IStmt ex1 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(2))),
                        new PrintStmt(new VarExp("v"))));
        ProgramState prg1 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex1);
        IRepository repo1 = new Repository(prg1, "log1.txt");
        Controller cont1 = new Controller(repo1);

        IStmt ex2 = new CompStmt( new VarDeclStmt("a",new IntType()),
                new CompStmt(new VarDeclStmt("b",new IntType()),
                        new CompStmt(new AssignStmt("a", new ArithExp(new ValueExp(new IntValue(2)),new
                                ArithExp(new ValueExp(new IntValue(3)), new ValueExp(new IntValue(5)), 3),1)),
                                new CompStmt(new AssignStmt("b",new ArithExp(new VarExp("a"), new ValueExp(new
                                        IntValue(1)),1)), new PrintStmt(new VarExp("b"))))));
        ProgramState prg2 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex1);
        IRepository repo2 = new Repository(prg2, "log2.txt");
        Controller cont2 = new Controller(repo2);

        IStmt ex3 = new CompStmt(new VarDeclStmt("a", new BoolType()),
                new CompStmt(new VarDeclStmt("v", new IntType()),
                        new CompStmt(new AssignStmt("a", new ValueExp(new BoolValue(true))),
                                new CompStmt(new IfStmt(new VarExp("a"),
                                        new AssignStmt("v", new ValueExp(new IntValue(2))),
                                        new AssignStmt("v", new ValueExp(new IntValue(3)))),
                                        new PrintStmt(new VarExp("v"))))));
        ProgramState prg3 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),  ex1);
        IRepository repo3 = new Repository(prg3, "log3.txt");
        Controller cont3 = new Controller(repo3);

        IStmt ex4 = new CompStmt(new VarDeclStmt("varf", new StringType()),
                new CompStmt(new AssignStmt("varf", new ValueExp(new StringValue("test.txt"))),
                        new CompStmt(new OpenReadFile(new VarExp("varf")),
                                new CompStmt(new VarDeclStmt("varc", new IntType()),
                                        new CompStmt(new ReadFile(new VarExp("varf"), "varc"),
                                                new CompStmt(new PrintStmt(new VarExp("varc")),
                                                        new CompStmt(new ReadFile(new VarExp("varf"), "varc"),
                                                                new CompStmt(new PrintStmt(new VarExp("varc")),
                                                                        new CloseReadFile(new VarExp("varf"))))))))));

        ProgramState prg4 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),  ex4);
        IRepository repo4 = new Repository(prg4, "log4.txt");
        Controller cont4 = new Controller(repo4);

        IStmt ex5 = new CompStmt(new VarDeclStmt("a", new IntType()),
                new CompStmt(new VarDeclStmt("b", new IntType()),
                        new CompStmt(new AssignStmt("a", new ValueExp(new IntValue(5))),
                                new CompStmt(new AssignStmt("b", new ValueExp(new IntValue(7))),
                                        new IfStmt(new RelationalExp( new VarExp("a"),
                                                new VarExp("b"), ">"),new PrintStmt(new VarExp("a")),
                                                new PrintStmt(new VarExp("b")))))));

        ProgramState prg5 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),  ex5);
        IRepository repo5 = new Repository(prg5, "log5.txt");
        Controller cont5 = new Controller(repo5);

        IStmt ex6 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())),
                new CompStmt(new NewStmt("v", new ValueExp(new IntValue(20))),
                        new CompStmt(new VarDeclStmt("a", new RefType(new RefType(new IntType()))),
                                new CompStmt(new NewStmt("a", new VarExp("v")),
                                        new CompStmt(new PrintStmt(new VarExp("v")), new PrintStmt(new VarExp("a")))))));
        ProgramState prg6 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),  ex6);
        IRepository repo6 = new Repository(prg6, "log5.txt");
        Controller cont6 = new Controller(repo6);

        IStmt ex7 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())),
                new CompStmt(new NewStmt("v", new ValueExp(new IntValue(20))),
                        new CompStmt(new VarDeclStmt("a", new RefType(new RefType(new IntType()))),
                                new CompStmt(new NewStmt("a", new VarExp("v")),
                                        new CompStmt(new PrintStmt(new ReadHeapExp(new VarExp("v"))),
                                                new PrintStmt(new ArithExp(new ReadHeapExp(new ReadHeapExp(new VarExp("a"))), new ValueExp(new IntValue(5)), 1)))))));

        ProgramState prg7 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),  ex7);
        IRepository repo7 = new Repository(prg7, "log7.txt");
        Controller cont7 = new Controller(repo7);

        IStmt ex8 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())),
                new CompStmt(new NewStmt("v", new ValueExp(new IntValue(20))),
                        new CompStmt(new PrintStmt(new ReadHeapExp(new VarExp("v"))),
                            new CompStmt(new WriteHeapStmt("v", new ValueExp(new IntValue(30))),
                                    new PrintStmt( new ArithExp(new ReadHeapExp(new VarExp("v")), new ValueExp(new IntValue(5)), 1))
                                    ))));

        ProgramState prg8 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),  ex8);
        IRepository repo8 = new Repository(prg8, "log8.txt");
        Controller cont8 = new Controller(repo8);

        IStmt ex9 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())),
                new CompStmt(new NewStmt("v", new ValueExp(new IntValue(20))),
                        new CompStmt(new VarDeclStmt("a", new RefType(new RefType(new IntType()))),
                                new CompStmt(new NewStmt("a", new VarExp("v")),
                                    new CompStmt(new NewStmt("v", new ValueExp(new IntValue(30))),
                                            new PrintStmt(new ReadHeapExp(new ReadHeapExp(new VarExp("a")))))))));
        ProgramState prg9 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),  ex9);
        IRepository repo9 = new Repository(prg9, "log9.txt");
        Controller cont9 = new Controller(repo9);

        IStmt ex10 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(4))),
                        new CompStmt(new WhileStmt(new RelationalExp( new VarExp("v"), new ValueExp(new IntValue(0)), ">"),
                                new CompStmt(new PrintStmt(new VarExp("v")), new AssignStmt("v",new ArithExp(new VarExp("v"), new ValueExp(new IntValue(1)), 2)))),
                                new PrintStmt(new VarExp("v")))));

        ProgramState prg10 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),  ex10);
        IRepository repo10 = new Repository(prg10, "log10.txt");
        Controller cont10 = new Controller(repo10);

        IStmt ex11 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new VarDeclStmt("a", new RefType(new IntType())),
                        new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(10))),
                                new CompStmt(new NewStmt("a", new ValueExp(new IntValue(22))),
                                        new CompStmt(new ForkStmt(new CompStmt(new WriteHeapStmt("a", new ValueExp(new IntValue(30))),
                                                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(32))),
                                                        new CompStmt(new PrintStmt(new VarExp("v")), new PrintStmt(new ReadHeapExp(new VarExp("a"))))))),
                                                new CompStmt(new PrintStmt(new VarExp("v")), new PrintStmt(new ReadHeapExp(new VarExp("a")))))))));
        ProgramState prg11 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(),  ex11);
        IRepository repo11 = new Repository(prg11, "log11.txt");
        Controller cont11 = new Controller(repo11);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExampleCommand("1", ex1.toString(), cont1));
        menu.addCommand(new RunExampleCommand("2", ex2.toString(), cont2));
        menu.addCommand(new RunExampleCommand("3", ex3.toString(), cont3));
        menu.addCommand(new RunExampleCommand("4", ex4.toString(), cont4));
        menu.addCommand(new RunExampleCommand("5", ex5.toString(), cont5));
        menu.addCommand(new RunExampleCommand("6", ex6.toString(), cont6));
        menu.addCommand(new RunExampleCommand("7", ex7.toString(), cont7));
        menu.addCommand(new RunExampleCommand("8", ex8.toString(), cont8));
        menu.addCommand(new RunExampleCommand("9", ex9.toString(), cont9));
        menu.addCommand(new RunExampleCommand("10", ex10.toString(), cont10));
        menu.addCommand(new RunExampleCommand("11", ex11.toString(), cont11));
        menu.show();
    }
}
