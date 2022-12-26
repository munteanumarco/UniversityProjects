package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Exceptions.MyException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Type.IntType;
import Model.Type.Type;
import Model.Value.IntValue;
import Model.Value.Value;

public class ArithExp implements IExpression {

    private IExpression exp1;
    private IExpression exp2;
    private int opCode; // 1 for +, 2 for -, 3 for *, 4 for /
    public ArithExp(IExpression exp1, IExpression exp2, int opCode) {
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.opCode = opCode;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symTable, MyIHeap heap) throws ExpEvalException, ADTException {
        Value value1,value2;
        value1 = exp1.eval(symTable, heap);
        if (value1.getType().equals(new IntType())) {
            value2 = exp2.eval(symTable, heap);
            if (value2.getType().equals(new IntType())) {
                IntValue i1 = (IntValue) value1;
                IntValue i2 = (IntValue) value2;
                int intValue1, intValue2;
                intValue1 = i1.getValue();
                intValue2 = i2.getValue();
                if (opCode == 1) {
                    return new IntValue(intValue1+intValue2);
                }
                if (opCode == 2) {
                    return new IntValue(intValue1-intValue2);
                }
                if(opCode == 3) {
                    return new IntValue(intValue1*intValue2);
                }
                if (opCode == 4) {
                    if (intValue2 == 0) {
                        throw new ExpEvalException("Division by zero!");
                    }
                    return new IntValue(intValue1/intValue2);
                }
            } else {
                throw new ExpEvalException("Second operand is not an integer.");
            }
        } else {
            throw new ExpEvalException("First operand is not an integer.");
        }
        return null;
    }

    @Override
    public Type typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type type1, type2;
        type1 = exp1.typeCheck(typeEnv);
        type2 = exp2.typeCheck(typeEnv);
        if (type1.equals(new IntType())) {
            if (type2.equals(new IntType())) {
                return new IntType();
            } else {
                throw new MyException("Second operand is not an integer");
            }
        } else {
            throw new MyException("First operand is not an integer");
        }
    }

    @Override
    public IExpression deepCopy() {
        return new ArithExp(exp1.deepCopy(), exp2.deepCopy(), opCode);
    }

    @Override
    public String toString() {
        return exp1.toString() + " " + opCode + " " + exp2.toString();
    }
}
