<!DOCTYPE html>
<html>
<head>
	<?php include dir_inc."header.php"; ?>
	<link  type="text/css" rel="stylesheet" href="css/content/main.css"/>
</head>
<body>
	<div class='main'>
		<div class="background"></div>
		<?php include dir_inc."menu.php";?>
		<div class='topic'>
			<center><h2>Имею поддержку web разработки при помощи следующих инструментов</h2></center>
			<div class="article">
				<p class='title'>Верстка</p>
				<div id='css' class='icon'></div><div id='html5' class='icon'></div>
			</div>
			<div class="article">
				<p class='title'>Скрипты</p>
				<div id='php' class='icon'></div><div id='js' class='icon'></div>
			</div>
			<div class="article">
				<p class='title'>Фраемворки</p>
				<div id='WP' class='icon'></div><div id='jq' class='icon' title="JQ"></div><div id='jqUI' class='icon' title="jquery ui"></div>
			</div>
			<div id="completed_work" class="article">
				<h2 class='title'>Законченные работы</h2>
				<div id="list_works"><ul class="carousel">
					<li><img src="images/content/portfolio/gelocation.png" title="геолокация" rel="#overlay_img"></li>
					<li><img src="images/content/portfolio/fotoalbom.png" title="фотоальбом" rel="#overlay_img"></li>
					<li><img src="images/content/portfolio/mysql_inection.jpg" title="mysql инъекция" rel="#overlay_img">взломал сайт</li>
				</ul></div>
			</div>
		</div>
	</div>
	<?php include dir_inc."footer.php"; ?>
</body>
</html>