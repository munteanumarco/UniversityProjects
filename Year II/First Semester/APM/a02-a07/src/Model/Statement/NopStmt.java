package Model.Statement;

import Exceptions.MyException;
import Model.ADT.MyIDictionary;
import Model.ProgramState.ProgramState;
import Model.Type.Type;

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
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        return typeEnv;
    }

    @Override
    public IStmt deepCopy() {
        return new NopStmt();
    }
}
