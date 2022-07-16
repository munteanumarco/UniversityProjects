from src.domain.validators import StudentLabAssignmentException
import datetime
from src.services.undo_redo import UndoManager,RedoManager
from src.services.undo_redo_handlers import UndoHandlers,RedoHandlers
class InvalidInputException(StudentLabAssignmentException):
    pass

class Console:
    def __init__(self,student_service,assignment_service,grade_service):
        self._student_service = student_service
        self._assignment_service = assignment_service
        self._grade_service = grade_service

    @staticmethod
    def print_main_menu_options():
        print("Welcome to Student Lab Assignment Application\n"
              "0.Exit Application\n"
              "1.Manage Students\n"
              "2.Manage Assignments\n"
              "3.Give Assignment\n"
              "4.List Grades\n"
              "5.Grade Student Assignment\n"
              "6.Statistics\n"
              "7.Undo last operation\n"
              "8.Redo\n")
    @staticmethod
    def print_specific_area_menu_options(area):
        print('0.Go back \n'
              '1.Add ' + str(area) + '\n'
              '2.Remove ' + str(area) + '\n'
              '3.Update ' + str(area) + '\n'
              '4.List ' + str(area) + 's \n')
    @staticmethod
    def print_statistics_menu():
        print('0.Go back \n'
              '1.All students ordered descending by grade at given assignment\n'
              '2.All students who are late in handing in at least one assignment\n'
              '3.Students sorted in descending order of the average grade received for all graded assignments\n')

    def add_student(self):
        print("==Add new student==\n")
        student_id = input("Insert Student ID:")
        student_name = input("Insert Student Name:")
        student_group = input("Insert Student Group:")
        for character in student_name:
            if not (character.isalpha() or character.isspace()):
                raise InvalidInputException("Invalid Name for student (only letters and spaces are allowed)")
        try:
            student_id = int(student_id)
            student_group = int(student_group)
        except:
            raise InvalidInputException("Invalid input for student attributes")
        self._student_service.add_student(student_id, student_name, student_group)
    def remove_student(self):
        print("==Remove student==\n")
        student_id = input("Insert the Student ID:")
        try:
            student_id = int(student_id)
        except:
            raise InvalidInputException("Invalid Student ID")
        self._student_service.remove_student(student_id)
        self._grade_service.remove_student_assignments(student_id)

    def update_student(self):
        print("==Update student==\n")
        student_id = input("Please insert Student ID:")
        try:
            student_id = int(student_id)
        except:
            raise InvalidInputException("Invalid Student ID\n")
        print("1.Update Student Name\n"
              "2.Update Student Group\n")
        update_option = input("Insert update option:")
        try:
            update_option = int(update_option)
        except:
            raise InvalidInputException("Invalid update option\n")
        if update_option == 1:
            new_student_name = input("Insert new Student Name:")
            for character in new_student_name:
                if not (character.isalpha() or character.isspace()):
                    raise InvalidInputException("Invalid New Student Name(only letters and spaces are allowed)\n")

            self._student_service.update_student_name(new_student_name,student_id)
        else:
            if update_option == 2:
                new_student_group = input("Insert new Student Group:")
                try:
                    new_student_group = int(new_student_group)
                except:
                    raise InvalidInputException("Invalid New Student Group(integers only)")
                self._student_service.update_student_group(new_student_group,student_id)
            else:
                raise InvalidInputException("Invalid update option\n")

    def list_students(self):
        students = self._student_service.get_students()
        for key,value in students.items():
            print(str(value))

    def give_assignment_to_student(self):
        print("==Give assignment to a student==\n")
        student_id = input("Please insert Student ID:")
        assignment_id = input("Please insert Assignment ID:")
        try:
            student_id = int(student_id)
            assignment_id = int(assignment_id)
        except:
            raise InvalidInputException("Invalid Student/Assignment ID(integers only)\n")
        students = self._student_service.get_students()
        assignments = self._assignment_service.get_assignments()
        self._grade_service.add_assignment_to_student(student_id,assignment_id,None,students,assignments)

    def give_assignment_to_group_of_students(self):
        print("==Give assignment to a group of students==\n")
        group = input("Please insert the group:")
        assignment_id = input("Please insert the Assignment ID:")
        try:
            group = int(group)
            assignment_id = int(assignment_id)
        except:
            raise InvalidInputException("Invalid Group/Assignment ID(only integers)")
        students = self._student_service.get_students()
        self._grade_service.add_assignment_to_group_of_students(students,group,assignment_id)

    def list_grades(self):
        grades = self._grade_service.get_grades()
        for grade in grades:
            print(str(grade))

    def add_assignment(self):
        print("==Add new assignment==\n")
        assignment_id = input("Insert Assignment ID:")
        assignment_description = input("Insert Assignment Description:")
        assignment_deadline_year = input("Insert Assignment Year deadline:")
        assignment_deadline_month = input("Insert Assignment Month deadline:")
        assignment_deadline_day = input("Insert Assignment Day deadline:")
        try:
            assignment_id = int(assignment_id)
            assignment_deadline_year = int(assignment_deadline_year)
            assignment_deadline_month = int(assignment_deadline_month)
            assignment_deadline_day = int(assignment_deadline_day)
        except:
            raise InvalidInputException("Invalid input for assignment attributes")
        try:
            deadline = datetime.date(assignment_deadline_year,assignment_deadline_month,assignment_deadline_day)
        except ValueError as value_error:
            raise InvalidInputException(str(value_error))
        self._assignment_service.add_assignment(assignment_id,assignment_description,deadline)
    def remove_assignment(self):
        print("==Remove assignment==\n")
        assignment_id = input("Insert the Assignment ID:")
        try:
            assignment_id = int(assignment_id)
        except:
            raise InvalidInputException("Invalid Assignment ID\n")
        self._assignment_service.remove_assignment(assignment_id)
        self._grade_service.remove_assignment_grades(assignment_id)

    def update_assignment(self):
        print("==Update Assignment==\n")
        assignment_id = input("Insert Assignment ID:")
        try:
            assignment_id = int(assignment_id)
        except:
            raise InvalidInputException("Invalid Assignment ID(integers only)\n")
        print("1.Update Assignment Description\n"
              "2.Update Assignment Deadline\n")
        update_option = input("Insert update option:")
        try:
            update_option = int(update_option)
        except:
            raise InvalidInputException("Invalid update option\n")
        if update_option == 1:
            new_description = input("Insert new description:")
            self._assignment_service.update_assignment_description(new_description,assignment_id)

        else:
            if update_option == 2:
                new_deadline_year = input("Insert new deadline year:")
                new_deadline_month = input("Insert new deadline month:")
                new_deadline_day = input("Insert new deadline day:")
                try:
                    new_deadline_year = int(new_deadline_year)
                    new_deadline_month = int(new_deadline_month)
                    new_deadline_day = int(new_deadline_day)
                except:
                    raise InvalidInputException("Invalid input for deadline attributes(integers only)")

                try:
                    new_deadline = datetime.date(new_deadline_year, new_deadline_month,
                                             new_deadline_day)
                except ValueError as value_error:
                    raise InvalidInputException(str(value_error))
                self._assignment_service.update_assignment_deadline(new_deadline,assignment_id)
            else:
                raise InvalidInputException("Invalid update option\n")


    def list_assignments(self):
        assignments = self._assignment_service.get_assignments()
        for key,value in assignments.items():
            print(str(value))

    def grade_student_assignment(self):
        print("==Grade Student Assignment==\n")
        student_id = input("Please insert Student ID:")
        try:
            student_id = int(student_id)
        except:
            raise InvalidInputException("Invalid input Student ID\n")

        students = self._student_service.get_students()
        ungraded_assignments = self._grade_service.get_student_ungraded_assignments(student_id,students)
        print("Ungraded Assignments IDs:")
        for assignment_id in ungraded_assignments:
            print(assignment_id)

        assignment_id = input("Please select from above an Assignment ID for grading:")
        new_grade = input("Please insert the grade:")
        try:
            assignment_id = int(assignment_id)
            new_grade = int(new_grade)
        except:
            raise InvalidInputException("Invalid input for the Assignment ID/New Grade\n")

        if assignment_id not in ungraded_assignments:
            raise InvalidInputException("Student doesn't have the Assignment ID " + str(assignment_id) + " ungraded")

        self._grade_service.grade_student_assignment(student_id,assignment_id,new_grade)

    def display_students_descending_at_assignment_id(self):
        print("==All students ordered descending by grade at given assignment==\n")
        assignment_id = input("Please insert the Assignment ID:")
        try:
            assignment_id = int(assignment_id)
        except:
            raise InvalidInputException("Invalid Assignment ID (integers only)")

        assignments = self._assignment_service.get_assignments()
        students = self._student_service.get_students()
        grades = self._grade_service.grades_descending_at_assignment_id(assignment_id,assignments)

        for grade in grades:
            student = self._student_service.find_student_by_id(grade.student_id,students)
            print(str(student) + ', Grade: ' + str(grade.value))

    def display_late_assignments(self):
        print("==All students who are late in handing in at least one assignment==")
        students = self._student_service.get_students()
        grades = self._grade_service.late_assignments()
        for grade in grades:
            student = self._student_service.find_student_by_id(grade.student_id,students)
            print(str(student) + " Late Assignment ID : " + str(grade.assignment_id))
        if len(grades) == 0:
            print("There are no students with late assignments\n")

    def display_general_leaderboard(self):
        print("==Students sorted in descending order of the average grade received for all graded assignments.==\n")
        students = self._student_service.get_students()
        leaderboard = self._grade_service.general_leaderboard(students)
        for leaderboard_element in leaderboard:
            student = self._student_service.find_student_by_id(leaderboard_element[0],students)
            print(str(student) + ", Average : " + str(leaderboard_element[1]))

    def start_application(self):
        while True:
            try:
                self.print_main_menu_options()
                user_input = input("Please select an operation:")
                try:
                    user_input = int(user_input)
                except:
                    raise InvalidInputException("Invalid input for options\n")
                if user_input == 0:
                    break
                if user_input == 1:
                    self.print_specific_area_menu_options('student')
                    user_input = input("Please select an operation:")
                    try:
                        user_input = int(user_input)
                    except:
                        raise InvalidInputException("Invalid input for options\n")
                    if user_input == 1:
                        self.add_student()
                    else:
                        if user_input == 2:
                            self.remove_student()
                        else:
                            if user_input == 3:
                                self.update_student()
                            else:
                                if user_input == 4:
                                    self.list_students()
                else:
                    if user_input == 2:
                        self.print_specific_area_menu_options('assignment')
                        user_input = input("Please select an operation:")
                        try:
                            user_input = int(user_input)
                        except:
                            raise InvalidInputException("Invalid input for menu options\n")
                        if user_input == 1:
                            self.add_assignment()
                        else:
                            if user_input == 2:
                                self.remove_assignment()
                            else:
                                if user_input == 3:
                                    self.update_assignment()
                                else:
                                    if user_input == 4:
                                        self.list_assignments()
                    else:
                        if user_input == 3:
                            print("1.Give Assignment to a Student\n"
                                  "2.Give Assignment to a Group of Students\n")
                            user_input = input("Please select an operation:")
                            try:
                                user_input = int(user_input)
                            except:
                                raise InvalidInputException("Invalid input for operation(integers only)\n")
                            if user_input == 1:
                                self.give_assignment_to_student()
                            else:
                                if user_input == 2:
                                    self.give_assignment_to_group_of_students()
                                else:
                                    raise InvalidInputException("Invalid operation number\n")
                        else:
                            if user_input == 4:
                                self.list_grades()
                            else:
                                if user_input == 5:
                                    self.grade_student_assignment()
                                else:
                                    if user_input == 6:
                                        self.print_statistics_menu()
                                        user_input = input("Select a statistics option:")
                                        try:
                                            user_input = int(user_input)
                                        except:
                                            raise InvalidInputException("Invalid option\n")
                                        if user_input == 1:
                                            self.display_students_descending_at_assignment_id()
                                        else:
                                            if user_input == 2:
                                                self.display_late_assignments()
                                            else:
                                                if user_input == 3:
                                                    self.display_general_leaderboard()
                                                else:
                                                    raise InvalidInputException("Invalid option\n")
                                    else:
                                        if user_input == 7:
                                            UndoManager.undo()
                                        else:
                                            if user_input == 8:
                                                RedoManager.redo()
                                            else:
                                                raise InvalidInputException("Invalid menu option\n")
            except StudentLabAssignmentException as exception:
                print(exception)
