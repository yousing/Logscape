<?php

 function nick_change($datum){
    $time = $datum[0];
    $prenick = $datum[1];
    $datum[0] = "<li class=\"changed\"><span class=\"time\">$time</span>";
    $datum[2] = " -&gt; ";
    $datum[] = "</li> \n";
    foreach($datum as $view){print($view);}
}

function chanel_part($datum){
    $space = " ";
    $time = $datum[0];
    $datum[0] = "<li class=\"part_room\"><span class=\"time\">$time</span>";
    $datum[] = "</li> \n";
    for ($i=1 ; isset($datum[$i])  ; $i++){$datum[$i] = $datum[$i].$space ;}
    foreach($datum as $view){print($view);}
}

function chanel_join($datum){
    $space = " ";
    $time = $datum[0];
    $datum[0] = "<li class=\"in_room\"><span class=\"time\">$time</span>";
    $datum[] = "</li>\n";
    for ($i=1 ; isset($datum[$i])  ; $i++){$datum[$i] = $datum[$i].$space ;}
    foreach($datum as $view){print($view);}
}

function mode_chg($datum){
    $space = " ";
    $time = $datum[0];
    $datum[0] = "<li class=\"mode_chg\"><span class=\"time\">$time</span>";
    $datum[] = "</li>\n";
    for ($i=1 ; isset($datum[$i])  ; $i++){$datum[$i] = $datum[$i].$space ;}
    foreach($datum as $view){print($view);}
}

function topic_set($datum){
    $space = " ";
    $time = $datum[0];
    $datum[0] = "<li class=\"topic_set\"><span class=\"time\">$time</span>";
    $datum[] = "</li>\n";
    for ($i=1 ; isset($datum[$i])  ; $i++){
    $datum[$i] = preg_replace("/\"/","&quot;",$datum[$i]);
    $datum[$i] = $datum[$i].$space ;
    }
    foreach($datum as $view){
    print($view);
    }
}

function m_mai($datum){
    include './logscape.conf';
    $space = " ";
    $time = $datum[0];
    $datum[0] = "<li class=\"m_mai\"><span class=\"time\">$time</span>";
    $nick = $datum[1];
    //ニック内のチャンネル名
    $start_lt = "/^<$cur_chanel:/";
    $lt_replace = "&lt;";
    $tmp_nick = preg_replace($start_lt,$lt_replace,$nick);
    $end_gt = "/>$/";
    $gt_replace = "&gt;";
    $tmp_nick = preg_replace($end_gt,$gt_replace,$tmp_nick);
    $nick = $tmp_nick ;
    $datum[1] = "<span class=\"nick\">$nick</span>";
    $datum[] = "</li>\n";
    for ($i=1 ; isset($datum[$i])  ; $i++){$datum[$i] = $datum[$i].$space ;}
    foreach($datum as $view){print($view); }
}

function dametunes($datum){
    include './logscape.conf';
    $space = " ";
    $time = $datum[0];
    $datum[0] = "<li class=\"dametunes\"><span class=\"time\">$time</span>";
    $datum[] = "</li> \n";
    for ($i=1 ; isset($datum[$i])  ; $i++){$datum[$i] = $datum[$i].$space ;}
    foreach($datum as $view){print($view); }
}

function log_txt_noimage($datum){
    include './logscape.conf';
    $space = " ";
    $time = $datum[0];
    $datum[0] = "<li><span class=\"time\">$time</span>";
    $nick = $datum[1];
//ニック内のチャンネル名
    $start_lt = "/^<$cur_chanel:/";
    $lt_replace = "&lt;";
    $tmp_nick = preg_replace($start_lt,$lt_replace,$nick);
    $end_gt = "/>$/";
    $gt_replace = "&gt;";
    $tmp_nick = preg_replace($end_gt,$gt_replace,$tmp_nick);
    $nick = $tmp_nick ;
    $datum[1] = "<span class=\"nick\">$nick</span>";
    for ($i=2 ; isset($datum[$i])  ; $i++){
        $datum[$i] = preg_replace("/</","&lt;",$datum[$i]);
        $datum[$i] = preg_replace("/>/","&gt;",$datum[$i]);
        $datum[$i] = $datum[$i].$space ;
        $tmp_url = mbereg_replace('(https?|ftp)(:\/\/[-_.!~*\'()a-zA-Z0-9;\/?:\@&=+\$,%#]+)','<a href="\0" target = \"_blank\">\0</a>',$datum[$i]);
        $datum[$i] = $tmp_url ;
    }
    $datum[] = "</li>\n";
    foreach($datum as $view){print($view);}
}

function log_txt($datum){
    include './logscape.conf';
    $space = " ";
    $time = $datum[0];
    $datum[0] = "<li><span class=\"time\">$time</span>";
    $nick = $datum[1];
//ニック内のチャンネル名
    $start_lt = "/^<$cur_chanel:/";
    $lt_replace = "&lt;";
    $tmp_nick = preg_replace($start_lt,$lt_replace,$nick);
    $end_gt = "/>$/";
    $gt_replace = "&gt;";
    $tmp_nick = preg_replace($end_gt,$gt_replace,$tmp_nick);
    $nick = $tmp_nick ;
    $datum[1] = "<span class=\"nick\">$nick</span>";
    for ($i=2 ; isset($datum[$i])  ; $i++){
        $datum[$i] = preg_replace("/</","&lt;",$datum[$i]);
        $datum[$i] = preg_replace("/>/","&gt;",$datum[$i]);
        $datum[$i] = $datum[$i].$space ;
        mb_ereg('(https?|ftp)(:\/\/[-_.!~*\'()a-zA-Z0-9;\/?:\@&=+\$,%#]+)',$datum[$i],$tmp_html);
        if(preg_match("/.png$|.jpg$|.jpeg$|.gif$|.PNG$|.JPG$|.JPEG$|.GIF$/",$tmp_html[0])){
            $tmp_url = mbereg_replace('(https?|ftp)(:\/\/[-_.!~*\'()a-zA-Z0-9;\/?:\@&=+\$,%#]+)','<a href="\0" target = \"_blanj\">\0</a></li><li><img src="\0" alt="images" />',$datum[$i]);            
        }else{
            $tmp_url = mbereg_replace('(https?|ftp)(:\/\/[-_.!~*\'()a-zA-Z0-9;\/?:\@&=+\$,%#]+)','<a href="\0" target = \"_blank\">\0</a>',$datum[$i]);
        }
        $datum[$i] = $tmp_url ;
    }
    $datum[] = "</li>\n";
    foreach($datum as $view){print($view);}
}

function get_topic($data){
for($count = 0 ; isset($data[$count]) ; $count++ ){
    if(preg_match("/^Topic/",$data[$count][1])){
        for($count_int = 7; isset($data[$count][$count_int]) ; $count_int++){
            $topic_get .= $data[$count][$count_int]." ";
        }
        $topic_get = preg_replace("/\"/","&quot;",$topic_get);
        $get_topi_fp=fopen("./topic.tmp" ,"w");
        flock($get_topi_fp,LOCK_EX);
        $topic_cash = "<?php \$set_topic=\"";
        $topic_cash .= $topic_get ;
        $topic_cash .= "\"?>" ;
        fputs($get_topi_fp,$topic_cash);
        flock($get_topi_fp,LOCK_UN);
        fclose($get_topi_fp);
//    print($count);
//    print($data[$count][7]);
    }
    $topic_get = "";
    }
}
?>
