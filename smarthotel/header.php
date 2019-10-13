<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title><? echo $PAGE_TITLE; ?></title>
    <link rel="stylesheet" type="text/css" href="styles.css" />
</head>
<div class="m1">
    <?php
    if ($SHOW_MENU) { ?>
    <div class="dm" style="width: 50px">
    </div>
    <div class="dm">
        <p class="hm">Reservations</p>
    </div>
    <div class="dmr"">
    <p class="hm"><?php echo $_SESSION["user_name"]; ?><img src="img/menu.png" style="float: right; width: 22px; height: 22px; margin-left: 5px; display: block" /></p>
    <div class="dropdown-content">
        <p onclick="window.location='/smarthotel/logout.php'">Logout</p>
    </div>
    <?php } else { ?>
        <p class="smarthotel">SMARTHOTEL PMS</p>
    <?php } ?>
</div>
