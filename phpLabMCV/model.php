<?php
define("DB_HOST",     "localhost");
define("DB_NAME",     "Karpenko_db_mvc");
define("DB_CHARSET",  "utf8mb4");
define("DB_USER",     "root");
define("DB_PASSWORD", "usbw");

class DB {
    public $error = "";
    private $pdo = null;
    private $stmt = null;

     // (A) CONNECT TO DATABASE
    function __construct(){
        $this->pdo = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME.";charset=".DB_CHARSET, DB_USER, DB_PASSWORD);
    }

    // (B) CLOSE CONNECTION
    function __destruct(){
        if ($this->stmt!==null) { $this->stmt = null; }
        if ($this->pdo!==null) { $this->pdo = null; }
    }

    // (C) RUN A SELECT QUERY
    function select($sql, $data=null){
        $this->stmt = $this->pdo->prepare($sql);
        $this->stmt->execute($data);
        return $this->stmt->fetchAll();
    }
}



?>
