from src.domain.assignment import Assignment
from src.services.undo_redo import UndoManager,RedoManager
from src.services.undo_redo_handlers import UndoHandlers,RedoHandlers

class AssignmentService:
    def __init__(self,assignment_repository,validator):
        self._assignment_repository = assignment_repository
        self._validator = validator

    def get_assignments(self):
        return self._assignment_repository.get_assignments()

    def find_assignment_by_id(self,assignment_id,assignments):
        self._validator.validate_assignment_existence(assignment_id,assignments)
        return self._assignment_repository.find_assignment_by_id(assignment_id)

    def remove_assignment(self,assignment_id):
        assignments = self.get_assignments()
        self._validator.validate_assignment_existence(assignment_id,assignments)
        removed_assignment = self.find_assignment_by_id(assignment_id,assignments)
        self._assignment_repository.remove_assignment(assignment_id)
        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.REMOVE_ASSIGNMENT,removed_assignment.id,
                                       removed_assignment.description, removed_assignment.deadline)

    def remove_assignment_undo_redo_functionality(self,assignment_id):
        self._assignment_repository.remove_assignment(assignment_id)

    def add_assignment(self,assignment_id,assignment_description,assignment_deadline):
        assignments = self.get_assignments()
        new_assignment = Assignment(assignment_id,assignment_description,assignment_deadline)
        self._validator.validate_assignment_attributes(new_assignment)
        self._validator.validate_assignment_not_duplicate(new_assignment,assignments)
        self._assignment_repository.add_assignment(new_assignment)
        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.ADD_ASSIGNMENT, assignment_id,assignment_description,assignment_deadline)

    def add_assignment_undo_redo_functionality(self,assignment_id,assignment_description,assignment_deadline):
        new_assignment = Assignment(assignment_id, assignment_description, assignment_deadline)
        self._assignment_repository.add_assignment(new_assignment)

    def update_assignment_description(self,new_description,assignment_id):
        assignments = self.get_assignments()
        self._validator.validate_assignment_existence(assignment_id,assignments)
        assignment = self.find_assignment_by_id(assignment_id,assignments)
        old_description = assignment.description
        self._assignment_repository.update_assignment_description(new_description,assignment_id)
        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.UPDATE_ASSIGNMENT_DESCRIPTION,
                                       old_description, new_description, assignment_id)

    def update_assignment_deadline(self,new_deadline,assignment_id):
        assignments = self.get_assignments()
        self._validator.validate_assignment_existence(assignment_id,assignments)
        assignment = self.find_assignment_by_id(assignment_id,assignments)
        old_deadline = assignment.deadline
        self._assignment_repository.update_assignment_deadline(new_deadline,assignment_id)
        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.UPDATE_ASSIGNMENT_DEADLINE, old_deadline,
                                       new_deadline, assignment_id)
    def update_assignment_description_undo_redo_functionality(self, new_description, assignment_id):
        self._assignment_repository.update_assignment_description(new_description, assignment_id)

    def update_assignment_deadline_undo_redo_functionality(self, new_deadline, assignment_id):
        self._assignment_repository.update_assignment_deadline(new_deadline, assignment_id)