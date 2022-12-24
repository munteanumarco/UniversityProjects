package Model.Statement;

import Exceptions.ADTException;
import Exceptions.ExpEvalException;
import Model.ADT.MyIList;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Value.Value;

public class PrintStmt implements IStmt {
    IExpression expression;

    public PrintStmt(IExpression expression) {
        this.expression = expression;
    }

    @Override
    public IStmt deepCopy() {
        return new PrintStmt(expression.deepCopy());
    }

    @Override
    public String toString() {
        return String.format("Print(%s)", expression.toString());
    }

    @Override
    public ProgramState execute(ProgramState state) throws ExpEvalException, ADTException {
        MyIList<Value> out = state.getOut();
        out.add(expression.eval(state.getSymTable(), state.getHeap()));
        state.setOut(out);
        return null;
    }
}
