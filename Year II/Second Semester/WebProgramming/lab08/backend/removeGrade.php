<?php

header("Access-Control-Allow-Origin: http://localhost:4200");
header("Access-Control-Allow-Methods: POST");
header("Access-Control-Allow-Headers: Content-Type, Authorization");
http_response_code(200);
require_once 'validateProfessor.php';
if (!validate()) {
    echo json_encode(array("error" => "Unauthorized"));
    exit();
}

require_once 'db.php';

$courseId = $_GET['courseId'];
$studentId = $_GET['studentId'];

$stmt = mysqli_prepare($conn, "DELETE FROM Catalog WHERE courseId = ? AND studentId = ?");
mysqli_stmt_bind_param($stmt, "ii", $courseId, $studentId);
            
mysqli_stmt_execute($stmt);
mysqli_stmt_close($stmt);
mysqli_close($conn);

echo json_encode(array('success' => true));
?>