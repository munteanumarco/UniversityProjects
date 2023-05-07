<?php

session_start();

if (isset($_SESSION['username']) && $_SESSION['role'] == 'professor') {
    require_once 'db.php';
  
    $courseId = $_POST['courseId'];
    $group = $_POST['group'];
    $professorId = $_SESSION['user_id'];

    $stmt = mysqli_prepare($conn, "DELETE FROM ProfessorCourseGroup WHERE cId = ? AND pId = ? AND facultyGroup = ?");
    mysqli_stmt_bind_param($stmt, "iii", $courseId, $professorId, $group);
               
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);
    mysqli_close($conn);
    echo json_encode(array('success' => true));
}
?>