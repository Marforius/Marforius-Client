<?php
	function show_error($error = "unknown issue") {
	  echo '<div class="nosuccess"><span style="padding-left:25px;color:#FFF;font-weight:bold;">ERROR:</span> ' . $error . ' <div class="n-img"></div></div><br />';
	}
	function locked_error($error = "unknown issue") {
	  echo '<div class="locked"><span style="padding-left:25px;color:#FFF;font-weight:bold;">ERROR:</span> ' . $error . ' <div class="l-img"></div></div><br />';
	}
	
	if($show_all) {
		if(isset($_GET['status']) && $_GET['status'] == "showall") {
			if(!file_exists('all.php'))
			return show_error("all.php is missing");
			else include("all.php");
		}
	}
	
	function vTheme() {
		global $theme, $checker;
		switch ($theme) {
			case 0:
			echo 'nvision';
			break;
			case 1:
			echo 'tvw';
			break;
			case 2:
			echo 'cataclysm';
			break;
			default:
			echo 'nvision';
		}		
	}
		
	function str_replace_assoc($array,$string) {
		$from_array = array();
		$to_array = array();
		
		foreach ($array as $k => $v){
			$from_array[] = $k;
			$to_array[] = $v;
		}
		
		return str_replace($from_array,$to_array,$string);
	}
	
	function xmlStuff() {
		global $xmlfile, $xmldisplay;
		if($xmldisplay != 0) {
			if(file_exists($xmlfile)) {
				$xml = simplexml_load_file($xmlfile);
				
				if($xmldisplay != 2 && $xmldisplay != 3) {
					return "<div align='center'>Uptime: " . $xml->status->uptime . "</div><br /><div align='center'>Online GMs: " . $xml->status->gmcount . "</div><br />";
				}
				if($xmldisplay != 1 && $xmldisplay != 3) {
					return "<div align='center'>Uptime: " . $xml->status->uptime . "</div><br />";
				}
				if($xmldisplay != 2 && $xmldisplay != 1) {
					return "<div align='center'>Online GMs " . $xml->status->gmcount . "</div><br />";
				}
			} else {
				return show_error("Your xml file cannot be found, please insert right settings in config.php");
			}
		}	
	}
	
	function jStyle() {
      global $js;
      echo ($js == 1) ? 'slide' : 'fade';
    }
	
	//Mav approved ^^
	function displayPlayers() {
		global $show_players, $online_players, $show_all;
		if ($show_players < $online_players) echo 'Displaying random ' . $show_players . ' of ' . $online_players . ' players.';
        if($show_all) echo ' - <a href="#showall" onClick="getOnline(id);">Show All</a>';
		else echo 'Displaying ' . $online_players . ' players.';
	}
	
	function is_valid_email ($email) {
		$qtext = '[^\\x0d\\x22\\x5c\\x80-\\xff]';
		$dtext = '[^\\x0d\\x5b-\\x5d\\x80-\\xff]';
		$atom = '[^\\x00-\\x20\\x22\\x28\\x29\\x2c\\x2e\\x3a-\\x3c'.
					'\\x3e\\x40\\x5b-\\x5d\\x7f-\\xff]+';
		$quoted_pair = '\\x5c\\x00-\\x7f';
		$domain_literal = "\\x5b($dtext|$quoted_pair)*\\x5d";
		$quoted_string = "\\x22($qtext|$quoted_pair)*\\x22";
		$domain_ref = $atom;
		$sub_domain = "($domain_ref|$domain_literal)";
		$word = "($atom|$quoted_string)";
		$domain = "$sub_domain(\\x2e$sub_domain)*";
		$local_part = "$word(\\x2e$word)*";
		$addr_spec = "$local_part\\x40$domain";
	 
		return preg_match("!^$addr_spec$!", $email) ? true : false;
	}
			
	function showPlayersOnline() {
		global $show_players;
		$poquery = mysql_query("SELECT name, race, class, gender, level FROM characters WHERE online = '1' ORDER BY RAND() LIMIT {$show_players}");
		if(mysql_num_rows($poquery) > 0) {
			while($row =mysql_fetch_array($poquery)) {
				echo '      <tr>
										<td width="185">'.$row['name'].'</td>
										<td width="71" align="center"><img src=\'images/stats/'.$row['race'].'-'.$row['gender'].'.gif\'></td>
										<td width="63" align="center"><img src=\'images/stats/'.$row['class'].'.gif\'></td>
										<td width="48" align="center">'.$row['level'].'</td>
									</tr>';
			}
		} else $error = 'No online characters!';
		
	}
	
	function showAllPlayersOnline() {
		$poquery2 = mysql_query("SELECT name, race, class, gender, level FROM characters WHERE online = '1' ORDER BY RAND()") or die(mysql_error());
		if(mysql_num_rows($poquery2) > 0) {
			while($row =mysql_fetch_array($poquery2)) {
				echo '      <tr>
										<td width="185">'.$row['name'].'</td>
										<td width="71" align="center"><img src=\'images/stats/'.$row['race'].'-'.$row['gender'].'.gif\'></td>
										<td width="63" align="center"><img src=\'images/stats/'.$row['class'].'.gif\'></td>
										<td width="48" align="center">'.$row['level'].'</td>
									</tr>';
			}
		} else $error = 'No online Characters!';
	}
	
?>