package Model.ADT;

import Exceptions.ADTException;
import Exceptions.MyException;
import java.util.List;

public interface MyIStack<T> {
    void push(T elem);
    T pop() throws ADTException;
    T peek();
    boolean isEmpty();
    List<T> getReversed();
}
