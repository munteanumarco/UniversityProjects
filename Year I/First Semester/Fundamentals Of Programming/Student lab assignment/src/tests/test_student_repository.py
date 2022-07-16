import unittest
from src.domain.student import Student
from src.repository.students_repository import StudentsRepository

class TestStudentsRepository(unittest.TestCase):
    def test_add_student__ValidID__AddedCorrectly(self):
        students_repository = StudentsRepository()
        students = students_repository.get_students()
        new_student = Student(12,"Popescu Ion",916)
        students_repository.add_student(new_student)
        assert students[12] == new_student
    def test_remove_student__ValidID__RemovedCorrectPosition(self):
        students_repository = StudentsRepository()
        students = students_repository.get_students()
        students_repository.remove_student(12)
        try:
            students[12]
            assert False
        except:
            assert True
    def test_update_student_name__ValidID__Updated(self):
        students_repository = StudentsRepository()
        students = students_repository.get_students()
        new_name = "John Wish"
        students_repository.update_student_name(new_name,5)
        assert students[5].name == new_name

    def test_update_student_group__ValidID__Updated(self):
        students_repository = StudentsRepository()
        students = students_repository.get_students()
        new_group = 917
        students_repository.update_student_group(new_group,1)
        assert students[1].group == new_group