package Model.ADT;

import Exceptions.ADTException;
import Model.Value.Value;

import java.util.HashMap;
import java.util.Set;

public class MyHeap implements MyIHeap {

    private HashMap<Integer, Value> heap;
    private Integer freeLocation;

    public MyHeap() {
        this.heap = new HashMap<>();
        this.freeLocation = 1;
    }

    private int newFreeLocation() {
        this.freeLocation += 1;
        while(this.freeLocation == 0  || this.heap.containsKey(this.freeLocation)) {
            this.freeLocation += 1;
        }
        return this.freeLocation;
    }

    @Override
    public int getFreeLocation() {
        return this.freeLocation;
    }

    @Override
    public HashMap<Integer, Value> getContent() {
        return this.heap;
    }

    @Override
    public void setContent(HashMap<Integer, Value> newHeap) {
        this.heap = newHeap;
    }

    @Override
    public int add(Value newValue) {
        heap.put(this.freeLocation, newValue);
        Integer addressToReturn  = this.freeLocation;
        this.freeLocation = this.newFreeLocation();
        return addressToReturn;
    }

    @Override
    public void update(Integer address, Value newValue) throws ADTException {
        if (!heap.containsKey(address)) {
            throw new ADTException("Address doesn't exist in the heap");
        }
        heap.put(address, newValue);
    }

    @Override
    public Value get(Integer address) throws ADTException {
        if (!heap.containsKey(address)) {
            throw new ADTException("Address doesn't exist in the heap");
        }
        return heap.get(address);
    }

    @Override
    public boolean containsKey(Integer address) {
        return heap.containsKey(address);
    }

    @Override
    public void remove(Integer address) throws ADTException {
        if (!heap.containsKey(address)) {
            throw new ADTException("Address doesn't exist in the heap");
        }
        freeLocation = address;
        heap.remove(address);
    }

    @Override
    public Set<Integer> keySet() {
        return this.heap.keySet();
    }

    @Override
    public String toString() {
        return this.heap.toString();
    }
}
