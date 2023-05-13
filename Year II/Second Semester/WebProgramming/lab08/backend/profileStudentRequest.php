<?php

header("Access-Control-Allow-Origin: http://localhost:4200");
header("Access-Control-Allow-Methods: POST");
header("Access-Control-Allow-Headers: Content-Type");
http_response_code(200);
require_once 'db.php';
$studentId = $_GET['user_id'];
$stmt = mysqli_prepare($conn, "SELECT S.firstName, S.lastName, S.facultyGroup FROM Student S WHERE S.id = ?");
mysqli_stmt_bind_param($stmt, "i", $studentId);

if (!mysqli_stmt_execute($stmt)) {
    error_log("Error executing statement: " . mysqli_stmt_error($stmt));
    header("Location: operationFailed.php");
    return;
}

mysqli_stmt_bind_result($stmt, $firstName, $lastName, $group);
mysqli_stmt_fetch($stmt);

$response = array(
    'firstName' => $firstName,
    'lastName' => $lastName,
    'group' => $group
);
mysqli_stmt_close($stmt);
mysqli_close($conn);

header('Content-Type: application/json');
echo json_encode($response);

?>