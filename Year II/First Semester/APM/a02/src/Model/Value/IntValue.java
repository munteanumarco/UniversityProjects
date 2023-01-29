package Model.Value;

import Model.Type.IntType;
import Model.Type.Type;

public class IntValue implements Value{

    private final int value;

    public IntValue(int value) {
        this.value = value;
    }

    @Override
    public Type getType() {
        return new IntType();
    }

    @Override
    public Value deepCopy() {
        return new IntValue(this.value);
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof IntValue)) {
            return false;
        }
        IntValue castValue = (IntValue) obj;
        return this.value == castValue.value;
    }

    public int getValue() {
        return this.value;
    }

    @Override
    public String toString() {
        return String.format("%d", this.value);
    }
}
