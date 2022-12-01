package Model.Statement;

import Exceptions.MyException;
import Exceptions.StmtExecutionException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIList;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.StringType;
import Model.Value.StringValue;
import Model.Value.Value;

import javax.xml.crypto.dsig.spec.DigestMethodParameterSpec;
import java.io.BufferedReader;
import java.io.IOException;

public class CloseReadFile implements IStmt {

    private final IExpression expression;

    public CloseReadFile(IExpression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {

        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIDictionary<String,BufferedReader> fileTable = state.getFileTable();

        Value v = this.expression.eval(symTable);
        if (!v.getType().equals(new StringType())) {
            throw new StmtExecutionException(String.format("%s cannot be evaluated as StringType", this.expression.toString()));
        }
        StringValue fileName = (StringValue) v;
        if (!fileTable.isVarDef(fileName.getValue())) {
            throw new StmtExecutionException(String.format("%s is not opened", fileName.getValue()));
        }
        BufferedReader br = fileTable.lookup(fileName.getValue());
        try {
            br.close();
        } catch (IOException e) {
            throw new StmtExecutionException(String.format("Cannot close %s", fileName.getValue()));
        }
        fileTable.remove(fileName.getValue());
        state.setFileTable(fileTable);
        return state;
    }

    @Override
    public String toString() {
        return String.format("CloseReadFile(%s)",this.expression.toString());
    }

    @Override
    public IStmt deepCopy() {
        return new CloseReadFile(this.expression.deepCopy());
    }
}
