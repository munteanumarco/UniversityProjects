<?php

session_start();

if (isset($_SESSION['username']) && $_SESSION['role'] == 'professor') {
    require_once 'db.php';
    $professorId = $_SESSION['user_id'];
    $stmt = mysqli_prepare($conn, "SELECT P.firstName, P.lastName, P.department FROM Professor P WHERE P.id = ?");
    mysqli_stmt_bind_param($stmt, "i", $professorId);

    if (!mysqli_stmt_execute($stmt)) {
        error_log("Error executing statement: " . mysqli_stmt_error($stmt));
        header("Location: operationFailed.php");
        return;
    }

    mysqli_stmt_bind_result($stmt, $firstName, $lastName, $department);
	mysqli_stmt_fetch($stmt);

    $response = array(
        'firstName' => $firstName,
        'lastName' => $lastName,
        'department' => $department
    );
    mysqli_stmt_close($stmt);
    mysqli_close($conn);
    
    header('Content-Type: application/json');
    echo json_encode($response);

}
?>