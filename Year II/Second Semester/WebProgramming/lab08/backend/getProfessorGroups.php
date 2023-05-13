<?php
header("Access-Control-Allow-Origin: http://localhost:4200");
header("Access-Control-Allow-Methods: POST");
header("Access-Control-Allow-Headers: Content-Type");
http_response_code(200);
require_once 'db.php';
$professorId = $_GET['user_id'];
$stmt = mysqli_prepare($conn, "SELECT C.id, C.name, PCG.facultyGroup
                                FROM ProfessorCourseGroup PCG
                                INNER JOIN Course C on C.id = PCG.cId
                                WHERE PCG.pId = ?");
mysqli_stmt_bind_param($stmt, "i", $professorId);

if (!mysqli_stmt_execute($stmt)) {
    error_log("Error executing statement: " . mysqli_stmt_error($stmt));
    header("Location: operationFailed.php");
    return;
}

$data = array();
mysqli_stmt_bind_result($stmt, $courseId, $courseName, $group);
while (mysqli_stmt_fetch($stmt)) {
    $data[] = array(
        'courseId' => $courseId,
        'courseName' => $courseName,
        'group' => $group,
    );
}

mysqli_stmt_close($stmt);
mysqli_close($conn);

header('Content-Type: application/json');
echo json_encode($data);


?>