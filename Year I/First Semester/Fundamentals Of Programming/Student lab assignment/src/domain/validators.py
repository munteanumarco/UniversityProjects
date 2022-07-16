from src.domain.student import Student

class StudentLabAssignmentException(Exception):
    pass

class StudentValidatorException(StudentLabAssignmentException):
    pass
class GradeValidatorException(StudentValidatorException):
    pass
class AssignmentValidatorException(StudentValidatorException):
    pass


class StudentValidator:

    @staticmethod
    def check_student_exists_by_id(student_id,students):
        if student_id in students.keys():
            return True
        return False
    @staticmethod
    def validate_student_attributes(student):
        if student.id<0:
            raise StudentValidatorException("Student ID must be positive\n")
        if student.group<0:
            raise StudentValidatorException("Group must be positive integer\n")

    @staticmethod
    def validate_student_not_duplicate(student,students):
        if StudentValidator.check_student_exists_by_id(student.id,students) is True:
            raise StudentValidatorException("Duplicate Student ID\n")

    @staticmethod
    def validate_student_existence(student_id,students):
        if StudentValidator.check_student_exists_by_id(student_id,students) is False:
            raise StudentValidatorException("There is no Student with ID: " + str(student_id) + '\n')

class AssignmentValidator:
    @staticmethod
    def check_assignment_exists_by_id(assignment_id, assignments):
        if assignment_id in assignments.keys():
            return True
        return False

    @staticmethod
    def validate_assignment_attributes(assignment):
        if assignment.id < 0:
            raise StudentValidatorException("Assignment ID must be positive\n")

    @staticmethod
    def validate_assignment_not_duplicate(assignment,assignments):
        if AssignmentValidator.check_assignment_exists_by_id(assignment.id,assignments) is True:
            raise AssignmentValidatorException("Duplicate Student ID\n")

    @staticmethod
    def validate_assignment_existence(assignment_id, assignments):
        if AssignmentValidator.check_assignment_exists_by_id(assignment_id, assignments) is False:
            raise AssignmentValidatorException("There is no Assignment with ID: " + str(assignment_id) + '\n')

class GradeValidator:
    @staticmethod
    def validate_assignment_not_given_already_to_student(assignment_id,student_id,grades):
        for grade in grades:
            if grade.student_id == student_id and grade.assignment_id == assignment_id:
                raise GradeValidatorException("The Assignment with ID " + str(assignment_id) + " is already given to the Student with ID " + str(student_id) + '\n')
    @staticmethod
    def validate_assignment_group_of_students(assignment_id,group,grades,students):
        assignments_given_counter = 0

        for key,student in students.items():
            if int(student.group) == int(group):
                assignment_given = False
                for grade in grades:
                    if int(grade.student_id) == int(student.id) and int(grade.assignment_id) == int(assignment_id):
                        assignment_given = True
                        break
                if assignment_given is False:
                    assignments_given_counter += 1
        if assignments_given_counter == 0:
            raise GradeValidatorException("Assignment already given to this group / The group doesn't exists")
    @staticmethod
    def validate_grade(grade):
        if grade != None:
            if grade < 0 or grade > 10:
                raise GradeValidatorException("Grades are integers between 0 and 10")
