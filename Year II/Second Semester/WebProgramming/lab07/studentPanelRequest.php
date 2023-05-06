<?php

session_start();

if (isset($_SESSION['username']) && $_SESSION['role'] == 'student') {
    require_once 'db.php';
    $studentId = $_SESSION['user_id'];

    $stmt = mysqli_prepare($conn, "SELECT C.name, C.credits, Catalog.grade
    FROM Course C 
    INNER JOIN Catalog ON C.id = Catalog.courseId 
    WHERE Catalog.studentId = ?");
    mysqli_stmt_bind_param($stmt, "i", $studentId);

    if (!mysqli_stmt_execute($stmt)) {
        error_log("Error executing statement: " . mysqli_stmt_error($stmt));
        header("Location: operationFailed.php");
        return;
    }

    $data = array();
    mysqli_stmt_bind_result($stmt, $name, $credits, $grade);
	while (mysqli_stmt_fetch($stmt)) {
        $data[] = array(
            'name' => $name,
            'credits' => $credits,
            'grade' => $grade
        );
    }

    mysqli_stmt_close($stmt);
    mysqli_close($conn);
    
    header('Content-Type: application/json');
    echo json_encode($data);

}
?>