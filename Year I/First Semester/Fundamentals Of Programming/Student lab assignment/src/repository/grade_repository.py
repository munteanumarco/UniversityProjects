import pickle
import random
import unittest
import os

from src.domain.student import Student
from src.domain.assignment import Assignment
from src.domain.grade import Grade
from src.domain.validators import StudentLabAssignmentException
from src.services.undo_redo import UndoManager
from src.services.undo_redo_handlers import UndoHandlers
class GradeRepositoryException(StudentLabAssignmentException):
    pass

class GradesRepository:

    @staticmethod
    def generate_grades():
        grades = []
        generated_counter = 0
        picked_students = []
        while generated_counter < 20:

            student_id = random.randint(1,20)
            while student_id in picked_students:
                student_id = random.randint(1,20)
            picked_students.append(student_id)

            picked_assignments = []
            assignments_counter = 0
            while assignments_counter < 3:
                assignment_id = random.randint(1,20)
                while assignment_id in picked_assignments:
                    assignment_id = random.randint(1,20)
                picked_assignments.append(assignment_id)
                assignments_counter += 1

            new_grade1 = Grade(picked_assignments[0],student_id,random.randint(1,10))
            new_grade2 = Grade(picked_assignments[1],student_id,None)
            new_grade3 = Grade(picked_assignments[2],student_id,random.randint(1,10))
            grades.append(new_grade1)
            grades.append(new_grade2)
            grades.append(new_grade3)
            generated_counter += 1
        return grades

    def __init__(self):
        self._grades = GradesRepository.generate_grades()

    def get_grades(self):
        return self._grades

    def add_assignment_to_student(self, student_id, assignment_id, value):
        new_grade = Grade(assignment_id, student_id, value)
        self._grades.append(new_grade)

    def remove_student_specific_assignment(self, student_id, assignment_id):
        new_grades = [grade for grade in self._grades if grade.student_id != student_id or grade.assignment_id != assignment_id]
        self._grades = new_grades

    def grade_student_assignment(self,student_id,assignment_id,new_grade):
        for grade in self._grades:
            if grade.student_id == student_id and grade.assignment_id == assignment_id:
                grade.value = new_grade
                break

    def remove_student_assignments(self, student_id):
        new_grades = [grade for grade in self._grades if grade.student_id != student_id]
        removed_assignments = [grade for grade in self._grades if grade.student_id == student_id]
        self._grades = new_grades
        return removed_assignments

    def remove_assignment_grades(self, assignment_id):
        new_grades = [grade for grade in self._grades if grade.assignment_id != assignment_id]
        removed_grades = [grade for grade in self._grades if grade.assignment_id == assignment_id]
        self._grades = new_grades
        return removed_grades


class GradesTextFileRepository(GradesRepository):
    def __init__(self,file_name):
        super().__init__()

        self._file_name = file_name
        self._load_file()

    def _load_file(self):
        file = open(self._file_name, "rt")  # rt -> read, text-mode
        if os.stat(self._file_name).st_size != 0:
            self._grades = []
        for line in file.readlines():
            assignment_id, student_id, grade = line.split(maxsplit=2, sep=',')
            self.add_assignment_to_student(int(student_id),int(assignment_id),grade.rstrip())

        file.close()

    def _save_file(self):
        file = open(self._file_name, "wt")  # wt -> write, text-mode

        for grade in self._grades:
            file.write(str(grade.assignment_id) + ',' + str(grade.student_id) + ',' + str(grade.value) + "\n")

        file.close()

    def add_assignment_to_student(self, student_id, assignment_id, value):
         super(GradesTextFileRepository,self).add_assignment_to_student(student_id,assignment_id,value)
         self._save_file()

    def remove_student_specific_assignment(self, student_id, assignment_id):
        super(GradesTextFileRepository, self).remove_student_specific_assignment(student_id,assignment_id)
        self._save_file()

    def grade_student_assignment(self,student_id,assignment_id,new_grade):
        super(GradesTextFileRepository, self).grade_student_assignment(student_id,assignment_id,new_grade)
        self._save_file()

    def remove_student_assignments(self, student_id):
        removed_grades = super(GradesTextFileRepository, self).remove_student_assignments(student_id)
        self._save_file()
        return removed_grades

    def remove_assignment_grades(self, assignment_id):
        removed_grades = super(GradesTextFileRepository, self).remove_assignment_grades(assignment_id)
        self._save_file()
        return removed_grades

    def get_grades(self):
        self._save_file()
        return super(GradesTextFileRepository, self).get_grades()

class GradesBinaryFileRepository(GradesRepository):
    def __init__(self,file_name):
        super().__init__()

        self._file_name = file_name
        if os.stat(self._file_name).st_size != 0:
            self._load_file()
        else:
            self._save_file()

    def _load_file(self):
        file = open(self._file_name, "rb")  # rb -> read, bin-mode
        file.seek(0)
        self._grades = pickle.load(file)
        file.close()

    def _save_file(self):
        file = open(self._file_name, "wb")  # wb -> write, in-mode
        pickle.dump(self._grades,file)
        file.close()

    def add_assignment_to_student(self, student_id, assignment_id, value):
         super(GradesBinaryFileRepository,self).add_assignment_to_student(student_id,assignment_id,value)
         self._save_file()

    def remove_student_specific_assignment(self, student_id, assignment_id):
        super(GradesBinaryFileRepository, self).remove_student_specific_assignment(student_id,assignment_id)
        self._save_file()

    def grade_student_assignment(self,student_id,assignment_id,new_grade):
        super(GradesBinaryFileRepository, self).grade_student_assignment(student_id,assignment_id,new_grade)
        self._save_file()

    def remove_student_assignments(self, student_id):
        removed_grades = super(GradesBinaryFileRepository, self).remove_student_assignments(student_id)
        self._save_file()
        return removed_grades

    def remove_assignment_grades(self, assignment_id):
        removed_grades = super(GradesBinaryFileRepository, self).remove_assignment_grades(assignment_id)
        self._save_file()
        return removed_grades

    def get_grades(self):
        self._save_file()
        return super(GradesBinaryFileRepository, self).get_grades()