package Model.ADT;

import Exceptions.ADTException;
import Exceptions.InterpreterException;
import Exceptions.MyException;

import java.util.Map;
import java.util.Set;

public interface MyIDictionary<K,V> {
    V put(K key, V value);
    V lookup(K key) throws ADTException;
    boolean isVarDef(K key);
    void update(K key, V value) throws ADTException;
    void remove(K key) throws InterpreterException;
    Set<K> keySet();
    Map<K,V> getContent();
}
