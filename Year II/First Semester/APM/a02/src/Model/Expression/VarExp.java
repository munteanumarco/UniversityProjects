package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Exceptions.MyException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Type.Type;
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
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        return typeEnv.lookup(id);
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
