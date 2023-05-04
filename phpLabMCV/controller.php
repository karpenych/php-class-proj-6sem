<?php

require "model.php";

function get_result($_DB){
    $results = $_DB->select("SELECT * FROM `cars` WHERE `name` LIKE ?", ["{$_POST["search"]}%"]);
    return $results;
}


?>
