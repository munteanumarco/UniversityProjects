<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Homepage</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="assets/styles.css">
</head>
<body>
    
<?php 
    include('nav.php');
    session_start();
?>

<div class="container">
    <?php
        if (isset($_SESSION['username'])) {
            echo '<h1>Welcome back ' . $_SESSION['username'] . ' !</h1>
                    <h3>Your role is ' . $_SESSION['role'] . '</h3>'
                    ;
        } else {
            echo '<h1> Hello!</h1><h3>Login to access the platform</h3>';
        }
    ?>
</div>
<?php
    include('footer.php');
?>

</body>
</html>