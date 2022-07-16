import datetime
import unittest
from src.services.undo_redo import UndoManager,RedoManager
from src.services.undo_redo_handlers import UndoHandlers,RedoHandlers
from src.services.student_service import StudentService
from src.repository.students_repository import StudentsRepository
from src.domain.validators import StudentValidator
from src.services.assignment_service import AssignmentService
from src.domain.validators import AssignmentValidator
from src.repository.assignments_repository import AssignmentsRepository
from src.services.grade_service import GradeService
from src.repository.grade_repository import GradesRepository
from src.domain.validators import GradeValidator
from src.domain.student import Student
from src.domain.assignment import Assignment
from src.domain.grade import Grade
from src.ui.console import Console

class TestUndo(unittest.TestCase):
    def generate_student_service(self):
        student_service = StudentService(StudentsRepository(),StudentValidator)
        return student_service
    def generate_assignment_service(self):
        assignment_service = AssignmentService(AssignmentsRepository(),AssignmentValidator)
        return assignment_service
    def generate_grade_service(self):
        grade_service = GradeService(GradesRepository(), StudentValidator, AssignmentValidator, GradeValidator,AssignmentService(AssignmentsRepository(),AssignmentValidator))
        return grade_service

    def test_undo__EmptyOperationStack__ExceptionThrown(self):
        try:
            UndoManager.undo()
            assert False
        except:
            assert True

    def test_undo__AfterRemovedStudent__RestoredStudentAndGrades(self):
        student_service = self.generate_student_service()
        grade_service = self.generate_grade_service()
        students = student_service.get_students()
        student_service.remove_student(12)
        removed_grades = grade_service.remove_student_assignments(12)
        UndoManager.undo()
        try:
            student_service.find_student_by_id(12,students)
            assert True
        except:
            assert False
        grades = grade_service.get_grades()
        for removed_grade in removed_grades:
            found = False
            for grade in grades:
                if grade.student_id == removed_grade.student_id and grade.assignment_id == removed_grade.assignment_id:
                    found = True
                    break
            if found is False:
                assert False
        assert True

    def test_undo__AfterAddedStudent__RemoveStudent(self):
        student_service = self.generate_student_service()
        student_service.add_student(21,"John Wick",915)
        added_student = Student(21,"John Wick",915)
        UndoManager.undo()
        students = student_service.get_students()
        index_of_last_element =  list(students.keys())[-1]
        self.assertNotEqual(students[index_of_last_element],added_student)

    def test_undo__AfterAddedStudentUndoTwice__ExceptionThrown(self):
        student_service = self.generate_student_service()
        student_service.add_student(21, "John Wick", 915)
        UndoManager.undo()
        try:
            UndoManager.undo()
            assert False
        except:
            assert True

    def test_undo__AfterUpdatedStudentName__RestoredOldName(self):
        student_service = self.generate_student_service()
        students = student_service.get_students()
        student_id = 10
        new_student_name = "John Casper"
        student = student_service.find_student_by_id(student_id,students)
        old_student_name = student.student_name
        student_service.update_student_name(new_student_name,student_id)
        UndoManager.undo()
        self.assertEqual(student.student_name,old_student_name)

    def test_undo__AfterUpdatedStudentGroup__RestoredOldGroup(self):
        student_service = self.generate_student_service()
        students = student_service.get_students()
        student_id = 12
        new_student_group = 999
        student = student_service.find_student_by_id(student_id, students)
        old_student_group = student.student_group
        student_service.update_student_group(new_student_group, student_id)
        UndoManager.undo()
        self.assertEqual(student.student_group, old_student_group)

    def test_undo__AfterRemovedAssignment__RestoredAssignmentAndGrades(self):
        assignment_service = self.generate_assignment_service()
        grade_service = self.generate_grade_service()
        assignments = assignment_service.get_assignments()
        assignment_service.remove_assignment(12)
        removed_grades = grade_service.remove_assignment_grades(12)
        UndoManager.undo()
        try:
            assignment_service.find_assignment_by_id(12,assignments)
            assert True
        except:
            assert False
        grades = grade_service.get_grades()
        for removed_grade in removed_grades:
            found = False
            for grade in grades:
                if removed_grade.assignment_id == grade.assignment_id and removed_grade.student_id == grade.student_id:
                    found = True
                    break
            if found == False:
                assert False
        assert True

    def test_undo__AfterAddedAssignment__RemoveAssignment(self):
        assignment_service = self.generate_assignment_service()
        assignment_service.add_assignment(21,"This is a description",datetime.date(2021,12,12))
        added_assignment = Assignment(21,"This is a description",datetime.date(2021,12,12))
        UndoManager.undo()
        assignments = assignment_service.get_assignments()
        index_of_last_element =  list(assignments.keys())[-1]
        self.assertNotEqual(assignments[index_of_last_element],added_assignment)

    def test_undo__AfterAddedAssignmentUndoTwice__ExceptionThrown(self):
        assignment_service = self.generate_assignment_service()
        assignment_service.add_assignment(21, "This is a description", datetime.date(2021, 12, 12))
        UndoManager.undo()
        try:
            UndoManager.undo()
            assert False
        except:
            assert True

    def test_undo__AfterUpdatedAssignmentDescription__RestoredOldDescription(self):
        assignment_service = self.generate_assignment_service()
        assignments = assignment_service.get_assignments()
        assignment_id = 11
        new_description = "New Description"
        assignment = assignment_service.find_assignment_by_id(assignment_id,assignments)
        old_description = assignment.description
        assignment_service.update_assignment_description(new_description,assignment_id)
        UndoManager.undo()
        self.assertEqual(assignment.description,old_description)

    def test_undo__AfterUpdatedAssignmentDeadline__RestoredOldDeadline(self):
        assignment_service = self.generate_assignment_service()
        assignments = assignment_service.get_assignments()
        assignment_id = 13
        new_deadline= datetime.date(2021,12,12)
        assignment = assignment_service.find_assignment_by_id(assignment_id, assignments)
        old_deadline = assignment.deadline
        assignment_service.update_assignment_deadline(new_deadline,assignment_id)
        UndoManager.undo()
        self.assertEqual(assignment.deadline, old_deadline)

    def test_undo__AfterGradedAssignment__RemoveTheGrade(self):
        student_service = self.generate_student_service()
        grade_service = self.generate_grade_service()
        student_id = 20
        students = student_service.get_students()
        ungraded_assignments = grade_service.get_student_ungraded_assignments(student_id,students)
        grade_service.grade_student_assignment(student_id,ungraded_assignments[0],8)
        UndoManager.undo()
        ungraded_assignments_after_undo = grade_service.get_student_ungraded_assignments(student_id,students)
        self.assertEqual(ungraded_assignments,ungraded_assignments_after_undo)

    def test_undo__AfterGivenAssignmentToStudent__RemoveAssignmentFromStudent(self):
        student_service = self.generate_student_service()
        grade_service = self.generate_grade_service()
        assignments_service = self.generate_assignment_service()
        students = student_service.get_students()
        assignments = assignments_service.get_assignments()
        student_id = 14
        assignment_id = 14
        #remove all assignments so it can be properly tested
        grade_service.remove_student_assignments_undo_redo_functionality(student_id)
        grade_service.add_assignment_to_student(student_id,assignment_id,None,students,assignments)
        UndoManager.undo()
        try:
            grade_service.get_student_ungraded_assignments(student_id,students)
            assert False
        except:
            assert True

    def test_undo__AfterGivenAssignmentToGroupOfStudents__RemoveGivenAssignments(self):
        student_service = self.generate_student_service()
        grade_service = self.generate_grade_service()
        students = student_service.get_students()
        assignment_id = 18
        group = 911
        added_assignments_to_students = grade_service.add_assignment_to_group_of_students(students,group,assignment_id)
        UndoManager.undo()
        grades = grade_service.get_grades()
        for student_id in added_assignments_to_students:
            for grade in grades:
                if grade.student_id == student_id and grade.assignment_id == assignment_id:
                    assert False
        assert True

class TestRedo(unittest.TestCase):
    def generate_student_service(self):
        student_service = StudentService(StudentsRepository(), StudentValidator)
        return student_service

    def generate_assignment_service(self):
        assignment_service = AssignmentService(AssignmentsRepository(), AssignmentValidator)
        return assignment_service

    def generate_grade_service(self):
        grade_service = GradeService(GradesRepository(), StudentValidator, AssignmentValidator, GradeValidator,AssignmentService(AssignmentsRepository(),AssignmentValidator))
        return grade_service

    def test_redo__EmptyStackOperation__ExceptionThrown(self):
        try:
            RedoManager.redo()
            assert False
        except:
            assert True


    def test_redo__UndoAfterAddedNewStudent__AddStudentBack(self):
        student_service = self.generate_student_service()
        students = student_service.get_students()
        student_service.add_student(21, "John Wick", 915)
        added_student = Student(21, "John Wick", 915)
        UndoManager.undo()
        RedoManager.redo()
        try:
            student_service.find_student_by_id(21,students)
            assert True
        except:
            assert False

    def test_redo__UndoAfterRemovedStudent__RemoveStudentAndGrades(self):
        student_service = self.generate_student_service()
        grade_service = self.generate_grade_service()
        students = student_service.get_students()
        student_service.remove_student(12)
        removed_grades = grade_service.remove_student_assignments(12)
        UndoManager.undo()
        RedoManager.redo()
        try:
            student_service.find_student_by_id(12, students)
            assert False
        except:
            assert True
        grades = grade_service.get_grades()
        for removed_grade in removed_grades:
            for grade in grades:
                if grade.student_id == removed_grade.student_id and grade.assignment_id == removed_grade.assignment_id:
                    assert False
        assert True

    def test_redo__UndoAfterUpdatedStudentName__RestoredNewName(self):
        student_service = self.generate_student_service()
        students = student_service.get_students()
        student_id = 10
        new_student_name = "John Casper"
        student = student_service.find_student_by_id(student_id, students)
        student_service.update_student_name(new_student_name, student_id)
        UndoManager.undo()
        RedoManager.redo()
        self.assertEqual(student.student_name, new_student_name)

    def test_redo__UndoAfterUpdatedStudentGroup__RestoredNewGroup(self):
        student_service = self.generate_student_service()
        students = student_service.get_students()
        student_id = 12
        new_student_group = 999
        student = student_service.find_student_by_id(student_id, students)
        student_service.update_student_group(new_student_group, student_id)
        UndoManager.undo()
        RedoManager.redo()
        self.assertEqual(student.student_group, new_student_group)

    def test_redo__UndoAfterAddedNewAssignment__AddAssignmentBack(self):
        assignment_service = self.generate_assignment_service()
        assignments = assignment_service.get_assignments()
        assignment_service.add_assignment(21, "This is a description", datetime.date(2021, 12, 12))
        UndoManager.undo()
        RedoManager.redo()
        try:
            assignment_service.find_assignment_by_id(21,assignments)
            assert True
        except:
            assert False

    def test_redo__UndoAfterRemovedAssignment__RemovedAssignmentAndGrades(self):
        assignment_service = self.generate_assignment_service()
        grade_service = self.generate_grade_service()
        assignments = assignment_service.get_assignments()
        assignment_service.remove_assignment(12)
        removed_grades = grade_service.remove_assignment_grades(12)
        UndoManager.undo()
        RedoManager.redo()
        try:
            assignment_service.find_assignment_by_id(12, assignments)
            assert False
        except:
            assert True
        grades = grade_service.get_grades()
        for removed_grade in removed_grades:
            for grade in grades:
                if removed_grade.assignment_id == grade.assignment_id and removed_grade.student_id == grade.student_id:
                    assert False
        assert True

    def test_redo__UndoAfterUpdatedAssignmentDescription__RestoredNewDescription(self):
        assignment_service = self.generate_assignment_service()
        assignments = assignment_service.get_assignments()
        assignment_id = 11
        new_description = "New Description"
        assignment = assignment_service.find_assignment_by_id(assignment_id, assignments)
        assignment_service.update_assignment_description(new_description, assignment_id)
        UndoManager.undo()
        RedoManager.redo()
        self.assertEqual(assignment.description, new_description)

    def test_redo__UndoAfterUpdatedAssignmentDeadline__RestoredNewDeadline(self):
        assignment_service = self.generate_assignment_service()
        assignments = assignment_service.get_assignments()
        assignment_id = 13
        new_deadline = datetime.date(2021, 12, 12)
        assignment = assignment_service.find_assignment_by_id(assignment_id, assignments)
        assignment_service.update_assignment_deadline(new_deadline, assignment_id)
        UndoManager.undo()
        RedoManager.redo()
        self.assertEqual(assignment.deadline, new_deadline)

    def test_redo__UndoAfterGradedStudentAssignment__RestoredGivenGrade(self):
        student_service = self.generate_student_service()
        grade_service = self.generate_grade_service()
        student_id = 20
        students = student_service.get_students()
        ungraded_assignments = grade_service.get_student_ungraded_assignments(student_id, students)
        assignment_id = ungraded_assignments[0]
        grade_service.grade_student_assignment(student_id, assignment_id, 8)
        UndoManager.undo()
        RedoManager.redo()
        grades = grade_service.get_grades()
        found = False
        for grade in grades:
            if grade.student_id == student_id and grade.assignment_id == assignment_id and grade.value == 8:
                found = True
                break
        if found is True:
            assert True
        else:
            assert False

    def test_redo__UndoAfterGivenAssignmentToStudent__AddedAssignmentBackToStudent(self):
        student_service = self.generate_student_service()
        grade_service = self.generate_grade_service()
        assignments_service = self.generate_assignment_service()
        students = student_service.get_students()
        assignments = assignments_service.get_assignments()
        student_id = 14
        assignment_id = 14
        # remove all assignments so it can be properly tested
        grade_service.remove_student_assignments_undo_redo_functionality(student_id)
        grade_service.add_assignment_to_student(student_id, assignment_id, None, students, assignments)
        UndoManager.undo()
        RedoManager.redo()
        try:
            grade_service.get_student_ungraded_assignments(student_id, students)
            assert True
        except:
            assert False

    def test_redo__UndoAfterGivenAssignmentToGroupOfStudents__AddedAssignmentBackToGroupOfStudents(self):
        student_service = self.generate_student_service()
        grade_service = self.generate_grade_service()
        students = student_service.get_students()
        assignment_id = 18
        group = 911
        added_assignments_to_students = grade_service.add_assignment_to_group_of_students(students, group,
                                                                                          assignment_id)
        UndoManager.undo()
        RedoManager.redo()
        grades = grade_service.get_grades()
        for student_id in added_assignments_to_students:
            found = False
            for grade in grades:
                if grade.student_id == student_id and grade.assignment_id == assignment_id:
                    found = True
                    break
            if found is False:
                assert False
        assert True