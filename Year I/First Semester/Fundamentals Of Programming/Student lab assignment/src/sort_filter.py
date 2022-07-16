from src.domain.validators import StudentLabAssignmentException

class ShellSortException(StudentLabAssignmentException):
    pass
class FilterException(StudentLabAssignmentException):
    pass

class DataStructure:
    def __init__(self):
        self._data = {}

    def __setitem__(self, key, value):
        self._data[key] = value

    def __getitem__(self, item):
        return self._data[item]

    def shell_sort(self,compare_function):
        try:
            length = len(self._data.keys())
            gap = length // 2
            while gap > 0:
                for i in range(gap,length):
                    temporary = self._data[i]
                    j = i
                    while j >= gap and compare_function(self._data[j-gap],temporary) > 0 :
                        self._data[j] = self._data[j-gap]
                        j-=gap
                    self._data[j] = temporary
                gap //= 2
        except:
            raise ShellSortException("Shell Short Exception occurred\n")

    def filter(self,filter_function):
        try:
            wanted_data = {}
            for key,value in self._data.items():
                if filter_function(value) == 1:
                    wanted_data[key] = value
            return wanted_data
        except:
            raise FilterException("Filter Exception occurred\n")

    def get_data(self):
        return self._data
