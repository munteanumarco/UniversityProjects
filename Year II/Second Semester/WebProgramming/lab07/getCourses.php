<?php

session_start();

if (isset($_SESSION['username']) && $_SESSION['role'] == 'professor') {
    require_once 'db.php';
    $professorId = $_SESSION['user_id'];
    $stmt = mysqli_prepare($conn, "SELECT C.id, C.name
                                    FROM Course C");
    if (!mysqli_stmt_execute($stmt)) {
        error_log("Error executing statement: " . mysqli_stmt_error($stmt));
        header("Location: operationFailed.php");
        return;
    }

    $data = array();
    mysqli_stmt_bind_result($stmt, $courseId, $courseName);
	while (mysqli_stmt_fetch($stmt)) {
        $data[] = array(
            'courseId' => $courseId,
            'courseName' => $courseName,
        );
    }

    mysqli_stmt_close($stmt);
    mysqli_close($conn);
    
    header('Content-Type: application/json');
    echo json_encode($data);

}
?>