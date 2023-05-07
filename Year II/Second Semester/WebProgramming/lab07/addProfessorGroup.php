<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Professor Panel</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="fetchAvailableCourses.js"></script>
    <script src="fetchAvailableGroups.js"></script>
    <link rel="stylesheet" type="text/css" href="assets/styles.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">
</head>
<body>
    <?php include('nav.php');?>
    <div class="container">
        <h1>Add new Group</h1>
        <div class="container">
            <form action="addProfGroupReq.php" method="POST" class="container">
                <label for="groups">Select the group:</label>
                <select name="groups" id="groups">   
                </select>
                <label for="courses">Select the course:</label>
                <select name="courses" id="courses">
                </select>
                <button type="submit" class="btn btn-success">Add</button>
            </form>
        </div>
    </div>
    <?php include('footer.php'); ?>
</body>
</html>