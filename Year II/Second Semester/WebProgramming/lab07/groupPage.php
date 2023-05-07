
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Group Page</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="fetchStudentsFromGroup.js"></script>
    <link rel="stylesheet" type="text/css" href="assets/styles.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">

</head>
<body>
<?php include('nav.php');?>

<div class="container">
    <h1>See the students</h1>
    <h4><?php echo $_GET['course'];?> </h4>
    <h4>Group  <?php echo $_GET['group'];?> </h4>
    <table id="data-table" class="styled-table">
        <thead>
            <tr>
                <th>First Name</th>
                <th>Last Name</th>
                <th>Grade</th>
                <th></th>
            </tr>
        </thead>
        <tbody>
        </tbody>
    </table>
    <div class="pagination">
        <button class="btn btn-primary" id="prev-btn" onclick="prev()">Prev</button>
        <span id="page-info"></span>
        <button class="btn btn-primary" id="next-btn" onclick="next()">Next</button>
    </div>

</div>

<?php include('footer.php');?>
</body>
</html>