<?php

session_start();

if (isset($_SESSION['username']) && $_SESSION['role'] == 'professor') {
    require_once 'db.php';

    if (!isset($_POST['groups']) || !isset($_POST['courses'])) {
        die("Error: group and course parameters are required.");
    }
    $group = $_POST['groups'];
    $courseId = $_POST['courses'];
    $professorId = $_SESSION['user_id'];

    $stmt = mysqli_prepare($conn, "INSERT INTO ProfessorCourseGroup (pId, cId, facultyGroup) VALUES (?, ?, ?)");
    mysqli_stmt_bind_param($stmt, "iii", $professorId, $courseId, $group);
    
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);
    mysqli_close($conn);

    header("Location: professorPanelPage.php");
}
?>