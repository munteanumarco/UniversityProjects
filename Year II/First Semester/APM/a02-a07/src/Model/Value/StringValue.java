package Model.Value;

import Model.Type.StringType;
import Model.Type.Type;

public class StringValue implements Value{

    private final String value;

    public StringValue(String value) {
        this.value = value;
    }

    @Override
    public Type getType() {
        return new StringType();
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof StringValue o) {
            return this.value == o.getValue();
        }
        return false;
    }

    @Override
    public Value deepCopy() {
        return new StringValue(this.value);
    }

    @Override
    public String toString() {
        return String.format("%s", this.value);
    }

    public String getValue() {
        return this.value;
    }


}
