import random
import os
from src.domain.student import Student
from src.domain.validators import StudentLabAssignmentException
import pickle

class StudentRepositoryException(StudentLabAssignmentException):
    pass

class StudentsRepository:
    @staticmethod
    def generate_students():
        students = {}
        first_names = ("Ion","Adrian","Andrei","Ana",
                 "Filip","Geroge","Andreea","Marius",
                 "Radu","Alex","Maria","Marcel","Titu","Simon","Stefan","Barbara","Clara","Daria","Andra","Stefania")
        last_names = ("Popescu","Bivol","Ciucu","Vasilache","Lazarescu","Ivan","Tosco","Chiriac","Marian","Ifrim","Doica","Simbrim","Danciu",
                      "Vasiliu","Tiros","Haroi","Joghici","Macovei","Lisca","Petros")
        groups = (911,912,913,914,915,916,917)
        id = 0
        students_generated = 0
        while students_generated < 20:
            random_last_name_index = random.randint(0,19)
            random_first_name_index = random.randint(0,19)
            random_group_index = random.randint(0,6)
            id += 1
            name = first_names[random_first_name_index] + " " + last_names[random_last_name_index]
            new_student = Student(id,name,groups[random_group_index])
            students[id] = new_student
            students_generated += 1
        return students

    def __init__(self):
        self._students = StudentsRepository.generate_students()

    def find_student_by_id(self,student_id):
        return self._students[student_id]

    def add_student(self,student):
        self._students[student.id] = student

    def remove_student(self,student_id):
        del self._students[student_id]

    def update_student_name(self,new_student_name,student_id):
        self._students[student_id].student_name = new_student_name

    def update_student_group(self,new_student_group,student_id):
        self._students[student_id].student_group = new_student_group

    def get_students(self):
        return self._students


class StudentsTextFileRepository(StudentsRepository):
    def __init__(self,file_name):
        super().__init__()

        self._file_name = file_name
        self._load_file()

    def _load_file(self):
            file = open(self._file_name, "rt")  # rt -> read, text-mode
            if os.stat(self._file_name).st_size != 0:
                self._students = {}
            for line in file.readlines():
                _id, name,group = line.split(maxsplit=2, sep=',')
                self.add_student(Student(int(_id), name.rstrip(), group.rstrip()))
            file.close()

    def _save_file(self):
        file = open(self._file_name, "wt")  # wt -> write, text-mode

        for student in self._students.values():
            file.write(str(student.id) + ',' + str(student.name) + ',' + str(student.group)+ "\n")

        file.close()

    def add_student(self, student):
        super(StudentsTextFileRepository, self).add_student(student)
        self._save_file()

    def remove_student(self,student_id):
        super(StudentsTextFileRepository,self).remove_student(student_id)
        self._save_file()

    def update_student_name(self,new_student_name,student_id):
        super(StudentsTextFileRepository, self).update_student_name(new_student_name,student_id)
        self._save_file()

    def update_student_group(self,new_student_group,student_id):
        super(StudentsTextFileRepository, self).update_student_group(new_student_group, student_id)
        self._save_file()

    def get_students(self):
        self._save_file()
        return super(StudentsTextFileRepository, self).get_students()

class StudentsBinaryFileRepository(StudentsRepository):
    def __init__(self, file_name):
        super().__init__()
        self._file_name = file_name
        if os.stat(self._file_name).st_size != 0:
            self._load_file()
        else:
            self._save_file()

    def _load_file(self):
        file = open(self._file_name, "rb")  # rt -> read, text-mode
        #file.seek(0)
        self._students = pickle.load(file)
        file.close()

    def _save_file(self):
        file = open(self._file_name, "wb")  # wt -> write, text-mode
        pickle.dump(self._students,file)
        file.close()

    def add_student(self, student):
        """
        1. Do whatever the add method in the base class does
        2. Save to file
        """
        super(StudentsBinaryFileRepository, self).add_student(student)
        self._save_file()

    def remove_student(self, student_id):
        super(StudentsBinaryFileRepository, self).remove_student(student_id)
        self._save_file()

    def update_student_name(self, new_student_name, student_id):
        super(StudentsBinaryFileRepository, self).update_student_name(new_student_name, student_id)
        self._save_file()

    def update_student_group(self, new_student_group, student_id):
        super(StudentsBinaryFileRepository, self).update_student_group(new_student_group, student_id)
        self._save_file()

    def get_students(self):
        self._save_file()
        return super(StudentsBinaryFileRepository, self).get_students()