<?php

$host = 'localhost';
$user = 'dbcinema_admin';
$pass = 'Qwerqwer1';
$dbname = 'dbcinema';


try {
    $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
}
catch(PDOException $e) {
    echo $e->getMessage();
}

function get_cinema_name(){
    if(isset($_POST['bt_submit']) && isset($_POST['cinema_selector']) && $_POST['cinema_selector'] != '-1'){
        print "<span id=\"cinema_name\">{$_POST['cinema_selector']}</span>";
    }
}

function get_cinemas(){
    global $DBH;
    $cinemas = $DBH->query("SELECT * FROM `cinema`");

    while($cinema = $cinemas->fetch(PDO::FETCH_ASSOC))
        print "<option value=\"{$cinema['name']}\">{$cinema['name']}</option>\n";
}

function get_cinema_data(){
    global $DBH;

    if(isset($_POST['bt_submit']) && isset($_POST['cinema_selector']) && $_POST['cinema_selector'] != '-1'){
        try{
            $cinemas = $DBH->query("SELECT * FROM `cinema` WHERE `name` = \"{$_POST['cinema_selector']}\"");
        }
        catch(PDOException $ex){
            print "<p>{$ex->getMessage()}</p>";
            print "<p>Ошибка в запросе к таблице `cinema`</p>";
        }
        if($cinemas->rowCount() == 1){
            $cinema = $cinemas->fetch(PDO::FETCH_ASSOC);
            print "<p id='cinema_descr'>{$cinema['description']}</p>";
            print "<p id='sheduler_text'><b>~~Расписание сеансов~~</b></p>";
            print "<p style=\"text-align: unset;\"><span style=\"margin-left: 2%;\"><b>Дата:</b></span><span style=\"margin-left: 5%;\">
            <b>Название:</b></span><span style=\"margin-left: 5%;\"><b>Цена:</b></span></p>";
            try{
                $films = $DBH->query("SELECT * FROM `movie_poster` WHERE `cinema_id` = \"{$cinema['id']}\"");
            }
            catch(PDOException $ex){
                print "<p>{$ex->getMessage()}</p>";
                print "<p>Ошибка в запросе к таблице `movie_poster`</p>";
            }
            while($film = $films->fetch(PDO::FETCH_ASSOC)){
                print "<p style=\"text-align: unset;\"><span style=\"margin-left: 2%;\"><b>{$film['date']}</b></span>
                <span style=\"margin-left: 5%;\"><b>{$film['film']}</b></span><span style=\"margin-left: 5%;\"><b>{$film['cost']}р.</b></span></p>";
            }
        } else{
            print "<p>Значение [name] повторяется (должно быть уникальным)</p>";
        }
    }
}


?>
