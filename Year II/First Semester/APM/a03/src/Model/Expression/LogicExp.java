package Model.Expression;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Model.ADT.MyIDictionary;
import Model.Type.BoolType;
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
    public Value eval(MyIDictionary<String, Value> symTable) throws ExpEvalException, ADTException {
        Value value1, value2;
        value1 = exp1.eval(symTable);
        if (value1.getType() == new BoolType()) {
            value2 = exp2.eval(symTable);
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
    public IExpression deepCopy() {
        return new LogicExp(this.exp1.deepCopy(), this.exp2.deepCopy(), opCode);
    }

    @Override
    public String toString() {
        return exp1.toString() + " "  + opCode + " " + exp2.toString();
    }
}
