package Model.Statement;

import Exceptions.MyException;
import Model.ProgramState.ProgramState;

public interface IStatement {
    ProgramState execute(ProgramState state) throws MyException;
    IStatement deepCopy();
}
