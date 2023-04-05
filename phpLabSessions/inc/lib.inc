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
            <li><a href="input.php">Ввод</a></li>
            <li><a href="output.php">Вывод</a></li>
        </ul>
    </div>
<?php
}

function load_index_content(){
    print "<br><br><br><h3>Это главная страница</h3><br><br><br>";
}

function load_input_content(){
?>
    <form method="post" action="">
    <fieldset>
        <legend><b>СОЗДАНИЕ СЕССИИ</b></legend>
        <div class = "field">
            <input type="text" size="15" name="inp_salon" placeholder="Салон">
        </div>
        <div class = "field">
            <input type="text" size="15" name="inp_master" placeholder="Мастер">
        </div>
        <div class = "field">
            <input type="text" size="15" name="inp_haircut" placeholder="Стрижка">
        </div>
        <div class = "field">
            <input type="text" size="15" name="inp_photo" placeholder="Фото">
        </div>
        <div class = "field">
            <input type="datetime-local" size="15" name="inp_time" placeholder="Время">
        </div>
        <div class = "field">
            <input type="number" size="15" name="inp_cost" placeholder="Стоимость">
        </div>
        <input type="submit" name="bt_submit" value="ввести"/>
    </fieldset>
    </form>
<?php
    $_SESSION['name'] = "Стрижка";
    if (isset($_POST['bt_submit'])){
        $arr = array(
            "Салон"     => $_POST['inp_salon'],
            "Мастер"    => $_POST['inp_master'],
            "Стрижка"   => $_POST['inp_haircut'],
            "Фото"      => $_POST['inp_photo'],
            "Время"     => $_POST['inp_time'],
            "Стоимость" => $_POST['inp_cost']
        );
        $_SESSION['array'] = $arr;
    }
}

function load_output_content(){
?>
    <fieldset>
        <legend><b>ИСПОЛЬЗОВАНИЕ ПЕРЕМЕННЫХ СЕССИИ</b></legend>
<?php
        print "<p>Ваша услуга: \"{$_SESSION['name']}\"<br>
                Информация:</p><p>";
        foreach($_SESSION['array'] as $key => $value){
            print "$key - $value<br>";
        }
        print "</p>";
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
        case "input":
            load_input_content();
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
