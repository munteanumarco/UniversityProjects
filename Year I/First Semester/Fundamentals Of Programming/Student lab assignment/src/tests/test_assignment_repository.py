import unittest
from src.domain.assignment import Assignment
from src.repository.assignments_repository import AssignmentsRepository
import datetime

class TestAssignmentsRepository(unittest.TestCase):
    def test_add_assignment__ValidData__AddedCorrectly(self):
        assignment_repository = AssignmentsRepository()
        new_assignment = Assignment(12,"This is an assignment",datetime.date(2021,12,12))
        assignment_repository.add_assignment(new_assignment)
        assignments = assignment_repository.get_assignments()
        assert assignments[new_assignment.id] == new_assignment

    def test_remove_assignment__ValidAssignmentID__RemovedCorrectPosition(self):
        assignment_repository = AssignmentsRepository()
        assignments = assignment_repository.get_assignments()
        assignment_repository.remove_assignment(3)
        try:
            assignments[3]
            assert False
        except:
            assert True

    def test_update_assignment_description__ValidData__Updated(self):
        assignment_repository = AssignmentsRepository()
        assignments = assignment_repository.get_assignments()
        assignment_repository.update_assignment_description("Updated Description",5)
        assert assignments[5].description == "Updated Description"

    def test_update_assignment_deadline__ValidAssignmentID__Updated(self):
        assignment_repository = AssignmentsRepository()
        assignments = assignment_repository.get_assignments()
        new_deadline = datetime.date(2000,1,1)
        assignment_repository.update_assignment_deadline(new_deadline,5)
        assert assignments[5].deadline == new_deadline