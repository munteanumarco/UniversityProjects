import unittest
from src.domain.grade import Grade
from src.domain.validators import GradeValidator,StudentValidator,AssignmentValidator
from src.repository.assignments_repository import AssignmentsRepository
from src.repository.students_repository import StudentsRepository
from src.repository.grade_repository import GradesRepository
from src.services.grade_service import GradeService
from src.services.undo_redo import UndoManager
from src.services.undo_redo_handlers import UndoHandlers
from src.services.assignment_service import AssignmentService


class TestGradeService(unittest.TestCase):
    def generate_test_data(self):
        grade_service = GradeService(GradesRepository(), StudentValidator, AssignmentValidator, GradeValidator,AssignmentService(AssignmentsRepository,AssignmentValidator))
        return grade_service

    def test_add_assignment_to_student__DuplicateAssignmentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        students = StudentsRepository().get_students()
        assignments = AssignmentsRepository().get_assignments()
        student_id = 7
        assignment_id = 7
        UndoManager.register_operation(1,UndoHandlers.ADD_ASSIGNMENT_TO_STUDENT)
        #clear possible overlays(ex that student already has that Assignment
        grade_service.remove_student_assignments(student_id)
        #now we add the assignment to the student
        grade_service.add_assignment_to_student(student_id,assignment_id,None,students,assignments)
        #try to do it again
        try:
            grade_service.add_assignment_to_student(student_id, assignment_id, students, assignments)
            assert False
        except:
            assert True

    def test_add_assignment_to_student__NonExistentStudentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        students = StudentsRepository().get_students()
        assignments = AssignmentsRepository().get_assignments()
        student_id = 9999
        assignment_id = 7
        try:
            grade_service.add_assignment_to_student(student_id, assignment_id, students, assignments)
            assert False
        except:
            assert True

    #def get_student_ungraded_assignments(self,student_id,students):
    def test_get_student_ungraded_assignments__NegativeStudentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        students = StudentsRepository().get_students()
        student_id = -12
        try:
            grade_service.get_student_ungraded_assignments(student_id,students)
            assert False
        except:
            assert True

    def test_get_student_ungraded_assignments__NonExistentStudentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        students = StudentsRepository().get_students()
        student_id = 122222
        try:
            grade_service.get_student_ungraded_assignments(student_id, students)
            assert False
        except:
            assert True

    def test_grade_student_assignment__NegativeAssignmentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        grade = 10
        student_id = 8
        assignment_id = -222
        try:
            grade_service.grade_student_assignment(student_id,assignment_id,grade)
            assert False
        except:
            assert True

    def test_grade_student_assignment__NonExistentAssignmentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        grade = 10
        student_id = 8
        assignment_id = 222212
        try:
            grade_service.grade_student_assignment(student_id,assignment_id,grade)
            assert False
        except:
            assert True

    def test_grade_student_assignment__NegativeStudentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        grade = 10
        student_id = -18
        assignment_id = 2
        try:
            grade_service.grade_student_assignment(student_id,assignment_id,grade)
            assert False
        except:
            assert True

    def test_remove_student_assignments__NonExistentStudentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        student_id = 99999
        try:
            grade_service.remove_student_assignments(student_id)
            assert False
        except:
            assert True
    def test_remove_student_assignments__ValidStudentID__RemovedCorrectStudent(self):
        grade_service = self.generate_test_data()
        student_id = 15
        grade_service.remove_student_assignments(student_id)
        grades = grade_service.get_grades()
        for grade in grades:
            if grade.student_id == student_id:
                assert False
        assert True

    def test_remove_assignment_grades__NegativeAssignmentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        assignment_id = -24
        try:
            grade_service.remove_assignment_grades(assignment_id)
            assert False
        except:
            assert True

    def test_remove_assignment_grades__ValidAssignmentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        assignment_id = 12
        grade_service.remove_assignment_grades(assignment_id)
        grades = grade_service.get_grades()
        for grade in grades:
            if grade.assignment_id == assignment_id:
                assert False
        assert True

    def test_get_student_average_score_all_assignments__NonExistentStudentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        student_id = 99999
        try:
            grade_service.get_student_average_score_all_assignments(student_id)
            assert False
        except:
            assert True

    def test_get_student_average_score_all_assignments__NegativeStudentID__ExceptionThrown(self):
        grade_service = self.generate_test_data()
        student_id = -9999
        try:
            grade_service.get_student_average_score_all_assignments(student_id)
            assert False
        except:
            assert True




