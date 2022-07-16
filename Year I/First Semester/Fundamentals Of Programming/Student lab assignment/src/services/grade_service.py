import datetime

from src.domain.validators import StudentLabAssignmentException
from src.services.undo_redo import UndoManager,RedoManager
from src.services.undo_redo_handlers import UndoHandlers
from src.sort_filter import DataStructure

class GradeServiceException(StudentLabAssignmentException):
    pass


class GradeService:
    def __init__(self, grade_repository, student_validator, assignment_validator, grade_validator,assignment_service):
        self._grade_repository = grade_repository
        self._student_validator = student_validator
        self._assignment_validator = assignment_validator
        self._grade_validator = grade_validator
        self._assignment_service = assignment_service
    def get_grades(self):
        return self._grade_repository.get_grades()

    def add_assignment_to_student(self, student_id, assignment_id, value, students, assignments):
        grades = self.get_grades()

        self._student_validator.validate_student_existence(student_id, students)
        self._assignment_validator.validate_assignment_existence(assignment_id, assignments)
        self._grade_validator.validate_assignment_not_given_already_to_student(assignment_id, student_id, grades)
        self._grade_repository.add_assignment_to_student(student_id, assignment_id, value)

        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self,UndoHandlers.ADD_ASSIGNMENT_TO_STUDENT,student_id,assignment_id)

    def redo_add_grade(self, student_id, assignment_id, grade):
        self._grade_repository.add_assignment_to_student(student_id, assignment_id, grade)

    def remove_student_specific_assignment(self, student_id, assignment_id):
        self._grade_repository.remove_student_specific_assignment(student_id, assignment_id)

    def add_assignment_to_group_of_students(self, students, group, assignment_id):
        grades = self.get_grades()
        self._grade_validator.validate_assignment_group_of_students(assignment_id, group, grades, students)
        added_assignments = []
        for key, student in students.items():
            if student.group == group:
                assignment_given = False
                for grade in grades:
                    if grade.student_id == student.id and grade.assignment_id == assignment_id:
                        assignment_given = True
                        break
                if assignment_given is False:
                    self._grade_repository.add_assignment_to_student(student.id, assignment_id, None)
                    added_assignments.append(student.id)

        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.ADD_ASSIGNMENT_TO_GROUP_STUDENTS, added_assignments,assignment_id)
        return added_assignments

    def get_student_ungraded_assignments(self, student_id, students):
        self._student_validator.validate_student_existence(student_id, students)
        grades = self.get_grades()
        ungraded_assignments = []
        for grade in grades:
            if grade.student_id == student_id and (grade.value is None or grade.value == 'None'):
                ungraded_assignments.append(grade.assignment_id)
        if len(ungraded_assignments) > 0:
            return ungraded_assignments
        raise GradeServiceException("Student with ID " + str(student_id) + " has no ungraded assignment\n")

    def grade_student_assignment(self, student_id, assignment_id, grade):
        self._grade_validator.validate_grade(grade)
        self._grade_repository.grade_student_assignment(student_id, assignment_id, grade)
        RedoManager.clear_redo_operations()
        UndoManager.register_operation(self, UndoHandlers.GRADE_STUDENT_ASSIGNMENT, student_id,
                                       assignment_id, grade)

    def grade_student_assignment_undo_redo_functionality(self, student_id, assignment_id, grade):
        self._grade_repository.grade_student_assignment(student_id, assignment_id, grade)

    def remove_student_assignments(self, student_id):
        removed_assignments = self._grade_repository.remove_student_assignments(student_id)
        UndoManager.complete_last_operation(self,removed_assignments)
        return removed_assignments

    def remove_student_assignments_undo_redo_functionality(self, student_id):
        self._grade_repository.remove_student_assignments(student_id)

    def remove_assignment_grades(self, assignment_id):
        removed_grades = self._grade_repository.remove_assignment_grades(assignment_id)
        UndoManager.complete_last_operation(self,removed_grades)
        return removed_grades

    def remove_assignment_grades_undo_redo_functionality(self, assignment_id):
        return self._grade_repository.remove_assignment_grades(assignment_id)

    def compare_descending_grades(self,grade1,grade2):
        return grade1.value < grade2.value

    def grades_descending_at_assignment_id(self, assignment_id, assignments):
        self._assignment_validator.validate_assignment_existence(assignment_id, assignments)
        grades = self.get_grades()
        wanted_grades = [grade for grade in grades if grade.assignment_id == assignment_id and grade.value != None]

        if len(wanted_grades) == 0:
            raise GradeServiceException("No students have Assignment ID " + str(assignment_id) + " graded\n")

        loaded_grades = DataStructure()
        grade_id = 0
        for grade in wanted_grades:
            loaded_grades.__setitem__(grade_id,grade)
            grade_id += 1

        loaded_grades.shell_sort(self.compare_descending_grades)

        sorted_grades = []
        for key,value in loaded_grades.get_data().items():
            sorted_grades.append(value)

        return sorted_grades

    def filter_late_assignment(self,grade):
        assignments = self._assignment_service.get_assignments()
        if grade.value is None:
            deadline = assignments[grade.assignment_id].deadline
            if deadline < datetime.date.today():
                return 1
        return 0

    def late_assignments(self):
        grades = self.get_grades()
        loaded_grades = DataStructure()
        grade_id = 0
        for grade in grades:
            loaded_grades.__setitem__(grade_id, grade)
            grade_id += 1

        late_grades_dictionary = loaded_grades.filter(self.filter_late_assignment)

        late_grades = []
        for key,value in late_grades_dictionary.items():
            late_grades.append(value)

        return late_grades

    def get_student_average_score_all_assignments(self, student_id):
        grades = self.get_grades()
        sum_of_grades = 0
        number_of_grades = 0
        for grade in grades:
            if grade.student_id == student_id and grade.value != None:
                sum_of_grades += grade.value
                number_of_grades += 1
        if number_of_grades > 0:
            return sum_of_grades / number_of_grades
        return 0

    def compare_student_averages(self,student1_average,student2_average):
        return student1_average[1]<student2_average[1]

    def general_leaderboard(self, students):
        load_students_average = DataStructure()
        loaded_id = 0
        for key, student in students.items():
            element = (student.id, self.get_student_average_score_all_assignments(student.id))
            load_students_average.__setitem__(loaded_id,element)
            loaded_id += 1

        load_students_average.shell_sort(self.compare_student_averages)

        students_average_score = []
        for key,value in load_students_average.get_data().items():
            students_average_score.append(value)

        return students_average_score
