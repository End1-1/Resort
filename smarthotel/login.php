<?php
require_once "conf.php";
require_once "user.php";

if (isset($_POST["login"])) {
    $user = new User();
    if ($user->login()) {
        header("Location: " . "/smarthotel");
        return;
    } else {
        $login_msg = $user->error;
    }
}

$PAGE_TITLE = "Login";
require_once "header.php";
?>

<body>
<form action="login.php" method="post">
    <input type="hidden" id="login" name="login" />
    <div class="p1">
        <div class="pr">
            <div class="p1">

            </div>
        </div>
        <div class="pr">
            <div class="pr1">Login</div>
            <div class="pr2"><input type="text" id="username" name="username" autofocus/></div>
        </div>
        <div class="pr">
            <div class="pr1">Password</div>
            <div class="pr2"><input type="password" id="password" name="password" /></div>
        </div>
        <div class="pr">
            <div class="p1">
                <p class="error_msg"><?php echo $login_msg; ?></p>
            </div>
        </div>
        <div class="pr">
            <div class="p1">
                <input type="submit" value="ENTER" />
            </div>
        </div>
    </div>
</form>
</body>

<?php
require_once "footer.php";
