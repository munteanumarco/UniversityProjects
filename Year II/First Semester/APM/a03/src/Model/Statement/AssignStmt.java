package Model.Statement;

import Exceptions.MyException;
import Exceptions.StmtExecutionException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.ADT.MyIStack;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.Type;
import Model.Value.Value;

public class AssignStmt implements IStmt {
    private String id;
    private IExpression expression;


    public AssignStmt(String id, IExpression expression) {
        this.id = id;
        this.expression = expression;
    }

    @Override
    public String toString() {
        return String.format("%s = %s", id, expression.toString());
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();
        if (symTable.isVarDef(id)) {
            Value val = expression.eval(symTable, heap);
            Type typeId = (symTable.lookup(id).getType());
            if ((val.getType()).equals(typeId)) {
                symTable.update(id, val);
                state.setSymTable(symTable);
            } else {
                throw new StmtExecutionException(String.format("declared type of variable %s and type of the assigned expression do not match", id.toString()));
            }
        } else {
            throw new StmtExecutionException(String.format("The used variable %s was not declared before.", id));
        }
        return null;
    }

    @Override
    public IStmt deepCopy() {
        return new AssignStmt(id, expression.deepCopy());
    }
}
