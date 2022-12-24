package Model.Statement;

import Exceptions.MyException;
import Exceptions.StmtExecutionException;
import Model.ADT.MyIDictionary;
import Model.ProgramState.ProgramState;
import Model.Type.Type;
import Model.Value.Value;

import java.security.Key;

public class VarDeclStmt implements IStmt {
    private String name;
    private Type type;

    public VarDeclStmt(String name, Type t) {
        this.name = name;
        this.type = t;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        MyIDictionary<String, Value> symTable = state.getSymTable();
        if (symTable.isVarDef(name)) {
            throw new StmtExecutionException("Variable " + name + " already exists in the symTable.");
        } else {
            symTable.put(name,type.defaultValue());
            state.setSymTable(symTable);
        }
        return null;
    }

    @Override
    public String toString() {
        return String.format("%s %s", type.toString(), name);
    }

    @Override
    public IStmt deepCopy() {
        return new VarDeclStmt(name, type);
    }
}
