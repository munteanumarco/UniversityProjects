<?php

header("Access-Control-Allow-Origin: http://localhost:4200");
header("Access-Control-Allow-Methods: POST");
header("Access-Control-Allow-Headers: Content-Type, Authorization");

require_once 'validateProfessor.php';
if (!validate()) {
    echo json_encode(array("error" => "Unauthorized"));
    exit();
}

require_once 'db.php';

$courseId = $_GET['course_id'];
$group = $_GET['group'];
$professorId = $_GET['user_id'];

$stmt = mysqli_prepare($conn, "DELETE FROM ProfessorCourseGroup WHERE cId = ? AND pId = ? AND facultyGroup = ?");
mysqli_stmt_bind_param($stmt, "iii", $courseId, $professorId, $group);
            
mysqli_stmt_execute($stmt);
mysqli_stmt_close($stmt);
mysqli_close($conn);
echo json_encode(array('success' => true));

?>