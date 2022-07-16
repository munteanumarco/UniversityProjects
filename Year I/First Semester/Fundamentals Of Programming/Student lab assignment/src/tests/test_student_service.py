import unittest
from src.services.student_service import StudentService
from src.repository.students_repository import StudentsRepository
from src.domain.student import Student
from src.domain.validators import StudentValidator


class TestStudentService(unittest.TestCase):
    def generate_testing_data(self):
        student_service = StudentService(StudentsRepository(),StudentValidator)
        return student_service

    def test_add_student__DuplicateID__ExceptionThrown(self):
        student_service = self.generate_testing_data()
        student_id = 1
        student_name = "Andrei Moraru"
        student_group = 916
        try:
            student_service.add_student(student_id, student_name, student_group)
            assert False
        except:
            assert True
    def test_remove_student__NonExistentID__ExceptionThrown(self):
        student_service = self.generate_testing_data()
        student_id = 99
        try:
            student_service.remove_student(student_id)
            assert False
        except:
            assert True

    def test_update_student_name__NegativeID__ExceptionThrown(self):
        student_service = self.generate_testing_data()
        new_student_name = "John"
        student_id = -1
        try:
            student_service.update_student_name(new_student_name,student_id)
            assert False
        except:
            assert True

    def test_update_student_group__NonExistentID__ExceptionThrown(self):
        student_service = self.generate_testing_data()
        new_group = 999
        student_id = 10000
        try:
            student_service.update_student_group(new_group,student_id)
            assert False
        except:
            assert True
