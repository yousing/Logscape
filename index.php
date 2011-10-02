<?php
include './logscape.conf';
include './header_index.txt';
?>
<div class="content">
<?php
clearstatcache();
$o_dir=opendir($root_path);
while($file[] = readdir($o_dir)){}
closedir($o_dir);
rsort($file);
reset($file);
array_pop($file);
while ($filename = each($file)) {
if($filename[1] !="." && $filename[1] != ".." ){
include './logtime.src' ;
?>
	<ul class="content_list">
		<li>
			<ul class="function_list">            
            <li class="date"><a href="./logview.php?name=<?php print($filename[1]); ?>&num=-<?php print($filename[0]); ?>" title="URL読み込み、昇順"><?php print($file_ymd) ; ?></a></li>
            <li><a href="./logview.php?name=<?php print($filename[1]); ?>&num=-<?php print($filename[0]); ?>&flag=1" title="URL読み込みなし、昇順">ピュア</a></li>
            <li><a href="./logview.php?name=<?php print($filename[1]); ?>&num=-<?php print($filename[0]); ?>&flag=6" title="携帯用・URL読み込みなし、昇順">スモール</a></li>
            <li><a href="./logview.php?name=<?php print($filename[1]); ?>&num=-<?php print($filename[0]); ?>&flag=4" title="URL抽出・読み込み、昇順">URLのみ</a></li>
            </ul>
		</li>
	</ul>
<?php
}
}
?>
</div>
<?php include './footer.txt';?>
</body>
</html>