<?php  
    header("Access-Control-Allow-Origin: http://localhost:4200");
    header("Access-Control-Allow-Methods: POST");
    header("Access-Control-Allow-Headers: Content-Type");
    http_response_code(200);
    
    $json = file_get_contents('php://input');
    $_POST = json_decode($json, true);

    $formUser = $_POST['username'];
    $formPassword = hash('sha256', $_POST['password']);
    
    require_once 'db.php';

    $stmt = mysqli_prepare($conn, "SELECT id, username, password, user_role FROM User WHERE username = ? and password = ?");
    mysqli_stmt_bind_param($stmt, "ss", $formUser, $formPassword);
    
    mysqli_stmt_execute($stmt);
    mysqli_stmt_bind_result($stmt, $dbId, $dbUser, $dbPassword, $dbUserRole);

    if (!mysqli_stmt_fetch($stmt)) {
        echo json_encode(array("error" => "Invalid username or password"));
        exit();
    }	

    mysqli_stmt_close($stmt);
    mysqli_close($conn);

    $response = array('user_id' => $dbId, 'role' => $dbUserRole, 'username' => $formUser);
    echo json_encode($response);
    exit();
?>




