<?php  
    require 'vendor/autoload.php';
    use Firebase\JWT\JWT;

    header("Access-Control-Allow-Origin: http://localhost:4200");
    header("Access-Control-Allow-Methods: POST");
    header("Access-Control-Allow-Headers: Content-Type");
    http_response_code(200);

    ini_set('display_errors', 0);
    ini_set('log_errors', 1);
    ini_set('error_log', '/path/to/error.log');

    
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

    $algorithm = 'HS256';
    $secretKey = "my-secret-key";
    $payload = array(
        'user_id' => $dbId,
        'role' => $dbUserRole,
        'username' => $formUser,
        'exp' => time() + 3600 * 24
    );

    try {
        $jwt = JWT::encode($payload, $secretKey, $algorithm);
        $response = array(
            'token' => $jwt
        );
    
        echo json_encode($response);
    } catch (Exception $e) {
        error_log("JWT encoding error: " . $e->getMessage());
        echo json_encode(array("error" => "Internal server error" . $e->getMessage()));
    }
?>




