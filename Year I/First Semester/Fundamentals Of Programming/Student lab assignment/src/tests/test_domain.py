import datetime
import unittest
from src.domain.student import Student
from src.domain.assignment import Assignment
from src.domain.grade import Grade

class TestStudent(unittest.TestCase):
    def test_property_getter__ValidValues__GotCorrectStudentValues(self):
        new_student = Student(1,"Andrei Bratu",915)
        assert new_student.name == "Andrei Bratu"
        assert new_student.id == 1
        assert  new_student.group == 915
    def test_property_setter__ValidValues__SetCorrectStudentValues(self):
        new_student = Student(0,"",None)
        new_student.student_group = 915
        new_student.id = 1
        new_student.student_name = "Mihai Mitrache"
        assert new_student.id == 1
        assert  new_student.name == "Mihai Mitrache"
        assert new_student.group == 915

class TestAssignment(unittest.TestCase):
    def test_property_getter__ValidValues__GotCorrectAssignmentValues(self):
        new_assignment = Assignment(1,"Description",datetime.date(2021,12,12))
        assert new_assignment.id == 1
        assert new_assignment.description == "Description"
        assert  new_assignment.deadline == datetime.date(2021,12,12)

    def test_property_setter__ValidValues__SetCorrectAssignmentValues(self):
        new_assignment = Assignment(0,"",0)
        new_assignment.id = 1
        new_assignment.description = "Desc"
        new_assignment.deadline = datetime.date(2021,12,12)
        assert new_assignment.id == 1
        assert new_assignment.description == "Desc"
        assert new_assignment.deadline == datetime.date(2021,12,12)

class TestGrade(unittest.TestCase):
    def test_property_getter__ValidValues__GotCorrectGradeValues(self):
        new_grade = Grade(1,1,10)
        assert new_grade.assignment_id == 1
        assert new_grade.student_id == 1
        assert new_grade.value == 10

    def test_property_setter__ValidValues__SetCorrectGradeValues(self):
        new_grade = Grade(0,0,None)
        new_grade.student_id = 10
        new_grade.assignment_id = 10
        new_grade.value = 10
        assert new_grade.assignment_id == 10
        assert new_grade.student_id == 10
        assert new_grade.value == 10