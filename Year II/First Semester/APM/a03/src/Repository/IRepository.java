package Repository;

import Exceptions.ADTException;
import Model.ProgramState.ProgramState;

import java.io.IOException;
import java.util.List;

public interface IRepository {
    List<ProgramState> getProgramList();
    void addProgram(ProgramState state);
    ProgramState getCurrentProgram();
    void logPrgStateExec() throws IOException, ADTException;
}
