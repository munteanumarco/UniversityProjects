<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="assets/styles.css">
</head>
<body>

    <?php include('nav.php');?>
    <div class="container">
        <h1>Add new course !</h1>
        <h4>Fill details bellow</h4>
        <form method="post" action="addCourseOperation.php">
        <div class="mb-3">
            <label for="exampleInputEmail1" class="form-label">Course Name</label>
            <input type="username" class="form-control" id="courseName" name="courseName" aria-describedby="usernameInput">
        </div>
        <div class="mb-3">
            <label for="exampleInputEmail1" class="form-label">Course Description</label>
            <input type="text" class="form-control" id="courseDesc" name="courseDesc" aria-describedby="descriptionInput">
        </div>
        <div class="mb-3">
            <label for="exampleInputEmail1" class="form-label">Credits</label>
            <input type="number" class="form-control" id="credits" name="credits" aria-describedby="descriptionInput">
        </div>
        <button type="submit" name="submit" class="btn btn-primary">Add</button>
        </form>
    </div>

    <?php include('footer.php'); ?>
</body>
</html>
