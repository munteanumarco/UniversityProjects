class Assignment:
    def __init__(self,assignment_id,assignment_description,assignment_deadline):
        self._id = assignment_id
        self._description = assignment_description
        self._deadline = assignment_deadline

    @property
    def id(self):
        return self._id
    @id.setter
    def id(self,assignment_id):
        self._id = assignment_id

    @property
    def description(self):
        return self._description
    @description.setter
    def description(self,assignment_description):
        self._description = assignment_description

    @property
    def deadline(self):
        return self._deadline
    @deadline.setter
    def deadline(self,assignment_deadline):
        self._deadline = assignment_deadline

    def __str__(self):
        return 'Assignment ID: ' + str(self._id) + ', Assignment Description: ' + str(self._description) + ', Assignment Deadline: ' + str(self._deadline)

    def __eq__(self, other):
        if(isinstance(other,Assignment)):
            return self.id == other._id and self.description == other.description and self.deadline == other.deadline
        return False