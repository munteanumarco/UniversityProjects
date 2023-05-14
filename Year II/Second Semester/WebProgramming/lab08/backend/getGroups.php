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
$professorId = $_SESSION['user_id'];
$stmt = mysqli_prepare($conn, "SELECT DISTINCT S.facultyGroup
                                FROM Student S");
if (!mysqli_stmt_execute($stmt)) {
    error_log("Error executing statement: " . mysqli_stmt_error($stmt));
    header("Location: operationFailed.php");
    return;
}

$data = array();
mysqli_stmt_bind_result($stmt, $facultyGroup);
while (mysqli_stmt_fetch($stmt)) {
    $data[] = array(
        'facultyGroup' => $facultyGroup
    );
}

mysqli_stmt_close($stmt);
mysqli_close($conn);

header('Content-Type: application/json');
echo json_encode($data);


?>