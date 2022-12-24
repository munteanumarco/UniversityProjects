package Model.Type;


import Model.Value.Value;

public interface Type {
    boolean equals(Type t);
    Value defaultValue();
    Type deepCopy();
}
