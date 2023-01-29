package Model.Expression;

import Exceptions.ExpEvalException;
import Exceptions.MyException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Type.Type;
import Model.Value.Value;

public class ValueExp implements IExpression {
    private Value value;

    public ValueExp(Value v) {
        this.value = v;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ExpEvalException {
        return this.value;
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        return value.getType();
    }

    @Override
    public String toString() {
        return value.toString();
    }

    @Override
    public IExpression deepCopy() {
        return new ValueExp(value.deepCopy());
    }
}
