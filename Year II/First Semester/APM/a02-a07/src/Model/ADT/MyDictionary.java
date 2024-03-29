package Model.ADT;

import Exceptions.ADTException;
import Exceptions.InterpreterException;
import Exceptions.MyException;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MyDictionary<K,V> implements MyIDictionary<K,V> {
    private Map<K,V> map;
    public MyDictionary() {
        this.map = new HashMap<K,V>();
    }

    @Override
    public V put(K key, V value) {
        return map.put(key, value);
    }

    @Override
    public boolean isVarDef(K key) {
        return this.map.containsKey(key);
    }

    @Override
    public V lookup(K key) throws ADTException {
        V value = this.map.get(key);
        if (value == null) {
            throw new ADTException("Id not declared!");
        }
        return value;
    }

    @Override
    public void update(K key, V value) throws ADTException {
        if (!this.isVarDef(key)){
            throw new ADTException("Id not declared!");
        }
        this.put(key, value);
    }

    @Override
    public void remove(K key) throws InterpreterException {
        if (!isVarDef(key)) {
            throw new InterpreterException(key + " is not defined.");
        }
        this.map.remove(key);
    }

    @Override
    public MyIDictionary<K, V> deepcopy() throws ADTException {
        MyIDictionary<K,V> newDict = new MyDictionary<>();
        for (K key: keySet()) {
            newDict.put(key, lookup(key));
        }
        return newDict;
    }

    @Override
    public Set<K> keySet() {
        return this.map.keySet();
    }

    @Override
    public Map<K, V> getContent() {
        return this.map;
    }

    @Override
    public String toString() {
        return this.map.toString();
    }
}
