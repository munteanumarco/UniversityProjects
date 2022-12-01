package Model.ADT;

import Exceptions.MyException;
import java.util.List;

public interface MyIStack<T> {
    void push(T elem);
    T pop() throws MyException;
    T peek();
    boolean isEmpty();
    List<T> getReversed();
    String toString();
}
