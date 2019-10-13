<?php
require_once "conf.php";
if (empty($_SESSION["id"])) {
    require_once "login.php";
    return;
}

$stmt = $dbconn->prepare("select f_user from web_sessions where f_state=1 and f_session=?");
$stmt->bind_param("s", $_SESSION["id"]);
$stmt->execute();
$stmt->bind_result($user_id);
if (!$stmt->fetch()) {
    require_once "login.php";
    return;
}

$SHOW_MENU = true;
require_once "header.php";
require_once "footer.php";
