<?php
require_once "db.php";

class User extends Db {
    function login() {
        $stmt = $this->db->prepare("select f_id, concat(f_lastname, ' ', f_firstname) from users where lower(f_username)=lower(?) and lower(f_password)=lower(md5(?))");
        $stmt->bind_param("ss", $_POST["username"], $_POST["password"]);
        $stmt->execute();
        $stmt->bind_result($user_id, $user_name);
        if ($stmt->fetch()) {
            session_regenerate_id(true);
            $_SESSION["user_id"] = $user_id;
            $_SESSION["user_name"] = $user_name;
            $_SESSION["id"] = session_id();
            $stmt->close();
            if (!($stmt = $this->db->prepare("insert into web_sessions (f_session, f_state, f_user, f_start) values (?, 1, ?, current_timestamp)"))) {
               $this->error = $this->db->error . $stmt->error . "FUCK";
               return false;
            }
            $stmt->bind_param("si", $_SESSION["id"], $user_id);
            $stmt->execute();
        } else {
            $this->error = "Invalid username or password";
        }
        $stmt->close();
        return empty($this->error);
    }
}
