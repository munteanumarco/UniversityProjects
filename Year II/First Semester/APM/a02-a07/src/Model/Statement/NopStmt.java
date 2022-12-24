package Model.Statement;

import Exceptions.MyException;
import Model.ProgramState.ProgramState;

public class NopStmt implements IStmt {


    @Override
    public String toString() {
        return "NopStatement";
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        return null;
    }

    @Override
    public IStmt deepCopy() {
        return new NopStmt();
    }
}
