import unittest
from src.domain.grade import Grade
from src.domain.student import Student
from src.repository.students_repository import StudentsRepository
from src.repository.assignments_repository import AssignmentsRepository
from src.repository.grade_repository import GradesRepository

class TestGradeRepository(unittest.TestCase):
    def test_add_assignment_to_student__ValidStudentAndAssignmentID__AddedCorrectly(self):
        grade_repository = GradesRepository()
        student_id = 3
        assignment_id = 3
        grade_repository.add_assignment_to_student(student_id, assignment_id,None)
        grades = grade_repository.get_grades()
        assert grades[-1].value == None
        assert grades[-1].student_id == student_id
        assert grades[-1].assignment_id == assignment_id

    def test_grade_student_assignment__ValidArguments__GradedCorrectly(self):
        grade_repository = GradesRepository()
        student_id = 2
        assignment_id = 12
        new_grade = 10
        grade_repository.grade_student_assignment(student_id,assignment_id,new_grade)
        grades = grade_repository.get_grades()
        for grade in grades:
            if grade.assignment_id == assignment_id and grade.student_id == student_id:
                assert grade.value == new_grade
                break

    def test_remove_student_assignments__ValidStudentID__RemovedCorrectStudentAssignments(self):
        grade_repository = GradesRepository()
        student_id = 10
        grade_repository.remove_student_assignments(student_id)
        grades = grade_repository.get_grades()
        for grade in grades:
            if grade.student_id == student_id:
                assert False
        assert True

    def test_remove_assignment_grades__ValidAssignmentID__RemovedCorrectAssignmentGrades(self):
        grade_repository = GradesRepository()
        assignment_id = 8
        grade_repository.remove_assignment_grades(assignment_id)
        grades = grade_repository.get_grades()
        for grade in grades:
            if grade.assignment_id == assignment_id:
                assert False
        assert True


