package Controller;

import Exceptions.MyException;
import Model.ADT.MyIStack;
import Model.ProgramState.ProgramState;
import Model.Statement.IStmt;
import Repository.IRepository;

import java.io.IOException;

public class Controller {
    IRepository repository;
    boolean displayFlag;

    public Controller(IRepository repository) {
        this.repository = repository;
        displayFlag = false;
    }

    public ProgramState oneStep(ProgramState state) throws MyException {
        MyIStack<IStmt> stack = state.getStack();
        if (stack.isEmpty()) {
            throw new MyException("Execution stack is empty!");
        }
        IStmt currentStmt = stack.pop();
        return currentStmt.execute(state);
    }

    public void allSteps() throws MyException, IOException {
        ProgramState prg = this.repository.getCurrentProgram();
        this.repository.logPrgStateExec();
        display();
        while(!prg.getStack().isEmpty()){
            this.oneStep(prg);
            this.repository.logPrgStateExec();
            display();
        }
    }

    public void setDisplayFlag(boolean displayFlag) {
        this.displayFlag = displayFlag;
    }

    private void display() {
        if (displayFlag) {
            System.out.println(this.repository.getCurrentProgram().toString());
        }
    }
}
