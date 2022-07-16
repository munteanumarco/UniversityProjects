import random
import unittest
from src.sort_filter import DataStructure
from src.domain.grade import Grade
class TestSortFilter(unittest.TestCase):
    def generate_grades(self):
        generated = 0
        grades_generated = []

        while generated < 20:
            student_id = random.randint(1,20)
            assignment_id = random.randint(1,20)
            grade_value = random.randint(1,10)
            grades_generated.append(Grade(assignment_id,student_id,grade_value))
            generated += 1
        return grades_generated

    def setup_data(self):
        my_structure = DataStructure()
        grades = self.generate_grades()
        load_id = 0
        for grade in grades:
            my_structure.__setitem__(load_id,grade)
            load_id += 1
        return my_structure

    def compare_grade_value_descending(self,grade1,grade2):
        return grade1.value < grade2.value

    def test_sort__ValidComparatorFunction__Sorted(self):
        my_structure = self.setup_data()
        my_structure.shell_sort(self.compare_grade_value_descending)
        sorted_grades = my_structure.get_data()

        previous_grade_value = 11
        for key,grade in sorted_grades.items():
            assert grade.value <= previous_grade_value
            previous_grade_value = grade.value

    def filter_passing_grades(self,grade):
        if grade.value >= 5:
            return 1
        return 0

    def test_filter__ValidFilterFunction__Filtered(self):
        my_structure = self.setup_data()
        grades = my_structure.get_data()
        expected_filtered_grades = {}
        for key,grade in grades.items():
            if grade.value >= 5:
                expected_filtered_grades[key] = grade

        filtered_grades = my_structure.filter(self.filter_passing_grades)

        self.assertEqual(expected_filtered_grades,filtered_grades)

    def invalid_filter(self,grade):
        if grade.grade_value >= 5:
            return 1
        return 0

    def test_filter__InvalidFilterFunction__ExceptionThrown(self):
        my_structure = self.setup_data()
        try:
            filtered_grades = my_structure.filter(self.filter_passing_grades)
            assert False
        except:
            assert True

    def invalid_comparator(self,grade1,grade2):
        return grade1.grade_value < grade2.grade_value

    def test_sort__InvalidComparatorFunction__ExceptionThrown(self):
        my_structure = self.setup_data()
        try:
            my_structure.shell_sort(self.invalid_comparator)
            assert False
        except:
            assert True