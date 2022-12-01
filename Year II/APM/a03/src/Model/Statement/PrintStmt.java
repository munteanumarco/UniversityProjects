package Model.Statement;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Exceptions.MyException;
import Model.ADT.MyIList;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Value.Value;

public class PrintStatement implements IStatement {
    IExpression expression;

    public PrintStatement(IExpression expression) {
        this.expression = expression;
    }

    @Override
    public IStatement deepCopy() {
        return new PrintStatement(expression.deepCopy());
    }

    @Override
    public String toString() {
        return String.format("Print(%s)", expression.toString());
    }

    @Override
    public ProgramState execute(ProgramState state) throws ExpEvalException, ADTException {
        MyIList<Value> out = state.getOut();
        out.add(expression.eval(state.getSymTable()));
        state.setOut(out);
        return state;
    }
}
