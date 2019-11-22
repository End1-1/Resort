<?php
session_start();

$servername = "10.1.0.2:3306";
$username = "root";
$password = "osyolia";
$database = "resort";
$dbconn = new mysqli($servername, $username,  $password, $database);
if ($dbconn->connect_error) {
    die("Connection failed: " . $dbconn->connect_error);
}
$dbconn->set_charset("utf8");

$SHOW_MENU = false;
