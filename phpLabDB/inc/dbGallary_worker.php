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


function CreateDB(){
    if(isset($_POST['bt_create'])){
        global $host;
        global $user;
        global $pass;
        global $dbname;
        $root = "root";
        $root_password = "Borisenco28#";

        try {
            $DBH = new PDO("mysql:host=$host", $root, $root_password);

            $DBH->exec("CREATE DATABASE `$dbname`;
                        CREATE USER '$user'@'localhost' IDENTIFIED BY '$pass';
                        GRANT ALL ON `$dbname`.* TO '$user'@'localhost';
                        FLUSH PRIVILEGES;");

            print "<p>База данных \"Галерея\" и пользователь успешно созданы</p>
                   <br>
                   <p>CREATE DATABASE `$dbname`;<br>
                   CREATE USER '$user'@'localhost' IDENTIFIED BY '$pass';<br>
                   GRANT ALL ON `$dbname`.* TO '$user'@'localhost';<br>
                   FLUSH PRIVILEGES;</p>";

        }
        catch (PDOException $e) {
            print "<p>ERROR: {$e->getMessage()}</p>";
        }
    }
}

function DeleteDB(){
    if(isset($_POST['bt_delete'])){
        global $host;
        global $user;
        global $dbname;
        $root = "root";
        $root_password = "Borisenco28#";

        try {
            $DBH = new PDO("mysql:host=$host", $root, $root_password);

            $DBH->exec("DROP DATABASE $dbname;
                        DROP USER $user;");

            print "<p>База данных \"Галерея\" и пользователь успешно удалены</p>
            <br>
            <p>CDROP DATABASE $dbname;<br>
            DROP USER $user;</p>";
        }
        catch (PDOException $e) {
            print "<p>ERROR: {$e->getMessage()}</p>";
        }
    }
}


?>
