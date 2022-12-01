package Repository;

import Exceptions.ADTException;
import Model.ProgramState.ProgramState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repository implements IRepository {
    private List<ProgramState> programStates;
    private int currentPosition;

    private final String logFilePath;
    public Repository(ProgramState state, String logFilePath) {
        this.logFilePath = logFilePath;
        this.programStates = new ArrayList<>();
        this.currentPosition = 0;
        this.addProgram(state);
    }

    @Override
    public void addProgram(ProgramState state) {
        this.programStates.add(state);
    }

    @Override
    public List<ProgramState> getProgramList() {
        return this.programStates;
    }

    @Override
    public ProgramState getCurrentProgram() {
        return this.programStates.get(this.currentPosition);
    }

    @Override
    public void logPrgStateExec() throws IOException, ADTException {
        PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
        logFile.println(this.programStates.get(0).programStateToString());
        logFile.close();
    }
}
