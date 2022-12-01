package Model.Statement;

import Exceptions.MyException;
import Model.ADT.MyIStack;
import Model.ProgramState.ProgramState;

public class CompStmt implements IStmt{
    private IStmt firstStmt;
    private IStmt secondStmt;

    public CompStmt(IStmt first, IStmt second) {
        this.firstStmt = first;
        this.secondStmt = second;
    }

    @Override
    public String toString() {
        return String.format("(%s ; %s)", firstStmt.toString(), secondStmt.toString());
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        MyIStack<IStmt> stack = state.getStack();
        stack.push(secondStmt);
        stack.push(firstStmt);
        state.setStack(stack);
        return state;
    }

    @Override
    public IStmt deepCopy() {
        return new CompStmt(firstStmt.deepCopy(), secondStmt.deepCopy());
    }
}
