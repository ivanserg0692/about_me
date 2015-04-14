<?php 
require_once "conf.php";
$name_page=preg_match('/\/([^\/\n]+)$/ui',$_SERVER['REQUEST_URI'],$match)==1?$match[1].".php":page_main;
include dir_pages.$name_page;