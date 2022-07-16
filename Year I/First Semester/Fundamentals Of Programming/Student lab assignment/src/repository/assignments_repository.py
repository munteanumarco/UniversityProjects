import random
import pickle
import os
from src.domain.validators import StudentLabAssignmentException
from src.domain.assignment import Assignment
import datetime
class AssignmentRepositoryException(StudentLabAssignmentException):
    pass

class AssignmentsRepository:
    @staticmethod
    def generate_assignments():
        assignments = {}
        id = 0
        descriptions = ("Develop a calendar application managing events","Develop a tic-tac-toe game","Develop an application for iOS devices",
                        "Develop a cloud based application","Develop a game for Android devices")
        generated_assignments = 0
        while generated_assignments<20:
            id += 1
            deadline = datetime.date(random.randint(2021, 2022), random.randint(1, 12), random.randint(1, 28))
            description_index = random.randint(0,4)
            new_assignment = Assignment(id,descriptions[description_index],deadline)
            assignments[id] = new_assignment
            generated_assignments += 1
        return assignments

    def __init__(self):
        self._assignments = AssignmentsRepository.generate_assignments()

    def find_assignment_by_id(self,assignment_id):
        return self._assignments[assignment_id]

    def add_assignment(self,assignment):
        self._assignments[assignment.id] = assignment

    def remove_assignment(self,assignment_id):
        del self._assignments[assignment_id]

    def update_assignment_description(self,new_description,assignment_id):
        self._assignments[assignment_id].description = new_description

    def update_assignment_deadline(self,new_deadline,assignment_id):
        self._assignments[assignment_id].deadline = new_deadline

    def get_assignments(self):
        return self._assignments


class AssignmentsTextFileRepository(AssignmentsRepository):
    def __init__(self,file_name):
        super().__init__()

        self._file_name = file_name
        self._load_file()

    def _load_file(self):
        file = open(self._file_name, "rt")  # rt -> read, text-mode
        if os.stat(self._file_name).st_size != 0:
            self._assignments = {}
        for line in file.readlines():
            _id, description, deadline = line.split(maxsplit=2, sep=',')
            self.add_assignment(Assignment(int(_id), description.rstrip(), deadline.rstrip()))
        file.close()
    def _save_file(self):
        file = open(self._file_name, "wt")  # wt -> write, text-mode

        for assignment in self._assignments.values():
            file.write(str(assignment.id) + ',' + str(assignment.description) + ',' + str(assignment.deadline) + "\n")

        file.close()

    def add_assignment(self,assignment):
        super(AssignmentsTextFileRepository,self).add_assignment(assignment)
        self._save_file()

    def remove_assignment(self,assignment_id):
        super(AssignmentsTextFileRepository, self).remove_assignment(assignment_id)
        self._save_file()

    def update_assignment_description(self,new_description,assignment_id):
        super(AssignmentsTextFileRepository,self).update_assignment_description(new_description,assignment_id)
        self._save_file()

    def update_assignment_deadline(self,new_deadline,assignment_id):
        super(AssignmentsTextFileRepository, self).update_assignment_deadline(new_deadline,assignment_id)
        self._save_file()

    def get_assignments(self):
        self._save_file()
        return super(AssignmentsTextFileRepository, self).get_assignments()

class AssignmentsBinaryFileRepository(AssignmentsRepository):
    def __init__(self,file_name):
        super().__init__()

        self._file_name = file_name
        if os.stat(self._file_name).st_size != 0:
            self._load_file()
        else:
            self._save_file()

    def _load_file(self):
        file = open(self._file_name, "rb")  # rt -> read, text-mode
        file.seek(0)
        self._assignments = pickle.load(file)
        file.close()

    def _save_file(self):
        file = open(self._file_name, "wb")  # wt -> write, text-mode
        pickle.dump(self._assignments,file)
        file.close()

    def add_assignment(self, assignment):
        super(AssignmentsBinaryFileRepository, self).add_assignment(assignment)
        self._save_file()

    def remove_assignment(self, assignment_id):
        super(AssignmentsBinaryFileRepository, self).remove_assignment(assignment_id)
        self._save_file()

    def update_assignment_description(self, new_description, assignment_id):
        super(AssignmentsBinaryFileRepository, self).update_assignment_description(new_description, assignment_id)
        self._save_file()

    def update_assignment_deadline(self, new_deadline, assignment_id):
        super(AssignmentsBinaryFileRepository, self).update_assignment_deadline(new_deadline, assignment_id)
        self._save_file()

    def get_assignments(self):
        self._save_file()
        return super(AssignmentsBinaryFileRepository, self).get_assignments()