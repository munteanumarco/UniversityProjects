package Model.Statement;

import Exceptions.MyException;
import Exceptions.StmtExecutionException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.RefType;
import Model.Type.Type;
import Model.Value.RefValue;
import Model.Value.Value;

public class NewStmt implements IStmt {

    private final String varName;
    private final IExpression expression;

    public NewStmt(String varName, IExpression expression) {
        this.varName = varName;
        this.expression = expression;
    }


    @Override
    public String toString() {
        return String.format("New(%s, %s)", varName, expression);
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();

        if (!symTable.isVarDef(this.varName)) {
            throw new StmtExecutionException(this.varName + " is not declared") ;
        }
        if (!(symTable.lookup(varName) instanceof RefValue)) {
            throw new StmtExecutionException(this.varName + " is not of type RefType");
        }
        RefValue ref = (RefValue) symTable.lookup(varName);
        Value value = this.expression.eval(symTable, heap);
        if (!value.getType().equals(ref.getLocationType())) {
            throw new StmtExecutionException(this.expression.toString() + " cannot be evaluated to " + ref.getType().toString());
        }
        int newPos = heap.add(value);
        symTable.put(varName, new RefValue(newPos, ref.getLocationType()));
        state.setSymTable(symTable);
        state.setHeap(heap);
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        Type typeVar = typeEnv.lookup(varName);
        Type typeExp = expression.typeCheck(typeEnv);
        if (typeVar.equals(new RefType(typeExp))) {
            return typeEnv;
        } else {
            throw new MyException("New Stmt: right hand side and left hand side have different types");
        }
    }

    @Override
    public IStmt deepCopy() {
        return new NewStmt(varName, expression.deepCopy());
    }
}
