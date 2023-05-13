<?php

session_start();

if (isset($_SESSION['username']) && $_SESSION['role'] == 'professor') {
    require_once 'db.php';
    $courseName = $_POST['courseName'];
    $courseDesc = $_POST['courseDesc'];
    $credits = $_POST['credits'];
    
    $stmt = mysqli_prepare($conn, "INSERT INTO Course (name, description, credits) VALUES(?, ?, ?)");
    mysqli_stmt_bind_param($stmt, "ssi", $courseName, $courseDesc, $credits);

    if (!mysqli_stmt_execute($stmt)) {
        error_log("Error executing statement: " . mysqli_stmt_error($stmt));
        header("Location: operationFailed.php");
        return;
    }

    mysqli_stmt_close($stmt);
    mysqli_close($conn);
    
    header("Location: professorPanelPage.php");

}
?>