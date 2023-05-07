<?php

session_start();

if (isset($_SESSION['username']) && $_SESSION['role'] == 'professor') {
    require_once 'db.php';
    if (!isset($_POST['courseId']) || !isset($_POST['studentId']) || !isset($_POST['grade'])){
        echo "Error no course and student ids / grade";
    }
    $courseId = $_POST['courseId'];
    $studentId = $_POST['studentId'];
    $grade = $_POST['grade'];
    $alreadyGraded = $_POST['alreadyGraded'];


    if ($alreadyGraded == 'true') {
        echo "should update";
        $stmt = mysqli_prepare($conn, "UPDATE Catalog SET grade = ? WHERE courseId = ? AND studentId = ?");
        mysqli_stmt_bind_param($stmt, "iii", $grade, $courseId, $studentId);
               
    } else if ($alreadyGraded == 'false'){
        echo "should insert";
        $stmt = mysqli_prepare($conn, "INSERT INTO Catalog (studentId, courseId, grade) VALUES (?, ?, ?)");
        mysqli_stmt_bind_param($stmt, "iii", $studentId, $courseId, $grade);
    }   
    
    mysqli_stmt_execute($stmt);
    mysqli_stmt_close($stmt);
    mysqli_close($conn);

    // If the HTTP_REFERER server variable is empty or the redirect failed, redirect to a default page
    header("Location: professorPanelPage.php");
    exit();

}
?>