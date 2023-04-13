<?php

function print_site_head(){
    print "<h1>Работа с классами </h1>";
}

function print_page_head($head){
    print $head;
}

function load_menu(){
?>
    <div class="block_nav">
        <ul class="navigation">
            <li><a href="index.php">Главная</a></li>
            <li><a href="vegetables.php">Овощи</a></li>
        </ul>
    </div>
<?php
}

function load_index_content(){
?>
    <fieldset>
    <br><br><br><h3>Это главная страница</h3><br><br><br>
    <h3>Вариант 4</h3><br>
    <h3>Задание: создать класс, позволяющий вывести информацию об овоще: название, вкус, цвет, страна, рисунок</h3>
    </fieldset>
<?php
}

function load_vegetables_content(){
?>
    <form method="post" action="" enctype='multipart/form-data'>
    <fieldset>
        <legend><b>ВСЁ ОБ ОВОЩЕ</b></legend>
        <div class = "field">
            <SELECT name="vegetable_selector">
                <option value="-1"> Овощи </option>
                <option value= "1"> Картофель </option>
                <option value= "2"> Томат </option>
                <option value= "3"> Огурец </option>
                <option value= "4"> Лук </option>
                <option value= "5"> Баклажан </option>
            </SELECT>
        </div>
        <input type="submit" name="bt_submit" value="ввести"/>
<?php
    class Vegetable{
        private $name;
        private $taste;
        private $color;
        private $country;
        private $drawing;

        public function __construct($name, $taste, $color, $country, $drawing){
            $this->name    = $name;
            $this->taste   = $taste;
            $this->color   = $color;
            $this->country = $country;
            $this->drawing = $drawing;
        }

        public function GetVegetable(){
            print "<p>";
            print "Название: ".$this->name."<br><br>";
            print "Вкус: ".$this->taste."<br><br>";
            print "Страна: ".$this->country."<br><br>";
            print "Цвет: <span style=\"background-color: #{$this->color}; color: #{$this->color};\">______</span><br><br>";
            print "<img src=\"{$this->drawing}\"><br>";
            print "</p>";
        }
    }

    if (isset($_POST['bt_submit'])){
        switch($_POST['vegetable_selector'])
        {
            case 1:
                $vegetable = new Vegetable("Картофель", "Картошка фри", "463918", "Белорусь", "img/potato.jpg");
                $vegetable->GetVegetable();
                break;
            case 2:
                $vegetable = new Vegetable("Томат", "Кетчуп", "7f1e05", "Китай", "img/tomato.jpeg");
                $vegetable->GetVegetable();
                break;
            case 3:
                $vegetable = new Vegetable("Огурец", "Спрайт Огурец", "0f3e13", "Россия", "img/cucumber.png");
                $vegetable->GetVegetable();
                break;
            case 4:
                $vegetable = new Vegetable("Лук", "Чипсы \"Луковые кольца\"", "777b47", "Япония", "img/onion.png");
                $vegetable->GetVegetable();
                break;
            case 5:
                $vegetable = new Vegetable("Баклажан", "Баклажановая икра", "4c3966", "Таджикистан", "img/eggplant.jpg");
                $vegetable->GetVegetable();
                break;
            default:
                print "<p>Выберите овощь</p>";
                break;
        }
    }
?>
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
        case "vegetables":
            load_vegetables_content();
            break;
    }
}

function print_copyright(){
    print "<h2>&copy Студент 214.31 Карпенко Д. А. Верхнепортовая 50. 2023г</h2>";
}

?>
