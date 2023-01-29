package Model.ADT;

import Exceptions.ADTException;
import Exceptions.MyException;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;
import java.util.List;

public class MyStack<T> implements MyIStack<T> {
    private Stack<T> stack;
    public MyStack() {
        stack = new Stack<>();
    }

    @Override
    public void push(T elem) {
        this.stack.push(elem);
    }

    @Override
    public T pop() throws ADTException {
        if (this.isEmpty()) {
            throw new ADTException("Stack is empty!");
        }
        return this.stack.pop();
    }

    @Override
    public boolean isEmpty() {
        return this.stack.empty();
    }

    @Override
    public String toString() {
        return this.stack.toString();
    }

    @Override
    public T peek() {
        return this.stack.peek();
    }

    @Override
    public List<T> getReversed() {
        List<T> l = new ArrayList<T>(this.stack);
        Collections.reverse(l);
        return l;
    }
}
