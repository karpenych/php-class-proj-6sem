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
    <fieldset>
        <legend><b>СОЗДАТЬ ТАБЛИЦЫ</b></legend>
        <input type="submit" name="bt_create" value="создать"/>
        <input type="submit" name="bt_delete" value="удалить"/>
        <?php create_delete_tables(); ?>
    </fieldset>
    </form>
<?php
}

function load_fillTables_content(){
?>
    <form method="post" action="">
    <fieldset>
        <legend><b>ВЫСТАВКИ</b></legend>
        <div class = "field">
            <input type="text" size="15" name="inp_name" placeholder="Название">
        </div>
        <div class = "field">
            <input type="datetime-local" name="inp_date">
        </div>
        <div class = "field">
            <input type="text" size="30" name="inp_address" placeholder="Адрес">
        </div>
        <input type="submit" name="bt_exhibitions" value="заполнить"/>
    </fieldset>
    <fieldset>
        <legend><b>ЗАЛЫ</b></legend>
        <div class = "field">
            <input type="text" size="3" name="inp_number" placeholder="№">
        </div>
        <div class = "field">
            <SELECT name="exhibition_selector">
                <option value="-1">Выставка</option>
                <?php GetExhibitions() ?>
            </SELECT>
        </div>
        <input type="submit" name="bt_halls" value="заполнить"/>
    </fieldset>
    <fieldset>
        <legend><b>ХУДОЖНИКИ</b></legend>
        <div class = "field">
            <input type="text" size="15" name="inp_sername" placeholder="Фамилия">
        </div>
        <div class = "field">
            <input type="text" size="15" name="inp_name" placeholder="Имя">
        </div>
        <input type="submit" name="bt_artists" value="заполнить"/>
    </fieldset>
    <fieldset>
        <legend><b>КАРТИНЫ</b></legend>
        <div class = "field">
            <input type="text" size="15" name="inp_name" placeholder="Название">
        </div>
        <div class = "field">
            <input type="number" size="15" name="inp_cost" placeholder="Цена">
        </div>
        <div class = "field">
            <SELECT name="artist_selector">
                <option value="-1">Художник</option>
                <?php GetArtists() ?>
            </SELECT>
        </div>
        <div class = "field">
            <SELECT name="hall_selector">
                <option value="-1">Зал</option>
                <?php GetHalls() ?>
            </SELECT>
        </div>
        <input type="submit" name="bt_paintings" value="заполнить"/>
    </fieldset>
    <?php FillTable(); ?>
    </form>
<?php
}

function load_showTables_content(){
?>
    <form method="post" action="">
    <fieldset>
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
