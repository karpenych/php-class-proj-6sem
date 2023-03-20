<?php

function checkYear(){
    if(isset($_POST['bt_submit']) && isset($_POST['input_year'])){
        $year = $_POST['input_year'];
        if (is_numeric($year)){
            if ($year % 400 == 0)
                print "<p>Високосный год. Дней в году: 366</p>";
            else if ($year % 100 == 0)
                print "<p>Не високосный год. Дней в году: 365</p>";
            else if ($year % 4 == 0)
                print "<p>Високосный год. Дней в году: 366</p>" ;
            else
                print "<p>Не високосный год. Дней в году: 365</p>";
        } else
            print "<p>Введите год для проверки</p>";
    }
}

function GetRandomEnglishLetters(){
    if(isset($_POST['bt_submit'])){
        for ($i = 0; $i < 6; ++$i){
            for($j = 0; $j < 6; ++$j){
                $letter = chr(rand(65, 90));
                print " $letter";
            }
            print "<br>";
        }
    }
}

function ShowDate(){
    if(isset($_POST['bt_submit']) && isset($_POST['input_date'])){
        $timestamp_input = strtotime($_POST['input_date']); // Преобразуем введенную дату в таймстамп
        $timestamp_now = time(); // Получаем текущий таймстамп
        $seconds_diff = $timestamp_now - $timestamp_input; // Вычисляем разницу в секундах
        $days_diff = floor($seconds_diff / 86400); // Получаем разницу в днях и округляем до целого числа
        $weeks_diff = floor($days_diff/7); // Получаем разницу в неделях и округляем до целого
        print "<p>Прошло дней: $days_diff<br>Прошло недель: $weeks_diff</p>";
    }
}

function lab3_1(){
    if(isset($_POST['bt_submit'])){
        $startStr = htmlentities(file_get_contents("{$_SERVER['DOCUMENT_ROOT']}/php-class-proj/phpLabs1-6/txt/lab3.txt"));
        $str = "попрыгунья стрекоза $startStr";
        $strToDel = "оглянуться не успела";        
        $str = str_replace($strToDel, "", $str);
        $firstLetter = mb_substr($str, 0, 1, 'utf-8');
        $firstLetter = mb_strtoupper($firstLetter, 'utf-8'); 
        $str = mb_substr($str, 1, mb_strlen($str, 'utf-8') - 1, 'utf-8');
        $str = "{$firstLetter}{$str}";
        print "<p>$str</p>";
    }
}

function lab3_2(){
    if(isset($_POST['bt_submit'])){
        $startStr = htmlentities(file_get_contents("{$_SERVER['DOCUMENT_ROOT']}/php-class-proj/phpLabs1-6/txt/lab3.txt"));
        $strToChange = mb_substr($startStr, 3, 5, 'utf-8');
        $str = str_replace($strToChange, "!!!", $startStr);
        print "<p>$str</p>";
    }
}


?>
