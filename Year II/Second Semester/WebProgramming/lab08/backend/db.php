<?php

$serverName = "localhost";
$username = "root";
$password  = "";
$dbName = "test";

$conn = mysqli_connect($serverName, $username, $password, $dbName);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
header('Cache-Control: no-cache, no-store, must-revalidate');

?>
