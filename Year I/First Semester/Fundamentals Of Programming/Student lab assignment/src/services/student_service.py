from src.domain.validators import StudentLabAssignmentException
from src.domain.student import Student
from src.services.undo_redo_handlers import RedoHandlers,UndoHandlers
from src.services.undo_redo import RedoManager,UndoManager,Operation

class StudentServiceException(StudentLabAssignmentException):
    pass

class StudentService:
    def __init__(self,student_repository,validator):
        self._student_repository = student_repository
        self._validator = validator

    def get_students(self):
        return self._student_repository.get_students()

    def find_student_by_id(self,student_id,students):
        self._validator.validate_student_existence(student_id,students)
        return self._student_repository.find_student_by_id(student_id)

    def remove_student(self,student_id):
        students = self.get_students()
        self._validator.validate_student_existence(student_id,students)
        removed_student = self.find_student_by_id(student_id, students)
        self._student_repository.remove_student(student_id)
        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.REMOVE_STUDENT,removed_student.id,removed_student.name, removed_student.group)

    def remove_student_undo_redo_functionality(self,student_id):
        self._student_repository.remove_student(student_id)


    def add_student(self,student_id,student_name,student_group):
        new_student = Student(student_id,student_name,student_group)
        students = self.get_students()
        self._validator.validate_student_attributes(new_student)
        self._validator.validate_student_not_duplicate(new_student,students)
        self._student_repository.add_student(new_student)

        #register operation for undo functionality
        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.ADD_STUDENT, student_id, student_name,
                                       student_group)

    def add_student_undo_redo_functionality(self,student_id,name,group):
        new_student = Student(student_id,name,group)
        self._student_repository.add_student(new_student)

    def update_student_name(self,new_student_name,student_id):
        students = self.get_students()
        self._validator.validate_student_existence(student_id,students)
        student = self.find_student_by_id(student_id,students)
        old_name = student.student_name
        self._student_repository.update_student_name(new_student_name,student_id)
        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.UPDATE_STUDENT_NAME, old_name,
                                       new_student_name, student_id)
    def update_student_name_undo_redo_functionality(self,new_student_name,student_id):
        self._student_repository.update_student_name(new_student_name, student_id)

    def update_student_group(self,new_student_group,student_id):
        students = self.get_students()
        self._validator.validate_student_existence(student_id,students)
        student = self.find_student_by_id(student_id,students)
        old_group = student.student_group
        self._student_repository.update_student_group(new_student_group,student_id)
        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.UPDATE_STUDENT_GROUP, old_group,
                                       new_student_group, student_id)

    def update_student_group_undo_redo_functionality(self,new_student_group,student_id):
        self._student_repository.update_student_group(new_student_group, student_id)

