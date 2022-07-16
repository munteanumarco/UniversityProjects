import unittest
import datetime
from src.services.assignment_service import AssignmentService
from src.domain.assignment import Assignment
from src.domain.validators import AssignmentValidator
from src.repository.assignments_repository import AssignmentsRepository


class TestAssignmentService(unittest.TestCase):

    def generate_testing_data(self):
        assignment_service = AssignmentService(AssignmentsRepository(), AssignmentValidator)
        return assignment_service
    def test_add_assignment__DuplicateID__ExceptionThrown(self):
        assignment_service = self.generate_testing_data()
        assignment_id = 1
        assignment_description = "Description"
        assignment_deadline = datetime.date(2021,12,12)
        try:
            assignment_service.add_assignment(assignment_id,assignment_description,assignment_deadline)
            assert False
        except:
            assert True

    def test_remove_assignment__NonExistentID_ExceptionThrown(self):
        assignment_service = self.generate_testing_data()
        assignment_id = 99
        try:
            assignment_service.remove_student(student_id)
            assert False
        except:
            assert True

    def test_update_assignment_description__NegativeID__ExceptionThrown(self):
        assignment_service = self.generate_testing_data()
        new_description = "New description"
        assignment_id = -1
        try:
            assignment_service.update_assignment_description(new_description,assignment_id)
            assert False
        except:
            assert True

    def test_update_assignment_deadline__NonExistentID__ExceptionThrown(self):
        assignment_service = self.generate_testing_data()
        new_deadline = datetime.date(2021,12,12)
        assignment_id = 10000
        try:
            assignment_service.update_assignment_deadline(new_deadline,assignment_id)
            assert False
        except:
            assert True