package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Model.ADT.MyIDictionary;
import Model.Value.Value;

public interface IExpression {
    Value eval(MyIDictionary<String, Value> symTable) throws ExpEvalException, ADTException;
    IExpression deepCopy();
}
