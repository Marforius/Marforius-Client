<?php
/*********************************************
*   PACW - Pingue Account Creation Website   *
*                 Version: 1.0               *
*            coded by Adam Viðarsson         *
*                                            *
*             http://thepingue.com           *
*                                            *
*********************************************/

include('../core/config.php');
$dbcon = @mysql_connect($dbhost, $dbuser, $dbpass);
	if (!$dbcon)
	{
	  return show_error(mysql_error());
	}
	$dba = @mysql_select_db($dbchars, $dbcon);
	if (!$dba)
	{
	  return show_error(mysql_error());
	}
echo '{"online":"';

$poquery2 = mysql_query("SELECT name, race, class, gender, level FROM characters WHERE online = '1' ORDER BY RAND()") or die(mysql_error());
if(mysql_num_rows($poquery2) > 0) {
	echo '<table>';
	while($row =mysql_fetch_array($poquery2)) {
		echo '<tr><td width=\'185\'>'.$row['name'].'</td><td width=\'71\' align=\'center\'><img src=\'images/stats/'.$row['race'].'-'.$row['gender'].'.gif\'></td><td width=\'63\' align=\'center\'><img src=\'images/stats/'.$row['class'].'.gif\'></td><td width=\'48\' align=\'center\'>'.$row['level'].'</td></tr>';
	}
	echo '</table>';
} else $error = 'No online Characters!';

echo '"}';
?>