<?php

header("Access-Control-Allow-Origin: http://localhost:4200");
header("Access-Control-Allow-Methods: POST");
header("Access-Control-Allow-Headers: Content-Type, Authorization");
http_response_code(200);
require_once 'db.php';

require_once 'validateProfessor.php';
if (!validate()) {
    echo json_encode(array("error" => "Unauthorized"));
    exit();
}

$group = $_GET['group'];
$courseId = $_GET['courseId'];

$stmt = mysqli_prepare($conn, "SELECT S.id, S.firstName, S.lastName, C.grade
                                FROM Student S
                                LEFT JOIN Catalog C ON S.id = C.studentId AND C.courseId = ?
                                WHERE S.facultyGroup = ?");
mysqli_stmt_bind_param($stmt, "ii", $courseId, $group);

if (!mysqli_stmt_execute($stmt)) {
    error_log("Error executing statement: " . mysqli_stmt_error($stmt));
    header("Location: operationFailed.php");
    return;
}

$data = array();
mysqli_stmt_bind_result($stmt, $studentId, $firstName, $lastName, $grade);
while (mysqli_stmt_fetch($stmt)) {
    $data[] = array(
        'studentId' => $studentId,
        'firstName' => $firstName,
        'lastName' => $lastName,
        'grade' => $grade 
    );
}

mysqli_stmt_close($stmt);
mysqli_close($conn);

header('Content-Type: application/json');
echo json_encode($data);


?>