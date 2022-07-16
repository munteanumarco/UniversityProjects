class Student:
    def __init__(self,student_id,student_name,student_group):
        self._id = student_id
        self._name = student_name
        self._group = student_group

    @property
    def id(self):
        return self._id
    @id.setter
    def id(self,new_id):
        self._id = new_id

    @property
    def name(self):
        return self._name
    @name.setter
    def student_name(self,new_name):
        self._name = new_name

    @property
    def group(self):
        return self._group
    @group.setter
    def student_group(self,new_group):
        self._group = new_group

    def __str__(self):
        return 'Student ID: ' + str(self._id) + ', Student Name: ' + str(self._name) + ', Student Group: ' + str(self._group)

    def __eq__(self,second_student):
        if isinstance(second_student,Student):
            return self.id == second_student.id and self.name == second_student.name and self.group == second_student.group
        return False