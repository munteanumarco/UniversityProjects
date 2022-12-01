package Model.Expression;

import Exceptions.ExpEvalException;
import Model.ADT.MyIDictionary;
import Model.Value.Value;

public class ValueExp implements IExpression {
    private Value value;

    public ValueExp(Value v) {
        this.value = v;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable) throws ExpEvalException {
        return this.value;
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
