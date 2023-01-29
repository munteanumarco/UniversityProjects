package model.statement;

import exceptions.InterpreterException;
import model.expression.IExpression;
import model.expression.RelationalExpression;
import model.expression.VariableExpression;
import model.programState.ProgramState;
import model.type.IntType;
import model.type.Type;
import model.utils.MyIDictionary;
import model.utils.MyIStack;

public class ForStatement implements IStatement {

    private final String var;
    private final IExpression exp1;
    private final IExpression exp2;
    private final IExpression exp3;
    private final IStatement stmt;

    public ForStatement(String var, IExpression exp1, IExpression exp2, IExpression exp3, IStatement stmt) {
        this.var = var;
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.exp3 = exp3;
        this.stmt = stmt;
    }

    @Override
    public ProgramState execute(ProgramState state) throws InterpreterException {

        MyIStack<IStatement> exeStack = state.getExeStack();
        IStatement newStatement = new CompoundStatement(new AssignStatement(this.var, this.exp1),
                        new WhileStatement(new RelationalExpression("<", new VariableExpression(this.var), this.exp2), new CompoundStatement(stmt,
                                new AssignStatement(this.var, this.exp3))));

        exeStack.push(newStatement);
        state.setExeStack(exeStack);
        return null;
    }

    @Override
    public IStatement deepCopy() {
        return new ForStatement(this.var, this.exp1.deepCopy(),this.exp2.deepCopy(),this.exp3.deepCopy(),this.stmt.deepCopy());
    }

    @Override
    public String toString() {
        return String.format("for(%s = %s; %s < %s; %s = %s) %s",this.var, this.exp1.toString(), this.var, this.exp2.toString(), this.var, this.exp3.toString(), this.stmt.toString());
    }

    @Override
    public MyIDictionary<String, Type> typeCheck(MyIDictionary<String, Type> typeEnv) throws InterpreterException {
        if (!this.exp1.typeCheck(typeEnv).equals(new IntType())) {
            throw new InterpreterException(String.format("%s cannot be evaluated as IntType", this.exp1));
        }
        if (!this.exp2.typeCheck(typeEnv).equals(new IntType())) {
            throw new InterpreterException(String.format("%s cannot be evaluated as IntType", this.exp2));
        }
        if (!this.exp3.typeCheck(typeEnv).equals(new IntType())) {
            throw new InterpreterException(String.format("%s cannot be evaluated as IntType", this.exp3));
        }
        return typeEnv;
    }
}
