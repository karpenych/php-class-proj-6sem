<?php

require "controller.php";

$host = 'localhost';
$user = 'root';
$pass = 'usbw'; #<=<=<=<=<=<=<=<=<=<=<=<=  ВСТАВИТЬ СВОЙ ПАРОЛЬ ###########################
$dbname = 'Karpenko_db_mvc';
$table = 'cars';

function print_site_head(){
    print "<h1> MVC </h1>";
}

function print_page_head($head){
    print $head;
}

function load_menu(){
?>
    <div class="block_nav">
        <ul class="navigation">
            <li><a href="index.php">Главная</a></li>
            <li><a href="view.php">MVC</a></li>
        </ul>
    </div>
<?php
}

function load_index_content(){
    print "<br><br><br><h3>Это главная страница</h3><br><br><br>";
    ?>
        <form method="post" action="">
        <fieldset>
            <legend><b>БД "Karpenko_db_mvc"</b></legend>
            <input type="submit" name="bt_create" value="СОЗДАТЬ БД"/>
            <input type="submit" name="bt_del" value="УДАЛИТЬ БД"/>
    <?php
        global $host;
        global $user;
        global $pass;
        global $dbname;
        global $table;

        if(isset($_POST['bt_create'])){
            try {
                $DBH = new PDO("mysql:host=$host", $user, $pass);
                $DBH->exec("CREATE DATABASE `$dbname`;");
                print "<p>База данных \"$dbname\" создана<br>
                          CREATE DATABASE `$dbname`;</p>";

                $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
                $DBH -> setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );
                $sql = "CREATE table $table(
                        ID   INT(4) AUTO_INCREMENT NOT NULL PRIMARY KEY,
                        name VARCHAR(100) NOT NULL);";
                $DBH->exec($sql);
                print "<p>Таблица \"$table\" успешно создана: <br>$sql</p>";

                $sql = "INSERT INTO $table (name) VALUES
                    ('Audi'),
                    ('BMV'),
                    ('Ford'),
                    ('Honda'),
                    ('Hyundai'),
                    ('Infiniti'),
                    ('Kia'),
                    ('Lexus'),
                    ('Mazda'),
                    ('Mercedes-Benz'),
                    ('Mitsubishi'),
                    ('Nissan'),
                    ('Subaru'),
                    ('Suzuki'),
                    ('Toyota');";
                $DBH->exec($sql);
                print "<p>Таблица \"$table\" успешно заполнена: <br>$sql</p>";
            }
            catch (PDOException $e) {
                print "<p>ERROR: {$e->getMessage()}</p>";
            }
        }

        if(isset($_POST['bt_del'])){
            try {
                $DBH = new PDO("mysql:host=$host", $user, $pass);
                $DBH->exec("DROP DATABASE $dbname;");
                print "<p>База данных \"$dbname\" удалена</p>
                       <p>DROP DATABASE $dbname;</p>";
            }
            catch (PDOException $e) {
                print "<p>ERROR: {$e->getMessage()}</p>";
            }
        }
    ?>
        </fieldset>
        </form>
    <?php
}

function load_mvc_content(){
?>
    <form method="post" action="" enctype='multipart/form-data'>
    <fieldset>
        <legend><b>МАРКИ МАШИН</b></legend>
        <input type="text" name="search" size="6"/>
        <input type="submit" name="bt_submit" value="Найти"/>
<?php
        $_DB = new DB();
        if(isset($_POST['bt_submit']) && isset($_POST['search'])){
            if(strlen($_POST['search']) > 0){
                print "<p>";
                foreach(get_result($_DB) as $car){
                    print "{$car['ID']} - {$car['name']}<br>";
                }
                print "</p>";
            }
        }
?>
    </fieldset>
    </form>
<?php
}

function load_page(){
    global $page;

    switch ($page){
        case "index":
            load_index_content();
            break;
        case "mvc":
            load_mvc_content();
            break;
    }
}

function print_copyright(){
    print "<h2>&copy Студент 214.31 Карпенко Д. А. Верхнепортовая 50. 2023г</h2>";
}

?>
