<?php

include "{$_SERVER['DOCUMENT_ROOT']}/php-class-proj/phpLabs1-6/inc/dbCinema_worker.php";
include "{$_SERVER['DOCUMENT_ROOT']}/php-class-proj/phpLabs1-6/inc/tools.php";


function print_site_head(){
    print "<h1>Структура сайта на языке PHP</h1>";
}

function print_page_head($head){
    print $head;
}

function load_menu(){
?>
    <div class="block_nav">
        <ul class="navigation">
            <li><a href="index.php">Главная</a></li>
            <li><a href="LR1.php">ЛР1</a></li>
            <li><a>ЛР2</a>
                <ul>
                    <li><a href="LR2_1.php">Задание 1</a></li>
                    <li><a href="LR2_2.php">Задание 2</a></li>
                </ul>
            </li>
            <li><a>ЛР3</a>
                <ul>
                    <li><a href="LR3_1.php">Задание 1</a></li>
                    <li><a href="LR3_2.php">Задание 2</a></li>
                    <li><a href="LR3_3.php">Задание 3</a></li>
                </ul>
            </li>
        </ul>
    </div>
<?php
}

function load_index_content(){
    print "<p>Это главная страница</p>";
}

function load_LR1_content(){
?>
    <form method="post" action="">
        <fieldset id="fslb1">
            <legend><b>КИНОАФИША</b></legend>
            <SELECT name="cinema_selector" size="1">
                <option value="-1"></option>
                <?php get_cinemas(); ?>
            </SELECT>
            <input type="submit" name="bt_submit" value="Показать"/>
            <?php get_cinema_name();?>
            <br>
            <?php get_cinema_data(); ?>
        </fieldset>
    </form>
<?php
}

function load_LR2_1_content(){
?>
    <form method="post" action="">
    <fieldset id="fslb2_1">
        <legend><b>ОПРЕДЕЛИТЕЛЬ ДНЕЙ В ГОДУ</b></legend>
        <label for="input_year">Введите год: </label>
        <input type="text" size="6" name="input_year" placeholder="2023" id="year">
        <input type="submit" name="bt_submit" value="Определить дни"/>
        <span><?php checkYear(); ?></span>
    </fieldset>
    </form>
<?php
}

function load_LR2_2_content(){
?>
    <form method="post" action="">
    <fieldset id="fslb2_2">
        <legend><b>Случайные заглавные английские буквы</b></legend>
        <input type="submit" name="bt_submit" value="Вывести таблицу"/>
        <div><?php GetRandomEnglishLetters(); ?></div>
    </fieldset>
    </form>
<?php
}

function load_LR3_3_content(){
?>
    <form method="post" action="">
    <fieldset id="fslb3_3">
        <legend><b>КОЛИЧЕСТВО ДНЕЙ/НЕДЕЛЬ</b></legend>
        <label for="input_date">Выберите дату: </label>
        <input type="date" name="input_date" value="2002-06-14">
        <input type="submit" name="bt_submit" value="Определить количество дней/недель"/>
        <span><?php ShowDate(); ?></span>
    </fieldset>
    </form>
<?php
}

function load_LR3_1_content(){
?>
    <form method="post" action="">
    <fieldset id="fslb3_1">
        <legend><b>Строки-1</b></legend>
        <p>Вариант 4</p>
        <p>В строке «лето красное пропела оглянуться не успела» вставить в начало строки
        «попрыгунья стрекоза» и убрать в конце «оглянуться не успела», первую букву
        сделать прописной.</p>
        <?php
        $str = htmlentities(file_get_contents("{$_SERVER['DOCUMENT_ROOT']}/php-class-proj/phpLabs1-6/txt/lab3.txt"));
        print "<p>Исходный текст: '$str'</p>";
        ?>
        <input type="submit" name="bt_submit" value="Выполнить"/>
        <?php lab3_1(); ?>
    </fieldset>
    </form>
<?php
}

function load_LR3_2_content(){
?>
    <form method="post" action="">
    <fieldset id="fslb3_2">
        <legend><b>Строки-2</b></legend>
        <p>Вариант 4</p>
        <p>Дана строка $str. Вырежьте из нее подстроку с 3-го символа (отсчет с нуля), 5
        штук и вместо нее вставьте '!!!'.</p>
        <?php
        $str = htmlentities(file_get_contents("{$_SERVER['DOCUMENT_ROOT']}/php-class-proj/phpLabs1-6/txt/lab3.txt"));
        print "<p>Исходный текст: '$str'</p>";
        ?>
        <input type="submit" name="bt_submit" value="Выполнить"/>
        <?php lab3_2(); ?>
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
        case "LR1":
            load_LR1_content();
            break;
        case "LR2_1":
            load_LR2_1_content();
            break;
        case "LR2_2":
            load_LR2_2_content();
            break;
        case "LR3_1":
            load_LR3_1_content();
            break;
        case "LR3_2":
            load_LR3_2_content();
            break;
        case "LR3_3":
            load_LR3_3_content();
            break;
    }
}

function print_copyright(){
    print "<h2>&copy Студент 214.31 Карпенко Д. А. Верхнепортовая 50. 2023г</h2>";
}

?>
