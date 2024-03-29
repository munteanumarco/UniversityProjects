package Model.Statement;

import Exceptions.MyException;
import Exceptions.StmtExecutionException;
import Model.ADT.MyIDictionary;
import Model.ADT.MyIHeap;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.IntType;
import Model.Type.StringType;
import Model.Type.Type;
import Model.Value.IntValue;
import Model.Value.StringValue;
import Model.Value.Value;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements IStmt {

    private final IExpression expression;
    private final String varName;

    public ReadFile(IExpression expression, String varName) {
        this.expression = expression;
        this.varName = varName;
    }


    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyIDictionary<String, BufferedReader> fileTable = state.getFileTable();
        MyIHeap heap = state.getHeap();

        if (!symTable.isVarDef(this.varName)) {
            throw new StmtExecutionException(String.format("%s is not declared",this.varName));
        }
        if (!symTable.lookup(this.varName).getType().equals(new IntType())) {
            throw new StmtExecutionException(String.format("%s is not of IntType",this.varName));
        }

        Value v = this.expression.eval(symTable, heap);
        if (!v.getType().equals(new StringType())) {
            throw new StmtExecutionException(String.format("%s cannot be evaluated as StringType",this.expression.toString()));
        }
        StringValue fileName = (StringValue) v;
        if (!fileTable.isVarDef(fileName.getValue())) {
            throw new StmtExecutionException(String.format("%s not contained in the fileTable",fileName.toString()));
        }
        BufferedReader br = fileTable.lookup(fileName.getValue());
        try {
            String line = br.readLine();
            if (line == null) {
                line = "0";
            }
            symTable.put(this.varName, new IntValue(Integer.parseInt(line)));
            state.setSymTable(symTable);
        } catch (IOException e) {
            throw new StmtExecutionException(String.format("Cannot read from file %s", fileName.getValue()));
        }
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws MyException {
        if (expression.typeCheck(typeEnv).equals(new StringType())) {
            if (typeEnv.lookup(varName).equals(new IntType())) {
                return typeEnv;
            } else {
                throw new StmtExecutionException("ReadFile requires an int as its variable parameter");
            }
        } else {
            throw new StmtExecutionException("ReadFile requires a string as an expression parameter");
        }
    }

    @Override
    public String toString() {
        return String.format("ReadFile(%s,%s)",this.expression.toString(),this.varName);
    }

    @Override
    public IStmt deepCopy() {
        return new ReadFile(this.expression.deepCopy(),this.varName);
    }
}
