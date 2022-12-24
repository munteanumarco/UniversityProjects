package Model.Statement;

import Exceptions.MyException;
import Exceptions.StmtExecutionException;
import Model.ADT.MyIStack;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.BoolType;
import Model.Value.BoolValue;
import Model.Value.Value;

public class IfStmt implements IStmt {
    private IExpression expression;
    IStmt thenStmt;
    IStmt elseStmt;

    public IfStmt(IExpression expression, IStmt thenStmt, IStmt elseStmt) {
        this.expression = expression;
        this.thenStmt = thenStmt;
        this.elseStmt = elseStmt;
    }

    @Override
    public String toString() {
        return String.format("IF(%s)THEN(%s)ELSE(%s)",expression.toString(),thenStmt.toString(),elseStmt.toString());
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        Value cond = expression.eval(state.getSymTable(), state.getHeap());
        if (cond instanceof BoolValue boolResult) {
            IStmt statement;
            if (boolResult.getValue()) {
                statement = this.thenStmt;
            } else {
                statement = this.elseStmt;
            }

            MyIStack<IStmt> stack = state.getStack();
            stack.push(statement);
            state.setStack(stack);
        }
        else {
            throw new StmtExecutionException("Please provide a boolean expression in an if statement.");
        }

        return null;
    }

    @Override
    public IStmt deepCopy() {
        return new IfStmt(this.expression.deepCopy(),this.thenStmt.deepCopy(), this.elseStmt.deepCopy());
    }
}
