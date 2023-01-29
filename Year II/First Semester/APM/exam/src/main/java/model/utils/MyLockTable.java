package model.utils;

import exceptions.InterpreterException;

import java.util.HashMap;
import java.util.Set;

public class MyLockTable implements MyILockTable{
    private HashMap<Integer, Integer> lockTable;
    private int nextFreeLocation = -1;

    public MyLockTable() {
        this.lockTable = new HashMap<>();

    }
    @Override
    public int getFreeValue() {
        synchronized (this) {
            nextFreeLocation++;
            return nextFreeLocation;
        }
    }

    @Override
    public void put(int key, int value) throws InterpreterException {
        synchronized (this) {
            if (!lockTable.containsKey(key)) {
                lockTable.put(key, value);
            } else {
                throw new InterpreterException(String.format("The key %d is already in the lock table!", key));
            }
        }
    }

    @Override
    public HashMap<Integer, Integer> getContent() {
        synchronized (this) {
            return lockTable;
        }
    }

    @Override
    public boolean containsKey(int position) {
        synchronized (this) {
            return lockTable.containsKey(position);
        }
    }

    @Override
    public int get(int position) throws InterpreterException {
        synchronized (this) {
            if (!lockTable.containsKey(position))
                throw new InterpreterException(String.format("The position %d is not in the lock table!", position));
            return lockTable.get(position);
        }
    }

    @Override
    public void update(int position, int value) throws InterpreterException {
        synchronized (this) {
            if (lockTable.containsKey(position)) {
                lockTable.replace(position, value);
            } else {
                throw new InterpreterException(String.format("The position %d is not present in the table!", position));
            }
        }
    }

    @Override
    public void setContent(HashMap<Integer, Integer> newMap) {
        synchronized (this) {
            this.lockTable = newMap;
        }
    }

    @Override
    public Set<Integer> keySet() {
        synchronized (this) {
            return lockTable.keySet();
        }
    }

    @Override
    public String toString() {
        return lockTable.toString();
    }
}
