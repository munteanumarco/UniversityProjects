class Grade:
    def __init__(self,assignment_id,student_id,grade_value):
        self._assignment_id = assignment_id
        self._student_id = student_id
        self._value = grade_value

    @property
    def assignment_id(self):
        return self._assignment_id
    @assignment_id.setter
    def assignment_id(self,id):
        self._assignment_id = id

    @property
    def student_id(self):
        return self._student_id
    @student_id.setter
    def student_id(self,id):
        self._student_id = id

    @property
    def value(self):
        return self._value
    @value.setter
    def value(self,grade_value):
        self._value = grade_value

    def __str__(self):
        return 'Assignment ID: ' + str(self._assignment_id) + ', Student ID: ' + str(self._student_id) + ', Grade: ' + str(self._value)
    def __eq__(self, other):
        if isinstance(other,Grade):
            return self.value == other.value and self.student_id == other.student_id and self.assignment_id == other.assignment_id
        return False