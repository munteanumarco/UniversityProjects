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

public class UnlockStatement implements IStatement{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public UnlockStatement(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws InterpreterException {
        lock.lock();

        MyIDictionary<String, Value> symTable = state.getSymTable();
        MyILockTable lockTable = state.getLockTable();

        if (!symTable.isDefined(this.var)) {
            throw new InterpreterException(String.format("Variable %s is not defined!", this.var));
        }
        if (!symTable.lookUp(this.var).getType().equals(new IntType())) {
            throw new InterpreterException(String.format("Variable %s is not of IntType!", this.var));
        }

        IntValue iv = (IntValue) symTable.lookUp(this.var);
        int index = iv.getValue();

        if (!lockTable.containsKey(index)) {
            throw new InterpreterException(String.format("Variable index %s is not in the lock table!", this.var));
        }

        if (lockTable.get(index) == state.getId()) {
            lockTable.update(index, -1);
        }

        lock.unlock();
        return null;
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws InterpreterException {
        if (!typeEnv.lookUp(var).equals(new IntType())) {
            throw new InterpreterException(String.format("Variable %s is not of IntType!", this.var));
        }
        return typeEnv;
    }

    @Override
    public IStatement deepCopy() {
        return new UnlockStatement(this.var);
    }

    @Override
    public String toString() {
        return String.format("unlock(%s)", this.var);
    }
}
