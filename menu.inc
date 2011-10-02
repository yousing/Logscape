<?php
$yest_day = $_GET['num'];
$next_day = $_GET['num'];
$view_flag = $_GET['flag'];
$cur_day = $_GET['num'];
$cur_file = $_GET['name'];
$yest_day -= 1; 
$next_day += 1;
$cur_file = $file_data ;
$cur_ymd ;
$noimage_flag ;
$rev_flag ;
$rev_noimage_flag ;
$cur_ymd = preg_replace("/^log/","",$cur_file);
$cur_y = substr($cur_ymd,0,2);
$cur_m = substr($cur_ymd,2,2);
$cur_d = substr($cur_ymd,4,2);
//echo $cur_y.$cur_m.$cur_d ;
$yest_ymd = date("ymd",mktime(0,0,0,$cur_m,$cur_d+(-1),$cur_y));
$next_ymd = date("ymd",mktime(0,0,0,$cur_m,$cur_d+(1),$cur_y));
//print($yest_ymd);
?>