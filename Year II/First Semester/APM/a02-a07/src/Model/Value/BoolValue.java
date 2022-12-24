package Model.Value;

import Model.Type.BoolType;
import Model.Type.Type;

public class BoolValue implements Value {

    private final boolean value;

    public BoolValue(boolean value) {
        this.value = value;
    }

    @Override
    public Type getType() {
        return new BoolType();
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof BoolValue)) {
            return false;
        }
        BoolValue castValue = (BoolValue) obj;
        return this.value == castValue.value;
    }

    @Override
    public Value deepCopy() {
        return new BoolValue(this.value);
    }

    public boolean getValue() {
        return this.value;
    }

    @Override
    public String toString() {
        return this.value ? "true" : "false";
    }
}
