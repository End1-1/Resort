<?php

class Db {
    protected $db;
    public $error = "";

    function __construct() {
        global $dbconn;
        $this->db = $dbconn;
    }
}
