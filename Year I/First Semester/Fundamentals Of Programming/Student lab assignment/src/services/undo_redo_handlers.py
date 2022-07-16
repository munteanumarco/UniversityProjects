from src.services.undo_redo import RedoManager,UndoManager
from enum import Enum

#UNDO Operation
#Students Management
def add_student_handler_undo(student_service,student_id,name,group):
    student_service.remove_student_undo_redo_functionality(student_id)
    RedoManager.register_operation(student_service,RedoHandlers.ADD_STUDENT,student_id,name,group)

def remove_student_handler_undo(student_service,student_id,name,group,grade_service,removed_assignments):
    #adds the student back and also the deleted assignments
    student_service.add_student_undo_redo_functionality(student_id,name,group)
    remove_student_assignments_undo(grade_service,removed_assignments)
    RedoManager.register_operation(student_service,RedoHandlers.REMOVE_STUDENT,student_id,name,group,grade_service,removed_assignments)

def update_student_name_handler_undo(student_service,old_name,new_name,id):
    student_service.update_student_name_undo_redo_functionality(old_name,id)
    RedoManager.register_operation(student_service,RedoHandlers.UPDATE_STUDENT_NAME,old_name,new_name,id)

def update_student_group_handler_undo(student_service,old_group,new_group,id):
    student_service.update_student_group_undo_redo_functionality(old_group,id)
    RedoManager.register_operation(student_service,RedoHandlers.UPDATE_STUDENT_GROUP,old_group,new_group,id)

#Assignments Management
def add_assignment_handler_undo(assignment_service,assignment_id,description,deadline):
    assignment_service.remove_assignment_undo_redo_functionality(assignment_id)
    RedoManager.register_operation(assignment_service,RedoHandlers.ADD_ASSIGNMENT,assignment_id,description,deadline)

def remove_assignment_handler_undo(assignment_service,assignment_id,description,deadline,grade_service,removed_grades):
    assignment_service.add_assignment_undo_redo_functionality(assignment_id,description,deadline)
    remove_assignments_grades_undo(grade_service,removed_grades)
    RedoManager.register_operation(assignment_service,RedoHandlers.REMOVE_ASSIGNMENT,assignment_id,description,deadline,grade_service,removed_grades)

def update_assignment_description_handler_undo(assignment_service,old_description,new_description,assignment_id):
    assignment_service.update_assignment_description_undo_redo_functionality(old_description,assignment_id)
    RedoManager.register_operation(assignment_service,RedoHandlers.UPDATE_ASSIGNMENT_DESCRIPTION,old_description,new_description,assignment_id)

def update_assignment_deadline_handler_undo(assignment_service,old_deadline,new_deadline,assignment_id):
    assignment_service.update_assignment_deadline_undo_redo_functionality(old_deadline,assignment_id)
    RedoManager.register_operation(assignment_service,RedoHandlers.UPDATE_ASSIGNMENT_DEADLINE,old_deadline,new_deadline,assignment_id)

#Grades Management

def add_assignment_to_student_undo(grade_service,student_id,assignment_id):
    grade_service.remove_student_specific_assignment(student_id,assignment_id)
    RedoManager.register_operation(grade_service,RedoHandlers.ADD_ASSIGNMENT_TO_STUDENT,student_id,assignment_id)

def add_assignment_to_group_of_students_undo(grade_service,students_added,assignment_id):
    for student_id in students_added:
        grade_service.remove_student_specific_assignment(student_id,assignment_id)
    RedoManager.register_operation(grade_service,RedoHandlers.ADD_ASSIGNMENT_TO_GROUP_STUDENTS,students_added,assignment_id)

def remove_assignments_grades_undo(grade_service,removed_grades):
    for grade in removed_grades:
        grade_service.redo_add_grade(grade.student_id, grade.assignment_id, grade.value)

def remove_student_assignments_undo(grade_service,removed_student_grades):
    for grade in removed_student_grades:
        grade_service.redo_add_grade(grade.student_id,grade.assignment_id,grade.value)

def grade_student_assignment_undo(grade_service,student_id,assignment_id,new_grade):
    grade_service.grade_student_assignment_undo_redo_functionality(student_id,assignment_id,None)
    RedoManager.register_operation(grade_service,RedoHandlers.GRADE_STUDENT_ASSIGNMENT,student_id,assignment_id,new_grade)



#REDO Operation

#Students Management
def add_student_handler_redo(student_service,student_id,name,group):
    student_service.add_student_undo_redo_functionality(student_id,name,group)
    UndoManager.register_operation(student_service, UndoHandlers.ADD_STUDENT, student_id, name, group)

def remove_student_handler_redo(student_service,student_id,name,group,grade_service,removed_assignments):
    student_service.remove_student_undo_redo_functionality(student_id)
    grade_service.remove_student_assignments_undo_redo_functionality(student_id)
    UndoManager.register_operation(student_service,UndoHandlers.REMOVE_STUDENT,student_id,name,group,grade_service,removed_assignments)

def update_student_name_handler_redo(student_service,old_name,new_name,id):
    student_service.update_student_name_undo_redo_functionality(new_name,id)
    UndoManager.register_operation(student_service,UndoHandlers.UPDATE_STUDENT_NAME,old_name,new_name,id)

def update_student_group_handler_redo(student_service,old_group,new_group,id):
    student_service.update_student_group_undo_redo_functionality(new_group,id)
    UndoManager.register_operation(student_service,UndoHandlers.UPDATE_STUDENT_GROUP,old_group,new_group,id)

#Assignments Management
def add_assignment_handler_redo(assignment_service,assignment_id,description,deadline):
    assignment_service.add_assignment_undo_redo_functionality(assignment_id,description,deadline)
    UndoManager.register_operation(assignment_service,UndoHandlers.ADD_ASSIGNMENT,assignment_id,description,deadline)

def remove_assignment_handler_redo(assignment_service,assignment_id,description,deadline,grade_service,removed_assignments):
    assignment_service.remove_assignment_undo_redo_functionality(assignment_id)
    grade_service.remove_assignment_grades_undo_redo_functionality(assignment_id)
    UndoManager.register_operation(assignment_service,UndoHandlers.REMOVE_ASSIGNMENT,assignment_id,description,deadline,grade_service,removed_assignments)

def update_assignment_description_handler_redo(assignment_service,old_description,new_description,assignment_id):
    assignment_service.update_assignment_description_undo_redo_functionality(new_description,assignment_id)
    UndoManager.register_operation(assignment_service,UndoHandlers.UPDATE_ASSIGNMENT_DESCRIPTION,old_description,new_description,assignment_id)

def update_assignment_deadline_handler_redo(assignment_service,old_deadline,new_deadline,assignment_id):
    assignment_service.update_assignment_deadline_undo_redo_functionality(new_deadline, assignment_id)
    UndoManager.register_operation(assignment_service, UndoHandlers.UPDATE_ASSIGNMENT_DEADLINE, old_deadline,
                                   new_deadline, assignment_id)
#Grades Management

def add_assignment_to_student_redo(grade_service,student_id,assignment_id):
    grade_service.redo_add_grade(student_id,assignment_id,None)
    UndoManager.register_operation(grade_service,UndoHandlers.ADD_ASSIGNMENT_TO_STUDENT,student_id,assignment_id)

def add_assignment_to_group_of_students_redo(grade_service,students_added,assignment_id):
    for student_id in students_added:
        grade_service.redo_add_grade(student_id,assignment_id,None)
    UndoManager.register_operation(grade_service,UndoHandlers.ADD_ASSIGNMENT_TO_GROUP_STUDENTS,students_added,assignment_id)

def grade_student_assignment_redo(grade_service,student_id,assignment_id,new_grade):
    grade_service.grade_student_assignment(student_id,assignment_id,new_grade)
    UndoManager.register_operation(grade_service,UndoHandlers.GRADE_STUDENT_ASSIGNMENT,student_id,assignment_id,None)

class UndoHandlers(Enum):
    ADD_STUDENT = add_student_handler_undo
    REMOVE_STUDENT = remove_student_handler_undo
    UPDATE_STUDENT_NAME = update_student_name_handler_undo
    UPDATE_STUDENT_GROUP = update_student_group_handler_undo

    ADD_ASSIGNMENT = add_assignment_handler_undo
    REMOVE_ASSIGNMENT = remove_assignment_handler_undo
    UPDATE_ASSIGNMENT_DESCRIPTION = update_assignment_description_handler_undo
    UPDATE_ASSIGNMENT_DEADLINE = update_assignment_deadline_handler_undo

    ADD_ASSIGNMENT_TO_STUDENT = add_assignment_to_student_undo
    ADD_ASSIGNMENT_TO_GROUP_STUDENTS = add_assignment_to_group_of_students_undo
    REMOVE_ASSIGNMENTS_GRADES = remove_assignments_grades_undo
    REMOVE_STUDENT_ASSIGNMENTS = remove_student_assignments_undo
    GRADE_STUDENT_ASSIGNMENT = grade_student_assignment_undo

class RedoHandlers(Enum):
    ADD_STUDENT = add_student_handler_redo
    REMOVE_STUDENT = remove_student_handler_redo
    UPDATE_STUDENT_NAME = update_student_name_handler_redo
    UPDATE_STUDENT_GROUP = update_student_group_handler_redo

    ADD_ASSIGNMENT = add_assignment_handler_redo
    REMOVE_ASSIGNMENT = remove_assignment_handler_redo
    UPDATE_ASSIGNMENT_DESCRIPTION = update_assignment_description_handler_redo
    UPDATE_ASSIGNMENT_DEADLINE = update_assignment_deadline_handler_redo

    ADD_ASSIGNMENT_TO_STUDENT = add_assignment_to_student_redo
    ADD_ASSIGNMENT_TO_GROUP_STUDENTS = add_assignment_to_group_of_students_redo
    GRADE_STUDENT_ASSIGNMENT = grade_student_assignment_redo