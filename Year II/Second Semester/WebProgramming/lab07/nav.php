<?php 
    session_start();
?>

    <nav class="navbar navbar-expand-lg bg-body-tertiary" data-bs-theme="dark">
    <div class="container-fluid">
        <a class="navbar-brand" href="index.php">Course Management</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
        <ul class="navbar-nav">
            <li class="nav-item">
            <a class="nav-link" aria-current="page" href="./">Home</a>
            </li>
            <?php 
                if (!isset($_SESSION['username'])) {
                    echo '<li class="nav-item">
                    <a class="nav-link" href="login.php">Login</a>
                    </li>
                    ';
                } else {
                    if($_SESSION['role'] == 'student') {
                        echo '<li class="nav-item">
                        <a class="nav-link" href="studentPanelPage.php">Panel</a>
                        </li>';
                    } else {
                        echo '<li class="nav-item">
                        <a class="nav-link" href="professorPanel.php">Panel</a>
                        </li>';
                    }
                    echo '<li class="nav-item">
                    <a class="nav-link" href="profilePageStudent.php">My Profile</a>
                    </li>';
                    echo '<li class="nav-item">
                    <a class="nav-link active" aria-current="page" href="logout.php">Logout</a>
                    </li>';
                }
            ?>
        </ul>
        </div>
    </div>
    </nav>