package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Model.ADT.MyIDictionary;
import Model.Type.IntType;
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
    public Value eval(MyIDictionary<String, Value> symTable) throws ExpEvalException, ADTException {
        Value value1,value2;
        value1 = exp1.eval(symTable);
        if (value1.getType().equals(new IntType())) {
            value2 = exp2.eval(symTable);
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
    public IExpression deepCopy() {
        return new ArithExp(exp1.deepCopy(), exp2.deepCopy(), opCode);
    }

    @Override
    public String toString() {
        return exp1.toString() + " " + opCode + " " + exp2.toString();
    }
}
