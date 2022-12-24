package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Value.Value;

public class VarExp implements IExpression {

    private String id;

    public VarExp(String id) {
        this.id = id;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ExpEvalException, ADTException {
        return symTable.lookup(id);
    }

    @Override
    public IExpression deepCopy() {
        return new VarExp(this.id);
    }

    @Override
    public String toString() {
        return id;
    }
}
