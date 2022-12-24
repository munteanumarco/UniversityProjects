package Model.Statement;

import Exceptions.MyException;
import Exceptions.StmtExecutionException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.ADT.MyIStack;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.RefType;
import Model.Value.RefValue;
import Model.Value.Value;

import java.util.concurrent.ExecutionException;

public class WriteHeapStmt implements IStmt {
    private final String varName;
    private final IExpression expression;

    public WriteHeapStmt(String varName, IExpression expression) {
        this.varName = varName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();

        if (!symTable.isVarDef(this.varName)) {
            throw new StmtExecutionException(String.format("%s is not declared",varName));
        }
        if (!(symTable.lookup(varName) instanceof RefValue)) {
            throw new StmtExecutionException(String.format("%s is not RefType",varName));
        }
        RefValue ref = (RefValue) symTable.lookup(varName);
        if (!heap.containsKey(ref.getAddress())) {
            throw new StmtExecutionException(String.format("%s is not in the heap",ref.toString()));
        }
        Value value = this.expression.eval(symTable, heap);
        if (!ref.getLocationType().equals(value.getType())) {
            throw new StmtExecutionException(String.format("%s cannot be evaluated to %s",expression.toString(), ref.getLocationType().toString()));
        }
        heap.update(ref.getAddress(), value);
        state.setHeap(heap);
        return null;
    }

    @Override
    public IStmt deepCopy() {
        return new WriteHeapStmt(varName,expression.deepCopy());
    }

    @Override
    public String toString() {
        return String.format("(%s,%s)", varName, expression.toString());
    }
}
