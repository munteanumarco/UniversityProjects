<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Profile Page</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="fetchProfessorProfile.js"></script>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="assets/styles.css">
</head>
<body>
<?php include('nav.php'); ?>
    <div class="container">
        <h1>Welcome to profile page</h1>
        <table id="data-table" class="styled-table">
            <thead>
                <tr>
                    <th>First Name</th>
                    <th>Last Name</th>
                    <th>Department</th>
                </tr>
            </thead>
            <tbody>
            </tbody>
        </table>
    </div>
    <?php include('footer.php'); ?>

</body>
</html>