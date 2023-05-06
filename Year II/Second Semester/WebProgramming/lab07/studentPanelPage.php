<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Panel</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="fetchStudentGrades.js"></script>
    <link rel="stylesheet" type="text/css" href="assets/styles.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">
</head>
<body>
    <?php include('nav.php'); ?>
    <div class="container">
        <h1>Here you can see your grades</h1>
        <table id="data-table" class="styled-table">
            <thead>
                <tr>
                    <th>Course Name</th>
                    <th>Number of Credits</th>
                    <th>Grade</th>
                </tr>
            </thead>
            <tbody>
            </tbody>
        </table>
    </div>
</body>
</html>