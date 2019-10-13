<?php
require_once "conf.php";
$stmt = $dbconn->prepare("update web_sessions set f_state=2, f_end=current_timestamp where f_session=?");
$stmt->bind_param("s", $_SESSION["id"]);
$stmt->execute();
$stmt->close();
session_unset();
header("Location: /smarthotel");
