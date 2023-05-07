<?php

session_start();

if (isset($_SESSION['username']) && $_SESSION['role'] == 'professor') {
    require_once 'db.php';
    if (!isset($_GET['courseId']) || !isset($_GET['studentId'])){
        echo "Error no course and student ids / grade";
    }
    $courseId = $_GET['courseId'];
    $studentId = $_GET['studentId'];

    $stmt = mysqli_prepare($conn, "DELETE FROM Catalog WHERE courseId = ? AND studentId = ?");
    mysqli_stmt_bind_param($stmt, "ii", $courseId, $studentId);
               
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);
    mysqli_close($conn);

    header("Location: professorPanelPage.php");
    exit();

}
?>