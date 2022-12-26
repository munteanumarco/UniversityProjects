package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Exceptions.MyException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Type.RefType;
import Model.Type.Type;
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
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type t = expression.typeCheck(typeEnv);
        if (t instanceof RefType) {
            RefType reft = (RefType) t;
            return reft.getInner();
        } else {
            throw new MyException("the rH argument is not a RefType");
        }
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
