package Model.ADT;

import Exceptions.ADTException;
import Model.Value.Value;

import java.util.HashMap;
import java.util.Set;

public interface MyIHeap {
    int getFreeLocation();
    HashMap<Integer, Value> getContent();
    void setContent(HashMap<Integer, Value> newHeap);
    int add(Value newValue);
    void update(Integer address, Value newValue) throws ADTException;
    Value get(Integer address) throws ADTException;
    boolean containsKey(Integer address);
    void remove(Integer address) throws ADTException;
    Set<Integer> keySet();
}

