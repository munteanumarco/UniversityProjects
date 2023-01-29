package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Exceptions.MyException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Type.BoolType;
import Model.Type.Type;
import Model.Value.BoolValue;
import Model.Value.Value;

import javax.swing.text.StyledEditorKit;

public class LogicExp implements IExpression {
    private IExpression exp1;
    private IExpression exp2;
    int opCode; // 1 - and;  2 - or;

    public LogicExp(IExpression exp1, IExpression exp2, int opCode) {
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.opCode = opCode;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ExpEvalException, ADTException {
        Value value1, value2;
        value1 = exp1.eval(symTable, heap);
        if (value1.getType() == new BoolType()) {
            value2 = exp2.eval(symTable, heap);
            if (value2.getType() == new BoolType()) {
                BoolValue bool1 = (BoolValue) value1;
                BoolValue bool2 = (BoolValue) value2;
                boolean b1,b2;
                b1 = bool1.getValue();
                b2 = bool2.getValue();
                if (opCode == 1) {
                    return new BoolValue(b1 && b2);
                }
                if (opCode == 2){
                    return new BoolValue(b1 || b2);
                }
            } else {
                throw new ExpEvalException("Second operand cannot be evaluated as boolean");
            }
        } else {
            throw new ExpEvalException("First operand cannot be evaluated as boolean");
        }
        return null;
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type t1 = exp1.typeCheck(typeEnv);
        Type t2 = exp2.typeCheck(typeEnv);
        if (t1.equals(new BoolType())) {
            if (t2.equals(new BoolType())) {
                return new BoolType();
            } else {
                throw new MyException("Second operand is not a boolean");
            }
        } else {
            throw new MyException("First operand is not a boolean");
        }
    }

    @Override
    public IExpression deepCopy() {
        return new LogicExp(this.exp1.deepCopy(), this.exp2.deepCopy(), opCode);
    }

    @Override
    public String toString() {
        return exp1.toString() + " "  + opCode + " " + exp2.toString();
    }
}
