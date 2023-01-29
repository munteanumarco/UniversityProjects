package model.statement;

import exceptions.InterpreterException;
import model.programState.ProgramState;
import model.type.IntType;
import model.type.Type;
import model.utils.MyIDictionary;
import model.utils.MyILockTable;
import model.value.IntValue;
import model.value.Value;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewLockStatement implements IStatement{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public NewLockStatement(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws InterpreterException {
        lock.lock();
        MyILockTable lockTable = state.getLockTable();
        MyIDictionary<String, Value> symTable = state.getSymTable();

        int nextFreeAddress = lockTable.getFreeValue();
        lockTable.put(nextFreeAddress, -1);

        if (!symTable.isDefined(var)) {
            throw new InterpreterException(String.format("Variable %s is not declared!", this.var));
        }
        if (!symTable.lookUp(this.var).getType().equals(new IntType())) {
            throw new InterpreterException(String.format("Variable %s is not of IntType", this.var));
        }

        symTable.update(this.var, new IntValue(nextFreeAddress));
        lock.unlock();

        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws InterpreterException {
        if (!typeEnv.lookUp(var).equals(new IntType())) {
            throw new InterpreterException(String.format("Variable %s is not of int type!", this.var));
        }
        return typeEnv;
    }

    @Override
    public IStatement deepCopy() {
        return new NewLockStatement(this.var);
    }

    @Override
    public String toString() {
        return String.format("newLock(%s)", this.var);
    }
}
