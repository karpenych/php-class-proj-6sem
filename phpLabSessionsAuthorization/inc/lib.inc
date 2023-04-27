<?php

$host = 'localhost';
$user = 'root';
$pass = 'Borisenco28#';
$dbname = 'Karpenko_db_log_reg';
$table_users = 'users';


function print_site_head(){
    print "<h1>Работа с сессиями </h1>";
}

function print_page_head($head){
    print $head;
}

function load_menu(){
?>
    <div class="block_nav">
        <ul class="navigation">
            <li><a href="index.php">Главная</a></li>
            <li><a href="logReg.php">Вход</a></li>
            <li><a href="output.php">Кукисы</a></li>
        </ul>
    </div>
<?php
}

function load_index_content(){
    print "<br><br><br><h3>Это главная страница</h3><br><br><br>";
?>
    <form method="post" action="">
    <fieldset>
        <legend><b>БД "Karpenko_db_log_reg"</b></legend>
        <input type="submit" name="bt_create" value="СОЗДАТЬ БД"/>
        <input type="submit" name="bt_del" value="УДАЛИТЬ БД"/>
<?php
    global $host;
    global $user;
    global $pass;
    global $dbname;
    global $table_users;

    if(isset($_POST['bt_create'])){
        try {
            $DBH = new PDO("mysql:host=$host", $user, $pass);
            $DBH->exec("CREATE DATABASE `$dbname`;");
            print "<p>База данных \"$dbname\" создана</p>
                   <p>CREATE DATABASE `$dbname`;</p>";

            $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
            $DBH -> setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );
            $sql = "CREATE table $table_users(
                    login    VARCHAR(20) PRIMARY KEY,
                    password VARCHAR(100) NOT NULL);";
            $DBH->exec($sql);
            print "<p>Таблица \"$table_users\" успешно создана: <br>$sql</p>";
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

function load_logreg_content(){
?>
    <form method="post" action="">
    <fieldset>
        <legend><b>ВХОД/РЕГИСТРАЦИЯ</b></legend>
        <div class = "field">
            <input type="text" size="15" name="inp_login" placeholder="Логин" value="<?php print "{$_SESSION['login']}" ?>">
        </div>
        <div class = "field">
            <input type="password" size="15" name="inp_password" placeholder="Пароль" value="<?php print "{$_SESSION['password']}" ?>">
        </div>
        <input type="submit" name="bt_login" value="Вход"/>
        <input type="submit" name="bt_register" value="Регистрация"/>
<?php
    global $host;
    global $user;
    global $pass;
    global $dbname;
    global $table_users;

    if(isset($_POST['bt_login'])){
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $DBH->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

        $login    = $_POST['inp_login'];
        $password = $_POST['inp_password'];
        if(isset($login) && isset($password)){
            $users = $DBH->query("SELECT * FROM `$table_users` WHERE `login` = '$login'");
            if($users->rowCount() == 1){
                $user = $users->fetch(PDO::FETCH_ASSOC);
                if(password_verify($password, $user['password'])){

                    $_SESSION['login'] = $login;
                    $_SESSION['password'] = $password;
                    header('Location: '.$_SERVER['REQUEST_URI'].'/../output.php');
                }else{
                    print "<p>!!!неправильный пароль!!!</p>";
                }
            }else{
                print "<p>!!!пользователя с таким логином не существует!!!</p>";
            }
        }
    }

    if(isset($_POST['bt_register'])){
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $DBH->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

        $login    = $_POST['inp_login'];
        $password = $_POST['inp_password'];
        if(isset($login) && isset($password)){
            $users = $DBH->query("SELECT * FROM `$table_users` WHERE `login` = '$login'");
            if($users->rowCount() == 0){
                $hash = password_hash($password, PASSWORD_DEFAULT);
                $DBH->query("INSERT INTO `$table_users`(`login`, `password`) VALUES ('$login', '$hash')");
                $_SESSION['login'] = $login;
                $_SESSION['password'] = $password;
                header('Location: '.$_SERVER['REQUEST_URI'].'/../output.php');
            }else{
                print "<p>!!!логин занят!!!</p>";
            }
        }
    }
?>
    </fieldset>
    </form>
<?php
}

function load_output_content(){
?>
    <fieldset>
        <legend><b>ИСПОЛЬЗОВАНИЕ ДАННЫХ ИЗ СЕССИИ</b></legend>
<?php
        print "<p>Вы вошли под логином: {$_SESSION['login']}<br>
                  Ваш пароль: {$_SESSION['password']}</p>";
?>
    </fieldset>
<?php
}

function load_page(){
    global $page;

    switch ($page)
    {
        case "index":
            load_index_content();
            break;
        case "logReg":
            load_logreg_content();
            break;
        case "output":
            load_output_content();
            break;
    }
}

function print_copyright(){
    print "<h2>&copy Студент 214.31 Карпенко Д. А. Верхнепортовая 50. 2023г</h2>";
}

?>
