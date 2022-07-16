from src.domain.validators import StudentLabAssignmentException
from dataclasses import dataclass
class UndoManagerException(StudentLabAssignmentException):
    pass

class RedoManagerException(StudentLabAssignmentException):
    pass

@dataclass
class Operation:
    target_object: object
    handler: object
    arguments: object

class UndoManager:
    __undo_operations = []

    @staticmethod
    def register_operation(target_object, handler, *arguments):
        UndoManager.__undo_operations.append(Operation(target_object,handler,arguments))

    @staticmethod
    def complete_last_operation(*arguments):
        UndoManager.__undo_operations[-1].arguments = UndoManager.__undo_operations[-1].arguments + arguments
        # last_operation = UndoManager.__undo_operations.pop()
        # last_operation.arguments =last_operation.arguments + arguments
        # UndoManager.__undo_operations.append(last_operation)

    @staticmethod
    def undo():
        try:
            undo_operation = UndoManager.__undo_operations.pop()
        except:
            raise UndoManagerException("No operation to undo\n")
        undo_operation.handler(undo_operation.target_object,*undo_operation.arguments)


class RedoManager:
    __redo_operations = []

    @staticmethod
    def register_operation(target_object,handler,*arguments):
        RedoManager.__redo_operations.append(Operation(target_object,handler,arguments))

    @staticmethod
    def redo():
        try:
            redo_operation = RedoManager.__redo_operations.pop()
        except:
            raise RedoManagerException("No undo done\n")
        redo_operation.handler(redo_operation.target_object,*redo_operation.arguments)

    @staticmethod
    def clear_redo_operations():
        RedoManager.__redo_operations = []