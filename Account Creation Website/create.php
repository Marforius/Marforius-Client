<?php
/*********************************************
*   PACW - Pingue Account Creation Website   *
*                 Version: 1.0               *
*            coded by Adam Viðarsson         *
*                                            *
*             http://thepingue.com           *
*        MODIFIED BY MYRAN2 OF MMOWNED       *
*        modified by Marforius, after Myran2 *
*********************************************/	
	$dbcon = @mysql_connect($dbhost, $dbuser, $dbpass);
	if (!$dbcon)
	{
	  return show_error(mysql_error());
	}
	$dba = @mysql_select_db($dbaccs, $dbcon);
	if (!$dba)
	{
	  return show_error(mysql_error());
	}

$ip = $_SERVER['REMOTE_ADDR'];

if($multi_ip != 1) {
	$query = @mysql_query("SELECT * FROM account WHERE last_ip = '$ip'") or die(mysql_error());
	if(mysql_num_rows($query) != 0) {
		return locked_error("You have already used this IP before to register an account.");
	} 
}

echo '<div id="acc">
<h2 align="center">Create an Account</h2><br /><form method="post">Account Name<br /><input type="text" name="accname" /><br /><br />Account Password<br /><input type="password" name="pword" /><br /><br />Retype your Password<br /><input type="password" name="pwordtwo" /><br /><br />E-mail Address (Use a valid E-mail)<br /><input type="text" name="accmail" /><br /><br /><input type="submit" value="" name="submit" /></form>
</div>';

if(isset($_POST['submit'])) {
  if(empty($_POST['accname']) || empty($_POST['pword']) || empty($_POST['pwordtwo']) || empty($_POST['accmail']))
    return show_error("Some fields were empty, please fill in all fields.");
$user = mysql_real_escape_string($_POST['accname']);
$pass = mysql_real_escape_string($_POST['pword']);
$email = mysql_real_escape_string($_POST['accmail']);
$hash = sha1(strtoupper($user).':'.strtoupper($pass));	

    if($_POST['pwordtwo'] != $_POST['pword']) return show_error("Your passwords did not match."); 
	if(!is_valid_email($_POST['accmail'])) return show_error("You must use a valid email");
	
    $query1 = @mysql_query("SELECT * FROM account WHERE username = '$_POST[accname]'") or die(mysql_error());
    if(mysql_num_rows($query1) != 0) return show_error("Username already exists in our database.");
    
    $query2 = @mysql_query("SELECT * FROM account WHERE email = '$_POST[accmail]'") or die(mysql_error());
    if(mysql_num_rows($query2) != 0) return show_error("E-mail already exists in our database.");
    
    $query3 = mysql_query("INSERT INTO account (username, sha_pass_hash, email) VALUES ('".$user."','".$hash."','".$email."')") or die(mysql_error()); 
    if (mysql_affected_rows($dbcon) <= 0) return show_error("Something went wrong, please try again. Account was not created!");

    echo '<div class="success"><span style="padding-left:35px;">Account successfully created!</span> <div class="s-img"></div></div><br />';
}

?>