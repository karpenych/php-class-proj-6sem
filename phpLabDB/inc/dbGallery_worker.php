<?php

$host = 'localhost';
$user = 'dbgallery_admin';
$pass = 'Qwerqwer1';
$dbname = 'dbgallery';

$table_artists = "Artists";
$table_exhibitions = "Exhibitions";
$table_halls = "Halls";
$table_paintings = "Paintings";

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

    global $table_artists;
    global $table_exhibitions;
    global $table_halls;
    global $table_paintings;

    try {
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $DBH->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

        $sql = "SET foreign_key_checks = 1;";
        $DBH->exec($sql);

        // TABLE "Artists"
        $sql = "CREATE table $table_artists(
            sername VARCHAR(100) PRIMARY KEY,
            name    VARCHAR(100));";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_artists\" успешно создана: <br>$sql</p>";

        // TABLE "Exhibitions"
        $sql = "CREATE table $table_exhibitions(
            name    VARCHAR(100) PRIMARY KEY,
            date    DATETIME NOT NULL,
            address VARCHAR(100) NOT NULL);";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_exhibitions\" успешно создана: <br>$sql</p>";

        // TABLE "Halls"
        $sql = "CREATE table $table_halls(
            number   TINYINT PRIMARY KEY,
            exhibition VARCHAR(100) NOT NULL,
            FOREIGN KEY (exhibition) REFERENCES $table_exhibitions (name));";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_halls\" успешно создана: <br>$sql</p>";

        // TABLE "Paintings"
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

    global $table_artists;
    global $table_exhibitions;
    global $table_halls;
    global $table_paintings;

    try {
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $DBH->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

        $sql = "SET foreign_key_checks = 0;";
        $DBH->exec($sql);

        // TABLE "Artists"
        $sql = "DROP TABLE $table_artists";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_artists\" успешно удалена: <br>$sql</p>";

        // TABLE "Exhibitions"
        $sql = "DROP TABLE $table_exhibitions";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_exhibitions\" успешно удалена: <br>$sql</p>";

        // TABLE "Halls"
        $sql = "DROP TABLE $table_halls";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_halls\" успешно удалена: <br>$sql</p>";

        // TABLE "Paintings"
        $sql = "DROP TABLE $table_paintings";
        $DBH->exec($sql);
        print "<p>Таблица \"$table_paintings\" успешно удалена: <br>$sql</p>";
    }
    catch (PDOException $e) {
        print "<p>ERROR: {$e->getMessage()}</p>";
    }
}

function FillTable(){
    global $host;
    global $dbname;
    global $user;
    global $pass;

    global $table_artists;
    global $table_exhibitions;
    global $table_halls;
    global $table_paintings;

    try{
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $DBH->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );
    }
    catch(PDOException $e){
        print "<p>ERROR: {$e->getMessage()}</p>";
    }

    if(isset($_POST['bt_exhibitions']) && isset($_POST['inp_name']) && isset($_POST['inp_date']) && isset($_POST['inp_address'])){
        print "<p>ЗАШЛО В Exhibitions</p>";
        try{
            $sql = "INSERT INTO $table_exhibitions SET
                    name = '{$_POST['inp_name']}',
                    date = '{$_POST['inp_date']}',
                    address = '{$_POST['inp_address']}';";
            $DBH->exec($sql);
            header('Location: '.$_SERVER['REQUEST_URI']);
            print "<p>Вставка прошла успешно!!!</p>";
        }
        catch(PDOException $e){
            print "<p>ERROR: {$e->getMessage()}</p>";
        }
    }

    if(isset($_POST['bt_halls']) && isset($_POST['inp_number']) && isset($_POST['exhibition_selector'])){
        print "<p>ЗАШЛО В Halls</p>";
        try{
            $sql = "INSERT INTO $table_halls SET
                    number = `{$_POST['inp_number']}`,
                    exhibition = `{$_POST['exhibition_selector']}`;";
            $DBH->exec($sql);
            header('Location: '.$_SERVER['REQUEST_URI']);
            print "<p>Вставка прошла успешно!!!</p>";
        }
        catch(PDOException $e){
            print "<p>ERROR: {$e->getMessage()}</p>";
        }
    }

    if(isset($_POST['bt_artists']) && isset($_POST['inp_sername']) && isset($_POST['inp_name'])){
        print "<p>ЗАШЛО В Artists</p>";
        try{
            $sql = "INSERT INTO $table_artists SET
                    sername = `{$_POST['inp_sername']}`,
                    name = `{$_POST['inp_name']}`;";
            $DBH->exec($sql);
            header('Location: '.$_SERVER['REQUEST_URI']);
            print "<p>Вставка прошла успешно!!!</p>";
        }
        catch(PDOException $e){
            print "<p>ERROR: {$e->getMessage()}</p>";
        }
    }

    if(isset($_POST['bt_paintings']) && isset($_POST['inp_name']) && isset($_POST['inp_cost']) && isset($_POST['artist_selector']) && isset($_POST['hall_selector'])){
        print "<p>ЗАШЛО В Paintings</p>";
        try{
            $sql = "INSERT INTO $table_paintings SET
                    name = `{$_POST['inp_name']}`,
                    cost = `{$_POST['inp_cost']}`,
                    artist = `{$_POST['artist_selector']}`,
                    hall = `{$_POST['hall_selector']}`;";
            $DBH->exec($sql);
            header('Location: '.$_SERVER['REQUEST_URI']);
            print "<p>Вставка прошла успешно!!!</p>";
        }
        catch(PDOException $e){
            print "<p>ERROR: {$e->getMessage()}</p>";
        }
    }

}

function GetExhibitions(){
    global $host;
    global $dbname;
    global $user;
    global $pass;
    global $table_exhibitions;

    try{
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $exhibitions = $DBH->query("SELECT * FROM `$table_exhibitions`");

        while($exhibition = $exhibitions->fetch(PDO::FETCH_ASSOC))
            print "<option value=\"{$exhibition['name']}\">{$exhibition['name']}</option>\n";
    }
    catch(PDOException $e){
        print "<p>ERROR: {$e->getMessage()}</p>";
    }
}

function GetArtists(){
    global $host;
    global $dbname;
    global $user;
    global $pass;
    global $table_artists;

    try{
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $artists = $DBH->query("SELECT * FROM `$table_artists`");

        while($artist = $artists->fetch(PDO::FETCH_ASSOC))
            print "<option value=\"{$artist['name']}\">{$artist['name']}</option>\n";
    }
    catch(PDOException $e){
        print "<p>ERROR: {$e->getMessage()}</p>";
    }
}

function GetHalls(){
    global $host;
    global $dbname;
    global $user;
    global $pass;
    global $table_halls;

    try{
        $DBH = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $pass);
        $halls = $DBH->query("SELECT * FROM `$table_halls`");

        while($hall = $halls->fetch(PDO::FETCH_ASSOC))
            print "<option value=\"{$hall['name']}\">{$hall['name']}</option>\n";
    }
    catch(PDOException $e){
        print "<p>ERROR: {$e->getMessage()}</p>";
    }
}




?>
