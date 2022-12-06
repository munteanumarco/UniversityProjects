package Controller;

import Exceptions.MyException;
import Model.ADT.MyIStack;
import Model.ProgramState.ProgramState;
import Model.Statement.IStmt;
import Model.Value.RefValue;
import Model.Value.Value;
import Repository.IRepository;

import java.io.IOException;
import java.sql.Ref;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

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
            prg.getHeap().setContent((HashMap<Integer, Value>)safeGarbageCollector(getSymTableAddr(prg.getSymTable().getContent().values()),getHeapAddr(prg.getHeap().getContent().values()), prg.getHeap().getContent()));
            this.repository.logPrgStateExec();
            display();
        }
        System.out.println(prg.outToString());
    }

    public void setDisplayFlag(boolean displayFlag) {
        this.displayFlag = displayFlag;
    }

    public List<Integer> getSymTableAddr(Collection<Value> symTableValues) {
        return symTableValues.stream()
                .filter(v -> v instanceof RefValue)
                .map(v -> {RefValue v1 = (RefValue) v; return v1.getAddress();})
                .collect(Collectors.toList());
    }

    public List<Integer> getHeapAddr(Collection<Value> heapValues) {
        return heapValues.stream()
                .filter(v -> v instanceof RefValue)
                .map(v -> {RefValue v1 = (RefValue) v; return v1.getAddress();})
                .collect(Collectors.toList());
    }

    public Map<Integer, Value> safeGarbageCollector(List<Integer> symTableAddr, List<Integer> heapAddr, Map<Integer, Value> heap) {
        return heap.entrySet().stream()
                .filter(e -> (symTableAddr.contains(e.getKey()) || heapAddr.contains(e.getKey())))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    private void display() {
        if (displayFlag) {
            System.out.println(this.repository.getCurrentProgram().toString());
        }
    }
}
