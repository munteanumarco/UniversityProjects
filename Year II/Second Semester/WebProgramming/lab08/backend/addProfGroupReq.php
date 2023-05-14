<?php
require 'vendor/autoload.php';
use Firebase\JWT\JWT;

header("Access-Control-Allow-Origin: http://localhost:4200");
header("Access-Control-Allow-Methods: GET");
header("Access-Control-Allow-Headers: Content-Type, Authorization");
http_response_code(200);

require_once 'validateProfessor.php';
if (!validate()) {
    echo json_encode(array("error" => "Unauthorized"));
    exit();
}

require_once 'db.php';

$group = $_GET['group'];
$courseId = $_GET['course'];
$professorId = $_GET['user_id'];


$stmt = mysqli_prepare($conn, "INSERT INTO ProfessorCourseGroup (pId, cId, facultyGroup) VALUES (?, ?, ?)");
mysqli_stmt_bind_param($stmt, "iii", $professorId, $courseId, $group);

mysqli_stmt_execute($stmt);
mysqli_stmt_close($stmt);
mysqli_close($conn);
echo json_encode(array('success' => true));

?>