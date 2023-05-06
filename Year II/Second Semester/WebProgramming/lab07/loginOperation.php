<?php  
    if (isset($_POST['submit'])) {
        $formUser = $_POST['username'];
        $formPassword = hash('sha256', $_POST['password']);
        
        require_once 'db.php';

        $stmt = mysqli_prepare($conn, "SELECT id, username, password, user_role FROM User WHERE username = ? and password = ?");
        mysqli_stmt_bind_param($stmt, "ss", $formUser, $formPassword);
        
        mysqli_stmt_execute($stmt);
        mysqli_stmt_bind_result($stmt, $dbId, $dbUser, $dbPassword, $dbUserRole);

        if (!mysqli_stmt_fetch($stmt)) {
            header("Location: invalidLogin.php");
            return;
        }	

        mysqli_stmt_close($stmt);
        mysqli_close($conn);

        session_start();

        $_SESSION['user_id'] = $dbId;
        $_SESSION['username'] = $formUser;
        $_SESSION['role'] = $dbUserRole;
        
        header("Location: index.php");
    }
?>




