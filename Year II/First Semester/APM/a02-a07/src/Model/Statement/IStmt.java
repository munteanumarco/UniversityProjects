package Model.Statement;

import Exceptions.MyException;
import Model.ADT.MyIDictionary;
import Model.ProgramState.ProgramState;
import Model.Type.Type;

public interface IStmt {
    ProgramState execute(ProgramState state) throws MyException;
    IStmt deepCopy();
    MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException;
}
