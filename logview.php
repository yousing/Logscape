<?php
//チャンネル指定
include './function.inc';
include './logscape.conf';
include './logview_head.src';
include './header.txt';

?>
<div class="content">
<?php  include './hedder_menu.src'; ?>
<ul class="comments">
<?php include './logview.src.php'; ?>
</ul>
<?php include './footter_menu.src';?>
</div>
<?php
include './footer.txt';
?>
</body>
</html>