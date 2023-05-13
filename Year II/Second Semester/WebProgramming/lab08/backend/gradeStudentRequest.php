<?php
header("Access-Control-Allow-Origin: http://localhost:4200");
header("Access-Control-Allow-Methods: POST");
header("Access-Control-Allow-Headers: Content-Type");
http_response_code(200);
require_once 'db.php';

$courseId = $_GET['courseId'];
$studentId = $_GET['studentId'];
$grade = $_GET['grade'];
$alreadyGraded = $_GET['alreadyGraded'];


if ($alreadyGraded == 'true') {
    $stmt = mysqli_prepare($conn, "UPDATE Catalog SET grade = ? WHERE courseId = ? AND studentId = ?");
    mysqli_stmt_bind_param($stmt, "iii", $grade, $courseId, $studentId);
            
} else if ($alreadyGraded == 'false'){
    $stmt = mysqli_prepare($conn, "INSERT INTO Catalog (studentId, courseId, grade) VALUES (?, ?, ?)");
    mysqli_stmt_bind_param($stmt, "iii", $studentId, $courseId, $grade);
}   

mysqli_stmt_execute($stmt);
mysqli_stmt_close($stmt);
mysqli_close($conn);

echo json_encode(array('success' => true));
?>