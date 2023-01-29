package Model.Type;

import Model.Value.StringValue;
import Model.Value.Value;

public class StringType implements Type {

    @Override
    public boolean equals(Type t) {
        return t instanceof StringType;
    }

    @Override
    public Value defaultValue() {
        return new StringValue("");
    }

    @Override
    public Type deepCopy() {
        return new StringType();
    }

    @Override
    public String toString() {
        return "string";
    }
}
