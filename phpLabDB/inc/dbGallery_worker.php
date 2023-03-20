<?php

$host = 'localhost';
$user = 'dbgallery_admin';
$pass = 'Qwerqwer1';
$dbname = 'dbgallery';


// try {
//     $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
// }
// catch(PDOException $e) {
//     print "<p>Error: {$e->getMessae()}</p>";
// }

function create_delete_db(){
    if(isset($_POST['bt_create'])){
        CreateDB();
    }
    if(isset($_POST['bt_delete'])){
        DeleteDB();
    }
}

function CreateDB(){
    global $host;
    global $user;
    global $pass;
    global $dbname;
    $root = "root";
    $root_password = "Borisenco28#";

    try {
        $DBH = new PDO("mysql:host=$host", $root, $root_password);

        $DBH->exec("CREATE DATABASE `$dbname`;
                    CREATE USER '$user'@'$host' IDENTIFIED BY '$pass';
                    GRANT SELECT,UPDATE,INSERT ON `$dbname`.* TO '$user'@'$host';
                    FLUSH PRIVILEGES;");

        print "<p>База данных \"Галерея\" и пользователь успешно созданы</p>
                <br>
                <p>CREATE DATABASE `$dbname`;<br>
                CREATE USER '$user'@'$host' IDENTIFIED BY '$pass';<br>
                GRANT ALL ON `$dbname`.* TO '$user'@'$host';<br>
                FLUSH PRIVILEGES;</p>";
    }
    catch (PDOException $e) {
        print "<p>ERROR: {$e->getMessage()}</p>";
    }
}

function DeleteDB(){
    global $host;
    global $user;
    global $dbname;
    $root = "root";
    $root_password = "Borisenco28#";

    try {
        $DBH = new PDO("mysql:host=$host", $root, $root_password);

        $DBH->exec("DROP USER '$user'@'$host';
                    DROP DATABASE $dbname;");

        print "<p>База данных \"Галерея\" и пользователь успешно удалены</p>
        <br>
        <p>DROP DATABASE $dbname;<br>
        DROP USER $user;</p>";
    }
    catch (PDOException $e) {
        print "<p>ERROR: {$e->getMessage()}</p>";
    }
}


?>
