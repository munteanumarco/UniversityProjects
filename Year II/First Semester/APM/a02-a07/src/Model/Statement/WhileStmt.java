package Model.Statement;

import Exceptions.MyException;
import Exceptions.StmtExecutionException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.ADT.MyIStack;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.BoolType;
import Model.Value.BoolValue;
import Model.Value.Value;

public class WhileStmt implements IStmt {
    private final IExpression expression;
    private final IStmt statement;

    public WhileStmt(IExpression expression, IStmt statement) {
        this.expression = expression;
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();
        MyIStack<IStmt> stack = state.getStack();

        Value value = expression.eval(symTable, heap);
        if (!value.getType().equals(new BoolType())) {
            throw new StmtExecutionException(this.expression.toString() + " does not evaluate to BoolType");
        }
        BoolValue boolVal = (BoolValue) value;
        if (boolVal.getValue() == true) {
            stack.push(this.deepCopy());
            stack.push(statement);
            state.setStack(stack);
        }
        return null;
    }

    @Override
    public String toString() {
        return String.format("while(%s){%s}", expression, statement);
    }

    @Override
    public IStmt deepCopy() {
        return new WhileStmt(expression.deepCopy(), statement.deepCopy());
    }
}
