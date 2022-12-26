package Model.Statement;

import Exceptions.MyException;
import Exceptions.StmtExecutionException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.StringType;
import Model.Type.Type;
import Model.Value.StringValue;
import Model.Value.Value;

import javax.xml.crypto.dsig.spec.DigestMethodParameterSpec;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.nio.Buffer;

public class OpenReadFile implements IStmt {
    private final IExpression expression;

    public OpenReadFile(IExpression expression) {
        this.expression = expression;
    }

    @Override
    public IStmt deepCopy() {
        return new OpenReadFile(this.expression.deepCopy());
    }

    @Override
    public String toString() {
        return String.format("OpenReadFile(%s)", this.expression);
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        if (expression.typeCheck(typeEnv).equals(new StringType())) {
            return typeEnv;
        } else {
            throw new StmtExecutionException("OpenReadFile must take a string");
        }
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIHeap heap = state.getHeap();
        Value v = this.expression.eval(symTable, heap);
        if (v.getType().equals(new StringType())) {
            StringValue fileName = (StringValue) v;
            MyIDictionary<String, BufferedReader> fileTable = state.getFileTable();
            if (!fileTable.isVarDef(fileName.getValue())) {
                BufferedReader br;
                try {
                    br = new BufferedReader(new FileReader(fileName.getValue()));
                } catch (FileNotFoundException e) {
                    throw new StmtExecutionException(String.format("%s could not be opened", fileName.getValue()));
                }
                fileTable.put(fileName.getValue(),br);
                state.setFileTable(fileTable);
            } else {
                throw new StmtExecutionException(String.format("%s is already opened", fileName.getValue()));

            }
        } else {
            throw new StmtExecutionException(String.format("%s does not evaluate to StringType", this.expression.toString()));
        }
        return null;
    }
}
