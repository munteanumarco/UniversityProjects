package Model.Statement;

import Exceptions.MyException;
import Model.ProgramState.ProgramState;

public interface IStmt {
    ProgramState execute(ProgramState state) throws MyException;
    IStmt deepCopy();
}
