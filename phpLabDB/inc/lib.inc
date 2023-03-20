<?php

include "{$_SERVER['DOCUMENT_ROOT']}/php-class-proj/phpLabDB/inc/dbGallery_worker.php";


function print_site_head(){
    print "<h1>Работа с базой данных </h1>";
}

function print_page_head($head){
    print $head;
}

function load_menu(){
?>
    <div class="block_nav">
        <ul class="navigation">
            <li><a href="index.php">Главная</a></li>
            <li><a href="createDB.php">создать бд</a></li>
            <li><a href="createTables.php">создать таблицы</a></li>
            <li><a href="fillTables.php">заполнить таблицы</a></li>
            <li><a href="showTables.php">показать таблицы</a></li>
        </ul>
    </div>
<?php
}

function load_index_content(){
    print "<br><br><br><h3>Это главная страница</h3><br><br><br>";
}

function load_createDB_content(){
?>
    <form method="post" action="">
        <fieldset>
            <legend><b>СОЗДАТЬ БД</b></legend>
            <input type="submit" name="bt_create" value="создать"/>
            <input type="submit" name="bt_delete" value="удалить"/>
            <?php create_delete_db(); ?>
        </fieldset>
    </form>
<?php
}

function load_createTables_content(){
?>
    <form method="post" action="">
    <fieldset id="fslb2_1">
        <legend><b>ОПРЕДЕЛИТЕЛЬ ДНЕЙ В ГОДУ</b></legend>

    </fieldset>
    </form>
<?php
}

function load_fillTables_content(){
?>
    <form method="post" action="">
    <fieldset id="fslb2_2">
        <legend><b>Случайные заглавные английские буквы</b></legend>

    </fieldset>
    </form>
<?php
}

function load_showTables_content(){
?>
    <form method="post" action="">
    <fieldset id="fslb3_1">
        <legend><b>Строки-1</b></legend>

    </fieldset>
    </form>
<?php
}

function load_page(){
    global $page;

    switch ($page)
    {
        case "index":
            load_index_content();
            break;
        case "createDB":
            load_createDB_content();
            break;
        case "createTables":
            load_createTables_content();
            break;
        case "fillTables":
            load_fillTables_content();
            break;
        case "showTables":
            load_showTables_content();
            break;
    }
}

function print_copyright(){
    print "<h2>&copy Студент 214.31 Карпенко Д. А. Верхнепортовая 50. 2023г</h2>";
}

?>
