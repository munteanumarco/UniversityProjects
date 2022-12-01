package Model.ADT;

import Exceptions.MyException;

import java.util.HashMap;
import java.util.Map;

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
    public V lookup(K key) throws MyException {
        V value = this.map.get(key);
        if (value == null) {
            throw new MyException("Id not declared!");
        }
        return value;
    }

    @Override
    public void update(K key, V value) throws MyException {
        if (!this.isVarDef(key)){
            throw new MyException("Id not declared!");
        }
        this.put(key, value);
    }

    @Override
    public String toString() {
        return this.map.toString();
    }
}
