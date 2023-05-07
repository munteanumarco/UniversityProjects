<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Grade Student</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <!-- <script src="fetchStudentProfile.js"></script> -->
    <link rel="stylesheet" type="text/css" href="assets/styles.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">
</head>
<body>
    <?php include('nav.php') ?>
    <div class="container">
        <h1>Welcome to the grading page</h1>
        <h4><?php echo $_GET['course']; ?></h4>
        <table id="data-table" class="styled-table">
            <thead>
                <tr>
                    <th>First Name</th>
                    <th>Last Name</th>
                    <th>Grade</th>
                    <?php 
                        if ($_GET['grade'] != 'none') {
                            echo '<th></th>';
                        }
                    ?>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <?php 
                        echo '<td>' . $_GET['sFirstName'] . '</td>';
                        echo '<td>' . $_GET['sLastName'] . '</td>';
                        echo '<td>' . $_GET['grade'] . '</td>';
                        if ($_GET['grade'] != 'none') {
                            echo '
                            <td>
                                <a href="removeGrade.php?courseId=' . $_GET['courseId'] . '&studentId=' . $_GET['studentId'] . '">
                                    <button type="button" class="btn btn-danger">Remove</button>
                                </a>
                            </td>';
                        }
                    ?>
                </tr>
            </tbody>
        </table>

        <form  method="POST" action="gradeStudentRequest.php">
            <label for="gradeInput">Insert new grade:</label>
            <input type="number" id="gradeInput" name="grade" min="1" max="10" style="width: 100px;">
            <input type="hidden" name="studentId" value="<?php echo $_GET['studentId'];?>">
            <input type="hidden" name="courseId" value="<?php echo $_GET['courseId'];?>">
            <input type="hidden" name="alreadyGraded" value="<?php 
                if ($_GET['grade'] == 'none') {
                    echo "false";
                } else {
                    echo "true";
                }
            ?>">
            <button class="btn btn-primary" type="submit">Submit</button>
        </form>


    </div>
    <?php include('footer.php')?>
</body>
</html>