package Model.Type;

import Model.Value.RefValue;
import Model.Value.Value;

public class RefType implements Type {

    private Type inner;
    public RefType(Type inner) {
        this.inner = inner;
    }
    Type getInner() {
        return this.inner;
    }

    @Override
    public boolean equals(Type another) {
        if (another instanceof RefType) {
            return inner.equals(((RefType) another).getInner());
        }
        else {
            return false;
        }
    }

    @Override
    public String toString() {
        return "Ref(" + inner.toString() + ")";
    }

    @Override
    public Value defaultValue() {
        return new RefValue(0, this.inner);
    }

    @Override
    public Type deepCopy() {
        return new RefType(this.inner.deepCopy());
    }
}
