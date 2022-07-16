from src.repository.students_repository import StudentsRepository,StudentsTextFileRepository, StudentsBinaryFileRepository
from src.repository.assignments_repository import AssignmentsRepository,AssignmentsTextFileRepository,AssignmentsBinaryFileRepository
from src.repository.grade_repository import GradesRepository,GradesTextFileRepository,GradesBinaryFileRepository
from src.services.student_service import StudentService
from src.services.assignment_service import AssignmentService
from src.services.grade_service import GradeService
from src.domain.validators import StudentValidator,AssignmentValidator,GradeValidator
from src.ui.console import Console
class SettingsExceptions(Exception):
    pass

if __name__ == '__main__':
    my_settings = {}
    try:
        with open('settings.properties','r') as file:
            for line in file:
                line = line.rstrip()
                if '=' not in line: continue
                key,value = line.split('=',1)
                my_settings[key.rstrip()] = value.rstrip()
        print(my_settings)
        if my_settings['repository'] == ' inmemory':
            student_repository = StudentsRepository()
            assignment_repository = AssignmentsRepository()
            grade_repository = GradesRepository()
        else:
            if my_settings['repository'] == ' textfiles':
                student_repository = StudentsTextFileRepository(my_settings['students'].lstrip())
                assignment_repository = AssignmentsTextFileRepository(my_settings['assignments'].lstrip())
                grade_repository = GradesTextFileRepository(my_settings['grades'].lstrip())
            else:
                if my_settings['repository'] == ' binaryfiles':
                    print(my_settings['assignments'].lstrip())
                    student_repository = StudentsBinaryFileRepository(my_settings['students'].lstrip())
                    assignment_repository = AssignmentsBinaryFileRepository(my_settings['assignments'].lstrip())
                    grade_repository = GradesBinaryFileRepository(my_settings['grades'].lstrip())
                else:
                    raise SettingsExceptions("Invalid repository format")

        student_service = StudentService(student_repository,StudentValidator)
        assignment_service = AssignmentService(assignment_repository,AssignmentValidator)
        grade_service = GradeService(grade_repository,StudentValidator,AssignmentValidator,GradeValidator,assignment_service)

        console = Console(student_service,assignment_service,grade_service)

        console.start_application()
    except SettingsExceptions as error:
        print(error)

