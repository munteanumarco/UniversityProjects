package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Exceptions.MyException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Type.Type;
import Model.Value.Value;

import java.util.HashMap;

public interface IExpression {
    Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ExpEvalException, ADTException;
    IExpression deepCopy();
    Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException;
}
