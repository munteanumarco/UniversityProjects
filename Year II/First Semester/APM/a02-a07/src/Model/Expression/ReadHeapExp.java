package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Type.RefType;
import Model.Value.RefValue;
import Model.Value.Value;

import java.rmi.registry.Registry;

public class ReadHeapExp implements IExpression {
    private final IExpression expression;

    public ReadHeapExp(IExpression expression) {
        this.expression = expression;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ExpEvalException, ADTException {
        Value value = this.expression.eval(symTable, heap);
        if (!(value instanceof RefValue)) {
            throw new ExpEvalException(String.format("%s is not evaluated to RefValue", expression.toString()));
        }
        RefValue ref = (RefValue) value;
        return heap.get(ref.getAddress());
    }

    @Override
    public String toString() {
        return String.format("ReadHeap(%s)", this.expression.toString());
    }

    @Override
    public IExpression deepCopy() {
        return new ReadHeapExp(this.expression.deepCopy());
    }
}
