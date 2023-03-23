<?php

$host = 'localhost';
$user = 'dbgallery_admin';
$pass = 'Qwerqwer1';
$dbname = 'dbgallery';

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
                    GRANT ALL ON `$dbname`.* TO '$user'@'$host';
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

function create_delete_tables(){
    if(isset($_POST['bt_create'])){
        CreateTables();
    }
    if(isset($_POST['bt_delete'])){
        DeleteTables();
    }
}

function CreateTables(){
    global $host;
    global $dbname;
    global $user;
    global $pass;

    try {
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $DBH->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

        $sql = "SET foreign_key_checks = 1;";
        $DBH->exec($sql);

        // TABLE "Artists"
        $table_artists = "Artists";
        $sql = "CREATE table $table_artists(
            sername VARCHAR(100) PRIMARY KEY,
            name    VARCHAR(100));";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_artists\" успешно создана: <br>$sql</p>";

        // TABLE "Exhibitions"
        $table_exhibitions = "Exhibitions";
        $sql = "CREATE table $table_exhibitions(
            name    VARCHAR(100) PRIMARY KEY,
            date    DATETIME NOT NULL,
            address VARCHAR(100) NOT NULL);";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_exhibitions\" успешно создана: <br>$sql</p>";

        // TABLE "Halls"
        $table_halls = "Halls";
        $sql = "CREATE table $table_halls(
            number   TINYINT PRIMARY KEY,
            exhibition VARCHAR(100) NOT NULL,
            FOREIGN KEY (exhibition) REFERENCES $table_exhibitions (name));";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_halls\" успешно создана: <br>$sql</p>";

        // TABLE "Paintings"
        $table_paintings = "Paintings";
        $sql = "CREATE table $table_paintings(
            name      VARCHAR(100) PRIMARY KEY,
            cost      DECIMAL(20,2),
            artist VARCHAR(100) NOT NULL,
            hall TINYINT NOT NULL,
            FOREIGN KEY (artist) REFERENCES $table_artists (sername),
            FOREIGN KEY (hall) REFERENCES $table_halls  (number));";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_paintings\" успешно создана: <br>$sql</p>";
    }
    catch(PDOException $e) {
        print "<p>ERROR: {$e->getMessage()}</p>";
    }
}

function DeleteTables(){
    global $host;
    global $dbname;
    global $user;
    global $pass;

    try {
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $DBH->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

        $sql = "SET foreign_key_checks = 0;";
        $DBH->exec($sql);

        // TABLE "Artists"
        $table_artists = "Artists";
        $sql = "DROP TABLE $table_artists";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_artists\" успешно удалена: <br>$sql</p>";

        // TABLE "Exhibitions"
        $table_exhibitions = "Exhibitions";
        $sql = "DROP TABLE $table_exhibitions";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_exhibitions\" успешно удалена: <br>$sql</p>";

        // TABLE "Halls"
        $table_halls = "Halls";
        $sql = "DROP TABLE $table_halls";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_halls\" успешно удалена: <br>$sql</p>";

        // TABLE "Paintings"
        $table_paintings = "Paintings";
        $sql = "DROP TABLE $table_paintings";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_paintings\" успешно удалена: <br>$sql</p>";
    }
    catch (PDOException $e) {
        print "<p>ERROR: {$e->getMessage()}</p>";
    }
}





?>
