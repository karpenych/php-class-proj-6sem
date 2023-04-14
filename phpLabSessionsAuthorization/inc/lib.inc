<?php

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
            <li><a href="output.php">Приветствие</a></li>
        </ul>
    </div>
<?php
}

function load_index_content(){
    print "<br><br><br><h3>Это главная страница</h3><br><br><br>";
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
    $user = "dbsessions_logreg_admin";
    $pass = "Qwerqwer1";

    if(isset($_POST['bt_login'])){
        $DBH = new PDO("mysql:host=localhost;dbname=dbsessions_logreg;charset=UTF8", $user, $pass);
        $DBH->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

        $login    = $_POST['inp_login'];
        $password = $_POST['inp_password'];
        if(isset($login) && isset($password)){
            $users = $DBH->query("SELECT * FROM `users` WHERE `login` = '$login'");
            if($users->rowCount() == 1){
                $user = $users->fetch(PDO::FETCH_ASSOC);
                if(password_verify($password, $user['password'])){
                    print "<p>---Вы успешно зашли---</p>";
                    $_SESSION['login'] = $login;
                    $_SESSION['password'] = $password;
                }else{
                    print "<p>!!!неправильный пароль!!!</p>";
                }
            }else{
                print "<p>!!!пользователя с таким логином не существует!!!</p>";
            }
        }
    }

    if(isset($_POST['bt_register'])){
        $DBH = new PDO("mysql:host=localhost;dbname=dbsessions_logreg;charset=UTF8", $user, $pass);
        $DBH->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

        $login    = $_POST['inp_login'];
        $password = $_POST['inp_password'];
        if(isset($login) && isset($password)){
            $users = $DBH->query("SELECT * FROM `users` WHERE `login` = '$login'");
            if($users->rowCount() == 0){
                $hash = password_hash($password, PASSWORD_DEFAULT);
                $DBH->query("INSERT INTO `users`(`login`, `password`) VALUES ('$login', '$hash')");
                print "<p>---Вы успешно зарегистрировались---</p>";
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
        print "<p>Вы вошли под логином: {$_SESSION['login']}<br>";
        print "Ваш пароль: {$_SESSION['password']}</p>";
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
