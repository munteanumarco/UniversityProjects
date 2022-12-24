package Repository;

import Exceptions.ADTException;
import Model.ProgramState.ProgramState;

import java.io.IOException;
import java.util.List;

public interface IRepository {
    List<ProgramState> getProgramList();
    void setProgramList(List<ProgramState> list);
    void addProgram(ProgramState state);
    void logPrgStateExec(ProgramState prgState) throws IOException, ADTException;
}
